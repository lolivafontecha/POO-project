QT += core gui opengl widgets
CONFIG += c++11 console

win32:LIBS += -lopengl32

TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    glsphere.cc \
    vue_opengl.cc 

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h \
    ../general/Integrateur.h \
    ../general/IntegrateurEulerCramer.h \
    ../general/IntegrateurNewmark.h \
    ../general/Vecteur.h \
    ../general/Oscillateur.h \
    ../general/Ressort.h \
    ../general/Pendule.h \
    ../general/Systeme.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h \
    ../general/var.h \
    ../general/RessortPenduleCouplee.h \
    ../general/Pendule_Double.h

RESOURCES += \
    resource.qrc
