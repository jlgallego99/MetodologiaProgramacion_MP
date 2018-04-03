//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 2
// Programa principal
//
// Guarda un número indefinido de valores int utilizando un vector dinámico
// que va creciendo conforme necesite espacio para almacenar un nuevo valor
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

const int TAM_PALABRAS = 10;

struct info_palabra{
   char * inicio;
   char * fin;
};

int encuentra_palabras(info_palabra *, char *);
void muestra_palabras(info_palabra *, int);
info_palabra * Redimensiona(info_palabra *, int &);

int main(){
   const int MAX_CARACTERES = 100;
   char la_cadena[MAX_CARACTERES];
   info_palabra * las_palabras;

   // Se inicializa el vector dinámico reservando TAM_PALABRAS casillas
   las_palabras = new info_palabra [TAM_PALABRAS];

   cout << "Introduzca distintas palabras: " << endl;
   cin.getline(la_cadena, MAX_CARACTERES);

   int num_palabras = encuentra_palabras(las_palabras, la_cadena);

   muestra_palabras(las_palabras, num_palabras);

   delete [] las_palabras;

   return 0;
}

int encuentra_palabras(info_palabra * palabras, char * cadena){
   const char ESPACIO = ' ', FIN_CADENA = '\0';
   int primera_letra = 0, num_palabras = 0;
   // Se inicializa la capacidad dinámica del vector al tamaño inicial de este
   int cap = TAM_PALABRAS;

   /* Algoritmo: Se recorre toda la cadena. Va guardando la posición siguiente 
   a la cual encuentra un espacio. Entonces, si a la siguiente vuelta se 
   encuentra con una letra, se guarda la dirección de memoria de esa primera
   letra */
   for (int i = 0 ; i < strlen(cadena) ; i++){
      /* Controla a cada vuelta la ocupación del array de punteros, si está 
      lleno, se redimensionará por bloque para que quepan más */
      if (i + 1 == cap){
         palabras = Redimensiona(palabras, cap);
      }
      /* Cada vez que encuentre un espacio, se guarda la posición siguiente 
      esperando que no sea un espacio */
      if (cadena[i] == ESPACIO){
         primera_letra = i + 1;
      }
      // Se controla que sólo se guarde la primera letra de cada palabra
      else if (primera_letra == i){
         (palabras + num_palabras)->inicio = &cadena[i];
      }
      /* Si, estando en la palabra, el siguiente caracter es un espacio, es que 
      estamos en el fin de ella */
      else if (cadena[i + 1] == ESPACIO || cadena[i + 1] == FIN_CADENA){
         (palabras + num_palabras)->fin = &cadena[i];

         // Ya tenemos el inicio y el fin, avanzamos el array de palabras
         num_palabras++;
      }
   }

   return num_palabras;
}

void muestra_palabras(info_palabra * las_palabras, int num_palabras){
   cout << "La cadena introducida tiene " << num_palabras 
        << " palabras" << endl;
   for (int i = 0 ; i < num_palabras ; i++){
      cout << "-Palabra " << i + 1 << ":" << endl;
      cout << "   Primera letra: " << *(las_palabras + i)->inicio << endl;
      cout << "   Última letra: " << *(las_palabras + i)->fin << endl;
   }
}

// Redimensiona un vector de struct info_palabra
info_palabra * Redimensiona(info_palabra * p, int & cap){
	const int TAM_BLOQUE = 20;

	cap += TAM_BLOQUE;
	
   info_palabra * q = new info_palabra [cap];
	memcpy(q, p, cap*sizeof(info_palabra));
	delete [] p;

	return q;
}