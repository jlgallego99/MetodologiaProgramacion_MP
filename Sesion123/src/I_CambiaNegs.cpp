//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 3
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
   int *ptr;
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

   ptr = v;

   while (contador <= TAMANIO){
      if (*(ptr + contador) < 0){
         *(ptr + contador) = abs(*(ptr + contador));
      }

      contador++;
   }

   /* cout << "10 valores sin negativos: " << endl;
   for (int i = 0 ; i < 10 ; i++){
      cout << v[i] << endl;
   } */

   return 0;
}