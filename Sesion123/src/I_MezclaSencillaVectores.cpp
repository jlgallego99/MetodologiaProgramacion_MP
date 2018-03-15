//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 5
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   const int TOPE = 100;
   int i = 0, j = 0, k = 0;
   float *ptr_1, *ptr_2, *ptr_res;
   float v1[TOPE] = {2,3,8,22,44,88,99,100,101,255,665};
   float v2[TOPE] = {1,3,4,5,6,25,87,89,99,100,500,1000};
   float res[2 * TOPE];
   int tam_v1 = 11, tam_v2 = 12; // 0 <= tam_v1, tam_v2 < TOPE
   int tam_res = tam_v1 + tam_v2; // 0 <= tam_res < 2*TOPE

   ptr_1 = v1;
   ptr_2 = v2;
   ptr_res = res;

   while (k < tam_res){
      if (*(ptr_1 + i) < *(ptr_2 + j)){
         *(ptr_res + k) = *(ptr_1 + i); 

         i++;
         k++;
      }
      else if (*(ptr_1 + i) > *(ptr_2 + j)){
         *(ptr_res + k) = *(ptr_2 + j);

         j++;
         k++;
      }
      else if (*(ptr_1 + i) == *(ptr_2 + j)){
         *(ptr_res + k) = *(ptr_1 + i);

         i++;
         j++;
         k++;
      }
   }

   for (i = 0 ; i < tam_res ; i++){
      cout << *(ptr_res + i) << endl;
   }
}