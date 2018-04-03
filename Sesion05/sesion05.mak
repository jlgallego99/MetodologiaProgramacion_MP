#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas I, Makefile de la sesión 05
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/I_MaxMin_Array \
			     $(BIN)/I_LeeEntero \
				  $(BIN)/I_PosMayor \
              $(BIN)/I_MezclaArrays \
				  $(BIN)/I_Sucursales_Matriz_Clasica

# Ejercicio 16

$(BIN)/I_LeeEntero : $(OBJ)/I_LeeEntero.o $(OBJ)/LeeEntero.o 
	g++ -g -o $(BIN)/I_LeeEntero $(OBJ)/I_LeeEntero.o $(OBJ)/LeeEntero.o 

$(OBJ)/I_LeeEntero.o : $(SRC)/I_LeeEntero.cpp $(INCLUDE)/LeeEntero.h 
	g++ -g -c -o $(OBJ)/I_LeeEntero.o $(SRC)/I_LeeEntero.cpp -I$(INCLUDE)

$(OBJ)/LeeEntero.o : $(SRC)/LeeEntero.cpp $(INCLUDE)/LeeEntero.h
	g++ -g -c -o $(OBJ)/LeeEntero.o $(SRC)/LeeEntero.cpp -I$(INCLUDE)


# Ejercicio 17

$(BIN)/I_MaxMin_Array : $(OBJ)/I_MaxMin_Array.o $(OBJ)/MaximoMinimo.o \
                        $(OBJ)/VectorAleatorio.o
	g++ -o $(BIN)/I_MaxMin_Array $(OBJ)/I_MaxMin_Array.o $(OBJ)/MaximoMinimo.o \
	       $(OBJ)/VectorAleatorio.o

$(OBJ)/I_MaxMin_Array.o : $(SRC)/I_MaxMin_Array.cpp $(INCLUDE)/MaximoMinimo.h \
                          $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/I_MaxMin_Array.o $(SRC)/I_MaxMin_Array.cpp -I$(INCLUDE)

$(OBJ)/MaximoMinimo.o : $(SRC)/MaximoMinimo.cpp $(INCLUDE)/MaximoMinimo.h
	g++ -c -o $(OBJ)/MaximoMinimo.o $(SRC)/MaximoMinimo.cpp -I$(INCLUDE)

$(OBJ)/VectorAleatorio.o : $(SRC)/VectorAleatorio.cpp $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/VectorAleatorio.o $(SRC)/VectorAleatorio.cpp -I$(INCLUDE)

# Ejercicio 18

$(BIN)/I_PosMayor : $(OBJ)/I_PosMayor.o $(OBJ)/PosMayor.o \
                    $(OBJ)/VectorAleatorio.o 
	g++ -o $(BIN)/I_PosMayor $(OBJ)/I_PosMayor.o $(OBJ)/PosMayor.o \
          $(OBJ)/VectorAleatorio.o 

$(OBJ)/I_PosMayor.o : $(SRC)/I_PosMayor.cpp $(INCLUDE)/PosMayor.h \
                      $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/I_PosMayor.o $(SRC)/I_PosMayor.cpp -I$(INCLUDE)

$(OBJ)/PosMayor.o : $(SRC)/PosMayor.cpp $(INCLUDE)/PosMayor.h
	g++ -c -o $(OBJ)/PosMayor.o $(SRC)/PosMayor.cpp -I$(INCLUDE)

# Ejercicio 20

$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o $(OBJ)/RellenaVector.o \
                        $(OBJ)/MuestraVector.o $(OBJ)/MezclaVectores.o \
								$(OBJ)/OrdenaVector.o $(OBJ)/VectorAleatorio.o
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o $(OBJ)/RellenaVector.o \
          $(OBJ)/MuestraVector.o $(OBJ)/MezclaVectores.o $(OBJ)/OrdenaVector.o \
			 $(OBJ)/VectorAleatorio.o

$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp $(INCLUDE)/RellenaVector.h \
                          $(INCLUDE)/MuestraVector.h $(INCLUDE)/MezclaVectores.h
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp -I$(INCLUDE)

$(OBJ)/RellenaVector.o : $(SRC)/RellenaVector.cpp $(INCLUDE)/RellenaVector.h \
                         $(INCLUDE)/OrdenaVector.h $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/RellenaVector.o $(SRC)/RellenaVector.cpp -I$(INCLUDE)

$(OBJ)/MuestraVector.o : $(SRC)/MuestraVector.cpp $(INCLUDE)/MuestraVector.h
	g++ -c -o $(OBJ)/MuestraVector.o $(SRC)/MuestraVector.cpp -I$(INCLUDE)

$(OBJ)/MezclaVectores.o : $(SRC)/MezclaVectores.cpp $(INCLUDE)/MezclaVectores.h \
                          $(INCLUDE)/OrdenaVector.h
	g++ -c -o $(OBJ)/MezclaVectores.o $(SRC)/MezclaVe/ctores.cpp -I$(INCLUDE)

$(OBJ)/OrdenaVector.o : $(SRC)/OrdenaVector.cpp $(INCLUDE)/OrdenaVector.h
	g++ -c -o $(OBJ)/OrdenaVector.o $(SRC)/OrdenaVector.cpp -I$(INCLUDE)

# Ejercicio 21

$(BIN)/I_Sucursales_Matriz_Clasica : $(OBJ)/I_Sucursales_Matriz_Clasica.o 
	g++ -o $(BIN)/I_Sucursales_Matriz_Clasica $(OBJ)/I_Sucursales_Matriz_Clasica.o 

$(OBJ)/I_Sucursales_Matriz_Clasica.o : $(SRC)/I_Sucursales_Matriz_Clasica.cpp
	g++ -c -o $(OBJ)/I_Sucursales_Matriz_Clasica.o \
	          $(SRC)/I_Sucursales_Matriz_Clasica.cpp

# LIMPIEZA 
clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*
