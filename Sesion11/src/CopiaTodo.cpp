//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 1
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar y los
// copia literalmente en la salida estándar
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;
   
   c = cin.get(); 

   while (!cin.eof()){

      cout.put(c);
      c = cin.get(); 

   }
   
   return 0;

}