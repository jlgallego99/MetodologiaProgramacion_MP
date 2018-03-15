#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas I, Makefile de la sesión 1, 2 y 3
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/I_CambiaNegs $(BIN)/I_CambiaNegs_PtrFinal \
              $(BIN)/I_MezclaSencillaVectores $(BIN)/I_ReorganizaVector

$(BIN)/I_CambiaNegs : $(OBJ)/I_CambiaNegs.o
	g++ $(OBJ)/I_CambiaNegs.o -o $(BIN)/I_CambiaNegs

$(OBJ)/I_CambiaNegs.o : $(SRC)/I_CambiaNegs.cpp
	g++ -c $(SRC)/I_CambiaNegs.cpp -o $(OBJ)/I_CambiaNegs.o

$(BIN)/I_CambiaNegs_PtrFinal : $(OBJ)/I_CambiaNegs_PtrFinal.o
	g++ $(OBJ)/I_CambiaNegs_PtrFinal.o -o $(BIN)/I_CambiaNegs_PtrFinal

$(OBJ)/I_CambiaNegs_PtrFinal.o : $(SRC)/I_CambiaNegs_PtrFinal.cpp
	g++ -c $(SRC)/I_CambiaNegs_PtrFinal.cpp -o $(OBJ)/I_CambiaNegs_PtrFinal.o

$(BIN)/I_MezclaSencillaVectores : $(OBJ)/I_MezclaSencillaVectores.o
	g++ $(OBJ)/I_MezclaSencillaVectores.o -o $(BIN)/I_MezclaSencillaVectores

$(OBJ)/I_MezclaSencillaVectores.o : $(SRC)/I_MezclaSencillaVectores.cpp
	g++ -c $(SRC)/I_MezclaSencillaVectores.cpp -o $(OBJ)/I_MezclaSencillaVectores.o

$(BIN)/I_ReorganizaVector : $(OBJ)/I_ReorganizaVector.o
	g++ $(OBJ)/I_ReorganizaVector.o -o $(BIN)/I_ReorganizaVector

$(OBJ)/I_ReorganizaVector.o : $(SRC)/I_ReorganizaVector.cpp
	g++ -c $(SRC)/I_ReorganizaVector.cpp -o $(OBJ)/I_ReorganizaVector.o

# LIMPIEZA  
clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*