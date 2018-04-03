//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 4
// Programa principal
//
// Lee una secuencia indeterminada de cadenas de caracteres mediante redirección
// de entrada con un fichero "prueba" y las guarda en memoria de manera que sean 
// accesibles a través de un vector dinámico de cadenas clásicas. 
// El programa muestra el número total de líneas, líneas no vacías y párrafos
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char ** Redimensiona(char **, int &);

int main(){
   int TAMANIO = 10;
	char ** v  = new char * [TAMANIO];
   int num_lineas = 0, vacias = 0, num_parrafos = 0, utilizados = 0;
   string cadena;
	bool fin_linea = false;

	while (getline(cin, cadena)){
      /* Vector dinámico de caracteres con la capacidad estrictamente necesaria
      de cada línea leída en cada vuelta */
      char * caracteres = new char [cadena.size() + 1];
      strcpy(caracteres, cadena.c_str());
		utilizados += strlen(caracteres) + 1;

		while (utilizados >= TAMANIO){
			v = Redimensiona(v, TAMANIO);
		}

		// Se almacena la dirección de memoria del primer elemento de la cadena
		v[num_lineas] = caracteres;

		num_lineas++;
	}
	
	for (int i = 0 ; i < num_lineas ; i++){
		/* Esta línea está vacía */
		if (*(*(v + i)) == '\0'){
			/* El caracter anterior es un \0, lo cual significa que hemos cambiado 
			de parrafo */
			if (fin_linea){
				num_parrafos++;
			}

			// Número de líneas vacías
			vacias++;
		}
		else{
			fin_linea = false;
		}
		for (int j = 0 ; j <= strlen(*(v + i)) ; j++){
			// Indicamos que se ha terminado la línea
			if(*(*(v + i) + j) == '\0'){
				fin_linea = true;
			}
		}
	}
	
	// Liberación de memoria
	delete [] v;
	
   cout << endl << "Número total de líneas: " << num_lineas << endl;
	cout << "Número de líneas no vacías: " << num_lineas - vacias << endl;
	cout << "Número total de párrafos: " << num_parrafos << endl;
}

// Redimensiona un vector de punteros a punteros a char
char ** Redimensiona(char ** p, int & cap){
	// Redimensión de uno en uno
	cap++;

	char ** q = new char * [cap];
	memcpy(q, p, cap*sizeof(char));
	delete [] p;
	memcpy(p, q, cap*sizeof(char));
	delete [] q;

	return p;
}