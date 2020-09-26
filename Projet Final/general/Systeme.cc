#include "Integrateur.h"
#include "Systeme.h"
#include "Oscillateur.h"
#include <iostream>
#include <vector> // pour push_back

using namespace std;

//==========================================================

void Systeme::dessine()
{ 
	support -> dessine(*this); 
	for(auto const& oscillateur: collection_osc) {
        oscillateur -> dessine();
        oscillateur -> dessine_phase();
	}
}

//==========================================================

void Systeme::evolue(double temps)
{
    /*/ on fait évoluer un par un tous les oscillateur du systeme avec l'integrateur
      du systeme et le temps précisé par l'utilisateur /*/
	for(auto& oscillateur : collection_osc) {
        _integrateur->integre(*oscillateur, temps);
	}
}

//==========================================================

// Méthodes pour ajouter des integrateurs et des oscillateurs au systeme

void Systeme::ajouterOscillateur(Oscillateur* oscillateur)
{
    if(oscillateur != nullptr) collection_osc.push_back(oscillateur);
}

//---------------------------------------------------------

void Systeme::ajouterIntegrateur(Integrateur* integrateur)
{
    if(integrateur != nullptr) _integrateur = integrateur;
}

//==========================================================

ostream& Systeme::affiche(ostream& sortie) const
{
    sortie << "Le système est constitué des oscillateurs suivants: " << endl;
	 return sortie;
}

//==========================================================

ostream& operator<<(ostream& sortie, Systeme const& systeme)
{
	 return systeme.affiche(sortie);
}

//==========================================================
