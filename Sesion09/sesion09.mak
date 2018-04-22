#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas III, Makefile de la sesión 09
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/III_Demo-VectorDinamico_ConstructorCopia \
				  $(BIN)/III_Demo-Matriz2D_1_ConstructorCopia \
				  $(BIN)/III_Demo-Lista_ConstructorCopia 

# Relación de problemas III, Ejercicio 1

$(BIN)/III_Demo-VectorDinamico_ConstructorCopia : \
$(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
$(LIB)/libVectorDinamico_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-VectorDinamico_ConstructorCopia\
	       $(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
	       -L$(LIB) -lVectorDinamico_ConstructorCopia

$(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o : \
$(SRC)/III_Demo-VectorDinamico_ConstructorCopia.cpp \
$(INCLUDE)/VectorDinamico_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-VectorDinamico_ConstructorCopia.o \
	          $(SRC)/III_Demo-VectorDinamico_ConstructorCopia.cpp -I$(INCLUDE)

# Relación de problemas III, Ejercicio 2

$(BIN)/III_Demo-Matriz2D_1_ConstructorCopia : \
$(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
$(LIB)/libMatriz2D_1_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-Matriz2D_1_ConstructorCopia \
			 $(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
			 -L$(LIB) -lMatriz2D_1_ConstructorCopia

$(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o : \
$(SRC)/III_Demo-Matriz2D_1_ConstructorCopia.cpp \
$(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-Matriz2D_1_ConstructorCopia.o \
	          $(SRC)/III_Demo-Matriz2D_1_ConstructorCopia.cpp \
				 -I$(INCLUDE)

# Relación de problemas III, Ejercicio 4

$(BIN)/III_Demo-Lista_ConstructorCopia : \
$(OBJ)/III_Demo-Lista_ConstructorCopia.o $(LIB)/libLista_ConstructorCopia.a
	g++ -o $(BIN)/III_Demo-Lista_ConstructorCopia \
			 $(OBJ)/III_Demo-Lista_ConstructorCopia.o \
			 -L$(LIB) -lLista_ConstructorCopia

$(OBJ)/III_Demo-Lista_ConstructorCopia.o : \
$(SRC)/III_Demo-Lista_ConstructorCopia.cpp $(INCLUDE)/Lista_ConstructorCopia.h
	g++ -c -o $(OBJ)/III_Demo-Lista_ConstructorCopia.o \
				 $(SRC)/III_Demo-Lista_ConstructorCopia.cpp -I$(INCLUDE)

# Clases

$(OBJ)/VectorDinamico_ConstructorCopia.o : \
$(SRC)/VectorDinamico_ConstructorCopia.cpp \
$(INCLUDE)/VectorDinamico_ConstructorCopia.h 
	g++ -c -o $(OBJ)/VectorDinamico_ConstructorCopia.o \
	          $(SRC)/VectorDinamico_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1_ConstructorCopia.o : $(SRC)/Matriz2D_1_ConstructorCopia.cpp \
													$(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $(OBJ)/Matriz2D_1_ConstructorCopia.o \
	          $(SRC)/Matriz2D_1_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/Lista_ConstructorCopia.o : $(SRC)/Lista_ConstructorCopia.cpp \
                                  $(INCLUDE)/Lista_ConstructorCopia.h
	g++ -c -o $(OBJ)/Lista_ConstructorCopia.o $(SRC)/Lista_ConstructorCopia.cpp \
                                  			   -I$(INCLUDE)

# Bibliotecas

$(LIB)/libVectorDinamico_ConstructorCopia.a : \
$(OBJ)/VectorDinamico_ConstructorCopia.o
	ar rvs $(LIB)/libVectorDinamico_ConstructorCopia.a \
	       $(OBJ)/VectorDinamico_ConstructorCopia.o

$(LIB)/libMatriz2D_1_ConstructorCopia.a : $(OBJ)/Matriz2D_1_ConstructorCopia.o
	ar rvs $(LIB)/libMatriz2D_1_ConstructorCopia.a \
	       $(OBJ)/Matriz2D_1_ConstructorCopia.o

$(LIB)/libLista_ConstructorCopia.a : $(OBJ)/Lista_ConstructorCopia.o
	ar rvs $(LIB)/libLista_ConstructorCopia.a $(OBJ)/Lista_ConstructorCopia.o

# LIMPIEZA 

clean : 
	-rm $(OBJ)/* 
	-rm $(LIB)/*

mrproper : clean
	-rm $(BIN)/* 