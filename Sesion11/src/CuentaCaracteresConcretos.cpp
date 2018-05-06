//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 12
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// Recibe como argumento desde la línea de ordenes un dato de tipo char
// Muestra en la salida estándar el número de caracteres leídos de la 
// entrada estándar iguales al argumento suministrado
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(int argc, char ** argv){
   // Si el número de argumentos no es correcto, muestra un mensaje de error
   if (argc != 2){

      cerr << "Número de argumentos introducidos incorrecto."
           << " Debe introducir un único argumento." << endl;
      
      exit (1);

   }

   char c;
   int num_caracteres = 0;
   char caracter = argv[1][0];

   while (cin.get(c)){

      if (c == caracter){

         num_caracteres++;

      }
   }

   cout << "Hay " << num_caracteres << " apariciones del carácter " << caracter;
   cout << endl;

   return 0;

}