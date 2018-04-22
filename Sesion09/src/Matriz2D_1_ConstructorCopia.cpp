//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Definición de la clase "Matriz2D_1"
//
// Clase que trabaja con matrices dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "Matriz2D_1_ConstructorCopia.h"

using namespace std;

// a) Constructor sin argumentos: 
// Crea una matriz vacía
Matriz2D_1 :: Matriz2D_1(){

	filas = 0;
	columnas = 0;

}

// b) Constructor con un argumento: 
// Crea una matriz cuadrada con el número de filas y columnas del argumento
Matriz2D_1 :: Matriz2D_1(int filscols){

	filas = filscols;
	columnas = filscols;

	ReservaMemoria();

}

// c) Constructor con dos argumentos:
// Crea una matriz con el número de filas indicado en el primer argumento 
// y el número de columnas indicado en el segundo
Matriz2D_1 :: Matriz2D_1(int fils, int cols){

	filas = fils;
	columnas = cols;

	ReservaMemoria();

}

// d) Constructor con tres argumentos:
// Crea una matriz con el número de filas indicado en el primer argumento,
// el número de columnas indicado en el segundo e iniciando todas las casillas
// al valor especificado en el tercero
Matriz2D_1 :: Matriz2D_1(int fils, int cols, TipoBase valor){

	filas = fils;
	columnas = cols;

	ReservaMemoria();

	InicializaMatriz(valor);

}

// e) Constructor de copia
Matriz2D_1 :: Matriz2D_1(const Matriz2D_1 & m){
	
	filas = m.filas;
	columnas = m.columnas;

	ReservaMemoria();

	CopiaMatriz(m);

}

// f) Destructor
Matriz2D_1 :: ~Matriz2D_1(){

	LiberaMemoria();

}

// g) Consulta si la matriz está vací­a
bool Matriz2D_1 :: EstaVacia(){

	return (filas == 0 || columnas == 0);

}

// h) Escribir/Leer un valor
void Matriz2D_1 :: ModificarValor(int fila, int col, TipoBase valor){

	// Comprueba que la fila y columna son correctas
	if (fila < filas && col < columnas){

		matriz[fila][col] = valor;

	}
}

TipoBase Matriz2D_1 :: LeerValor(int fila, int col) const{
	
	// Comprueba que la fila y columna son correctas
	if (fila < filas && col < columnas){

		return matriz[fila][col];

	}
}

// i) Inicializa todas las casillas de la matriz al valor del argumento
// Si no se especifica ninguno, inicia todas las casillas al valor nulo
void Matriz2D_1 :: InicializaMatriz(TipoBase valor){

	RellenaMatriz(valor);

}

void Matriz2D_1 :: InicializaMatriz(){

	RellenaMatriz(0);

}

// Reserva memoria para una matriz
void Matriz2D_1 :: ReservaMemoria(){
	
	// Se comprueba si los datos son correctos 
	// (no tiene sentido filas y columnas negativas)
	if (filas > 0 && columnas > 0){
		// Se crea el vector de punteros
		matriz = new TipoBase * [columnas];

		// Se crean todas las filas
		for (int i = 0 ; i < filas ; i++){

			matriz[i] = new TipoBase [columnas];

		}
	
	}
}

// Libera la memoria de una matriz
void Matriz2D_1 :: LiberaMemoria(){
	
	// Comprobar previamente si la matriz está vací­a
	if (!EstaVacia()){
		
		// Liberar la memoria ocupada por cada fila
		for (int i = 0 ; i < filas ; i++){

			delete [] matriz[i];

		}

		// Liberar la memoria del vector de punteros
		delete [] matriz;

	}

}

// Rellena una matriz por completo a un valor
void Matriz2D_1 :: RellenaMatriz(TipoBase valor){

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			ModificarValor(i, j, valor);
	
		}
	}
}

// Copia una matriz en otra
void Matriz2D_1 :: CopiaMatriz(const Matriz2D_1 & m){

	for (int i = 0 ; i < filas ; i++){

		memcpy(matriz[i], m.matriz[i], columnas*sizeof(TipoBase));		

	}
}

// Muestra por completo una matriz
void Matriz2D_1 :: MuestraMatriz(){

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			cout << matriz[i][j];

		}
		cout << endl;
	}
}