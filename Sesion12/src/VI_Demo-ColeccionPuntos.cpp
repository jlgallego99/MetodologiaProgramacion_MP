//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI, Ejercicio 9
// Programa principal
//
// Prueba métodos de la clase ColeccionPuntos2D
// Toma los puntos de un fichero de texto en el argumento
// PRECONDICIÓN: La primera línea del fichero contiene "PUNTOS"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ColeccionPuntos2D.h"
using namespace std;

int main(int argc, char ** argv){

   // Comprobar que el número de argumentos introducido es correcto
   if (argc != 2){

      cerr << "Error: número de argumentos introducido incorrecto" << endl;

      exit (1);

   }

   const char * nombre = "puntos";

   // Crea la colección a partir del fichero
   ColeccionPuntos2D coleccion (nombre);

   // Muestra los puntos
   for (int i = 0 ; i < coleccion.GetNum() ; i++){

      cout << "Punto " << i << ": " << endl;
      cout << "X: " << coleccion[i].GetX() << " Y: " << coleccion[i].GetY();
      cout << endl;

   }

   return 0;

}