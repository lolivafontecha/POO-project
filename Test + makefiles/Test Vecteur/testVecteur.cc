#include <iostream> 			
#include "Vecteur.h"

using namespace std;

int main() 
{
	Vecteur v0;
	Vecteur v1(4);
	Vecteur v2(2.3,0.4,-4.5);
	Vecteur v3({2.4,0.3,-3.5,-1.7});
	Vecteur v4(v2);
	Vecteur v5(3,4,0);
	
 // Test sans "exceptions"

try {


	cout << "Test de Constructeurs:" << endl
		 << "v1: " << v1 << endl
		 << "v2: " << v2 << endl
		 << "v3: " << v3 << endl
		 << "v4: " << v4 << endl
		 << "v5: " << v5 << endl << endl;



	cout << "Test du getComp: " << endl
		 << "v2.getComp(2):"
		 << v2.getComp(2) << endl
		 << "v3.getComp(1):"
		 << v3.getComp(1) << endl << endl;
/*/
	
/*/
	cout << "Test setCoord(place, valeur): " << endl
		 << "v1.set_coord(3,5.4)" << endl;
		v1.set_coord(3,5.4);
		v1.set_coord(2,-4.5);
	cout << "v1.set_coord(2,-4.5)"
		 << endl << "v1 : " << v1 << endl << endl;
/*/

/*/
	cout << "Test d'opérateurs: " << endl
		 << "->operateur * :" << endl
		 << "-5.3*("<<v2<<")= " << -5.3*v2 << endl
		 << "(" << v2 << ")*-5.3 = " << v2*-5.3 << endl
		 << "0.0*(" << v2 << ") = " << 0.0*v2 << endl << endl;
			
	cout << "->operateur + :" << endl
		 << "("<<v2<<") + ("<<v5<<") = " << v2 + v5 << endl << endl;
		

	cout << "->operateur - :" << endl
		 << "(" << v2 << ") - ("<<v5<<") = " << v2 - v5 << endl << endl;
			
	cout << "->operateur == :" << endl;
		if(v2 == v4)
	cout << "v2 = v4" << endl << endl;
		
	cout << "->operateur != :" << endl;
		if(v2 != v5)
	cout << " v2 != v5 " << endl << endl;

	cout << "->operateur ^ :" << endl
		 << "(" << v2 << ") ^ (" << v5 << ") = " << (v2^v5) << endl << endl;
		
	cout << "->operateur -= :" << endl
		 << "v2 -= v5 = " << (v2-=v5) << endl << endl;

	cout << "->operateur += :" << endl
		 << "v2 += v5 = " << (v2+=v5) << endl << endl;

/*/

/*/
	cout << "Test methode norme() : " << endl
		 << v5.norme() << endl << endl;

/*/

/*/
	cout << "Test methode faire unitaire: " << endl
		 << v2 << endl
		 << "v2.FaireUnitaire()" << endl;
	v2.FaireUnitaire();

	cout << "v2 = " << v2 << endl << endl;

}

catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }




// Test des "exceptions"
try {
/*/
	cout << "Test de Constructeur par default:" << endl
		 << "v0: " << v0 << endl;

/*/

/*/
	cout << "Test du getComp: " << endl
		 << "v2.getComp(5):"
		 << v2.getComp(5) << endl;
/*/
	
/*/	
	cout << "Test setCoord(place, valeur): " << endl
		 << "v1.set_coord(3,5.4)" << endl
		 << "v1.set_coord(6,-4.5)" << endl;
	
	v1.set_coord(3,5.4);
	v1.set_coord(6,-4.5);
	
	cout << endl << "v1 : " << v1 << endl << endl;
/*/

/*/
cout << "Test d'opérateurs: " << endl
	 << "->operateur * :" << endl
	 //<< "-5.3 * v0 = " << -5.3 * v0 << endl;
	 << "0.0 * v0 = " << 0.0 * v0 << endl;
/*/

/*/
	cout << "->operateur + :" << endl;
	cout << "v2+v3 = " << v2 + v3 << endl << endl;
/*/

/*/
	cout << "->operateur - :" << endl	
		 << "v2-v3 = " << v2-v3 << endl;	
/*/	

/*/
	cout << "->operateur ^ :" << endl
		 << "v3^v5 = " << (v3^v5) << endl;
/*/

/*/
	cout << "->operateur -= :" << endl
		 << "v3-=v5 =" << (v3-=v5) << endl;
/*/

/*/
	cout << "->operateur += :" << endl
		 << "v3+=v5 =" << (v3+=v5) << endl;
/*/

/*/
	cout << "Test methode faire unitaire : " << endl
		 << "v0.FaireUnitaire() :";
	v0.FaireUnitaire();
	cout << v0 << endl;
/*/

}

catch(string const& erreur) {
        cerr << "Il y a une erreur : " << erreur << endl;
    }
	 return 0;
}
