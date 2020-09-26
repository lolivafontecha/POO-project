#include <iostream>
#include <vector>
#include <cmath>
#include "TextViewer.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Systeme.h"
#include "Vecteur.h"

using namespace std;

#ifndef M_PI
#define M_PI 3.141592653589793
#endif


int main()
{
    /*/ On va créer un système avec un pendule, et un ressort. Pour faciliter les test du programme,
    on va écrire en commentaire un code avec une exception (on peut toujours essayez d'autres exceptions: masse negative, raideur
    négatif, longueur négatif, vecteur direction nul, vecteur vitesse et vecteur parametres de différente taille) et un autre code 
   (celui qui n'est pas comenté) qui compile et s'affiche correctement, les valeurs sont celles du site du cours /*/

     TextViewer ecran(cout);
     Systeme systeme(&ecran);

     // CODE SANS EXCEPTIONS
     Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

     // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1, 0,0});
    double masse_pendule(2), lambda_pendule(0), longueur_pendule(1.0);

     // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.8, 0, 0.6});
    double masse_ressort(0.25), raideur_ressort(0.33), lambda_ressort(0.15);

     IntegrateurEulerCramer integrateur_Euler_Cromer(0.1);
     systeme.ajouterIntegrateur(&integrateur_Euler_Cromer);

     // Pour tester avec integrateur de Newmark:
     //IntegrateurNewmark integrateur_Newmark;
     //systeme.ajouterIntegrateur(&integrateur_Newmark);

try {
         systeme.ajouterOscillateur(new Pendule(&ecran, parametre_pendule , vitesse_pendule,
                                             masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
         systeme.ajouterOscillateur(new Ressort(&ecran, parametre_ressort, vitesse_ressort, masse_ressort,
                                                 direction_ressort, origine, raideur_ressort, lambda_ressort));
    systeme.dessine();

            systeme.evolue(0.1);
            systeme.dessine();

} catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    } 
/*/
    // CODE AVEC EXCEPTIONS
     Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

     // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1, 0,0}), origine({0, 0, 0});
    double masse_pendule(2), lambda_pendule(0), longueur_pendule(1.0);

     // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.8, 0, 0.6});
    double masse_ressort(-0.25), raideur_ressort(0.33), lambda_ressort(0.15);

     IntegrateurEulerCramer integrateur_Euler_Cromer(0.1);
     systeme.ajouterIntegrateur(&integrateur_Euler_Cromer);

     // Pour tester avec integrateur de Newmark:
     //IntegrateurNewmark integrateur_Newmark;
     //systeme.ajouterIntegrateur(&integrateur_Newmark);

try {
         systeme.ajouterOscillateur(new Pendule(&ecran, parametre_pendule , vitesse_pendule,
                                             masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
         systeme.ajouterOscillateur(new Ressort(&ecran, parametre_ressort, vitesse_ressort, masse_ressort,
                                                 direction_ressort, origine, raideur_ressort, lambda_ressort));
    systeme.dessine();

            systeme.evolue(0.1);
            systeme.dessine();

} catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }/*/

  return 0;
}
