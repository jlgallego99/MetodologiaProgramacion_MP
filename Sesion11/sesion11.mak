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

all : preambulo \
		mrproper \
		ejecutables \
		$(BIN)/CopiaTodo \
		$(BIN)/CopiaExceptoVocales \
		$(BIN)/CuentaCaracteres \
		$(BIN)/CuentaLineasNoVacias-peek \
		$(BIN)/MuestraLineasNoVacias \
		$(BIN)/ComprimeLineas \
		$(BIN)/CopiaLineasSinAlmohadilla \
		$(BIN)/CopiaEnteros \
		$(BIN)/CopiaEnterosSeparados \
		$(BIN)/SumaEnteros \
		$(BIN)/CuentaCaracteresConcretos \
		$(BIN)/CuentaPalabrasLongitudConcreta \
		fin-ejecutables \
		fin

# Relación de problemas V, Ejercicio 1

$(BIN)/CopiaTodo : $(OBJ)/CopiaTodo.o 
	g++ -o $(BIN)/CopiaTodo $(OBJ)/CopiaTodo.o 

$(OBJ)/CopiaTodo.o : $(SRC)/CopiaTodo.cpp
	g++ -c -o $(OBJ)/CopiaTodo.o $(SRC)/CopiaTodo.cpp

# Relación de problemas V, Ejercicio 2

$(BIN)/CopiaExceptoVocales : $(OBJ)/CopiaExceptoVocales.o 
	g++ -o $(BIN)/CopiaExceptoVocales $(OBJ)/CopiaExceptoVocales.o 

$(OBJ)/CopiaExceptoVocales.o : $(SRC)/CopiaExceptoVocales.cpp
	g++ -c -o $(OBJ)/CopiaExceptoVocales.o $(SRC)/CopiaExceptoVocales.cpp

# Relación de problemas V, Ejercicio 3

$(BIN)/CuentaCaracteres : $(OBJ)/CuentaCaracteres.o 
	g++ -o $(BIN)/CuentaCaracteres $(OBJ)/CuentaCaracteres.o 

$(OBJ)/CuentaCaracteres.o : $(SRC)/CuentaCaracteres.cpp
	g++ -c -o $(OBJ)/CuentaCaracteres.o $(SRC)/CuentaCaracteres.cpp

# Relación de problemas V, Ejercicio 4

$(BIN)/CuentaLineasNoVacias-peek : $(OBJ)/CuentaLineasNoVacias-peek.o 
	g++ -o $(BIN)/CuentaLineasNoVacias-peek $(OBJ)/CuentaLineasNoVacias-peek.o 

$(OBJ)/CuentaLineasNoVacias-peek.o : $(SRC)/CuentaLineasNoVacias-peek.cpp
	g++ -c -o $(OBJ)/CuentaLineasNoVacias-peek.o \
	          $(SRC)/CuentaLineasNoVacias-peek.cpp

# Relación de problemas V, Ejercicio 5

$(BIN)/MuestraLineasNoVacias : $(OBJ)/MuestraLineasNoVacias.o 
	g++ -o $(BIN)/MuestraLineasNoVacias $(OBJ)/MuestraLineasNoVacias.o 

$(OBJ)/MuestraLineasNoVacias.o : $(SRC)/MuestraLineasNoVacias.cpp
	g++ -c -o $(OBJ)/MuestraLineasNoVacias.o $(SRC)/MuestraLineasNoVacias.cpp

# Relación de problemas V, Ejercicio 6

$(BIN)/ComprimeLineas : $(OBJ)/ComprimeLineas.o 
	g++ -o $(BIN)/ComprimeLineas $(OBJ)/ComprimeLineas.o 

$(OBJ)/ComprimeLineas.o : $(SRC)/ComprimeLineas.cpp
	g++ -c -o $(OBJ)/ComprimeLineas.o $(SRC)/ComprimeLineas.cpp

# Relación de problemas V, Ejercicio 7

$(BIN)/CopiaLineasSinAlmohadilla : $(OBJ)/CopiaLineasSinAlmohadilla.o 
	g++ -o $(BIN)/CopiaLineasSinAlmohadilla $(OBJ)/CopiaLineasSinAlmohadilla.o 

$(OBJ)/CopiaLineasSinAlmohadilla.o : $(SRC)/CopiaLineasSinAlmohadilla.cpp
	g++ -c -o $(OBJ)/CopiaLineasSinAlmohadilla.o \
	          $(SRC)/CopiaLineasSinAlmohadilla.cpp

# Relación de problemas V, Ejercicio 8

$(BIN)/CopiaEnteros : $(OBJ)/CopiaEnteros.o 
	g++ -o $(BIN)/CopiaEnteros $(OBJ)/CopiaEnteros.o 

$(OBJ)/CopiaEnteros.o : $(SRC)/CopiaEnteros.cpp
	g++ -c -o $(OBJ)/CopiaEnteros.o $(SRC)/CopiaEnteros.cpp

# Relación de problemas V, Ejercicio 10

$(BIN)/CopiaEnterosSeparados : $(OBJ)/CopiaEnterosSeparados.o 
	g++ -o $(BIN)/CopiaEnterosSeparados $(OBJ)/CopiaEnterosSeparados.o 

$(OBJ)/CopiaEnterosSeparados.o : $(SRC)/CopiaEnterosSeparados.cpp
	g++ -c -o $(OBJ)/CopiaEnterosSeparados.o $(SRC)/CopiaEnterosSeparados.cpp

# Relación de problemas V, Ejercicio 11

$(BIN)/SumaEnteros : $(OBJ)/SumaEnteros.o 
	g++ -o $(BIN)/SumaEnteros $(OBJ)/SumaEnteros.o 

$(OBJ)/SumaEnteros.o : $(SRC)/SumaEnteros.cpp
	g++ -c -o $(OBJ)/SumaEnteros.o $(SRC)/SumaEnteros.cpp

# Relación de problemas V, Ejercicio 12

$(BIN)/CuentaCaracteresConcretos : $(OBJ)/CuentaCaracteresConcretos.o 
	g++ -o $(BIN)/CuentaCaracteresConcretos $(OBJ)/CuentaCaracteresConcretos.o 

$(OBJ)/CuentaCaracteresConcretos.o : $(SRC)/CuentaCaracteresConcretos.cpp
	g++ -c -o $(OBJ)/CuentaCaracteresConcretos.o \
	          $(SRC)/CuentaCaracteresConcretos.cpp

# Relación de problemas V, Ejercicio 13

$(BIN)/CuentaPalabrasLongitudConcreta : $(OBJ)/CuentaPalabrasLongitudConcreta.o 
	g++ -o $(BIN)/CuentaPalabrasLongitudConcreta \
	       $(OBJ)/CuentaPalabrasLongitudConcreta.o 

$(OBJ)/CuentaPalabrasLongitudConcreta.o : $(SRC)/CuentaPalabrasLongitudConcreta.cpp
	g++ -c -o $(OBJ)/CuentaPalabrasLongitudConcreta.o \
	          $(SRC)/CuentaPalabrasLongitudConcreta.cpp


# Mensajes

preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Relación de problemas V
	@echo Sesion 11
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

	-rm $(OBJ)/CopiaTodo.o
	-rm $(OBJ)/CopiaExceptoVocales.o
	-rm $(OBJ)/CuentaCaracteres.o
	-rm $(OBJ)/CuentaLineasNoVacias-peek.o
	-rm $(OBJ)/MuestraLineasNoVacias.o
	-rm $(OBJ)/ComprimeLineas.o
	-rm $(OBJ)/CopiaLineasSinAlmohadilla.o
	-rm $(OBJ)/CopiaEnteros.o
	-rm $(OBJ)/CopiaEnterosSeparados.o
	-rm $(OBJ)/SumaEnteros.o
	-rm $(OBJ)/CuentaCaracteresConcretos.o
	-rm $(OBJ)/CuentaPalabrasLongitudConcreta.o

	@echo ...Borrados
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/CopiaTodo
	-rm $(BIN)/CopiaExceptoVocales
	-rm $(BIN)/CuentaCaracteres
	-rm $(BIN)/CuentaLineasNoVacias-peek
	-rm $(BIN)/MuestraLineasNoVacias
	-rm $(BIN)/ComprimeLineas
	-rm $(BIN)/CopiaLineasSinAlmohadilla
	-rm $(BIN)/CopiaEnteros
	-rm $(BIN)/CopiaEnterosSeparados
	-rm $(BIN)/SumaEnteros
	-rm $(BIN)/CuentaCaracteresConcretos
	-rm $(BIN)/CuentaPalabrasLongitudConcreta

	@echo ...Borrados
	@echo 	

clean-bak : 
	@echo Borrando copias antiguas...

	-rm $(SRC)/*.cpp~
	-rm $(INCLUDE)/*.h~

	@echo ...Borrados
	@echo 	

mrproper : clean clean-bins clean-bak