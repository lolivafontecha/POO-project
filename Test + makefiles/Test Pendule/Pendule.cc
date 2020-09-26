#include "Vecteur.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "var.h"
#include <cmath>
#include <iostream>

using namespace std;
using namespace var;

//==========================================================

Pendule* Pendule::clone() const
{
    return new Pendule(*this);
}

//==========================================================

Vecteur Pendule::eq_mvt() const
{
	 return Vecteur ({(-g.norme()/Longueur)*sin(Parametres.getComp(1))-(Lambda*Vitesse.getComp(1))/(masse*Longueur*Longueur)});
}

//==========================================================

Vecteur Pendule::position_masse() const 
{
	Vecteur copie_g(g);
	copie_g.FaireUnitaire();
    return Vecteur(Origine + Longueur*cos(Parametres.getComp(1))*copie_g
                   + Longueur*sin(Parametres.getComp(1))*Direction);
}

//==========================================================

ostream& Pendule::afficher(ostream& sortie) const
{
	sortie << " ## Pendule " << endl;
	Oscillateur::afficher(sortie);
    sortie << Lambda << "# frottements (lamda)" << endl
           << Longueur << "# longueur (L) " << endl;

	 return sortie;
}

//==========================================================
