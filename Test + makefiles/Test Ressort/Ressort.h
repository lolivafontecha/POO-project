#pragma once
#include "Vecteur.h"
#include "Oscillateur.h"
#include <cmath> // pour abs
#include <string>

class Ressort : public Oscillateur {
	 private:
    // attributs
	double Raideur;
	double Lambda;

	 public:
	Ressort(Vecteur const& Parametres, Vecteur const& Vitesse, double masse,			
			Vecteur const& Direction, Vecteur const& Origine, double Raideur, double Lambda) 
        : Oscillateur(Parametres, Vitesse, masse, Direction, Origine),
            Raideur(Raideur), Lambda(Lambda) {
				if((Raideur < 0) or (Lambda < 0)) throw std::string("Le raideur du ressort et le frottement doivent être positifs!");
				}
    /*/ Constructeur: fait appel au constructeur d'Oscillateur
    et initialise les valeurs de lambda et du raideur/*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Ressort& operator=(Ressort const&) = default;
	Ressort(Ressort const&) = default; 

    // Méthode hértitées d'oscillateurs
    Ressort* clone() const; // pour copie polymorphique
    Vecteur eq_mvt() const; // equation du mouvement du ressort
    Vecteur position_masse() const; // retourne la position de la masse au bout du ressort
    std::ostream& afficher(std::ostream& sortie) const; // affichage

	 ~Ressort(){}; // Destructeur
};


