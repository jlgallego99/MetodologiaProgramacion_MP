//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 20
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MaximoMinimo.h"
#include "VectorAleatorio.h"
using namespace std;

int main(){
   const int TOPE = 100;
   int vector[TOPE], minimo, maximo, izda, dcha;
   int *ptr_dcha, *ptr_izda;
   
   // Lectura de datos
   cout << "Valores del vector: ";
   cin >> minimo >> maximo;
   cout << "Extremos entre los cuales buscar el mínimo y el máximo: ";
   cin >> izda >> dcha;

   // Llamada a la función que rellena el vector con enteros aleatorios
   VectorAleatorio(vector, izda, dcha, minimo, maximo);

   // Punteros que delimitan donde realizar la búsqueda
   ptr_izda = &vector[izda];
   ptr_dcha = &vector[dcha];

   // Llamada a la función que calcula el mínimo y el máximo valor del vector
   MaximoMinimo(ptr_izda, ptr_dcha, minimo, maximo);

   cout << "Mínimo: " << minimo << endl;
   cout << "Máximo: " << maximo << endl;

   return 0;
}