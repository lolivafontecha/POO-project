#include "Vecteur.h"
#include "Pendule_Double.h"
#include "Oscillateur.h"
#include "var.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace var;

//==========================================================

// Copie Polymorphique

Pendule_Double*  Pendule_Double::clone() const
{
    return new Pendule_Double(*this);
}

//==========================================================

Vecteur Pendule_Double:: eq_mvt() const 
{
    double delta_theta(Parametres.getComp(1) - Parametres.getComp(2));
    // Description de l'équation du mouvement daccord avec le descriptif:
    return Vecteur({(masse_2*g.norme()*cos(delta_theta)*sin(Parametres.getComp(2)) -
		masse*g.norme()*sin(Parametres.getComp(1)) - 
		masse_2*Longueur_1*Vitesse.getComp(1)*Vitesse.getComp(1)*cos(delta_theta)*sin(delta_theta) - 
        masse_2*Longueur_2*Vitesse.getComp(2)*Vitesse.getComp(2)*sin(delta_theta)) /
        ((masse_1 + masse_2*sin(delta_theta)*sin(delta_theta))*Longueur_1) ,
		(masse*g.norme()*cos(delta_theta)*sin(Parametres.getComp(1)) - masse*g.norme()*sin(Parametres.getComp(2)) +
		masse_2*Longueur_2*Vitesse.getComp(2)*Vitesse.getComp(2)*cos(delta_theta)*sin(delta_theta) + 
        masse*Longueur_1*Vitesse.getComp(1)*Vitesse.getComp(1)*sin(delta_theta)) /
        ((masse_1 + masse_2*sin(delta_theta)*sin(delta_theta))*Longueur_2)});
}

//==========================================================

Vecteur Pendule_Double::position_masse() const
{
/*/ Pour utiliser le vecteur unitaire associé à la variable g(i.e. constante gravitationelle) sans
   la modifier, on effectue une copie de celle-ci puis on retourne le vecteur associé à la position
   de la masse à chaque instant daccord avec le descriptif du projet /*/
    Vecteur copie_g(g);
    copie_g.FaireUnitaire();
    return Vecteur(position_masse_milieu() + Longueur_2*cos(Parametres.getComp(2))*copie_g
                   + Longueur_2*sin(Parametres.getComp(2))*Direction);
}

//----------------------------------------------------------

Vecteur Pendule_Double::position_masse_milieu() const 
{
/*/ Pour utiliser le vecteur unitaire associé à la variable g(i.e. constante gravitationelle) sans
   la modifier, on effectue une copie de celle-ci puis on retourne le vecteur associé à la position
   de la masse à chaque instant daccord avec le descriptif du projet /*/
	Vecteur copie_g(g);
    copie_g.FaireUnitaire();
    return Vecteur(Origine + Longueur_1*cos(Parametres.getComp(1))*copie_g
                   + Longueur_1*sin(Parametres.getComp(1))*Direction);	
}
//==========================================================

void Pendule_Double::dessine()
{
	support -> dessine(*this);
}

//==========================================================

ostream& Pendule_Double::afficher(ostream& sortie) const
{
	sortie << " # Oscillateur Couplee: Pendule-Double" << endl;
	Oscillateur::afficher(sortie);
    sortie << masse_1 << " # masse 1" << endl
           << masse_2 << " # masse 2" << endl
           << Longueur_1 << " # Longueur 1" << endl
           << Longueur_2 << " # Longueur 2" <<endl;
	return sortie;
}

//==========================================================

