#pragma once
#include <vector> // pour dessine_phase
#include "Vecteur.h"

class Oscillateur;
class Ressort;
class Pendule;
class Systeme;
class RessortPenduleCouplee;
class Pendule_Double;

class SupportADessin
{
     public:
    /*/ méthode(s) de dessin : une pour chaque objet dessinable,
     plus une méthode pour dessiner l'espace de phases/*/
    virtual void dessine(Pendule const& pendule) = 0;
    virtual void dessine(Ressort const& ressort) = 0;
    virtual void dessine(Systeme const& systeme) = 0;
    virtual void dessine(RessortPenduleCouplee const& ressort_pendule) = 0;
    virtual void dessine(Pendule_Double const& pendule_double) = 0;
    virtual void dessine_phase(std::vector<Vecteur> const& espaceDePhase) = 0;

    virtual ~SupportADessin() {} // Destructeur
};
