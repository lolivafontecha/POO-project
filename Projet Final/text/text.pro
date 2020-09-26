CONFIG += c++11 console

TARGET = ex_05_text

LIBS += -L ../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main.cc \
    TextViewer.cc

HEADERS += \
    TextViewer.h \
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
    ../general/Pendule_Double.h \
