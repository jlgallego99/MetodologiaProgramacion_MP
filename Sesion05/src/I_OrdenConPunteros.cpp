//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 22
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

void Ordena(int *, int **, int, int);
void MuestraVector(int **, int);

int main(int argc, char * argv[]){
   const int TOPE = 50; // Capacidad
   int vec[TOPE];       // Array de datos
   int * ptr[TOPE];     // Indice al array "vector"

   int dato, util = 0;

   cout << "Introduzca datos en el vector (0 para terminar): ";
   cin >> dato;
   while (dato != 0){

      vec[util] = dato;
      ptr[util] = &vec[util];
      util++;

      cout << "Introduzca datos en el vector (0 para terminar): ";
      cin >> dato;

   }

   // El programa se ejecuta sin argumentos: 
   // Ordena todo el vector
   if (argc == 1){

      Ordena(vec, ptr, 0, util - 1);
      MuestraVector(ptr, util);

   }
   // El programa se ejecuta con dos argumentos:
   // Ordena el vector entre las dos posiciones dadas
   else if (argc == 3){

      Ordena(vec, ptr, atoi(argv[1]), atoi(argv[2]));
      MuestraVector(ptr, util);

   }
   // En otro caso muestra un mensaje de error y no hace nada más
   else{

      cerr << "Número de argumentos introducidos incorrecto." << endl
           << "   - Un argumento: Ordena todo el vector" << endl
           << "   - Dos argumentos: Ordena el vector entre las posiciones dadas";

   }

   return 0;

}

// Ordena un vector sin modificarlo mediante un vector de punteros
// Usa el método de ordenación por selección
void Ordena(int * vec, int ** ptr, int izda, int dcha){

   const int utilizados = dcha + 1 - izda;
   int minimo, pos_min;

   // Asigna direcciones de memoria para todo el vector
   for (int i = 0 ; i < utilizados ; i++){

      ptr[i] = &vec[i + izda];

   }

	int ultima = dcha - izda;

	for (int i = 0 ; i < ultima ; i++){

		minimo = *(ptr[i]); 
		pos_min = i;
	
		for (int j = i + 1 ; j <= ultima ; j++){

			if (*(ptr[j]) < minimo){
				pos_min = j;
				minimo = *(ptr[j]);
			}

		}

		int * tmp = &*ptr[i];
	   ptr[i] = &*ptr[pos_min];
	   ptr[pos_min] = tmp;

	}
}

// Muestra un vector completo por pantalla
void MuestraVector(int ** ptr, int util){

   cout << "Vector: " << endl;

   for (int i = 0 ; i < util ; i++){

      cout << (*ptr[i]) << " ";

   }

   cout << endl;

}