#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Relación de problemas VI, Makefile de la sesión 12
#
#************************************************************************#

HOME = .
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib

all : preambulo \
		mrproper \
		ejecutables \
		$(BIN)/NumeraLineas \
		$(BIN)/MezclaFichero \
		$(BIN)/VI_Demo-Lista-ES \
		$(BIN)/VI_Demo-Matriz-ES \
		$(BIN)/VI_Demo-Matriz-ES-Alt \
		$(BIN)/VI_Demo-ColeccionPuntos \
		$(BIN)/InfoPGM \
		fin-ejecutables \
		fin

# Relación de problemas VI, Ejercicio 1

$(BIN)/NumeraLineas : $(OBJ)/NumeraLineas.o 
	g++ -o $(BIN)/NumeraLineas $(OBJ)/NumeraLineas.o

$(OBJ)/NumeraLineas.o : $(SRC)/NumeraLineas.cpp
	g++ -c -o $(OBJ)/NumeraLineas.o $(SRC)/NumeraLineas.cpp

# Relación de problemas VI, Ejercicio 3

$(BIN)/MezclaFichero : $(OBJ)/MezclaFichero.o
	g++ -o $(BIN)/MezclaFichero $(OBJ)/MezclaFichero.o

$(OBJ)/MezclaFichero.o : $(SRC)/MezclaFichero.cpp
	g++ -c -o $(OBJ)/MezclaFichero.o $(SRC)/MezclaFichero.cpp

# Relación de problemas VI, Ejercicio 6

$(BIN)/VI_Demo-Lista-ES : $(OBJ)/VI_Demo-Lista-ES.o $(OBJ)/Lista.o \
                          $(OBJ)/CuentaLineasFichero.o
	g++ -o $(BIN)/VI_Demo-Lista-ES $(OBJ)/VI_Demo-Lista-ES.o $(OBJ)/Lista.o \
			 $(OBJ)/CuentaLineasFichero.o

$(OBJ)/VI_Demo-Lista-ES.o : $(SRC)/VI_Demo-Lista-ES.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/VI_Demo-Lista-ES.o $(SRC)/VI_Demo-Lista-ES.cpp -I$(INCLUDE)

# Relación de problemas VI, Ejercicio 7

$(BIN)/VI_Demo-Matriz-ES : $(OBJ)/VI_Demo-Matriz-ES.o $(OBJ)/Matriz2D_1.o
	g++ -o $(BIN)/VI_Demo-Matriz-ES $(OBJ)/VI_Demo-Matriz-ES.o \
	       $(OBJ)/Matriz2D_1.o

$(OBJ)/VI_Demo-Matriz-ES.o : $(SRC)/VI_Demo-Matriz-ES.cpp \
                             $(INCLUDE)/Matriz2D_1.h 
	g++ -c -o $(OBJ)/VI_Demo-Matriz-ES.o $(SRC)/VI_Demo-Matriz-ES.cpp \
	          -I$(INCLUDE)

# Relación de problemas VI, Ejercicio 8

$(BIN)/VI_Demo-Matriz-ES-Alt : $(OBJ)/VI_Demo-Matriz-ES-Alt.o \
                               $(OBJ)/Matriz2D_1_FicheroSinCabecera_sstream.o
	g++ -o $(BIN)/VI_Demo-Matriz-ES-Alt $(OBJ)/VI_Demo-Matriz-ES-Alt.o \
	       $(OBJ)/Matriz2D_1_FicheroSinCabecera_sstream.o

$(OBJ)/VI_Demo-Matriz-ES-Alt.o : $(SRC)/VI_Demo-Matriz-ES-Alt.cpp \
$(INCLUDE)/Matriz2D_1_FicheroSinCabecera_sstream.h
	g++ -c -o $(OBJ)/VI_Demo-Matriz-ES-Alt.o $(SRC)/VI_Demo-Matriz-ES-Alt.cpp \
		       -I$(INCLUDE)

# Relación de problemas VI, Ejercicio 9

$(BIN)/VI_Demo-ColeccionPuntos : $(OBJ)/VI_Demo-ColeccionPuntos.o \
                                 $(OBJ)/ColeccionPuntos2D.o
	g++ -o $(BIN)/VI_Demo-ColeccionPuntos $(OBJ)/VI_Demo-ColeccionPuntos.o \
          $(OBJ)/ColeccionPuntos2D.o

$(OBJ)/VI_Demo-ColeccionPuntos.o : $(SRC)/VI_Demo-ColeccionPuntos.cpp \
                                   $(INCLUDE)/ColeccionPuntos2D.h
	g++ -c -o $(OBJ)/VI_Demo-ColeccionPuntos.o $(SRC)/VI_Demo-ColeccionPuntos.cpp \
	          -I$(INCLUDE)

# Relación de problemas VI, Ejercicio 17

$(BIN)/InfoPGM : $(OBJ)/InfoPGM.o
	g++ -o $(BIN)/InfoPGM $(OBJ)/InfoPGM.o

$(OBJ)/InfoPGM.o : $(SRC)/InfoPGM.cpp
	g++ -c -o $(OBJ)/InfoPGM.o $(SRC)/InfoPGM.cpp

# Funciones

$(OBJ)/CuentaLineasFichero.o : $(SRC)/CuentaLineasFichero.cpp 
	g++ -c -o $(OBJ)/CuentaLineasFichero.o $(SRC)/CuentaLineasFichero.cpp 

# Clases

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h \
                 $(INCLUDE)/CuentaLineasFichero.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1_FicheroSinCabecera_sstream.o : \
$(SRC)/Matriz2D_1_FicheroSinCabecera_sstream.cpp \
$(INCLUDE)/Matriz2D_1_FicheroSinCabecera_sstream.h
	g++ -c -o $(OBJ)/Matriz2D_1_FicheroSinCabecera_sstream.o \
	          $(SRC)/Matriz2D_1_FicheroSinCabecera_sstream.cpp \
             -I$(INCLUDE)

$(OBJ)/ColeccionPuntos2D.o : $(SRC)/ColeccionPuntos2D.cpp \
                           $(INCLUDE)/ColeccionPuntos2D.h
	g++ -c -o $(OBJ)/ColeccionPuntos2D.o $(SRC)/ColeccionPuntos2D.cpp -I$(INCLUDE)

# Mensajes

preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Relación de problemas VI
	@echo Sesion 12
	@echo
	@echo Metodología de la Programación
	@echo ETS Informática y Telecomunicaciones. Universidad de Granada
	@echo
	@echo Autor: Jose Luis Gallego Peña
	@echo ------------------------------------------------------------
	@echo

ejecutables:
	@echo Creando ejecutables...

fin-ejecutables:
	@echo ...Creados
	@echo 	

fin :
	@echo
	@echo Todo listo

# LIMPIEZA 

clean : clean-objs

clean-objs : 
	@echo Borrando objetos...

	-rm $(OBJ)/NumeraLineas.o
	-rm $(OBJ)/MezclaFichero.o
	-rm $(OBJ)/VI_Demo-Lista-ES.o
	-rm $(OBJ)/VI_Demo-Matriz-ES.o
	-rm $(OBJ)/VI_Demo-Matriz-ES-Alt.o
	-rm $(OBJ)/VI_Demo-ColeccionPuntos.o
	-rm $(OBJ)/InfoPGM.o

	@echo ...Borrados
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/NumeraLineas
	-rm $(BIN)/MezclaFichero
	-rm $(BIN)/VI_Demo-Lista-ES
	-rm $(BIN)/VI_Demo-Matriz-ES
	-rm $(BIN)/VI_Demo-Matriz-ES-Alt
	-rm $(BIN)/VI_Demo-ColeccionPuntos
	-rm $(BIN)/InfoPGM

	@echo ...Borrados
	@echo 	

clean-bak : 
	@echo Borrando copias antiguas...

	-rm $(SRC)/*.cpp~
	-rm $(INCLUDE)/*.h~

	@echo ...Borrados
	@echo 	

mrproper : clean clean-bins clean-bak