#include "Vecteur.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "var.h" // pour g
#include <cmath> // pour cos, sin
#include <iostream>

using namespace std;
using namespace var;

//==========================================================

// Copie Polymorphique

Pendule* Pendule::clone() const
{
    return new Pendule(*this);
}

//==========================================================

Vecteur Pendule::eq_mvt() const
{
     return Vecteur ({(-g.norme()/Longueur)*sin(Parametres.getComp(1)) -
                      (Lambda*Vitesse.getComp(1))/(masse*Longueur*Longueur)});
}

//==========================================================

Vecteur Pendule::position_masse() const
{
    /*/Pour utiliser le vecteur unitaire associé à la variable g(i.e. constante gravitationelle) sans
       la modifier, on effectue une copie de celle-ci puis on retourne le vecteur associé à la position
       de la masse à chaque instant daccord avec le descriptif du projet /*/
    Vecteur copie_g(g);
    copie_g.FaireUnitaire();
    return Vecteur(Origine + Longueur*cos(Parametres.getComp(1))*copie_g
                   + Longueur*sin(Parametres.getComp(1))*Direction);
}

//==========================================================

void Pendule::dessine()
{
     support -> dessine(*this);
}

//==========================================================

ostream& Pendule::afficher(ostream& sortie) const
{
    sortie << " ## Pendule " << endl;
    Oscillateur::afficher(sortie);
    sortie << Lambda << " # frottements (lamda)" << endl
           << Longueur << " # longueur (L) " << endl;

     return sortie;
}

//==========================================================
