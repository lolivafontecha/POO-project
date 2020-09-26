#pragma once
#include "Vecteur.h"
#include "SupportADessin.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Systeme.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"
#include <vector> // pour dessine_phase
#include <iostream>

class TextViewer : public SupportADessin {
     public:
    TextViewer(std::ostream& flot) : flot(flot) {} // Constructeur

    // Méthode héritées de SupportADessin
    virtual void dessine(Pendule const& pendule) override;
    virtual void dessine(Ressort const& ressort) override;
    virtual void dessine(Systeme const& systeme) override;
    virtual void dessine(RessortPenduleCouplee const& ressort_pendule) override;
    virtual void dessine(Pendule_Double const& pendule_double) override;
    virtual void dessine_phase(std::vector<Vecteur> const& espaceDePhase) override;

    ~TextViewer() {} // Destructeur

     private:
    std::ostream& flot;
};







