//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I
// Definición de la función "VectorAleatorio" necesaria para los programas:
// I_MaxMin_Array, I_PosMayor y I_MezclaArrays 
//
// Rellena un vector de números enteros aleatorios entre dos valores dados
//
//////////////////////////////////////////////////////////////////////////

#include "VectorAleatorio.h"
#include <cstdlib>
#include <ctime>

void VectorAleatorio(int *v, int izda, int dcha, int min, int max){
   const int MY_MAX_RAND = max;
   time_t t;

   srand ((int) time(&t)); // Inicializa el generador con
                           // el reloj del sistema
   for (int i = izda ; i < dcha ; i++)
      v[i] = (rand() % MY_MAX_RAND + min);
}