#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Systeme.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Vecteur.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ======================================================================

void VueOpenGL::dessine(Systeme const& systeme)
{
    dessineAxes(); // on déssine les axes
    Q_UNUSED(systeme);
}

// ======================================================================

void VueOpenGL::dessine(Pendule const& pendule)
{
    /*/ On garde l'origine de pendule et la position de la masse dans
    des variables locales pour ne pas devoir appeler aux fonctions get à tous les coups /*/
    Vecteur origine = pendule.getOrigine();
    Vecteur pos_masse = pendule.position_masse();

    QMatrix4x4 matrice;
    // mise à jour de l'orientation
    matrice.translate(origine.getComp(1), origine.getComp(2), origine.getComp(3));
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    /*/ On utilise GL_Lines pour faire un segment de droite entre l'origine du pendule
    et la position de la masse qui correspond au bout du pendule /*/
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // on fait un segment de droite blanc
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, pos_masse.getComp(1), pos_masse.getComp(2),
                           pos_masse.getComp(3));
    glEnd();

    // On dessine la sphère de couleur rose au bout du pendule
    matrice.translate(pos_masse.getComp(1), pos_masse.getComp(2), pos_masse.getComp(3));
    matrice.scale(0.2); // on fixe la taille de notre sphère
    dessineSphere(matrice, 1.0, 0.3,  0.7);
}

// ======================================================================

void VueOpenGL::dessine(Ressort const& ressort)
{
    /*/ On garde l'origine de pendule et la position de la masse dans
    des variables locales pour ne pas devoir appeler aux fonctions get à tous les coups
    et on ajoute une variable longueur associée à la longueur du ressort /*/
    Vecteur origine = ressort.getOrigine();
    Vecteur pos_masse = ressort.position_masse();
    Vecteur longueur = pos_masse - origine;

    QMatrix4x4 matrice;
    // mise à jour de l'orientation
    matrice.translate(origine.getComp(1), origine.getComp(2), origine.getComp(3));
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    // Opérations nécessaire pour orienter l'espiral
    Vecteur v((ressort.getDirection()) ^ Vecteur(0,0,1));
    double angle(asin(v.norme()));
    angle *= -180.0 / M_PI;
    matrice.rotate(angle, v.getComp(1), v.getComp(2), v.getComp(3));

    // On déssine l'espiral de ressort
    dessineespiral(matrice, longueur.norme(), 1.0, 1.0, 0.0);

    // On dessine la sphère blanche au bout du ressort
    QMatrix4x4 mat2;
    mat2.translate(pos_masse.getComp(1), pos_masse.getComp(2), pos_masse.getComp(3));
    mat2.scale(0.15); // on fixe la taille de notre sphère
    dessineSphere(mat2);
}

// ======================================================================

void VueOpenGL::dessine(RessortPenduleCouplee const& ressort_pendule)
{
    /*/ On garde l'origine de pendule et la position de la masse dans
    des variables locales pour ne pas devoir appeler aux fonctions get à tous les coups/*/
    Vecteur origine = ressort_pendule.getOrigine();
    Vecteur pos_masse = ressort_pendule.position_masse();

    QMatrix4x4 matrice;
    // mise à jour de l'orientation
    matrice.translate(origine.getComp(1), origine.getComp(2), origine.getComp(3));
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    Vecteur v((pos_masse) ^ Vecteur(0,0, -1));

    QMatrix4x4 matrice_tmp(matrice);
    double angle_alpha(asin(v.norme()/pos_masse.norme())); // alpha et teta comme sur le croquis
    double angle_teta(0);

    /*/ Opérations nécessaire pour orienter l'espiral: la différence maintenant est que l'on travaille
    avec deux angles car notre pendule ici ne bouge plus sur un plan seulement sinon qu'il bouge sur l'espace /*/
    if(pos_masse.getComp(1) <= 0 and pos_masse.getComp(2)) angle_teta = M_PI;
    else angle_teta = 2*atan(pos_masse.getComp(2)/(pos_masse.getComp(1)+pos_masse.norme()));
    angle_alpha *= -180.0 / M_PI;
    angle_teta *= -180.0 / M_PI;
    matrice_tmp.rotate(angle_alpha, v.getComp(1), v.getComp(2), v.getComp(3));
    matrice_tmp.rotate(angle_teta, 0.0, 0.0, 1.0);

    dessineespiral(matrice_tmp, (pos_masse - origine).norme(), 0.0, 1.0, 1.0);

    // On dessine la sphère verte au bout du pendule
    matrice.translate(pos_masse.getComp(1), pos_masse.getComp(2), pos_masse.getComp(3));
    matrice.scale(0.2); // on fixe la taille de la sphère
    dessineSphere(matrice, 0.2, 0.8, 0.2);
}

// ======================================================================

void VueOpenGL::dessine(Pendule_Double const& pendule_double)
{
    /*/ On garde l'origine de pendule et la position de la masse dans
    des variables locales pour ne pas devoir appeler aux fonctions get à tous les coups /*/
    Vecteur origine = pendule_double.getOrigine();
    Vecteur pos_masse_milieu = pendule_double.position_masse_milieu();
    Vecteur pos_masse = pendule_double.position_masse();

    QMatrix4x4 matrice;
    // mise à jour de l'orientation
    matrice.translate(origine.getComp(1), origine.getComp(2), origine.getComp(3));
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    /*/ On utilise GL_Lines pour faire un segment de droite entre l'origine du pendule
    et la position de la masse qui correspond au bout du pendule /*/
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 0.2, 0.8, 0.5); // on fait un segment de droite
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, pos_masse_milieu.getComp(1), pos_masse_milieu.getComp(2),
                           pos_masse_milieu.getComp(3));
    glEnd();

    // On dessine la sphère de couleur rose au bout du premier pendule
    matrice.translate(pos_masse_milieu.getComp(1), pos_masse_milieu.getComp(2), pos_masse_milieu.getComp(3));
    matrice.scale(0.2); // on fixe la taille de notre sphère
    dessineSphere(matrice, 1.0, 0.5, 0.0);

    matrice.setToIdentity();
    matrice.translate(pos_masse_milieu.getComp(1), pos_masse_milieu.getComp(2), pos_masse_milieu.getComp(3));
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    /*/ On utilise GL_Lines pour faire un segment de droite entre l'origine du pendule
    et la position de la masse qui correspond au bout du pendule /*/
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 0.2, 0.8, 0.5); // on fait un segment de droite
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, pos_masse.getComp(1), pos_masse.getComp(2), pos_masse.getComp(3));
    glEnd();

    // On dessine la sphère de couleur rose au bout du deuxieme pendule
    matrice.translate(pos_masse.getComp(1), pos_masse.getComp(2), pos_masse.getComp(3));
    matrice.scale(0.2); // on fixe la taille de notre sphère
    dessineSphere(matrice, 0.0, 0.0,  1.0);

}

// ======================================================================

void VueOpenGL::dessine_phase(vector<Vecteur> const& espaceDePhase)
{
    if(!afficherEspaceDePhase) return; /*/ nécessaire pour pouvoir faire fonctionner
                                    la touche p, laquelle contrôle si l'espace des phases
                                    doit être déssiner ou non/*/

    QMatrix4x4 matrice;
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    // on relie tous les points de l'espace des phase avec l'outils GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
    for(auto const& point : espaceDePhase)
    {
        prog.setAttributeValue(SommetId, 0.0, point.getComp(2), point.getComp(1));
    }
    glEnd();
}

// ======================================================================

void VueOpenGL::toggleEspaceDePhase()
{
    if(afficherEspaceDePhase) afficherEspaceDePhase = false;  /*/ quand on appuie p la valeur du
                                                                    booléen change /*/
    else afficherEspaceDePhase = true;
}

// ======================================================================

void VueOpenGL::init()
{
    /* Initialise notre vue OpenGL.
    * Dans cet exemple, nous créons et activons notre shader.
    *
    * En raison du contenu des fichiers *.glsl, le shader de cet exemple
    * NE permet QUE de dessiner des primitives colorées
    * (pas de textures, brouillard, reflets de la lumière ou autres).
    *
    * Il est séparé en deux parties VERTEX et FRAGMENT.
    * Le VERTEX :
    * - récupère pour chaque sommet des primitives de couleur (dans
    *     l'attribut couleur) et de position (dans l'attribut sommet)
    * - multiplie l'attribut sommet par les matrices 'vue_modele' et
    *     'projection' et donne le résultat à OpenGL
    *   - passe la couleur au shader FRAGMENT.
    *
    * Le FRAGMENT :
    *   - applique la couleur qu'on lui donne
    */

    prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

    /* Identifie les deux attributs du shader de cet exemple
    * (voir vertex_shader.glsl).
    *
    * L'attribut identifié par 0 est particulier, il permet d'envoyer un
    * nouveau "point" à OpenGL
    *
    * C'est pourquoi il devra obligatoirement être spécifié et en dernier
    * (après la couleur dans cet exemple, voir plus bas).
    */

    prog.bindAttributeLocation("sommet",  SommetId);
    prog.bindAttributeLocation("couleur", CouleurId);

    // Compilation du shader OpenGL
    prog.link();

    // Activation du shader
    prog.bind();

    /* Activation du "Test de profondeur" et du "Back-face culling"
    * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
    * partielement caché par d'autres objets.
    *
    * Le Back-face culling consiste à ne dessiner que les face avec ordre
    * de déclaration dans le sens trigonométrique.
    */
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    sphere.initialize();                                      // initialise la sphère
    initializePosition();
}

// ======================================================================

void VueOpenGL::initializePosition()
{
    // position initiale
    matrice_vue.setToIdentity();
    matrice_vue.translate(0.0, 0.0, -4.0);
    matrice_vue.rotate(60.0, 0.0, 0.0, 1.0);
    matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
    matrice_vue.rotate(-20.0, 1.0, 0.0, 0.0);
}

// ======================================================================

void VueOpenGL::translate(double x, double y, double z)
{
    /* Multiplie la matrice de vue par LA GAUCHE.
    * Cela fait en sorte que la dernière modification apportée
    * à la matrice soit appliquée en dernier (composition de fonctions).
    */
    QMatrix4x4 translation_supplementaire;
    translation_supplementaire.translate(x, y, z);
    matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================

void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
    // Multiplie la matrice de vue par LA GAUCHE
    QMatrix4x4 rotation_supplementaire;
    rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
    matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================

void VueOpenGL::dessineAxes(QMatrix4x4 const& point_de_vue)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_LINES);

    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // x Rouge
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

    prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // y Vert
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

    prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // z Bleu
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

    glEnd();
}

// ======================================================================

void VueOpenGL::dessineSphere(QMatrix4x4 const& point_de_vue,
                              double rouge, double vert, double bleu){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
    sphere.draw(prog, SommetId);                           // dessine la sphère
}

// ======================================================================

void VueOpenGL::dessineespiral(QMatrix4x4 const& point_de_vue, double distance, double rouge,
                               double vert, double bleu, unsigned int nbr_boucle, unsigned int point_par_boucle)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    unsigned int nbr_points = nbr_boucle*point_par_boucle;

    // On fixe les couleurs de l'espiral
    prog.setAttributeValue(CouleurId, rouge, vert, bleu);

    /*/ On utilise GL_LINE_STRIP pour dessiner une espiral a partir de 'beaucoup' de points,
    on utilise l'équation paramètrique d'une hélice/*/
    glBegin(GL_LINE_STRIP);
    double tpas(1.0/nbr_points);
    for(double t(0); t <= 0.98; t += tpas)
    {
        double x(sin(2.0*M_PI*nbr_boucle*t)*0.05),
               y(cos(2.0*M_PI*nbr_boucle*t)*0.05),
               z(-1.0*t*distance);
        prog.setAttributeValue(SommetId, x,y,z);
    }
    glEnd();
}

// ======================================================================
