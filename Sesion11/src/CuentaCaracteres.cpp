//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 3
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y muestra en la salida estándar el número total de caracteres leídos
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   int total = 0;

   while (cin >> c){

      total++;

   }

   cout << "Total de caracteres leídos: " << total << endl;

   return 0;

}