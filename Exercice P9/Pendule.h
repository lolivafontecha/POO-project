#pragma once
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Vecteur.h"
#include "var.h"
#include <string>

class Pendule : public Oscillateur
{
	 private:
    // attributs
	double Lambda;
	double Longueur;
	
	 public:
    Pendule(SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse,
    double masse, Vecteur const& Direction, Vecteur const& Origine, double Lambda, double Longueur)
        : Oscillateur(support, Parametres, Vitesse, masse, Direction, Origine),
          Lambda(Lambda) , Longueur(Longueur) {
      // si la longueur ou le frottement sont négatifs, on lance une exception et le programme s'arrête
      if((Longueur <= 0))
        throw std::string("La longueur du pendule doit être strictement positive!");
      if(Lambda < 0)
        throw std::string("Le frottement du pendule doit être positif!");
      if(Direction*var::g != 0)
        throw std::string("Le vecteur direction doit être perpendiculaire à g pour un pendule!");
    }
    /*/ Constructeur: fait appel au constructeur d'Oscillateur
    et initialise les valeurs de lambda et de la longueur/*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Pendule& operator=(Pendule const&) = default;
    Pendule(Pendule const&) = default;

    // Méthodes héritées d'Oscillateur
    Pendule* clone() const; // pour copie polymorphique
    Vecteur eq_mvt() const; // equation du mouvement pour le pendule
    Vecteur position_masse() const; // position de la masse au bout de pendule
    virtual void dessine() override; // ...
    std::ostream& afficher(std::ostream& sortie) const; // affichage

	~Pendule(){}; // Destructeur
};
