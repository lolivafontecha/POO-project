#include <iostream> 
#include "TextViewer.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Ressort.h"

using namespace std;

void TextViewer::dessine(Pendule const& pendule) 
{
	flot << pendule << endl; 
}
  
void TextViewer::dessine(Ressort const& ressort)
{
	flot << ressort << endl;
}  
  
void TextViewer::dessine(Systeme const& systeme)
{
	flot << systeme << endl;
}



