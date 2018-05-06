//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 5
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y muestra en la salida estándar las líneas no vacías 
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;

   while (cin.get(c)){

      // Si el carácter no es un salto de línea, se muestra por pantalla
      if (c != '\n'){

         cout.put(c);

         // Comprobación de si el siguiente caracter es un salto de línea
         if (cin.peek() == '\n'){

            cout << endl;  // Salto de línea

         }
      }
   }

   return 0;

}