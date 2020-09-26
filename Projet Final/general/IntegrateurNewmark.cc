#include "Vecteur.h"
#include "Oscillateur.h"
#include "IntegrateurNewmark.h"

using namespace std;

void IntegrateurNewmark::integre(Oscillateur& oscillateur, double temps) const
{
    double epsilon(1e-6); // epsilon choisit arbitrairement petit, les tests marche avec ce choix
 for(int i((temps/pas_de_temps)+1e-20); i > 0; --i)
     /*/ comme on effectue une division entre deux double, si on passe
     comme paramètre la valeur du pas de temps de l'integrateur parfois la
     machine ne fait même pas une itération du a l'imprécision lors de la division,
     pour ceci on ajoute "1e-20" (une valeur suffisamment petite pour ne pas causer des
     grosses différences dans le fonctionnement du programme mais qui permet de résoudre ce problème) /*/
{
    // Définiton de l'intégrateur Newmark daccord avec le descriptif du projet
    Vecteur copie_parametre(oscillateur.getParametres());
    Vecteur copie_vitesse(oscillateur.getVitesse());
    Vecteur s = oscillateur.eq_mvt();
    Vecteur r, q;

 do {
    q = oscillateur.getParametres();
    r = oscillateur.eq_mvt();

    oscillateur.setVitesse(copie_vitesse + (pas_de_temps/2)*(r + s));

    oscillateur.setParametres(copie_parametre + pas_de_temps*copie_vitesse
        + (pas_de_temps*pas_de_temps/3)*(0.5*r + s));

    } while (((oscillateur.getParametres() - q)).norme() >= epsilon);

    Vecteur espaceDePhase({oscillateur.getParametres().getComp(1), oscillateur.getVitesse().getComp(1)});
    oscillateur.ajouterAEspacePhase(espaceDePhase);
    /*/ À chaque itération on ajoute le point composé par la première composante du vecteur
     paramètre et par la première composante du vecteur vitesse à lattribut espaceDePhase /*/
  }
}
