/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2017-2018
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// EXAMEN PRÁCTICO 1
//
// ¡RELLENAD LOS SIGUIENTES DATOS!
//
// Apellidos:	Gallego Peña
// Nombre:  Jose Luis
//
// GRUPO DE PRÁCTICAS: A1
//
// Fecha:  25/04/18
// 
// Ordenador (ver etiqueta): ei140177
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include "Lista.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

const int NUM_VALORES = 10;
const int MIN_ALEAT = 1;
const int MAX_ALEAT = 100;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{	
	Lista l;
	int num_valores;
	
	// Se reciben un número de argumentos distinto del pedido
	if (argc > 2 || argc == 1){

		num_valores = NUM_VALORES;	// Número de valores por defecto

	}

	// Se introduce un argumento
	else if (argc == 2){
		
		num_valores = atoi(argv[1]);

	}

	// Crea una lista con el número de nodos introducidos como argumento
	// y valores aleatorios entre MIN_ALEAT y MAX_ALEAT
	cout << "La lista tendrá " << num_valores << " elementos." << endl;

	RellenaListaAleatoriamente(l, atoi(argv[1]), MIN_ALEAT, MAX_ALEAT);	

	// Muestra la lista sin ordenar
	cout << "Lista sin ordenar: " << endl;
	PintaLista(l);

	// Ordena la lista
	OrdenaIntercambioLista(l);

	// Muestra la lista ordenada
	cout << "Lista ordenada: " << endl;
	PintaLista(l);

	// Finalmente se libera la memoria ocupada por la lista
	LiberaLista(l);

	return (0);
}

/***************************************************************************/
/***************************************************************************/
