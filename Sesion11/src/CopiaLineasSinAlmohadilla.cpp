//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 7
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// y copia en la salida estándar las líneas que NO comienzan por #
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   bool incorrecta = false;;

   while (cin.get(c)){

      // Nueva línea: Puede no ser incorrecta
      if (c == '\n'){

         incorrecta = false;

      }

      // Sólo se muestra el caracter si no es incorrecto 
      // (su linea no empieza por #)
      if (c != '#' && !incorrecta){

         cout.put(c);

      }
      // Empieza por #: Línea incorrecta
      else{ 

         incorrecta = true;

      }
   }

   return 0;

}