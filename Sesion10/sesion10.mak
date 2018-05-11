#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas IV, Makefile de la sesión 10
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper \
	  $(BIN)/IV_Demo-Matriz2D_1_Todo \
	  $(BIN)/IV_Demo-Lista_Todo.cpp \
	  $(BIN)/IV_Demo-RedCiudades \
	  $(BIN)/IV_Demo-PoliLinea

# Relación de problemas IV, Ejercicio 2

$(BIN)/IV_Demo-Matriz2D_1_Todo : $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
$(LIB)/libMatriz2D_1.a
	g++ -o $(BIN)/IV_Demo-Matriz2D_1_Todo $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
	       -L$(LIB) -lMatriz2D_1

$(OBJ)/IV_Demo-Matriz2D_1_Todo.o : $(SRC)/IV_Demo-Matriz2D_1_Todo.cpp \
$(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/IV_Demo-Matriz2D_1_Todo.o \
	          $(SRC)/IV_Demo-Matriz2D_1_Todo.cpp -I$(INCLUDE)

# Relación de problemas IV, Ejercicio 4

$(BIN)/IV_Demo-Lista_Todo.cpp : $(OBJ)/IV_Demo-Lista_Todo.o $(LIB)/libLista.a
	g++ -o $(BIN)/IV_Demo-Lista_Todo.cpp $(OBJ)/IV_Demo-Lista_Todo.o \
	       -L$(LIB) -lLista

$(OBJ)/IV_Demo-Lista_Todo.o : $(SRC)/IV_Demo-Lista_Todo.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/IV_Demo-Lista_Todo.o $(SRC)/IV_Demo-Lista_Todo.cpp \
	          -I$(INCLUDE)

# Relación de problemas IV, Ejercicio 9

$(BIN)/IV_Demo-PoliLinea : $(OBJ)/IV_Demo-PoliLinea.o $(LIB)/libPoliLinea.a
	g++ -o $(BIN)/IV_Demo-PoliLinea $(OBJ)/IV_Demo-PoliLinea.o \
	       -L$(LIB) -lPoliLinea

$(OBJ)/IV_Demo-PoliLinea.o : $(SRC)/IV_Demo-PoliLinea.cpp $(INCLUDE)/PoliLinea.h
	g++ -c -o $(OBJ)/IV_Demo-PoliLinea.o $(SRC)/IV_Demo-PoliLinea.cpp \
	          -I$(INCLUDE)

# Relación de problemas IV, Ejercicio 11

$(BIN)/IV_Demo-RedCiudades : $(OBJ)/IV_Demo-RedCiudades.o \
                             $(LIB)/libRedCiudades.a
	g++ -o $(BIN)/IV_Demo-RedCiudades $(OBJ)/IV_Demo-RedCiudades.o \
	       -L$(LIB) -lRedCiudades

$(OBJ)/IV_Demo-RedCiudades.o : $(SRC)/IV_Demo-RedCiudades.cpp \
                               $(INCLUDE)/RedCiudades.h
	g++ -c -o $(OBJ)/IV_Demo-RedCiudades.o $(SRC)/IV_Demo-RedCiudades.cpp \
             -I$(INCLUDE)

# Clases

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)

$(OBJ)/PoliLinea.o : $(SRC)/PoliLinea.cpp $(INCLUDE)/PoliLinea.h
	g++ -c -o $(OBJ)/PoliLinea.o $(SRC)/PoliLinea.cpp -I$(INCLUDE)

$(OBJ)/RedCiudades.o : $(SRC)/RedCiudades.cpp $(INCLUDE)/RedCiudades.h
	g++ -c -o $(OBJ)/RedCiudades.o $(SRC)/RedCiudades.cpp -I$(INCLUDE)

# Bibliotecas

$(LIB)/libMatriz2D_1.a : $(OBJ)/Matriz2D_1.o
	ar rvs $(LIB)/libMatriz2D_1.a $(OBJ)/Matriz2D_1.o

$(LIB)/libLista.a : $(OBJ)/Lista.o
	ar rvs $(LIB)/libLista.a $(OBJ)/Lista.o

$(LIB)/libPoliLinea.a : $(OBJ)/PoliLinea.o
	ar rvs $(LIB)/libPoliLinea.a $(OBJ)/PoliLinea.o

$(LIB)/libRedCiudades.a : $(OBJ)/RedCiudades.o
	ar rvs $(LIB)/libRedCiudades.a $(OBJ)/RedCiudades.o

# LIMPIEZA 

clean : 
	-rm $(OBJ)/* 
	-rm $(LIB)/*

mrproper : clean
	-rm $(BIN)/* 