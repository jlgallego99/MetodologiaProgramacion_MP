//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 1
// Programa principal
//
// Guarda un número indefinido de valores int utilizando un vector dinámico
// que va creciendo conforme necesite espacio para almacenar un nuevo valor
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cctype>
#include "Redimensiona.h"
#include "MuestraVector.h"
using namespace std;

void LeeVectorDinamico(int *, TipoRedimension, int &);

int main(int argc, char * argv[]){
	// Se reserva inicialmente TAM casillas
	int TAM = 5;
	int * v_dinamico = new int [TAM];
	int argumento = atoi(argv[1]);
	// Número maximo de enteros por linea
	const int MAX_LINE = 10; 
	TipoRedimension tipo_redimension;

	// Se introducen demasiados argumentos: Error y fin de programa
	if (argc > 2){
		cerr << "Ha introducido demasiados argumentos" << endl;
		exit (1);
	}
	// Sin argumentos: De uno en uno
	else if (argc == 1){
		tipo_redimension = TipoRedimension::DeUnoEnUno;
	}
	// Con 1 argumento
	else if (argc == 2){
		// De uno en uno
		if (argumento == 1){
			tipo_redimension = TipoRedimension::DeUnoEnUno;
		}
		// En bloques
		else if (argumento == 2){
			tipo_redimension = TipoRedimension::EnBloques;
		}
		// Duplicando
		else if (argumento == 3){
			tipo_redimension = TipoRedimension::Duplicando;
		}
	}

	LeeVectorDinamico(v_dinamico, tipo_redimension, TAM);
	MuestraVector(v_dinamico, TAM, MAX_LINE);

	delete [] v_dinamico;

	return 0;
}

void LeeVectorDinamico(int * p, TipoRedimension tipo, int & cap){
	const int TAMANIO = 10;
	char cadena[TAMANIO];
	const char * FIN = "FIN";
	int i = 0, entero;

	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline(cadena, TAMANIO);
	while (strcmp(cadena, FIN)){
		entero = atoi(cadena);
		
		// Si se ha superado la capacidad del vector, se redmensiona
		if (i == cap){
			p = Redimensiona(p, tipo, cap);
		}

		p[i] = entero;
		i++;

		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline(cadena, TAMANIO);
	}

	/* Se guarda como capacidad del vector únicamente los utilizados para luego
	poder mostrarlo correctamente */
	cap = i;
}