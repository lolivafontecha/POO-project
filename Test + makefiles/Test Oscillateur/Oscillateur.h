#pragma once
#include "Vecteur.h"
#include <iostream> // pour surcharge de l'operateur <<
#include <string>

class Oscillateur 
{
     protected:
    // attributs conforme au descriptif du projet
    Vecteur Parametres;
    Vecteur Vitesse; // (derivee temporelle de Parametres)
    double masse;
    Vecteur Direction;
    Vecteur Origine;

     public:
    // Constructeurs
    Oscillateur(size_t n): Parametres(n), Vitesse(n), masse(0.0), Direction({1,0,0}), Origine({0,0,0}) {}
    /*/ 1. initialise les vecteurs de taille n a 0, la direction à (1, 0, 0) (c'est 
    nous qui nous avons choisit cette convention), la masse a 0 et l'origine a (0,0,0) /*/
    Oscillateur (Vecteur const& Parametres, Vecteur const& Vitesse, double masse,
        Vecteur const& direction, Vecteur const& Origine)
        : Parametres(Parametres), Vitesse(Vitesse), masse(masse),
            Direction(direction), Origine(Origine) { 
			if(masse < 0)
             throw std::string("La masse de l'oscillateur doit être positive!");
				Direction.FaireUnitaire();}
    /*/ 2. On passe un parametre pour chaque attribut puis on fait unitaire le vecteur
    Direction au cas où l'utilisateur ai passé un vecteur non unitaire /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Oscillateur(Oscillateur const&) = default;
    Oscillateur& operator=(Oscillateur const&) = default;

    // Getters
    Vecteur getParametres() const;
    Vecteur getVitesse() const;
    Vecteur getOrigine() const;
    Vecteur getDirection() const;

    // Setters
    void setParametres(Vecteur const& new_parametres);
    void setVitesse(Vecteur const& new_vitesse);

    Vecteur eq_mvt(double temps) const; // equation du mouvement de l'oscillateur

    std::ostream& afficher(std::ostream& sortie) const; // affichage

   ~Oscillateur(){}  // Destructeur
};

    // surcharge externe d'operateurs
    std::ostream& operator<<(std::ostream& sortie, Oscillateur const& v);


