//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 6
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y comprime todas las líneas de la secuencia, eliminando los separadores
// que hubiera en cada línea
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;

   while (cin.get(c)){

      // Si el caracter no es un separador, se muestra por pantalla
      if (c != ' ' && c != '\t'){

         cout.put(c);

      }
   }

   return 0;

}