#pragma once
#include "Vecteur.h"
#include "Oscillateur.h"
#include "SupportADessin.h"
#include <string> // pour exception dans le constructeur
#include <iostream>

class Ressort : public Oscillateur {
     private:
    // attributs supplémentaire d'un pendule par rapport à un oscillateur quelconque
    double Raideur;
    double Lambda; // frottement

     public:
    Ressort(SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse, double masse,
            Vecteur const& Direction, Vecteur const& Origine, double Raideur, double Lambda)
        : Oscillateur(support, Parametres, Vitesse, masse, Direction, Origine),
            Raideur(Raideur), Lambda(Lambda) {
      // si le raideur ou le frottement sont négatifs, on lance une exception
      if((Raideur < 0) or (Lambda < 0))
          throw std::string("Le raideur du ressort et le frottement doivent être positifs!");
    }
    /*/ Constructeur: fait appel au constructeur d'Oscillateur
    et initialise les valeurs de lambda et du raideur /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Ressort& operator=(Ressort const&) = default;
    Ressort(Ressort const&) = default;

    // Méthode hértitées d'oscillateurs
    Ressort* clone() const override; // pour copie polymorphique
    Vecteur eq_mvt() const override; // equation du mouvement du ressort
    Vecteur position_masse() const override; // retourne la position de la masse au bout du ressort
    virtual void dessine() override; // méthode pour dessiner un ressort
    std::ostream& afficher(std::ostream& sortie) const override; // affichage

     ~Ressort(){}; // Destructeur
};


