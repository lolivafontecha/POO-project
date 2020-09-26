#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"

using namespace std;

void IntegrateurEulerCramer::integre(Oscillateur& oscillateur, double temps) const
{
 for(int i((temps/pas_de_temps)+1e-20); i > 0; --i)		//on arrondi par défaut
{
    oscillateur.setVitesse(oscillateur.getVitesse() + pas_de_temps * oscillateur.eq_mvt());
    oscillateur.setParametres(oscillateur.getParametres() + pas_de_temps * oscillateur.getVitesse());
  }
}

void IntegrateurNewmark::integre(Oscillateur& oscillateur, double temps) const
{
    double epsilon(1e-6);
 for(int i((temps/pas_de_temps)+1e-20); i > 0; --i)		//on arrondi par défaut
  {
    Vecteur copie_parametre(oscillateur.getParametres());
    Vecteur copie_vitesse(oscillateur.getVitesse());
    Vecteur s = oscillateur.eq_mvt();
    Vecteur r, q;

 do {
    q = oscillateur.getParametres();
    r = oscillateur.eq_mvt();

    oscillateur.setVitesse(copie_vitesse + (pas_de_temps/2)*(r + s));

    oscillateur.setParametres(copie_parametre + pas_de_temps*copie_vitesse
        + (pas_de_temps*pas_de_temps/3)*(0.5*r + s));

    } while (((oscillateur.getParametres() - q)).norme() >= epsilon);
  }
}
