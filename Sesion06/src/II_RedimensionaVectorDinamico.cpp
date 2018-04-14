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
#include <cstdlib>
using namespace std;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};
int * LeeVectorDinamico(int *, TipoRedimension, int &);
int * Redimensiona(int *, TipoRedimension, int &);
void MuestraVector(int *, int, int);

int main(int argc, char *argv[]){
	// Se reserva inicialmente TAM casillas
	int TAM = 5;
	int * v_dinamico = new int [TAM];
	int argumento = atoi(argv[1]);
	// Número maximo de enteros por linea
	const int MAX_LINE = 10; 
	TipoRedimension tipo;

	// Se introducen demasiados argumentos: Error y fin de programa
	if (argc > 2){
		cerr << "Ha introducido demasiados argumentos" << endl;
		exit (1);
	}

	// Sin argumentos: De uno en uno
	if (argc == 1){
		tipo = DeUnoEnUno;	
	}
	// Con 1 argumento
	else if (argc == 2){
		// De uno en uno
		if (argumento == 1){
			tipo = DeUnoEnUno;
		}
		// En bloques
		else if (argumento == 2){
			tipo = EnBloques;
		}
		// Duplicando
		else if (argumento == 3){
			tipo = Duplicando;
		}
	}
	
	v_dinamico = LeeVectorDinamico(v_dinamico, tipo, TAM);
	MuestraVector(v_dinamico, TAM, MAX_LINE);

	delete [] v_dinamico;

	return 0;
}

int * LeeVectorDinamico(int * p, TipoRedimension tipo, int & cap){
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

	/* Se guarda como capacidad del vector únicamente los utilizados para 
        luego poder mostrarlo correctamente */
	cap = i;

	return p;
}

/* Función que realoja y redimensiona un vector dinámico, ampliándolo, cuando no
haya espacio para almacenar un nuevo valor. Se puede realizar de tres maneras:
En una casilla, en bloques o duplicando su tamaño  */
int * Redimensiona(int * p, TipoRedimension tipo, int & cap){
	const int TAM_BLOQUE = 5;

	if (tipo == DeUnoEnUno){
		cap++;
	}
	else if (tipo == EnBloques){
		cap += TAM_BLOQUE;
	}
	else if (tipo == Duplicando){
		cap *= 2;
	}

	int * q = new int [cap];
	memcpy(q, p, cap*sizeof(int));

	return q;
}

// Muestra un vector completo por pantalla
void MuestraVector(int * p, int num_datos, int num_datos_linea){
	cout << "El vector es: ";

	for (int i = 0 ; i < num_datos ; i++){
		char separador = (((i + 1) % num_datos_linea) == 0) ? '\n':' ';
		cout << p[i] << separador;
	}

	cout << endl;
}
