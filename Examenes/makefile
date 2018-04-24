#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Examen prácticas 1 (2016 - 2017)
#
#************************************************************************#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all: $(LIB)/libLista.a $(BIN)/examen1617

$(BIN)/examen1617 : $(OBJ)/examen1617.o $(LIB)/libLista.a
	g++ -o $(BIN)/examen1617 $(OBJ)/examen1617.o -L$(LIB) -lLista

$(OBJ)/examen1617.o : $(SRC)/examen1617.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/examen1617.o $(SRC)/examen1617.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11

$(LIB)/libLista.a : $(OBJ)/Lista.o 
	ar rvs $(LIB)/libLista.a $(OBJ)/Lista.o 

clean: 
	-rm $(OBJ)/*
	-rm $(LIB)/*

mrproper: clean
	-rm $(BIN)/*