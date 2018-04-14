//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 10
// Programa principal
//
// (Examen extraordinario FP 2018) El problema del viajante de comercio:
// 
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main(){
   const int MAX_COSTE = 100;
   int n, n_inicial, n_actual, num_visitadas = 0, coste = 0;
   int min, col_min, distancia;
   
   cout << "Introduzca el número de ciudades: ";
   cin >> n;
   cout << "Matriz de costes C. ";
   Matriz2D_1 C = CreaMatriz2DLlena(n, n);
   cout << "Ciudad inicial: ";
   cin >> n_inicial;
   n_actual = n_inicial;

   // Vector que indica si esa ciudad ha sido visitada
   bool * ya_visitada = new bool [n];
   ya_visitada[n] = {false};

   // Vector que guarda el orden en el que se han visitado las ciudades
   int * orden_ciudades = new int [n];

   while (num_visitadas < n){
      min = MAX_COSTE;

      for (int j = 0 ; j < n ; j++){
         /* Calcula el mínimo únicamente si esa ciudad (columna) no ha sido 
         visitada anteriormente */
         if (!ya_visitada[j]){
            distancia = C.datos[n_actual][j];
            if (distancia < min){
               min = distancia;
               col_min = j;
            }
         }
      }

      // Se va acumulando el valor del coste minimo
      coste += C.datos[n_actual][col_min];

      /* Marcamos la ciudad (columna) donde se ha encontrado el minimo como 
      visitada */
      ya_visitada[col_min] = true;

      // Se guarda en orden la ciudad que ha sido visitada en cada viaje
      orden_ciudades[num_visitadas] = n_actual;
      num_visitadas++;

      /* La próxima ciudad a analizar será la ciudad en la que se ha encontrado 
      el mínimo, ya que se tiene que partir desde donde se llega */
      n_actual = col_min;
   }

   cout << "Matriz de costes C: " << endl;
   MuestraMatriz2D(C);
   cout << "Recorrido del viaje: " << endl;
   for (int i = 0 ; i < n ; i++){
      cout << orden_ciudades[i] << " ";
   }
   cout << endl << "Coste total de: " << coste << endl;

   return 0;
}