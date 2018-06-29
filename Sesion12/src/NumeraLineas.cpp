//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI, Ejercicio 1
// Programa principal
//
// Recibe los nombres de dos ficheros de texto de la línea de ordenes
// Crea un fichero cuyo nombre se especifica en el segundo argumento, a 
// partir de un fichero existente cuyo nombre se especifica en el primero
// copiando su contenido y añadiendo al principio de cada línea su número
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char ** argv){
   
   // Comprobar que el número de argumentos introducido es correcto
   if (argc != 3){

      cerr << "Error: número de argumentos introducidos incorrecto" << endl
           << "Debe introducir dos nombres de fichero" << endl;

      exit (1);

   }

   const int TAMANIO = 50;
   char cad[TAMANIO];

   ifstream fi;   // Flujo de entrada
   ofstream fo;   // Flujo de salida

   // Asociar el flujo de entrada al primer fichero
   fi.open(argv[1]);

   // Asociar el flujo de salida al segundo fichero
   fo.open(argv[2]);

   // Comprobación de fallos
   if (fi.fail()){

      cerr << "Error: no pudo abrirse el primer fichero" << endl
           << "No existe o no existe permiso de lectura" << endl;

      exit (1);

   }

   if (fo.fail()){

      cerr << "Error: no pudo crearse el segundo fichero" << endl
           << "No hay espacio disponible o no existe permiso de escritura" 
           << endl;

      exit (1);

   }

   // Copia todas las lineas del fichero de entrada al de salida
   int n = 1;  // Marca el número de línea
   while (!fi.eof()){

      fi >> cad;
      fo << n << " - " << cad << endl;
      n++;

   }

   // Desasociar flujos de entrada y salida de los ficheros
   fi.close();
   fo.close();

   return 0;

}