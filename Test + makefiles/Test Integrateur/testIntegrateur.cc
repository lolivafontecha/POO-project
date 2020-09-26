#include <iostream>			
#include "Integrateur.h"
#include "Oscillateur.h"

using namespace std;

int main() {
/*
	//Test Integrateur EulerCramer
	
	Oscillateur osc({0,1}, {1, 2}, 0.127, {1, 0, 0}, {0, 0, 0});
	
	IntegrateurEulerCramer I;
		
	try {
	for (int i(0); i < 68; ++i) {
		I.integre(osc, 0.01);
		cout << osc.getParametres()<<"# parametre"<<endl;
	}

} catch(string const& erreur) {
	cerr << "Il y a une erreur : " << erreur << endl;
}*/

/*
	//Test IntegrateurNewmark

	Oscillateur osc({0,1}, {1, 2}, 0.127, {1, 0, 0}, {0, 0, 0});
	
	IntegrateurNewmark I;
	
	try {
		for (int i(0); i < 65; ++i) {
	I.integre(osc, 0.01);
	cout << osc.getParametres()<<"# parametre"<<endl;
   }
} catch(string const& erreur) {
	cerr << "Il y a une erreur : " << erreur << endl;
}

*/
	 return 0;
}

