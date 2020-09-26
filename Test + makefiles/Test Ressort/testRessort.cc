#include "Oscillateur.h"	
#include "Integrateur.h"
#include "Vecteur.h"
#include "Ressort.h"
#include "var.h"
#include <iostream>

using namespace std;
using namespace var;

void faire_integrer(Oscillateur& osc, Integrateur& integrat, double temps)
{
	integrat.integre(osc, temps);
}

int main() {
	Vecteur Parametre({0.18}), Vitesse({0}), Direction({0.8, 0, 0.6}), Origine({0, 0, 0});
	double masse(0.25), raideur(0.33), lambda(0.15);

	IntegrateurEulerCramer I;
    

try {

//Test sans exceptions

/*/
	cout << "Test de Constructeur: " << endl
		 << "Ressort({0.18},{0},0.25,{0.8, 0, 0.6},{0,0,0},0.33,0.15)" << endl
		 << " donne: " <<endl;
	Ressort ressort(Parametre,Vitesse, masse,Direction,Origine,raideur,lambda);
	cout<<ressort<<endl;
/*/
		
/*/	
	Ressort ressort(Parametre,Vitesse, masse,Direction,Origine,raideur,lambda);
	 
	cout << "Test methode position_masse()" << endl
		 << "ressort.position_masse() = "
		 << ressort.position_masse() << endl;
		 faire_integrer(ressort, I, 0.05);
	cout << "Après l'évolution pour t = 0.05 :" << endl
		 << "ressort.position_masse() = "
		 << ressort.position_masse() << endl;
/*/	
/*/
	Ressort ressort(Parametre, Vitesse, masse, Direction, Origine, raideur, lambda);
	cout << "Test Eq. de mvt et IntegrateurEulerCramer : " << endl
		 << ressort << endl << endl
		 << "t = 0" << endl
		 << ressort.getParametres() <<" # parametre " << endl
		 << ressort.getVitesse() << " # vitesse" << endl << endl;
		
	faire_integrer(ressort, I, 0.05);
	
	cout << "t = 0.05" << endl
		 << ressort.getParametres() << " # parametre " << endl
		 << ressort.getVitesse() << " # vitesse" << endl;
/*/

} catch(string const& erreur) {
	cerr << "Il y a une erreur : " << erreur << endl;
}

//Test avec exceptions
try {
	/*/
	cout << "Test de Constructeur: " << endl
		 << "Ressort({0.18},{0},0.25,{0, 0, 0},{1,0,0},0.33,0.15)" << endl;
		 
	Ressort ressort1(Parametre,Vitesse, masse,{0.0,0.0,0.0},{1,0,0},raideur,lambda);
	
	/*/
	
	/*/
	cout << "Test de Constructeur: " << endl;
	cout << "Ressort({0.18},{0},-0.25,{2, 3, 0}, {1,0,0}, 0.33, 0.15)" << endl;
	Ressort ressort2({0.18},{0},-0.25,{2, 3, 0},{1,0,0},0.33,0.15);
	/*/

} catch(string const& erreur){
	cerr << "Il y a une erreur : " << erreur << endl;
}



	 return 0;
}
