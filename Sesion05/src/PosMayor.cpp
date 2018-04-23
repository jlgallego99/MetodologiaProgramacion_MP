//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 21
// Definición de la función "PosMayor"
//
// Recibe un vector de números enteros y dos valores enteros que indican
// las posiciones de los extremos de un intervalo sobre ese vector.
// Devuelve un puntero al elemento mayor dentro de ese intervalo.
//
//////////////////////////////////////////////////////////////////////////

#include "PosMayor.h"

int * PosMayor(int *pv, int izda, int dcha){
   // Se inicializa el mayor al primer valor del intervalo 
   int mayor = pv[izda];
   
   // Puntero apunta a la primera casilla del intervalo
   pv = &pv[izda];

   /* Algoritmo: Se recorre todo el intervalo del vector. Si se encuentra un 
   valor mayor que el mayor, este se reemplaza por el nuevo y se guarda su
   dirección de memoria */
   for (int i = izda ; i < dcha ; i++){
      if (pv[i] > mayor){
         mayor = pv[i];
         pv = &pv[i];
      }
   }

   return pv;
}