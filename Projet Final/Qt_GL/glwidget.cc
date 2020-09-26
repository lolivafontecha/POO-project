#include "glwidget.h"
#include "Oscillateur.h"
#include "Pendule.h"
#include "Ressort.h"
#include "Systeme.h"
#include "Integrateur.h"
#include "IntegrateurEulerCramer.h"
#include "IntegrateurNewmark.h"
#include "Vecteur.h"
#include "RessortPenduleCouplee.h"
#include "Pendule_Double.h"
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include <QString> // pour gestion d'erreurs
#include <QMessageBox> // pour gestion d'erreurs
#include <QApplication>
#include <iostream>
#include <cmath> // pour M_PI
#include <string> // pour gestion d'erreurs

using namespace std;

GLWidget::GLWidget(QWidget* parent, Integrateur* integrateur)
    : QGLWidget(parent), _systeme(&vue), integrateur(integrateur)
{
    /*/ On va créer un système avec un pendule, un ressort et un ressort-pendule. Pour faciliter les test du programme,
    on va écrire en commentaire un code avec une exception (on peut toujours essayez d'autres exceptions: masse negative, raideur
    négatif, longueur négatif, vecteur direction nul, vecteur vitesse et vecteur parametres de différente taille) et un
    autre code (celui-ci pas comme comentaire) qui compile et s'affiche correctement, les valeurs ont été choisit arbitrairement /*/

    // CODE SANS EXCEPTIONS
    Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

    // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1.0, 0.0, 0.0});
    double masse_pendule(1.0), lambda_pendule(0), longueur_pendule(1.0);

    // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.0, 0.0, 1.0});
    double masse_ressort(0.25), raideur_ressort(0.33), lambda_ressort(0.01);

    // Valeurs pour initialiser notre ressort-pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressortpendule({1.0, 0.3, 0.0}), vitesse_ressortpendule({2.0, 1.0, 0.0}),
                                                        direction_ressortpendule({0.0, 1.0, 0.0});
    double masse_ressortpendule(1.0), longueur_repos_ressortpendule(0.7), raideur_ressortpendule(5.0);

    // Valeurs pour initialiser notre pendule-double: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule_double({M_PI/2, M_PI/2}), vitesse_pendule_double({0.0, 0.0}),
                                                        direction_pendule_double({0.0, 1.0, 0.0});
    double masse_1_pendule_double(2.0), masse_2_pendule_double(2.0),
            longueur_1_pendule_double(2.0), longueur_2_pendule_double(1.0);

    integrateur = new IntegrateurEulerCramer(0.01);
    // Pour tester avec integrateur de Newmark:
    //integrateur = new IntegrateurNewmark(0.01);
    // le 0.01 c'est le pas de temps que l'on a choisit, on peut toujours le changer

    _systeme.ajouterIntegrateur(integrateur);

  try {
        _systeme.ajouterOscillateur(new Pendule(&vue, parametre_pendule , vitesse_pendule,
                                            masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
        _systeme.ajouterOscillateur(new Ressort(&vue, parametre_ressort, vitesse_ressort, masse_ressort,
                                                direction_ressort, origine, raideur_ressort, lambda_ressort));
        _systeme.ajouterOscillateur(new RessortPenduleCouplee(&vue, parametre_ressortpendule, vitesse_ressortpendule, masse_ressortpendule,
                                             direction_ressortpendule, origine, longueur_repos_ressortpendule, raideur_ressortpendule));
        _systeme.ajouterOscillateur(new Pendule_Double(&vue, parametre_pendule_double, vitesse_pendule_double,
                          direction_pendule_double, origine, longueur_1_pendule_double, longueur_2_pendule_double,
                          masse_1_pendule_double, masse_2_pendule_double));

  } catch(string const& erreur) {
           cerr << "Il y a une erreur : " << erreur << endl; // pour afficher sur le terminal
           QMessageBox::critical(0, "ERREUR D'INITIALISATION", erreur.c_str());
       // outils de qt qui permet un affichage des erreurs plus sophistiqué
      }

   // CODE AVEC EXCEPTIONS
    /*/    Vecteur origine({0.0, 0.0, 0.0}); // on a choisit de mettre le même origine à nos oscillateurs

    // Valeurs pour initialiser notre pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule({M_PI/2}), vitesse_pendule({0}), direction_pendule({1.0, 0.0, 0.0});
    double masse_pendule(-2), lambda_pendule(0.1), longueur_pendule(2.0);

    // Valeurs pour initialiser notre ressort: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressort({0.18}), vitesse_ressort({0}), direction_ressort({0.0, 0.0, 1.0});
    double masse_ressort(0.25), raideur_ressort(0.33), lambda_ressort(0.1);

    // Valeurs pour initialiser notre ressort-pendule: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_ressortpendule({1.0, 0.3, 0.0}), vitesse_ressortpendule({2.0, 1.0, 0.0}),
                                                        direction_ressortpendule({0.0, 0.0, 1.0});
    double masse_ressortpendule(1.0), longueur_repos_ressortpendule(0.7), raideur_ressortpendule(5.0);

    // Valeurs pour initialiser notre pendule-double: on peut toujours les changes pour tester des choses différentes!
    Vecteur parametre_pendule_double({M_PI/2, M_PI/2}), vitesse_pendule_double({0.0, 0.0}),
                                                        direction_pendule_double({0.0, 1.0, 0.0});
    double masse_1_pendule_double(2.0), masse_2_pendule_double(2.0),
            longueur_1_pendule_double(2.0), longueur_2_pendule_double(1.0);

       // Pour tester avec integrateur de EulerCramer:
       //integrateur = new IntegrateurEulerCramer(0.01);
       integrateur = new IntegrateurNewmark(0.01);
       // le 0.01 c'est le pas de temps que l'on a choisit, on peut toujours le changer

       _systeme.ajouterIntegrateur(integrateur);

     try {
          _systeme.ajouterOscillateur(new Pendule(&vue, parametre_pendule , vitesse_pendule,
                                              masse_pendule, direction_pendule , origine, lambda_pendule, longueur_pendule));
          _systeme.ajouterOscillateur(new Ressort(&vue, parametre_ressort, vitesse_ressort, masse_ressort,
                                                  direction_ressort, origine, raideur_ressort, lambda_ressort));
          _systeme.ajouterOscillateur(new RessortPenduleCouplee(&vue, parametre_ressortpendule, vitesse_ressortpendule, masse_ressortpendule,
                                               direction_ressortpendule, origine, longueur_repos_ressortpendule, raideur_ressortpendule));
          _systeme.ajouterOscillateur(new Pendule_Double(&vue, parametre_pendule_double, vitesse_pendule_double,
                          direction_pendule_double, origine, longueur_1_pendule_double, longueur_2_pendule_double,
                          masse_1_pendule_double, masse_2_pendule_double));

      } catch(string const& erreur) {
              cerr << "Il y a une erreur : " << erreur << endl; // pour afficher sur le terminal
              QMessageBox::critical(0, "ERREUR D'INITIALISATION", erreur.c_str());
      // outils de qt qui permet un affichage des erreurs plus sophistiqué
         }/*/
}

// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(20);
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  try{
     _systeme.dessine();
  } catch(string const& erreur) {
    cerr << "Il y a une erreur : " << erreur << endl; // pour afficher sur le terminal
    QMessageBox::critical(0, "ERREUR DE CALCUL" , erreur.c_str()); /*/ outils de qt qui permet un affichage
                                                                    des erreurs plus sophistiqué /*/
    pause();
  }
}

// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
    pause();
    break;

  case Qt::Key_P:      // nouvelle touche pour faire apparaitre/disparaitre l'espace des phases
    vue.toggleEspaceDePhase();
    break;

  };

  update(); // redessine
}

// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  double dt = chronometre.restart() / 1000.0;

  try{
     _systeme.evolue(dt);
  } catch(string const& erreur) {
    cerr << "Il y a une erreur : " << erreur << endl; // pour afficher sur le terminal
    QMessageBox::critical(0, "ERREUR DE CALCUL", erreur.c_str()); /*/ outils de qt qui permet un affichage
                                                                    des erreurs plus sophistiqué /*/
    pause();
  }
  update();
}

// ======================================================================
void GLWidget::pause()
{
  if (timerId == 0) {
    // dans ce cas le timer ne tourne pas alors on le lance
    timerId = startTimer(20);
    chronometre.restart();
  } else {
    // le timer tourne alors on l'arrête
    killTimer(timerId);
    timerId = 0;
  }
}

