#pragma once
#include "Oscillateur.h"
#include "Vecteur.h"
#include "SupportADessin.h"
#include "var.h"
#include <iostream>
#include <string> // pour exception dans le constructeur

class Pendule_Double : public Oscillateur
{
    private:
    // attributs supplémentaire d'un pendule double par rapport à un oscillateur quelconque
    double Longueur_1;
    double Longueur_2;
    double masse_1;
    double masse_2;

    public:
    Pendule_Double(SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse,			
            Vecteur const& Direction, Vecteur const& Origine, double Longueur_1, double Longueur_2,
            double masse_1, double masse_2)
        : Oscillateur(support, Parametres, Vitesse, masse_1 + masse_2, Direction, Origine),
            Longueur_1(Longueur_1), Longueur_2(Longueur_2), masse_1(masse_1), masse_2(masse_2) {
      // si le raideur ou la longueur au repos sont négatifs, on lance une exception
      if((masse_1 <= 0) or (masse_2 <= 0))
        throw std::string("Les masses du pendule-double doivent être strictement positives!");
      if((Longueur_1 <= 0) or (Longueur_2 <= 0))
        throw std::string("Les longueurs du pendule-double doivent être strictement positives!");
      if(var::g*Direction != 0)
        throw std::string("Le vecteur direction doit être perpendiculaire à g pour un pendule-double!");
 }
    /*/ Constructeur: fait appel au constructeur d'Oscillateur
    et initialise les valeurs du raideur et de la longueur au repos /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
	Pendule_Double& operator=(Pendule_Double const&) = default;
    Pendule_Double(Pendule_Double const&) = default;

    // Méthodes hértitées de la classe Oscillateur
    Pendule_Double* clone() const override; // copie polymorphique
    Vecteur eq_mvt() const override; // equation du mouvement du ressort pendule/pendule ressort
    Vecteur position_masse_milieu() const; // méthode pour repérer la masse qui est au milieu
    Vecteur position_masse() const override; // retourne la position de la masse
    virtual void dessine() override; // méthode pour dessiner un ressort pendule/ pendule ressort
    std::ostream& afficher(std::ostream& sortie) const override;// affichage

    ~Pendule_Double(){} // Destructeur
};

