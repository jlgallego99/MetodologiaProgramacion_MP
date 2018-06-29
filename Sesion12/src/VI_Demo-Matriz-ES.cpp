//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI, Ejercicio 7
// Programa principal
//
// Prueba tres nuevos métodos de la clase Matriz2D_1 que usan un fichero de 
// texto en el que los datos están separados por el fin de línea
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main(){

   const char * nombre = "datosmatriz1";

   // Crea una matriz con los datos de un fichero
   Matriz2D_1 m(nombre);

   cout << "Matriz: " << endl;
   MuestraMatriz(m);

   // Guarda en un fichero el contenido de la matriz
   nombre = "copiamatriz";
   m.EscribirMatriz2D_1(nombre);

   // Sustituye el contenido de la matriz por los valores de un fichero
   nombre = "datosmatriz2";
   m.LeerMatriz2D_1(nombre);

   cout << "Matriz nueva: " << endl;
   MuestraMatriz(m);

   return 0;

}