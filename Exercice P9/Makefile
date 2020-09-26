CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -pg                 # pour profiler
# LDFLAGS  += -pg                 # pour profiler
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all:exerciceP9

var.o: var.h

Vecteur.o: Vecteur.cc Vecteur.h

Oscillateur.o: Oscillateur.cc Oscillateur.h

Integrateur.o: Integrateur.cc Integrateur.h

Ressort.o: Ressort.cc Ressort.h 

Pendule.o: Pendule.cc Pendule.h

Systeme.o: Systeme.cc Systeme.h

TextViewer.o: TextViewer.cc TextViewer.h

exerciceP9.o: exerciceP9.cc 

exerciceP9: exerciceP9.o TextViewer.o Systeme.o Pendule.o Ressort.o Integrateur.o Oscillateur.o Vecteur.o 

#Nettoyage de fichiers (windows cleanwin:)
cleanlin:
	rm del exerciceP9.exe *.o
