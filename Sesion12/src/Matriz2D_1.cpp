//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI
// Definición de la clase "Matriz2D_1"
//
// Clase que trabaja con matrices dinámicas de datos de tipo TipoBase
//
// PRECONDICIONES: 
// Filas y columnas positivas y correctas
// Cada dato del fichero está en una línea
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include <fstream>
#include "Matriz2D_1.h"
using namespace std;

/*************************************************************************/
// Métodos públicos

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

Matriz2D_1 :: Matriz2D_1(const char * nombre){

	ifstream fi;      // Flujo de entrada del fichero
   fi.open(nombre);  // Asociar el flujo de entrada al fichero
   TipoBase n;       // Valor de cada línea del fichero

   // El primer dato es el número de filas
	fi >> n;
	filas = n;

	// El segundo dato es el número de columnas
	fi >> n;
	columnas = n;

	// Memoria para la matriz
	ReservaMemoria(filas, columnas);

	// El resto de datos se introducen en la matriz
	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			fi >> n;
			ModificarValor(i, j, n);

		}
	}

   fi.close(); // Desasociar el flujo de entrada del fichero

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

void Matriz2D_1 :: EscribirMatriz2D_1(const char * nombre) const{

	ofstream fo;      // Flujo de salida del fichero
   fo.open(nombre);  // Asociar el flujo de salida al fichero

   for (int i = 0 ; i < filas ; i++){

      for (int j = 0 ; j < columnas ; j++){

			
			fo << matriz[i][j] << " ";

		}

		fo << endl;

   }

   fo.close(); // Desasociar el flujo de salida del fichero

}

void Matriz2D_1 :: LeerMatriz2D_1(const char * nombre){

	ifstream fi;      // Flujo de entrada del fichero
   fi.open(nombre);  // Asociar el flujo de entrada al fichero
   TipoBase n;       // Valor de cada línea del fichero

	// El resto de datos se introducen en la matriz
	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			fi >> n;
			ModificarValor(i, j, n);

		}
	}

   fi.close(); // Desasociar el flujo de entrada del fichero

}

/*************************************************************************/
// Sobrecarga de operadores

Matriz2D_1 & Matriz2D_1 :: operator = (const Matriz2D_1 & m){

	if (this != &m){	// Evitar autoasignación
		
		// Si la matriz no está vacía, se libera su memoria
		if (!MatrizVacia()){

			LiberaMemoria();

		}
		
		// Memoria para la nueva matriz copia
		ReservaMemoria(m.filas, m.columnas);
		
		// Se copia la matriz
		CopiaMatriz(m);
		
	}
	
	// Devuelve una referencia al objeto implícito: izquierda de la asignación
	return (*this);	

}

Matriz2D_1 & Matriz2D_1 :: operator = (TipoBase valor){

	InicializaMatriz(valor);

	return (*this);

}

TipoBase & Matriz2D_1 :: operator () (const int fil, const int col){

	return matriz[fil][col];

}

Matriz2D_1 Matriz2D_1 :: operator + (){

	return (*this);

}

Matriz2D_1 Matriz2D_1 :: operator - (){

	// Matriz local para el resultado
	Matriz2D_1 m (filas, columnas);

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			m.ModificarValor(i, j, (-matriz[i][j]));

		}
	}

	return m;
}

Matriz2D_1 Matriz2D_1 :: operator + (const Matriz2D_1 & m){

	Matriz2D_1 suma (m.filas, m.columnas);	// Matriz suma
	
	// Sólo se realiza la operación si las dos matrices tienen la misma dimensión
	if (*this == m){

		for (int i = 0 ; i < filas ; i++){

			for (int j = 0 ; j < columnas ; j++){

				TipoBase valor = matriz[i][j] + m.matriz[i][j];
				suma.ModificarValor(i, j, valor);

			}
		}
	}

	return suma;

}

Matriz2D_1 Matriz2D_1 :: operator + (const TipoBase valor){

	Matriz2D_1 suma (filas, columnas);

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			TipoBase v = matriz[i][j] + valor;
			suma.ModificarValor(i, j, v);

		}
	}

	return suma;
}

Matriz2D_1 Matriz2D_1 :: operator - (const Matriz2D_1 & m){

	Matriz2D_1 resta (m.filas, m.columnas);	// Matriz resta

	// Sólo se realiza la operación si las dos matrices tienen la misma dimensión
	if (*this == m){

		for (int i = 0 ; i < filas ; i++){

			for (int j = 0 ; j < columnas ; j++){

				TipoBase valor = matriz[i][j] - m.matriz[i][j];
				resta.ModificarValor(i, j, valor);

			}
		}
	}

	return resta;

}

Matriz2D_1 Matriz2D_1 :: operator - (const TipoBase valor){

	Matriz2D_1 resta (filas, columnas);

	for (int i = 0 ; i < filas ; i++){

		for (int j = 0 ; j < columnas ; j++){

			TipoBase valor = matriz[i][j] - valor;
			resta.ModificarValor(i, j, valor);

		}
	}

	return resta;

}

Matriz2D_1 & Matriz2D_1 :: operator += (const TipoBase valor){

	(*this) = (*this) + valor;
	
	return (*this);

}

Matriz2D_1 & Matriz2D_1 :: operator -= (const TipoBase valor){

	(*this) = (*this) - valor;
	
	return (*this);

}

bool Matriz2D_1 :: operator == (const Matriz2D_1 & m){

	return ((filas == m.filas) && (columnas == m.columnas));

}

bool Matriz2D_1 :: operator != (const Matriz2D_1 & m){

	return (!((*this) == m));

}

/*************************************************************************/
// Métodos privados

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

void MuestraMatriz(const Matriz2D_1 & m){

	for (int i = 0 ; i < m.GetFilas() ; i++){

		for (int j = 0 ; j < m.GetColumnas() ; j++){

			cout << m.LeerValor(i, j) << " ";

		}
		cout << endl;
	}
}
