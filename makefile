# --- Makefile pour le TP3 de C++ ---
# utiliser la commande make all pour créer l'exécutable du projet

# mettre DEBUG à la valeur yes pour créer l'exécutable en mode debug
DEBUG=no
ifeq ($(DEBUG),yes)
	CFLAGS=-Wall -Werror -ansi -pedantic -std=c++11 -g -D MAP
	LDFLAGS=
else
	CFLAGS=-Wall -Werror -ansi -pedantic -std=c++11 -O3
	LDFLAGS=
endif
CC = g++
EXEC = TP4
SRC= main.cpp File.cpp Link.cpp Request.cpp Reader.cpp LogInterface.cpp Test.cpp
OBJ= $(SRC:.cpp=.o)
HEDR = $(SRC:.cpp=.h)


all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif


$(EXEC): $(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

TP3.o: TP3.cpp
	g++ -c $< $(CFLAGS)

%.o: %.cpp %.h
	g++ -c $< $(CFLAGS)

.PHONY = clean

clean:
	rm -rf *.o
