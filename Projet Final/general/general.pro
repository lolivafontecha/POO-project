TEMPLATE = lib

CONFIG = staticlib c++11

SOURCES = \
        IntegrateurNewmark.cc \
        IntegrateurEulerCramer.cc \
	Vecteur.cc \
	Oscillateur.cc \
	Ressort.cc \
	Pendule.cc \
	Systeme.cc \
        RessortPenduleCouplee.cc \
        Pendule_Double.cc

HEADERS += \
        Integrateur.h \
        IntegrateurNewmark.h \
        IntegrateurEulerCramer.h \
	Vecteur.h \
	Oscillateur.h \
	Ressort.h \
	Pendule.h \
	Systeme.h \
	Dessinable.h \
	SupportADessin.h \
	var.h \
        RessortPenduleCouplee.h \
        Pendule_Double.h
