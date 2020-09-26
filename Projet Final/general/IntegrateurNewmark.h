#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class IntegrateurNewmark : public Integrateur {
    public:
    using Integrateur::Integrateur; // pas de nouveaux attributs, on utilise le constructeur de Integrateur

    void integre(Oscillateur& oscillateur, double temps) const override;

    ~IntegrateurNewmark() {}  // Destructeur
};
