#pragma once
#include "Vecteur.h"
#include "Dessinable.h"
#include <iostream> // pour surcharge de l'operateur <<
#include <vector> // pour espaceDePhase
#include <string> // pour exception du constructeur

class Oscillateur : public Dessinable   // classe abstraite
{
     protected:
    // attributs conforme au descriptif du projet
    Vecteur Parametres;
    Vecteur Vitesse; // (derivee temporelle de Parametres)
    double masse;
    Vecteur Direction;
    Vecteur Origine;

    /*/ attribut nécessaire pour notre conception par rapport à l'affichage
    de l'espace des phases en mode graphique/*/
    std::vector<Vecteur> espaceDePhase;

     public:
    // Constructeur
    Oscillateur (SupportADessin* support, Vecteur const& Parametres, Vecteur const& Vitesse, double masse,
        Vecteur const& direction, Vecteur const& Origine)
        : Dessinable(support), Parametres(Parametres), Vitesse(Vitesse), masse(masse),
            Direction(direction), Origine(Origine) {
        Direction.FaireUnitaire(); // on fait unitaire le vecteur direction, s'il est nul --> erreur
        // si la masse est négative, on lance une exception
         if(masse <= 0)
             throw std::string("La masse de l'oscillateur doit être strictement positive!");
    }
    /*/ On passe un parametre pour chaque attribut sauf
    pour le tableau dynamique "espaceDePhase" qui appelle à son
    constructeur par défaut. Après, on fait unitaire le vecteur
    Direction au cas où l'utilisateur ai passé un vecteur non unitaire /*/

    // on met explicitement le constructeur de copie par défaut et l'opérateur = par défaut
    Oscillateur(Oscillateur const&) = default;
    Oscillateur& operator=(Oscillateur const&) = default;

    virtual Oscillateur* clone() const = 0; // méthode pour copie polymorphique

    // Getters
    Vecteur getParametres() const; // nécessaire pour la fonction integre d'integrateur
    Vecteur getVitesse() const; // nécessaire pour la fonction integre d'integrateur
    Vecteur getOrigine() const; // nécessaire pour les méthodes dessine de vueopengl
    Vecteur getDirection() const; // nécessaire pour les méthodes dessine de vueopengl

    // Setters
    void setParametres(Vecteur const& new_parametres); // nécessaire pour la fonction integre d'integrateur
    void setVitesse(Vecteur const& new_vitesse); // nécessaire pour la fonction integre d'integrateur

    //Méthodes pour EspaceDePhase
    void ajouterAEspacePhase(Vecteur const& point); /*/ ajout d'un point(= Vecteur de dimension 2)
                                                au tableau "espaceDePhase" /*/
    void dessine_phase() const; // méthode pour dessiner l'espace des phases

    // Méthodes virtuelle pure
    virtual Vecteur eq_mvt() const = 0; // equation du mouvement de l'oscillateur
    virtual Vecteur position_masse() const = 0; /*/ retourne la position de la masse,
                                                    nécessaire pour affichage sur qt /*/

    virtual std::ostream& afficher(std::ostream& sortie) const; // affichage

    virtual ~Oscillateur(){}  // Destructeur
};

    // surcharge externe d'operateurs
    std::ostream& operator<<(std::ostream& sortie, Oscillateur const& v);

