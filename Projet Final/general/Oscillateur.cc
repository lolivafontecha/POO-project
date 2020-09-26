#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h" // pour "support"
#include <iostream>
#include <string> // pour exceptions
#include <vector> // pour méthode push_back

using namespace std;

//==========================================================

// Getters

Vecteur Oscillateur::getParametres() const  /*/ nécessaire pour la définition de la méthode
                                            "integre" dans la classe Integrateur/*/
{
     return Parametres;
}

//--------------------------------------------------------

Vecteur Oscillateur::getVitesse() const /*/ nécessaire pour la définition de la méthode
                                            "integre" dans la classe Integrateur /*/
{
     return Vitesse;
}

//--------------------------------------------------------

Vecteur Oscillateur:: getOrigine() const    /*/ nécessaire pour notre conception de comment
                                            dessiner des oscillateurs sur QT /*/
{
     return Origine;
}

//--------------------------------------------------------

Vecteur Oscillateur:: getDirection() const  /*/ nécessaire pour notre conception de comment
                                            dessiner des oscillateurs sur QT /*/
{
     return Direction;
}

//==========================================================

// Setters

void Oscillateur::setParametres(Vecteur const& new_parametres)  /*/ nécessaire pour la définition de la méthode
                                            "integre" dans la classe Integrateur /*/
{
     Parametres = new_parametres;
}

//--------------------------------------------------------

void Oscillateur::setVitesse(Vecteur const& new_vitesse)  /*/ nécessaire pour la définition de la méthode
                                            "integre" dans la classe Integrateur /*/
{
     Vitesse = new_vitesse;
}

//==========================================================

// Méthodes nécessaires pour dessiner l'espace de phases

void Oscillateur::ajouterAEspacePhase(Vecteur const& point)
{
    /*/ si le vecteur que l'on ajouter au tableau "espaceDePhase" n'est pas de dimension 2 (point)
     on lance une exception et le programme s'arrête /*/
    if(point.size() != 2)
        throw string("Point invalide pour espace de phase");
    espaceDePhase.push_back(point);
}

//---------------------------------------------------------

void Oscillateur::dessine_phase() const
{
    support -> dessine_phase(espaceDePhase);
}

//==========================================================

// Affichage

ostream& Oscillateur::afficher(ostream& sortie) const
{
  sortie << Parametres << " # parametre " << endl
         << Vitesse << " # vitesse " << endl
         << masse << " # masse  " << endl
         << Direction << " # Direction " << endl
         << Origine << " # Origine " << endl;
     return sortie;
}

//==========================================================

// Surcharge externe de l'operateur <<

ostream& operator<<(ostream& sortie, Oscillateur const& o)
{
     return o.afficher(sortie);
}

//==========================================================




