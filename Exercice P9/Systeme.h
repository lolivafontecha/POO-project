#pragma once
#include <vector> // pour collection d'oscillateurs
#include <iostream> // pour surcharge operateur <<
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Oscillateur.h"
#include "Integrateur.h"
 
class Systeme : public Dessinable {
	 private:
    // attributs
    std::vector<Oscillateur*> collection_osc; // collection d'oscillateurs
    Integrateur* _integrateur;

	 public:
    Systeme(SupportADessin* support)
        : Dessinable(support), _integrateur(nullptr) {}
    /*/ Constructeur qui appelle au constructeur de la super classe Dessinable,
    initialise le pointeur sur l'integrateur a nullptr et fait appel au constructeur par
    défaut du tableau dynamique pour l'attribut "collection_osc"/*/

    /*/On efface le constructeur de copie et l'operateur =
     On considère que l'on ne peut pas copier des systemes/*/
    Systeme(Systeme const&) = delete;
	Systeme& operator=(Systeme const&) = delete;

    void evolue(double temps); // méthode qui fait evoluer les oscillateurs 

    virtual void dessine() override;

    // Méthodes pour ajouter des integrateurs et des oscillateurs au systeme
    void ajouterIntegrateur(Integrateur* integrateur);
	void ajouterOscillateur(Oscillateur* oscillateur);

    std::ostream& affiche(std::ostream& sortie) const; // affichage

	~Systeme() {
		for(auto& oscillateur : collection_osc) {
			delete oscillateur;
			oscillateur = nullptr;
		}
		collection_osc.clear();
        }
    // Destructeur: on détruit les objets pointées, ainsi que l'on affecte ceux-là à nullptr
};

    // surcharge externe de l'operateur <<
    std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);
