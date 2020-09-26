#pragma once
#include "Oscillateur.h"

class Integrateur {
	 protected: 
    // attribut
	double pas_de_temps;

	 public:
	Integrateur (double pas_de_temps = 0.01)
     : pas_de_temps(pas_de_temps) {} // Constructeur, par défaut le pas de temps est de 0.01

    virtual void integre(Oscillateur& oscillateur, double temps) const = 0;

    virtual ~Integrateur() {}; // Destructeur
};


class IntegrateurEulerCramer : public Integrateur{
	 public:
	using Integrateur::Integrateur; // pas de nouveaux attributs, on utilise le constructeur de Integrateur

    void integre(Oscillateur& oscillateur, double temps) const;

    ~IntegrateurEulerCramer(){}; // Destructeur
};

class IntegrateurNewmark : public Integrateur{
    public:
    using Integrateur::Integrateur; // pas de nouveaux attributs, on utilise le constructeur de Integrateur

    void integre(Oscillateur& oscillateur, double temps) const;

    ~IntegrateurNewmark(){}; // Destructeur
};

