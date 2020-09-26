#pragma once
#include "Oscillateur.h"
#include "Vecteur.h"
#include "SupportADessin.h"
#include "var.h"
#include <iostream>
#include <string> // pour exception dans le constructeur

class RessortPenduleCouplee : public Oscillateur
{
    private:
    // attributs supplémentaire d'un pendule par rapport à un oscillateur quelconque
    double Longueur_repos;
    double Raideur;

    public:
    RessortPenduleCouplee(SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse, double masse,
            Vecteur const& Direction, Vecteur const& Origine, double Longueur_repos, double Raideur)
        : Oscillateur(support, Parametres, Vitesse, masse, Direction, Origine),
            Longueur_repos(Longueur_repos), Raideur(Raideur) {
      // si le raideur ou la longueur au repos sont négatifs, on lance une exception
      if((Raideur < 0) or (Longueur_repos < 0))
          throw std::string("Le raideur et la longueur au repos du pendule-ressort doivent être positifs!");
      if(var::g*Direction != 0)
          throw std::string("Le vecteur direction doit être perpendiculaire à g pour un ressort-pendule!");
    }
    /*/ Constructeur: fait appel au constructeur d'Oscillateur
    et initialise les valeurs du raideur et de la longueur au repos /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    RessortPenduleCouplee& operator=(RessortPenduleCouplee const&) = default;
    RessortPenduleCouplee(RessortPenduleCouplee const&) = default;

    // Méthodes hértitées de la classe Oscillateur
    RessortPenduleCouplee* clone() const override; // copie polymorphique
    Vecteur eq_mvt() const override; // equation du mouvement du ressort pendule/pendule ressort
    Vecteur position_masse() const override; // retourne la position de la masse
    virtual void dessine() override; // méthode pour dessiner un ressort pendule/ pendule ressort
    std::ostream& afficher(std::ostream& sortie) const override;// affichage

    ~RessortPenduleCouplee(){} // Destructeur
};
