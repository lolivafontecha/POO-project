#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include <vector>
#include "glsphere.h"
#include "SupportADessin.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Systeme.h"
#include "Oscillateur.h"
#include "Vecteur.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"

class VueOpenGL : public SupportADessin {
public:

    VueOpenGL() : SupportADessin(), prog(), sphere(), matrice_vue(), afficherEspaceDePhase(false) { }

    // méthodes de dessin (héritées de SupportADessin)
    virtual void dessine(Pendule const& pendule) override;
    virtual void dessine(Ressort const& ressort) override;
    virtual void dessine(Systeme const& systeme) override;
    virtual void dessine(RessortPenduleCouplee const& ressort_pendule) override;
    virtual void dessine(Pendule_Double const& pendule_double) override;
    virtual void dessine_phase(std::vector<Vecteur> const& espaceDePhase) override;

    // méthodes de (ré-)initialisation
    void init();
    void initializePosition();

    // méthode set
    void setProjection(QMatrix4x4 const& projection)
    { prog.setUniformValue("projection", projection); }

    // Méthodes set
    void translate(double x, double y, double z);
    void rotate(double angle, double dir_x, double dir_y, double dir_z);

    // méthode utilitaire offerte pour simplifier
    void dessineAxes(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
    void dessineSphere(QMatrix4x4 const& point_de_vue,
                       double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
    void dessineespiral(QMatrix4x4 const& point_de_vue, double distance, double rouge = 1.0, double vert = 1.0,
                       double bleu = 1.0, unsigned int nbr_boucle = 10, unsigned int point_par_boucle = 20);
    // méthode qui dessine l'espiral qui représente le ressort

    void toggleEspaceDePhase(); /*/ méthode qui change la valeur de "afficherEspaceDePhase"
                                cette méthode fait cet attribut valoir true quand il est false et vice-versa /*/

private:
    // Un shader OpenGL encapsulé dans une classe Qt
    QOpenGLShaderProgram prog;
    GLSphere sphere;

    // Caméra
    QMatrix4x4 matrice_vue;

    bool afficherEspaceDePhase; /*/ Nécessaire pour pouvoir definir
                                une touche qui affiche l'espace des phases/*/
};

#endif
