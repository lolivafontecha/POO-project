#include "Vecteur.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//==========================================================

// Méthodes privées

bool Vecteur::essayer_dim(Vecteur const& vect) const {
    return (size() == vect.size());
}

//--------------------------------------------------------

bool Vecteur::compare(Vecteur const& vect) const
{
 if(!essayer_dim(vect)){
     throw string ("Opération \"Compare\" non valide, la taille des vecteurs est incompatible!");
}
    for(size_t i(0); i < size(); ++i)
    {
        if(coord[i] != vect.coord[i]) return false;
    }
 return true;
}

//--------------------------------------------------------

void Vecteur::augmente(double new_val)
{
	coord.push_back(new_val);
}

size_t Vecteur::size() const {
    return coord.size();
}

//==========================================================

// opérations "privées"

Vecteur Vecteur::addition(Vecteur const& vect) const
{
    Vecteur resultat;

    if(!essayer_dim(vect)){
        throw string ("Opération \"Addition/Soustraction\" non valide, la taille des vecteurs est incompatible!");
   }

    for (size_t i(0); i < size(); ++i)
    {
    resultat.augmente(coord[i]+vect.coord[i]);
    }

 return resultat;
}

//--------------------------------------------------------

Vecteur Vecteur::soustraction(Vecteur const& vect) const
{
    return addition(vect.oppose());
}

Vecteur Vecteur::oppose() const
{
    Vecteur op(size());

    for(size_t i(0); i<size(); ++i)
    {
    op.coord[i]=-coord[i];
    }

 return op;
}

//--------------------------------------------------------

double Vecteur::prod_scal(Vecteur const& vect) const
{
   if(!essayer_dim(vect)){
        throw string ("Opération \"Produit Scalaire\" non valide, la taille des vecteurs est incompatible!");
   }
    double resultat(0.0);
    for (size_t i(0); i < size(); ++i)
    {
        resultat += (coord[i]*vect.coord[i]);
    }

    return resultat;
}

//--------------------------------------------------------

Vecteur Vecteur::prod_vect(Vecteur const& vect) const
{
    if ((size() != 3) or (vect.size() != 3))
    {
    throw string("Dimension non valide, impossible effectuer le produit vectoriel");
    }
    Vecteur resultat(size());
    resultat.coord[0] = coord[1]*vect.coord[2]-coord[2]*vect.coord[1];
    resultat.coord[1] = coord[2]*vect.coord[0]-coord[0]*vect.coord[2];
    resultat.coord[2] = coord[0]*vect.coord[1]-coord[1]*vect.coord[0];

    return resultat;
}

//--------------------------------------------------------

double Vecteur::norme2() const
 // ATTENTION: si la dim de vecteur est 0, la norme par convention est 0
{
    double resultat(0.0);

    for(auto comp: coord)
    {
        resultat+=comp*comp;
    }

    return resultat;
}

//==========================================================

// Méthodes publiques

double Vecteur::getComp(size_t i) const
{
        if(i > size()) throw string ("Composante inexistente! Impossible \"getComp\"!" );
    return coord[i-1];
}

//--------------------------------------------------------

void Vecteur::set_coord(size_t place, double valeur)
{
    if (place-1 >= coord.size())
    {				/*/ Si la "place" passé en paramètre
                    est plus grande que la dim du vecteur --> erreur/*/
        throw string ("Composante inexistente! Impossible \"set_coord\"!");
    }

    coord[place-1]=valeur; /*/ on écrit moins 1 puisque pour nous c'esp plus facile
                            parler de composantes 1,2 et 3 que 0,1 et 2/*/
}

//--------------------------------------------------------

ostream& Vecteur::affiche(ostream& sortie) const
{
	if(size() == 0) throw string("Vecteur non affichable! (Dim = 0)");

		for (auto const& nombre : coord)
		{
         sortie << nombre << " " ;
		}
	 
	 return sortie;
}

//==========================================================

// Opérations publiques

Vecteur Vecteur::mult(double scal) const
{
    Vecteur resultat(*this);

    for (auto& comp : resultat.coord)
    {
        comp *= scal;
    }
     return resultat;
}

//--------------------------------------------------------

double Vecteur::norme() const
{
 return sqrt((norme2()));
}

//--------------------------------------------------------

void Vecteur::FaireUnitaire() 
{

  if(norme()== 0.0)  {
	throw string ("Impossible de rendre unitaire le vecteur nul!");
	}

	if(norme()!= 1.0) *this =(1.0/norme())*(*this);
}

//==========================================================

// Definition surcharge d'operateurs

bool Vecteur::operator==(Vecteur const& vect) const 
{
	return compare(vect);
}

//--------------------------------------------------------

bool Vecteur::operator!=(Vecteur const& vect) const
{
    return !(compare(vect));
}

//--------------------------------------------------------

Vecteur& Vecteur::operator+=(Vecteur const& vect) {
	coord = addition(vect).coord;
	return *this;
}

//--------------------------------------------------------

const Vecteur Vecteur::operator+(Vecteur const& vect) const 
{	
	return addition(vect);
}

//--------------------------------------------------------

Vecteur& Vecteur::operator-=(Vecteur const& vect) {
	coord = soustraction(vect).coord;
	return *this;
}

//--------------------------------------------------------

const Vecteur Vecteur::operator-(Vecteur const& vect) const 
{
	return soustraction(vect);	
}

//--------------------------------------------------------

const Vecteur Vecteur::operator^(Vecteur const& vect) const 
{
	return prod_vect(vect);
}

//--------------------------------------------------------

const Vecteur Vecteur::operator*(double a) const
{
	return mult(a);	
}

//--------------------------------------------------------

const Vecteur operator*(double a, Vecteur const& vect)
{
	return vect.mult(a);	
}

//--------------------------------------------------------

double Vecteur::operator*(Vecteur const& vect) const
{
	return prod_scal(vect);
}

//--------------------------------------------------------

ostream& operator<<(ostream& sortie, Vecteur const& v) 
{
	return v.affiche(sortie);
}

//==========================================================
