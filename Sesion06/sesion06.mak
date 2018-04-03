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
				  $(BIN)/II-RedimensionaVectorDinamico \
				  $(BIN)/II-EncuentraPalabras_MemDin \
				  $(BIN)/II-VectorDinamicoCadenas

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

$(BIN)/II-RedimensionaVectorDinamico : $(OBJ)/II-RedimensionaVectorDinamico.o \
                                       $(OBJ)/Redimensiona.o \
													$(OBJ)/MuestraVector.o
	g++ -o $(BIN)/II-RedimensionaVectorDinamico \
	          $(OBJ)/II-RedimensionaVectorDinamico.o \
				 $(OBJ)/Redimensiona.o \
				 $(OBJ)/MuestraVector.o

$(OBJ)/II-RedimensionaVectorDinamico.o : $(SRC)/II-RedimensionaVectorDinamico.cpp \
                                         $(INCLUDE)/Redimensiona.h \
													  $(INCLUDE)/MuestraVector.h
	g++ -c -o $(OBJ)/II-RedimensionaVectorDinamico.o \
	          $(SRC)/II-RedimensionaVectorDinamico.cpp -I$(INCLUDE)

$(OBJ)/Redimensiona.o : $(SRC)/Redimensiona.cpp
	g++ -c -o $(OBJ)/Redimensiona.o $(SRC)/Redimensiona.cpp -I$(INCLUDE)

$(OBJ)/MuestraVector.o : $(SRC)/MuestraVector.cpp
	g++ -c -o $(OBJ)/MuestraVector.o $(SRC)/MuestraVector.cpp -I$(INCLUDE)

# Relación de problemas II, Ejercicio 2

$(BIN)/II-EncuentraPalabras_MemDin : $(OBJ)/II-EncuentraPalabras_MemDin.o 
	g++ -o $(BIN)/II-EncuentraPalabras_MemDin $(OBJ)/II-EncuentraPalabras_MemDin.o

$(OBJ)/II-EncuentraPalabras_MemDin.o : $(SRC)/II-EncuentraPalabras_MemDin.cpp 
	g++ -c -o $(OBJ)/II-EncuentraPalabras_MemDin.o \
	          $(SRC)/II-EncuentraPalabras_MemDin.cpp 

# Relación de problemas II, Ejercicio 2

$(BIN)/II-VectorDinamicoCadenas : $(OBJ)/II-VectorDinamicoCadenas.o 
	g++ -o $(BIN)/II-VectorDinamicoCadenas $(OBJ)/II-VectorDinamicoCadenas.o

$(OBJ)/II-VectorDinamicoCadenas.o : $(SRC)/II-VectorDinamicoCadenas.cpp 
	g++ -c -o $(OBJ)/II-VectorDinamicoCadenas.o \
	          $(SRC)/II-VectorDinamicoCadenas.cpp 

# LIMPIEZA 
clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
