#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas II, Makefile de la sesión 08
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/II_BasicosLista \
              $(BIN)/II_OrdenarLista \
				  $(BIN)/II_GestionarListaOrdenada \
				  $(BIN)/II_MezclarListasOrdenadas

# Relación de problemas II, Ejercicio 12

$(BIN)/II_BasicosLista : $(OBJ)/II_BasicosLista.o $(LIB)/libLista.a
	g++ -o $(BIN)/II_BasicosLista $(OBJ)/II_BasicosLista.o -L$(LIB) -lLista

$(OBJ)/II_BasicosLista.o : $(SRC)/II_BasicosLista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_BasicosLista.o $(SRC)/II_BasicosLista.cpp -I$(INCLUDE)

# Relación de problemas II, Ejercicio 13

$(BIN)/II_OrdenarLista : $(OBJ)/II_OrdenarLista.o $(LIB)/libLista.a
	g++ -o $(BIN)/II_OrdenarLista $(OBJ)/II_OrdenarLista.o -L$(LIB) -lLista

$(OBJ)/II_OrdenarLista.o : $(SRC)/II_OrdenarLista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_OrdenarLista.o $(SRC)/II_OrdenarLista.cpp -I$(INCLUDE)

# Relación de problemas II, Ejercicio 14

$(BIN)/II_GestionarListaOrdenada : $(OBJ)/II_GestionarListaOrdenada.o \
                                   $(LIB)/libLista.a
	g++ -o $(BIN)/II_GestionarListaOrdenada $(OBJ)/II_GestionarListaOrdenada.o \
          -L$(LIB) -lLista

$(OBJ)/II_GestionarListaOrdenada.o : $(SRC)/II_GestionarListaOrdenada.cpp \
                                     $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_GestionarListaOrdenada.o \
	          $(SRC)/II_GestionarListaOrdenada.cpp \
             -I$(INCLUDE)

# Relación de problemas II, Ejercicio 15

$(BIN)/II_MezclarListasOrdenadas : $(OBJ)/II_MezclarListasOrdenadas.o \
                                   $(LIB)/libLista.a
	g++ -o $(BIN)/II_MezclarListasOrdenadas $(OBJ)/II_MezclarListasOrdenadas.o \
          -L$(LIB) -lLista

$(OBJ)/II_MezclarListasOrdenadas.o : $(SRC)/II_MezclarListasOrdenadas.cpp \
                                     $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/II_MezclarListasOrdenadas.o \
	          $(SRC)/II_MezclarListasOrdenadas.cpp \
             -I$(INCLUDE)

# Funciones y clases

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h \
                 $(INCLUDE)/GeneradorAleatorios.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)

$(OBJ)/GeneradorAleatorios.o : $(SRC)/GeneradorAleatorios.cpp \
                               $(INCLUDE)/GeneradorAleatorios.h
	g++ -c -o $(OBJ)/GeneradorAleatorios.o $(SRC)/GeneradorAleatorios.cpp \
	          -I$(INCLUDE)

$(LIB)/libLista.a : $(OBJ)/Lista.o $(OBJ)/GeneradorAleatorios.o
	ar rvs $(LIB)/libLista.a $(OBJ)/Lista.o $(OBJ)/GeneradorAleatorios.o

# LIMPIEZA 

clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*