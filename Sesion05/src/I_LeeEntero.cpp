//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 19
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "LeeEntero.h"
using namespace std;

int main(){
   int entero, inicio, fin;

   entero = LeeEntero();
   cout << "Número entero de la función sin argumento: " << entero << endl;

   cout << "Introduzca la posición final del intervalo: ";
   cin >> fin;

   entero = LeeEntero(fin);
   cout << "Número entero de la función con un argumento: " << entero << endl;

   cout << "Introduzca las posiciones inicial y final del intervalo: ";
   cin >> inicio >> fin;

   entero = LeeEntero(inicio, fin);
   cout << "Número entero de la función con dos argumentos: " << entero << endl;

   return 0;
}