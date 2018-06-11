#************************************************************************#
#
# Metodología de la Programación
# ETS Informática y Telecomunicaciones
# Universidad de Granada
# Autor: Jose Luis Gallego Peña
#
# Examen Convocatoria Ordinaria - 14 de Junio de 2017
# Makefile
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
		$(BIN)/examen \
		fin-ejecutables \
		fin

# Main

$(BIN)/examen : $(OBJ)/examen.o $(OBJ)/RedCiudadesExamen.o
	g++ -o $(BIN)/examen $(OBJ)/examen.o $(OBJ)/RedCiudadesExamen.o

$(OBJ)/examen.o : $(SRC)/examen.cpp $(INCLUDE)/RedCiudadesExamen.h
	g++ -c -o $(OBJ)/examen.o $(SRC)/examen.cpp -I$(INCLUDE)

# Clases

$(OBJ)/RedCiudadesExamen.o : $(SRC)/RedCiudadesExamen.cpp \
                             $(INCLUDE)/RedCiudadesExamen.h 
	g++ -c -o $(OBJ)/RedCiudadesExamen.o $(SRC)/RedCiudadesExamen.cpp \
	          -I$(INCLUDE)

# Mensajes

preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Examen Convocatoria Ordinaria - 14 de Junio de 2017
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

	-rm $(OBJ)/examen.o
	-rm $(OBJ)/RedCiudadesExamen.o

	@echo ...Borrados
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/examen

	@echo ...Borrados
	@echo 	

clean-bak : 
	@echo Borrando copias antiguas...

	-rm $(SRC)/*.cpp~
	-rm $(INCLUDE)/*.h~

	@echo ...Borrados
	@echo 	

mrproper : clean clean-bins clean-bak