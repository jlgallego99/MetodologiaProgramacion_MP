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

Matriz2D_1 :: Matriz2D_1()
	:filas(0), 
	columnas(0), 
	matriz(0)
{
}

Matriz2D_1 :: Matriz2D_1(int dimension)
	:filas(dimension),
	columnas(dimension)
{

	ReservaMemoria(dimension, dimension);

}

Matriz2D_1 :: Matriz2D_1(int num_fils, int num_cols)
	:filas(num_fils),
	columnas(num_cols)
{

	ReservaMemoria(num_fils, num_cols);

}

Matriz2D_1 :: Matriz2D_1(int num_fils, int num_cols, TipoBase valor)
	:filas(num_fils),
	columnas(num_cols)
{

	ReservaMemoria(num_fils, num_cols);
	InicializaMatriz(valor);

}

Matriz2D_1 :: Matriz2D_1(const Matriz2D_1 & m){	

	ReservaMemoria(m.filas, m.columnas);
	CopiaMatriz(m);

}

Matriz2D_1 :: ~Matriz2D_1(){

	LiberaMemoria();

}

int Matriz2D_1 :: GetFilas() const{

   return filas;

}

int Matriz2D_1 :: GetColumnas() const{

   return columnas;

}

bool Matriz2D_1 :: MatrizVacia() const{

	return (filas == 0 || columnas == 0);

}

void Matriz2D_1 :: ModificarValor(int fila, int col, TipoBase valor) const{

	matriz[fila][col] = valor;

}

TipoBase Matriz2D_1 :: LeerValor(int fila, int col) const{
	
	return matriz[fila][col];

}

void Matriz2D_1 :: InicializaMatriz(TipoBase valor){

	RellenaMatriz(valor);

}

void Matriz2D_1 :: InicializaMatriz(){

	RellenaMatriz(0);

}

void Matriz2D_1 :: MuestraMatriz() const{

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			cout << matriz[i][j];

		}
		cout << endl;
	}
}

void Matriz2D_1 :: ReservaMemoria(const int num_fils, const int num_cols){
	
	// Primero se crea el vector de punteros
	matriz = new TipoBase * [num_cols];

	// Se crean todas las filas
	for (int i = 0 ; i < num_fils ; i++){

		matriz[i] = new TipoBase [num_cols];

	}
}

void Matriz2D_1 :: LiberaMemoria(){
	
	// Comprobar previamente si la matriz está vací­a
	if (!MatrizVacia()){
		
		// Liberar la memoria ocupada por cada fila
		for (int i = 0 ; i < filas ; i++){

			delete [] matriz[i];

		}

		// Liberar la memoria del vector de punteros
		delete [] matriz;

	}
}

void Matriz2D_1 :: RellenaMatriz(TipoBase valor){

	for (int i = 0 ; i < filas ; i++){
	
		for (int j = 0 ; j < columnas ; j++){

			ModificarValor(i, j, valor);
	
		}
	}
}

void Matriz2D_1 :: CopiaMatriz(const Matriz2D_1 & m){

   filas = m.filas;
   columnas = m.columnas;

	for (int i = 0 ; i < filas ; i++){

		memcpy(matriz[i], m.matriz[i], columnas*sizeof(TipoBase));		

	}
}
