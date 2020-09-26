#pragma once
#include "Oscillateur.h"
#include "SupportADessin.h"
#include "Vecteur.h"
#include "var.h"
#include <string> // pour exception dans constructeur

class Pendule : public Oscillateur
{
     private:
    // attributs supplémentaire d'un pendule par rapport à un oscillateur quelconque
    double Lambda; // frottement
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
    Pendule* clone() const override; // pour copie polymorphique
    Vecteur eq_mvt() const override; // equation du mouvement pour le pendule
    Vecteur position_masse() const override; // position de la masse au bout de pendule
    virtual void dessine() override; // méthode pour dessiner un pendule
    std::ostream& afficher(std::ostream& sortie) const override; // affichage

    ~Pendule(){}; // Destructeur
};


