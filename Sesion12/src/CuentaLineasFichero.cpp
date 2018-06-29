//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI
// Definición de la función "CuentaLineasFichero"
//
// Cuenta cuántas líneas tiene un fichero de texto
//
//////////////////////////////////////////////////////////////////////////

#include <fstream>
using namespace std;

int CuentaLineasFichero(const char * nombre){

   ifstream fi;      // Flujo de entrada del fichero
   fi.open(nombre);  // Asociar el flujo de entrada al fichero
   int n;            // Número de líneas

   while (!fi.eof()){

      n++;

   }

   fi.close(); // Desasociar el flujo de entrada del fichero

   return n;

}