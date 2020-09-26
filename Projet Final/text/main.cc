#include "TextViewer.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Systeme.h"
#include "Vecteur.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"
#include "IntegrateurEulerCramer.h"
#include "IntegrateurNewmark.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /*/ On va créer un système avec un pendule, un ressort, un pendule-double et un ressort-pendule. Pour faciliter les tests du programme,
    on va écrire en commentaire un code avec une exception (on peut toujours essayez d'autres exceptions: masse negative, raideur
    négatif, longueur négatif, vecteur direction nul, vecteur vitesse et vecteur parametres de différente taille) et un autre code
    (celui qui n'est pas comenté) qui compile et s'affiche correctement, les valeurs ont été choisit arbitrairement /*/

     TextViewer ecran(cout);
     Systeme systeme(&ecran);

     // CODE SANS EXCEPTIONS
     Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

     // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
     Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1.0, 0.0, 0.0});
     double masse_pendule(1.0), lambda_pendule(0), longueur_pendule(1.0);

     // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
     Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.8, 0.0, 0.6});
     double masse_ressort(0.25), raideur_ressort(0.33), lambda_ressort(0.15);

     // Valeurs pour initialiser notre ressort-pendule: on peut toujours les changes pour tester des choses différentes!
     Vecteur parametre_ressortpendule({1.0, 0.3, 0.0}), vitesse_ressortpendule({2.0, 1.0, 0.0}),
                                                         direction_ressortpendule({0.0, 1.0, 0.0});
     double masse_ressortpendule(1.0), longueur_repos_ressortpendule(0.7), raideur_ressortpendule(5.0);

     // Valeurs pour initialiser notre pendule-double: on peut toujours les changes pour tester des choses différentes!
     Vecteur parametre_pendule_double({M_PI/2, M_PI/2}), vitesse_pendule_double({0.0, 0.0}),
                                                         direction_pendule_double({0.0, 1.0, 0.0});
     double masse_1_pendule_double(2.0), masse_2_pendule_double(2.0),
             longueur_1_pendule_double(2.0), longueur_2_pendule_double(1.0);

     IntegrateurEulerCramer integrateur_Euler_Cromer(0.1);
     systeme.ajouterIntegrateur(&integrateur_Euler_Cromer);

     // Pour tester avec integrateur de Newmark:
     //IntegrateurNewmark integrateur_Newmark;
     //systeme.ajouterIntegrateur(&integrateur_Newmark);

try {
         systeme.ajouterOscillateur(new Pendule(&ecran, parametre_pendule , vitesse_pendule,
                                             masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
         systeme.ajouterOscillateur(new RessortPenduleCouplee(&ecran, parametre_ressortpendule, vitesse_ressortpendule, masse_ressortpendule,
                                              direction_ressortpendule, origine, longueur_repos_ressortpendule, raideur_ressortpendule));
         systeme.ajouterOscillateur(new Pendule_Double(&ecran, parametre_pendule_double, vitesse_pendule_double,
                           direction_pendule_double, origine, longueur_1_pendule_double, longueur_2_pendule_double,
                           masse_1_pendule_double, masse_2_pendule_double));
         systeme.ajouterOscillateur(new Ressort(&ecran, parametre_ressort, vitesse_ressort, masse_ressort,
                                                 direction_ressort, origine, raideur_ressort, lambda_ressort));
    // À voir que maintenant sur gnuplot on aura la trajectoire dans l'espace des phases du ressort puisque c'est le dernier oscillateur du systeme

    systeme.dessine();

   // Ici on va faire evoluer tout les pendules de 0.1 s 600 fois pour creer des points pour appliquer gnuplot
   // Notre fonction evolue peut aussi prendre un temps absolut mais ce n'est pas ce que l'on veut pour dérouler gnuplot

  for(int i(0); i < 600; ++i)
    {
            systeme.evolue(0.1);
            systeme.dessine();
        }

} catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }
    /*/
    // CODE AVEC EXCEPTIONS
    Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

    // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1.0, 0.0, 1.0});
    double masse_pendule(2), lambda_pendule(0.1), longueur_pendule(2.0);

    // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.0, 0.0, 1.0});
    double masse_ressort(0.25), raideur_ressort(0.33), lambda_ressort(0.1);

    // Valeurs pour initialiser notre ressort-pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressortpendule({1.0, 0.3, 0.0}), vitesse_ressortpendule({2.0, 1.0, 0.0}),
                                                        direction_ressortpendule({0.0, 1.0, 0.0});
    double masse_ressortpendule(1.0), longueur_repos_ressortpendule(0.7), raideur_ressortpendule(5.0);

    // Valeurs pour initialiser notre pendule-double: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule_double({M_PI/2, M_PI/2}), vitesse_pendule_double({0.0, 0.0}),
                                                        direction_pendule_double({0.0, 1.0, 0.0});
    double masse_1_pendule_double(2.0), masse_2_pendule_double(2.0),
            longueur_1_pendule_double(2.0), longueur_2_pendule_double(1.0);

     IntegrateurEulerCramer integrateur_Euler_Cromer(0.1);
     systeme.ajouterIntegrateur(&integrateur_Euler_Cromer);

     // Pour tester avec integrateur de Newmark:
     //IntegrateurNewmark integrateur_Newmark;
     //systeme.ajouterIntegrateur(&integrateur_Newmark);

try {
         systeme.ajouterOscillateur(new Pendule(&ecran, parametre_pendule , vitesse_pendule,
                                             masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
         systeme.ajouterOscillateur(new RessortPenduleCouplee(&ecran, parametre_ressortpendule, vitesse_ressortpendule, masse_ressortpendule,
                                              direction_ressortpendule, origine, longueur_repos_ressortpendule, raideur_ressortpendule));
         systeme.ajouterOscillateur(new Pendule_Double(&ecran, parametre_pendule_double, vitesse_pendule_double,
                           direction_pendule_double, origine, longueur_1_pendule_double, longueur_2_pendule_double,
                           masse_1_pendule_double, masse_2_pendule_double));
         systeme.ajouterOscillateur(new Ressort(&ecran, parametre_ressort, vitesse_ressort, masse_ressort,
                                                 direction_ressort, origine, raideur_ressort, lambda_ressort));

     systeme.dessine();

     systeme.evolue(0.3);
     systeme.dessine();

} catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }/*/

  return 0;
}

