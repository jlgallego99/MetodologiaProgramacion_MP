//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI, Ejercicio 6
// Programa principal
//
// Prueba tres nuevos métodos de la clase Lista que usan un fichero de 
// texto en el que los datos están separados por caracteres separadores
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"
using namespace std;

int main(){
   
   const char * nombre = "ejercicio6"; // Nombre del fichero

   // Crea una lista rellenando los nodos con los datos del fichero
   Lista l(nombre);

   cout << "Lista: " << endl;
   PintaLista(l);

   // Guarda en un nuevo fichero el contenido de la lista
   nombre = "ejercicio6_copia";
   l.EscribirLista(nombre);

   // Sustituye el contenido de la lista por los valores de otro fichero
   nombre = "ejercicio6_nuevo";
   l.LeerLista(nombre);

   cout << "Nueva lista: " << endl;
   PintaLista(l);

   return 0;

}