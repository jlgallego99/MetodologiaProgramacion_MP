//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 10
// Programa principal
//
// Lee una serie indefinida de números de la entrada estándar, separados
// por el caracter '*' y los copia en el mismo orden en la salida estándar
// separados por un salto de línea
// PRECONDICIÓN: El último carácter es '*'
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   const int TAMANIO = 100;
   char c[TAMANIO];

   cout << "Introduzca secuencias de números separadas por el caracter *: ";
   cin.getline(c, TAMANIO, '*');

   while (!cin.eof()){

      cout << atoi(c) << endl;

      // Lee la cadena hasta encontrar el delimitador '*'
      cin.getline(c, TAMANIO, '*');

   }

   return 0;

}