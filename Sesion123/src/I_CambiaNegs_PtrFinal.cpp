//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 4
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
   const int TAMANIO = 1000;
   int v[TAMANIO], contador = 0;
   int *ptr_inicio, *ptr_final;
   const int MY_MAX_RAND = 50; // Queremos valores -50<=n<=50
   time_t t;

   srand ((int) time(&t)); // Inicializa el generador con
                           // el reloj del sistema
   
   for (int i = 0 ; i < TAMANIO ; i++)
      v[i] = (rand() % ((2*MY_MAX_RAND)+1)) - MY_MAX_RAND;

   /* cout << "10 valores con negativos: " << endl;
   for (int i = 0 ; i < 10 ; i++){
      cout << v[i] << endl;
   } */

   // Puntero al inicio del vector y puntero a la posición siguiente a la última
   ptr_inicio = v;
   ptr_final = ptr_inicio + TAMANIO;

   while (ptr_inicio < ptr_final){
      if (*(ptr_inicio + contador) < 0){
         *(ptr_inicio + contador) = abs(*(ptr_inicio + contador));
      }

      ptr_inicio++;
   }

   /* cout << "10 valores sin negativos: " << endl;
   for (int i = 0 ; i < 10 ; i++){
      cout << v[i] << endl;
   } */

   return 0;
}