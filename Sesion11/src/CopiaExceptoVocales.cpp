//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 2
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar y los
// copia literalmente en la salida estándar, exceptuando las vocales
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
   char c;

   c = cin.get(); 
   
   while (!cin.eof()){
      
      // Sólo se muestra el caracter si no es vocal
      bool vocal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

      if (!vocal){
         cout.put(c);
      }
      
      c = cin.get(); 

   }
   
   return 0;

}