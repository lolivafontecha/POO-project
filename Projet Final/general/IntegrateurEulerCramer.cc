#include "Vecteur.h"
#include "Oscillateur.h"
#include "IntegrateurEulerCramer.h"

using namespace std;

void IntegrateurEulerCramer::integre(Oscillateur& oscillateur, double temps) const
{
 for(int i((temps/pas_de_temps)+1e-20); i > 0; --i)
     /*/ comme on effectue une division entre deux double, si on passe
     comme paramètre la valeur du pas de temps de l'integrateur parfois la
     machine ne fait même pas une itération du a l'imprécision lors de la division,
     pour ceci on ajoute "1e-20" (une valeur suffisamment petite pour ne pas causer des
     grosses différences dans le fonctionnement du programme mais qui permet de résoudre ce problème) /*/
{
    // Définiton de l'intégrateur Newmark daccord avec le descriptif du projet
    oscillateur.setVitesse(oscillateur.getVitesse() + pas_de_temps * oscillateur.eq_mvt());
    oscillateur.setParametres(oscillateur.getParametres() + pas_de_temps * oscillateur.getVitesse());

    Vecteur espaceDePhase({oscillateur.getParametres().getComp(1), oscillateur.getVitesse().getComp(1)});
    oscillateur.ajouterAEspacePhase(espaceDePhase);
    /*/ En effet, à chaque itération on ajoute le point composé par la première composante du vecteur
     paramètre et par la première composante du vecteur vitesse à lattribut espaceDePhase que nous rappelons qu'il
     s'agit d'un tableau de Vecteurs /*/
}
}

