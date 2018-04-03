//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 20
// Definición de la función "OrdenaVector" 
//
// Ordena un vector de enteros de menor a mayor
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "OrdenaVector.h"

// Ordenación de un vector por inserción
void OrdenaVector(int *vector, int total_utilizados){
   int a_desplazar, i;

   for (int izda = 1; izda < total_utilizados; izda++){
      a_desplazar = *(vector + izda);

      for (i = izda; i > 0 && a_desplazar < *(vector + i - 1); i--)
         *(vector + i) = *(vector + i - 1);
      
      *(vector + i) = a_desplazar;
   }
}