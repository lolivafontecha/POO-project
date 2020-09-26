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

all::testPendule

var.o: var.h

Pendule.o: Pendule.cc Pendule.h 

Integrateur.o: Integrateur.cc Integrateur.h

Vecteur.o: Vecteur.cc Vecteur.h

Oscillateur.o: Oscillateur.cc Oscillateur.h 

testPendule.o: testPendule.cc 

testPendule:: testPendule.o Pendule.o Integrateur.o Oscillateur.o Vecteur.o

#Nettoyage de fichiers (windows cleanwin:)
cleanlin:
	rm del testPendule.exe *.o
