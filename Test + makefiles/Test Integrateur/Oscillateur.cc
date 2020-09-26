#include "Vecteur.h"
#include "Oscillateur.h"
#include <iostream>
#include <string>
#include <vector>
#include "var.h"

using namespace std;
using namespace var;

//==========================================================

// Getters

Vecteur Oscillateur::getParametres() const
{
     return Parametres;
}

//--------------------------------------------------------

Vecteur Oscillateur::getVitesse() const
{
     return Vitesse;
}

//--------------------------------------------------------

Vecteur Oscillateur:: getOrigine() const
{
     return Origine;
}

//--------------------------------------------------------

Vecteur Oscillateur:: getDirection() const
{
     return Direction;
}

//==========================================================

// Setters

void Oscillateur::setParametres(Vecteur const& new_parametres)
{
     Parametres = new_parametres;
}

//--------------------------------------------------------

void Oscillateur::setVitesse(Vecteur const& new_vitesse)
{
     Vitesse = new_vitesse;
}

//==========================================================

Vecteur Oscillateur::eq_mvt() const
{
     return {0, -9.81};
}

//==========================================================

// Affichage

std::ostream& Oscillateur::afficher(std::ostream& sortie) const
{
    sortie << Parametres << "# parametre " << endl
         << Vitesse << "# vitesse " << endl
         << masse << "# masse  " << endl
         << Direction << "# Direction " << endl
         << Origine << "# Origine " << endl;
     return sortie;
}

//==========================================================

// Surcharge externe d'operateurs

std::ostream& operator<<(std::ostream& sortie, Oscillateur const& o)
{
     return o.afficher(sortie);
}

//==========================================================

