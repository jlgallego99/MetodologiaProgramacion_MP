//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 20
// Definición de la función "RellenaVector" necesaria para el programa:
// I_MezclaArrays.cpp
//
// Rellena un vector aleatoriamente con unos valores dados y luego los ordena
// de menor a mayor
//
//////////////////////////////////////////////////////////////////////////

#include "RellenaVector.h"
#include "OrdenaVector.h"
#include "VectorAleatorio.h"

void RellenaVector (int v[], int util, int min, int max){
   /* Se rellenan aleatoriamente util casillas del vector con valores 
   comprendidos entre min y max */
   VectorAleatorio(v, 0, util, min, max);

   /* El vector es ordenado de menor a mayor */
   OrdenaVector(v, util);
}