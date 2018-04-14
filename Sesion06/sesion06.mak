#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas I y II, Makefile de la sesión 06
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/I_EncuentraInicioPalabras \
				  $(BIN)/I_EncuentraPalabras \
				  $(BIN)/II_RedimensionaVectorDinamico \
				  $(BIN)/II_EncuentraPalabras_MemDin \
				  $(BIN)/II_VectorDinamicoCadenas

# Relación de problemas I, Ejercicio 17

$(BIN)/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o 
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(OBJ)/I_EncuentraInicioPalabras.o

$(OBJ)/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp 
	g++ -c -o $(OBJ)/I_EncuentraInicioPalabras.o \
	          $(SRC)/I_EncuentraInicioPalabras.cpp 

# Relación de problemas I, Ejercicio 18

$(BIN)/I_EncuentraPalabras : $(OBJ)/I_EncuentraPalabras.o 
	g++ -o $(BIN)/I_EncuentraPalabras $(OBJ)/I_EncuentraPalabras.o

$(OBJ)/I_EncuentraPalabras.o : $(SRC)/I_EncuentraPalabras.cpp 
	g++ -c -o $(OBJ)/I_EncuentraPalabras.o $(SRC)/I_EncuentraPalabras.cpp 

# Relación de problemas II, Ejercicio 1

$(BIN)/II_RedimensionaVectorDinamico : $(OBJ)/II_RedimensionaVectorDinamico.o
	g++ -o $(BIN)/II_RedimensionaVectorDinamico \
	       $(OBJ)/II_RedimensionaVectorDinamico.o \

$(OBJ)/II_RedimensionaVectorDinamico.o : $(SRC)/II_RedimensionaVectorDinamico.cpp 	
	g++ -c -o $(OBJ)/II_RedimensionaVectorDinamico.o \
	          $(SRC)/II_RedimensionaVectorDinamico.cpp

# Relación de problemas II, Ejercicio 2

$(BIN)/II_EncuentraPalabras_MemDin : $(OBJ)/II_EncuentraPalabras_MemDin.o 
	g++ -o $(BIN)/II_EncuentraPalabras_MemDin $(OBJ)/II_EncuentraPalabras_MemDin.o

$(OBJ)/II_EncuentraPalabras_MemDin.o : $(SRC)/II_EncuentraPalabras_MemDin.cpp 
	g++ -c -o $(OBJ)/II_EncuentraPalabras_MemDin.o \
	          $(SRC)/II_EncuentraPalabras_MemDin.cpp 

# Relación de problemas II, Ejercicio 2

$(BIN)/II_VectorDinamicoCadenas : $(OBJ)/II_VectorDinamicoCadenas.o 
	g++ -o $(BIN)/II_VectorDinamicoCadenas $(OBJ)/II_VectorDinamicoCadenas.o

$(OBJ)/II_VectorDinamicoCadenas.o : $(SRC)/II_VectorDinamicoCadenas.cpp 
	g++ -c -o $(OBJ)/II_VectorDinamicoCadenas.o \
	          $(SRC)/II_VectorDinamicoCadenas.cpp 

# LIMPIEZA 
clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
