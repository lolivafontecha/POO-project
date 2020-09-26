#include "Vecteur.h"			
#include "Oscillateur.h"
#include "Integrateur.h"
#include "Pendule.h"
#include <iostream>
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

void faire_integrer(Oscillateur& osc, Integrateur& integrat, double temps)
{
	integrat.integre(osc, temps);
}
/*
int main() {
	Vecteur Parametre({M_PI/2}), Vitesse({0}), Direction({1, 0.0, 0.0}), Origine({0, 0, 0});
	double masse(1), lambda(0), longueur(1.0);
	Pendule pendule(Parametre , Vitesse, masse, Direction, Origine, lambda, longueur);

	IntegrateurEulerCramer I(0.1);
	
	try {
	faire_integrer(pendule, I, 0.2);
	cout << pendule;
} catch(string const& erreur) {
	cerr << "Il y a une erreur : " << erreur << endl;
}
*/
//Test avec exceptions
int main(){
try {
	/*/
	cout << "Test de Constructeur: " << endl
		 << "Pendule({0.18},{0},0.25,{0.8, 0, 0.6},{0,0,0},0.33,0.15)" << endl<< "donne: "<<endl;
	Pendule pendule({0.18},{0},0.25,{0, 0, 0},{1,0,0},0.33,0.15);
	/*/
	
	/*/
	cout << "Test de Constructeur: " << endl;
	cout << "Pendule({0.18},{0},-0.25,{2, 3, 0},{1,0,0},0.33,0.15)" << endl<<"donne: "<<endl;
	Pendule Pendule({0.18},{0},-0.25,{2, 3, 0},{1,0,0},0.33,0.15);
	/*/
} catch(string const& erreur){
	cerr << "Il y a une erreur : " << erreur << endl;
}


	 return 0;
}
