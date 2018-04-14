#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas II, Makefile de la sesión 07
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all: mrproper $(BIN)/II_Demo-Matriz2D_1 \
              $(BIN)/II_ProblemaAsignacion \
				  $(BIN)/II_ProblemaViajanteComercio

# Relación de problemas II, Ejercicio 6

$(BIN)/II_Demo-Matriz2D_1 : $(OBJ)/II_Demo-Matriz2D_1.o $(OBJ)/Matriz2D_1.o \
                            $(OBJ)/VectorAleatorio.o
	g++ -o $(BIN)/II_Demo-Matriz2D_1 $(OBJ)/II_Demo-Matriz2D_1.o \
	       $(OBJ)/Matriz2D_1.o $(OBJ)/VectorAleatorio.o

$(OBJ)/II_Demo-Matriz2D_1.o : $(SRC)/II_Demo-Matriz2D_1.cpp \
                              $(INCLUDE)/Matriz2D_1.h \
										$(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/II_Demo-Matriz2D_1.o $(SRC)/II_Demo-Matriz2D_1.cpp \
              -I$(INCLUDE)

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h \
                      $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/VectorAleatorio.o : $(SRC)/VectorAleatorio.cpp $(INCLUDE)/VectorAleatorio.h
	g++ -c -o $(OBJ)/VectorAleatorio.o $(SRC)/VectorAleatorio.cpp -I$(INCLUDE)

# Relación de problemas II, Ejercicio 9

$(BIN)/II_ProblemaAsignacion : $(OBJ)/II_ProblemaAsignacion.o \
                               $(OBJ)/Matriz2D_1.o \
										 $(OBJ)/VectorAleatorio.o
	g++ -o $(BIN)/II_ProblemaAsignacion $(OBJ)/II_ProblemaAsignacion.o \
	       $(OBJ)/Matriz2D_1.o $(OBJ)/VectorAleatorio.o

$(OBJ)/II_ProblemaAsignacion.o : $(SRC)/II_ProblemaAsignacion.cpp \
                              	$(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/II_ProblemaAsignacion.o $(SRC)/II_ProblemaAsignacion.cpp \
	          -I$(INCLUDE)

# Relación de problemas II, Ejercicio 10

$(BIN)/II_ProblemaViajanteComercio : $(OBJ)/II_ProblemaViajanteComercio.o \
                                     $(OBJ)/Matriz2D_1.o \
										       $(OBJ)/VectorAleatorio.o
	g++ -o $(BIN)/II_ProblemaViajanteComercio \
	       $(OBJ)/II_ProblemaViajanteComercio.o \
	       $(OBJ)/Matriz2D_1.o $(OBJ)/VectorAleatorio.o

$(OBJ)/II_ProblemaViajanteComercio.o : $(SRC)/II_ProblemaViajanteComercio.cpp \
                              	      $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/II_ProblemaViajanteComercio.o \
	          $(SRC)/II_ProblemaViajanteComercio.cpp \
	          -I$(INCLUDE)

# LIMPIEZA 

clean : 
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/*