#include "Vecteur.h"
#include "RessortPenduleCouplee.h"
#include "Oscillateur.h"
#include "var.h"
#include <iostream>

using namespace std;
using namespace var;

//==========================================================

// Copie Polymorphique

RessortPenduleCouplee*  RessortPenduleCouplee::clone() const
{
    return new RessortPenduleCouplee(*this);
}

//==========================================================

Vecteur RessortPenduleCouplee:: eq_mvt() const 
{
    return Vecteur(g-(Raideur/masse)*(1-(Longueur_repos/Parametres.norme()))*Parametres);
}

//==========================================================

Vecteur RessortPenduleCouplee::position_masse() const
{
    return Parametres;
}

//==========================================================

void RessortPenduleCouplee::dessine()
{
	support->dessine(*this);
}

//==========================================================

ostream& RessortPenduleCouplee::afficher(ostream& sortie) const
{
	sortie << " # Oscillateur Couplee: Pendule-Ressort" << endl;
	Oscillateur::afficher(sortie);
    sortie << Raideur << " # Raideur" << endl
           << Longueur_repos << " # Longueur repos" << endl;
	return sortie;
}

//==========================================================
