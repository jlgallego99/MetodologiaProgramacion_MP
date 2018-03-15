#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas I, Makefile de la sesión 04
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/I_PosicionPrimerBlanco $(BIN)/I_SaltaPrimeraPalabra $(BIN)/I_DemoCadenasClasicas

$(BIN)/I_PosicionPrimerBlanco : $(OBJ)/I_PosicionPrimerBlanco.o
	g++ $(OBJ)/I_PosicionPrimerBlanco.o -o $(BIN)/I_PosicionPrimerBlanco

$(OBJ)/I_PosicionPrimerBlanco.o : $(SRC)/I_PosicionPrimerBlanco.cpp
	g++ -c $(SRC)/I_PosicionPrimerBlanco.cpp -o $(OBJ)/I_PosicionPrimerBlanco.o

$(BIN)/I_SaltaPrimeraPalabra : $(OBJ)/I_SaltaPrimeraPalabra.o
	g++ $(OBJ)/I_SaltaPrimeraPalabra.o -o $(BIN)/I_SaltaPrimeraPalabra

$(OBJ)/I_SaltaPrimeraPalabra.o : $(SRC)/I_SaltaPrimeraPalabra.cpp
	g++ -c $(SRC)/I_SaltaPrimeraPalabra.cpp -o $(OBJ)/I_SaltaPrimeraPalabra.o

$(BIN)/I_DemoCadenasClasicas : $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o
	g++ -o $(BIN)/I_DemoCadenasClasicas $(OBJ)/I_DemoCadenasClasicas.o $(OBJ)/MiCadenaClasica.o -std=c++11

$(OBJ)/I_DemoCadenasClasicas.o : $(SRC)/I_DemoCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/I_DemoCadenasClasicas.o $(SRC)/I_DemoCadenasClasicas.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE) -std=c++11

# LIMPIEZA  
clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
