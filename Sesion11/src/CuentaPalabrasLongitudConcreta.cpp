//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas V, Ejercicio 13
// Programa principal
//
// Lee una secuencia indefinida de caracteres de la entrada estándar
// Recibe como argumento desde la línea de ordenes un dato de tipo int
// Muestra en la salida estándar el número de palabras leídas de la 
// entrada estándar cuya longitud sea igual al argumento suministrado
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv){
   // Si el número de argumentos no es correcto, muestra un mensaje de error
   if (argc != 2){

      cerr << "Número de argumentos introducidos incorrecto."
           << " Debe introducir un único argumento." << endl;
      
      exit (1);

   }

   const int TAMANIO = 100;
   char c[TAMANIO];
   int num_lineas = 0;
   int longitud = atoi(argv[1]);

   cout << "Introduzca líneas de caracteres: ";
   cin.getline(c, TAMANIO);

   while (!cin.eof()){

      if (strlen(c) == longitud){

         num_lineas++;

      }

      cin.getline(c, TAMANIO);

   }

   cout << "Hay " << num_lineas << " líneas de longitud " << longitud;
   cout << endl;

   return 0;

}