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
    /*/ si la dimension des deux vecteurs que l'on veut comparer n'est pas la même,
     on lance une exception et le programme s'arrête /*/
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

//==========================================================

// opérations "privées"

Vecteur Vecteur::addition(Vecteur const& vect) const
{
    Vecteur resultat;
    /*/ si la dimension des deux vecteurs que l'on veut additionner n'est pas la même,
     on lance une exception et le programme s'arrête /*/
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

//--------------------------------------------------------

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
    /*/ si la dimension des deux vecteurs n'est pas la même,
     on lance une exception et le programme s'arrête /*/
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
    /*/ si la dimension d'au moins un des deux vecteurs est différente de 3,
     on lance une exception et le programme s'arrête /*/
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
    /*/ si la composante que l'on souhaite avoir n'existe pas,
     on lance une exception et le programme s'arrête /*/
        if(i > size()) throw string ("Composante inexistente! Impossible \"getComp\"!" );
    return coord[i-1];
}

//--------------------------------------------------------

void Vecteur::set_coord(size_t place, double valeur)
{
    if (place-1 >= coord.size())
    {				/*/ Si la "place" passé en paramètre
                    est plus grande que la dim du vecteur,
                    on lance une exception et le programme s'arrête /*/

        throw string ("Composante inexistente! Impossible \"set_coord\"!");
    }

    coord[place-1]=valeur; /*/ on écrit moins 1 puisque pour nous c'esp plus facile de
                            parler de composantes 1,2 et 3 que 0,1 et 2 /*/
}

//--------------------------------------------------------

ostream& Vecteur::affiche(ostream& sortie) const
{
    /*/ si la dimension du vecteur que l'on veut afficher est nulle,
     on lance une exception et le programme s'arrête /*/
    if(size() == 0) throw string("Vecteur non affichable! (Dim = 0)");

        for (auto const& nombre : coord)
        {
         sortie << nombre << " " ;
        }

     return sortie;
}

//--------------------------------------------------------

size_t Vecteur::size() const {
    return coord.size();
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
    /*/ si le vecteur que l'on veut faire unitaire est nul,
     on lance une exception et le programme s'arrête. Notamment cette fonction est
     utile pour repèrer si l'utilisateur fournit le vecteur nul pour la direction de l'oscillateur /*/
  if(norme() == 0.0)  {
    throw string ("Impossible de rendre unitaire le vecteur nul!");
    }

    if(norme()!= 1.0) *this =(1.0/norme())*(*this);
}

//==========================================================

// Definition surcharge d'operateurs

//Surcharge interne

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

const Vecteur Vecteur::operator^(Vecteur const& vect) const // comme demandée, operateur associé au produit vectoriel
{
    return prod_vect(vect);
}

//--------------------------------------------------------

const Vecteur Vecteur::operator*(double a) const    // on a choisit * pour la multiplication par un scalaire
{
    return mult(a);
}

//--------------------------------------------------------

double Vecteur::operator*(Vecteur const& vect) const // on a choisit * pour le  scalaire
{
    return prod_scal(vect);
}

//==========================================================

// Surcharge externe

const Vecteur operator*(double a, Vecteur const& vect) // encore multiplication par un scalaire
{
    return vect.mult(a);
}

//--------------------------------------------------------

ostream& operator<<(ostream& sortie, Vecteur const& v)
{
    return v.affiche(sortie);
}

//==========================================================
