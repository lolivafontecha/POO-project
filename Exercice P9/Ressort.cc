#include "Vecteur.h"
#include "Oscillateur.h"
#include "Ressort.h"
#include "var.h"
#include <cmath>
#include <iostream>

using namespace std;
using namespace var;

//==========================================================

Ressort* Ressort::clone() const
{
    return new Ressort(*this);
}

//==========================================================

Vecteur Ressort::eq_mvt() const
{
	 return Vecteur ({(-Raideur/masse)*Parametres.getComp(1) - (Lambda/masse)*Vitesse.getComp(1) + g*Direction});
}

//==========================================================

Vecteur Ressort::position_masse() const 
{
	return Vecteur(Origine + Parametres.getComp(1)*Direction);
}

//==========================================================

void Ressort::dessine()
{
	support->dessine(*this);
}

//==========================================================

ostream& Ressort::afficher(ostream& sortie) const
{
    sortie << " ## Ressort " << endl;
    Oscillateur::afficher(sortie);
    sortie << Raideur << "# raideur (k)" << endl
           << masse << "# masse (m)" << endl
           << Lambda << "# frottements (lamda)" <<  endl;

     return sortie;
}

//==========================================================

