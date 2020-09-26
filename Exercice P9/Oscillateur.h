#pragma once
#include "Vecteur.h"
#include "Dessinable.h"
#include <iostream> // pour surcharge de l'operateur <<
#include <string>

class Oscillateur : public Dessinable
{
     protected:
    // attributs conforme au descriptif du projet
    Vecteur Parametres;
    Vecteur Vitesse; // (derivee temporelle de Parametres)
    double masse;
    Vecteur Direction;
    Vecteur Origine;

     public:
    // Constructeur
    Oscillateur (SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse, double masse,
        Vecteur const& direction, Vecteur const& Origine)
        : Dessinable(support), Parametres(Parametres), Vitesse(Vitesse), masse(masse),
            Direction(direction), Origine(Origine) { 
			if(masse <= 0)
             throw std::string("La masse de l'oscillateur doit être strictement positive!");
				Direction.FaireUnitaire();
			}
    /*/ On passe un parametre pour chaque attribut. Après, on fait unitaire le vecteur
    Direction au cas où l'utilisateur ai passé un vecteur non unitaire et on regarde si la 
    masse est positive /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Oscillateur(Oscillateur const&) = default;
    Oscillateur& operator=(Oscillateur const&) = default;

    virtual Oscillateur* clone() const = 0; // méthode pour copie polymorphique

    // Getters
    Vecteur getParametres() const;
    Vecteur getVitesse() const;
    Vecteur getOrigine() const;
    Vecteur getDirection() const;

    // Setters
    void setParametres(Vecteur const& new_parametres);
    void setVitesse(Vecteur const& new_vitesse);

    virtual Vecteur eq_mvt() const = 0; // equation du mouvement de l'oscillateur
    virtual Vecteur position_masse() const = 0; // retourne la position de la masse

    virtual std::ostream& afficher(std::ostream& sortie) const; // affichage

    virtual ~Oscillateur(){}  // Destructeur
};

    // surcharge externe d'operateurs
    std::ostream& operator<<(std::ostream& sortie, Oscillateur const& v);


