//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 18
// Programa principal
//
// Lee una cadena de caracteres, encuentra y registra el inicio y el final
// de cada palabra y muestra el número de palabras y el primer carácter de 
// cada una
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CARACTERES = 100;
const int MAX_PALABRAS = 20;

struct info_palabra{
   char * inicio;
   char * fin;
};

int encuentra_palabras(info_palabra *, char *);
void muestra_palabras(info_palabra *, int);

int main(){
   char la_cadena[MAX_CARACTERES];
   info_palabra las_palabras[MAX_PALABRAS];

   cout << "Introduzca distintas palabras: " << endl;
   cin.getline(la_cadena, MAX_CARACTERES);

   int num_palabras = encuentra_palabras(las_palabras, la_cadena);

   muestra_palabras(las_palabras, num_palabras);

   return 0;
}

int encuentra_palabras(info_palabra * palabras, char * cadena){
   const char ESPACIO = ' ', FIN_CADENA = '\0';
   int primera_letra = 0, num_palabras = 0;
   bool lleno = false;

   /* Algoritmo: Se recorre toda la cadena. Va guardando la posición siguiente 
   a la cual encuentra un espacio. Entonces, si a la siguiente vuelta se 
   encuentra con una letra, se guarda la dirección de memoria de esa primera
   letra */
   for (int i = 0 ; i < strlen(cadena) && !lleno ; i++){
      /* Controla a cada vuelta la ocupación del array de punteros, si está 
      lleno, no se consideran más palabras */
      if (num_palabras == MAX_PALABRAS){
         lleno = true;
      }
      /* Cada vez que encuentre un espacio, se guarda la posición siguiente 
      esperando que no sea un espacio */
      else if (cadena[i] == ESPACIO){
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

   // Si se llena el array de punteros, se muestra un mensaje de aviso
   if (lleno){
      cerr << "El array de punteros de palabras está lleno " 
           << "por lo que no se considerarán más de " << num_palabras 
           << " palabras" << endl;
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