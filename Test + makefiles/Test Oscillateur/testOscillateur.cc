#include <iostream> 
#include "Oscillateur.h"
#include "Vecteur.h"

using namespace std;

int main() {

	Oscillateur osc1({1,2},{3,4},5.4,{0,3,4},{0,0,0});
	Oscillateur osc2(3);
 
 // Test sans "exceptions"
/*
try {

    cout << "Test des constructeurs :" << endl << endl
         << "->Constructeur 1. Oscillateur(Parametres,Vitesse, Masse, Direction, Origine" << endl
         << "Oscillateur osc1({1,2},{3,4},5.4,{0,3,4},{0,0,0})" << endl
         << osc1 << endl;

    cout << "->Constructeur 2. Oscillateur(size_t n)" << endl
         << "Oscillateur osc2(3)" << endl
         << osc2 << endl;
*/

/*
    cout << "Test de get(): " << endl << endl
         << osc1 << endl
         << "de son parametre :" << osc1.getParametres() << endl
         << "de sa vitesse :" << osc1.getVitesse() << endl
         << "de l'origine :" << osc1.getOrigine() << endl
         << "de sa direction :" << osc1.getDirection() << endl
         << endl;
/*/
/*/
    cout << "Test de set(): " << endl << endl
         << "osc1: " << endl << osc1 << endl
         << "de son parametre : -2, -1 " << endl << "donne :"
         << endl;
    osc1.setParametres({-2,-1});

    cout << osc1 << endl << endl;
    cout << "de sa vitesse : -6, 12 " << endl << "donne :"
         << endl;
    osc1.setVitesse({-6,12});
	
    cout << osc1 << endl << endl;
/*/

/*/
cout << "Test d'Equation de mouvement: " << endl
     << "sa fonction d'évolution donne pour t=5 : "
     << osc1.eq_mvt(5) << endl;
}
    catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }
/*/


 // Test des "exceptions"
try {

/*
    cout << "Test du constructeur" << endl
         << "Oscillateur osc3({1,2},{3,4},5.4,{0,0,0},{1,2,0})" << endl;
    Oscillateur osc3({1,2},{3,4},5.4,{0,0,0},{1,2,0});
    cout << "Hello" << endl;
*/

/*
 cout << "Test du constructeur" << endl
      << "Oscillateur osc3({1,2},{3,4},-5.4,{0,0,0},{1,2,0})" << endl;
   
  Oscillateur osc3({1,2},{3,4},-5.4,{0,0,0},{1,2,0});
    cout << "Hello" << endl;
 */   
    
}
    catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }

	 return 0;
}
