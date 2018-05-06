//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 11
// Programa principal
//
// Lee una serie indefinida de números de la entrada estándar y muestra
// en la salida estándar la suma de todos esos números
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   const int TAMANIO = 100;
   char c[TAMANIO];
   int suma = 0;

   cout << "Introduzca secuencias de números separadas por el fin de línea: ";
   cin.getline(c, TAMANIO);

   while (!cin.eof()){

      // Suma de todos los números que lee
      suma += atoi(c);

      // Lee la cadena hasta encontrar el delimitador '\n'
      cin.getline(c, TAMANIO);

   }

   cout << "La suma de todos los números es: " << suma << endl;

   return 0;

}