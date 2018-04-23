//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 23
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "RellenaVector.h"
#include "MuestraVector.h"
#include "MezclaVectores.h"
using namespace std;

int main(int argc, char *argv[]){
   const int TOPE = 100;
   int v1[TOPE], v2[TOPE], mezcla[TOPE];
   int tamanio1, tamanio2, tamanio_mezcla, n;
   const char *mensaje1 = "\nVector 1: ";
   const char *mensaje2 = "\nVector 2: ";
   const char *mensaje3 = "\nVector mezcla: ";

   cout << "Introduzca cuántas casillas se van a ocupar en el vector 1: ";
   cin >> tamanio1;
   cout << "Introduzca cuántas casillas se van a ocupar en el vector 2: ";
   cin >> tamanio2;

   /* El programa se ejecuta sin argumentos: Se generan números aleatorios entre
   1 y 100 (incluidos) */
   if (argc == 1){
      RellenaVector(v1, tamanio1, 0, 100);
      RellenaVector(v2, tamanio2, 0, 100);
   }
   /* El programa se ejecuta con un argumento: Este argumento es el mayor valor
   aleatorio permitido, se generan aleatorios entre 1 y ese número */
   else if (argc == 2){
      RellenaVector(v1, tamanio1, 1, atoi(argv[1]));
      RellenaVector(v2, tamanio2, 1, atoi(argv[1]));
   }
   /* El programa se ejecuta con dos argumentos: Estos serán los extremos del
   intervalo que delimita los valores aleatorios */
   else if (argc == 3){
      RellenaVector(v1, tamanio1, atoi(argv[1]), atoi(argv[2]));
      RellenaVector(v1, tamanio2, atoi(argv[1]), atoi(argv[2]));
   }

   cout << "Introduzca cuantos datos quiere mostrar por línea de cada vector: ";
   cin >> n;

   // Se muestran los dos vectores separados
   MuestraVector(mensaje1, v1, tamanio1, n);
   MuestraVector(mensaje2, v2, tamanio2, n);

   // Se realiza la mezcla de los vectores y se devuelve el tamaño del vector
   tamanio_mezcla = MezclaVectores(mezcla, v1, tamanio1, v2, tamanio2);

   // Se muestra el vector de la mezcla de los dos vectores anteriores
   MuestraVector(mensaje3, mezcla, tamanio_mezcla, n); 

   return 0;
}