//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 4
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y muestra en la salida estándar el número de líneas no vacías 
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   int total = 0;

   while (cin.get(c)){

      // Si el carácter no indica una nueva línea
      if (c != '\n'){

         // Se comprueba si se ha acabado la línea, que sabemos que no es vacia
         if (cin.peek() == '\n'){

            total++;

         }
      }
   }

   cout << "Total de líneas no vacías: " << total << endl;

   return 0;

}