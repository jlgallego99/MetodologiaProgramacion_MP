//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 8
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

int main(){
   const int TAMANIO = 80;
   const char A_BUSCAR = ' ';
   char cadena[TAMANIO];
   char *ptr_cadena;

   cout << "Introduzca la cadena de caracteres: ";
   cin.getline(cadena, TAMANIO);

   /* Con strchr se busca la primera ocurrencia de un espacio en blanco.
   Se guarda en un puntero esa dirección, es decir, el puntero apunta
   a la cadena, pero después de la primera palabra. */
   ptr_cadena = strchr(cadena, A_BUSCAR);

   cout << "Cadena sin la primera palabra: " << ptr_cadena << endl;
}
