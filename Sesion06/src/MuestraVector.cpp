//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II
// Definición de la función MuestraVector
//
// Muestra un vector completo por pantalla
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MuestraVector.h"
using namespace std;

void MuestraVector(int * p, int num_datos, int num_datos_linea){
	cout << "El vector es: ";

	for (int i = 0 ; i < num_datos ; i++){
		char separador = (((i + 1) % num_datos_linea) == 0) ? '\n':' ';
		cout << p[i] << separador;
	}

	cout << endl;
}