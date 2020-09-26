#include <fstream>
#include <iostream>
#include "TextViewer.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Ressort.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"

using namespace std;

//==========================================================

//Méthodes pour dessiner

void TextViewer::dessine(Pendule const& pendule)
{
    flot << pendule << endl;
}

//-----------------------------------------------------------

void TextViewer::dessine(Ressort const& ressort)
{
    flot << ressort << endl;
}

//-----------------------------------------------------------

void TextViewer::dessine(Systeme const& systeme)
{
    flot << systeme << endl;
}

//-----------------------------------------------------------

void TextViewer::dessine(RessortPenduleCouplee const& ressort_pendule)
{
    flot << ressort_pendule << endl;
}

//-----------------------------------------------------------

void TextViewer::dessine(Pendule_Double const& pendule_double)
{
    flot << pendule_double << endl;
}

//-----------------------------------------------------------

void TextViewer::dessine_phase(vector<Vecteur> const& espaceDePhase)
{
    fstream file("data.txt", std::ios::out | std::ios::trunc);
    /*/ On crée un fichier data.txt et on garde dedans les points stockés dans notre tableau "espcedePhase"
      de la classe Oscillateur. Note: trunc nettoye tout ce qui a dans le fichier avant. De cette façon, en mode text
       la trajectoire dessinée avec gnuplot et celle du dernier oscillateur de notre système /*/

    for(auto const& point : espaceDePhase)
    {
        file << point.getComp(1) << " " << point.getComp(2) << endl;
    }
    file.close();
}

//==========================================================


