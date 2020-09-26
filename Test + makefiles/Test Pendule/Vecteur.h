#pragma once
#include <vector>
#include <cmath>
#include <string>
#include <initializer_list>

class Vecteur {
     private:
    // attributs
    std::vector<double> coord; // composantes du vecteur

    // méthodes privées
    bool essayer_dim(Vecteur const& vect) const; /*/ return vrai si la dimension de l'instance
                                                courante et la dimension du vecteur passé
                                                    en paramètre sont la même/*/

    bool compare(Vecteur const& vect) const; /*/ Compare deux vecteurs composante par composante
                                              sous la consdition au'ils soient de même taille/*/

    void augmente(double new_val); /*/ Ajoute une composante au vecteur
                                      et met la valeur passée en paramètre/*/
     
    // operations privées
    Vecteur addition(Vecteur const& vect) const; // addition de l'instance courante et du vecteur passé en paramètre
    Vecteur soustraction(Vecteur const& vect) const; // soustraction de l'instance courante et du vecteur passé en paramètre
    double prod_scal(Vecteur const& vect) const; // produit scalaire entre l'instance courante et le vecteur passé en paramètre
    Vecteur prod_vect(Vecteur const& vect) const; // produit vectoriel entre l'instance courante et le vecteur passé en paramètre
    Vecteur oppose() const; // calcule du vecteur opposé
    double norme2() const; // calcule de la norme au carré

     public:
    // Constructeurs
    Vecteur(size_t dim = 0): coord(dim){} /*/ 1. construit un vecteur de la taille passée en paramatre
                                            dont tous les valeurs sont nuls/*/
    Vecteur(double comp1, double comp2, double comp3)
    {
    augmente(comp1);
    augmente(comp2);
    augmente(comp3);
    } // 2. construit un vecteur de dimension 3 dont les valeurs sont passé comme parametre
    Vecteur(std::initializer_list<double> const& liste):coord(liste) {}
    // 3. construit un vecteur de taille n à partir d'une liste de nombres de taille n

    ~Vecteur() {} // Destructeur

    //Getter
    double getComp(size_t i) const; // retourne la i-eme composante du vecteur

    //Setter
    void set_coord(size_t place, double valeur); /*/ modifie la valeur de la place precisée
                                                 (méthode demandé dans l'exercice P1 mais non utilisé
                                                    dans le programme)/*/

    std::ostream& affiche(std::ostream& sortie) const; // affichage d'un vecteur
    
    // Autres opérations, maintenant public
    Vecteur mult(double scal) const; // multplication par un scalaire
    double norme() const; // calcule la norme
    void FaireUnitaire(); // fait de l'instance courante un vecteur unitaire
	size_t size() const; // retourne la taille du tableau "coord"
    // surcharge internes operateurs
    bool operator==(Vecteur const& vect) const;
    bool operator!=(Vecteur const& vect) const;
    Vecteur& operator+=(Vecteur const& vect);
    Vecteur& operator-=(Vecteur const& vect);
    const Vecteur operator+(Vecteur const& vect) const;
    const Vecteur operator-(Vecteur const& vect) const;
    const Vecteur operator^(Vecteur const& vect) const; //
    const Vecteur operator*(double a) const; // on a choisit * pour la multiplication par un scalaire
    double operator*(Vecteur const& vect) const; // on a choisit * pour le produit scalaire

};

    // surcharge externe d'operateurs
    std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);
    const Vecteur operator*(double a, Vecteur const& vect); /*/ encore multiplication par un scalaire,
                                                            cette fois ci pour pouvoir multiplier des deux côtés/*/
