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

all::testRessort

var.o: var.h

Ressort.o: Ressort.cc Ressort.h 

Integrateur.o: Integrateur.cc Integrateur.h

Vecteur.o: Vecteur.cc Vecteur.h

Oscillateur.o: Oscillateur.cc Oscillateur.h 

testRessort.o: testRessort.cc 

testRessort:: testRessort.o Ressort.o Integrateur.o Oscillateur.o Vecteur.o

#Nettoyage de fichiers (windows cleanwin:)
cleanlin:
	rm del testRessort.exe *.o
