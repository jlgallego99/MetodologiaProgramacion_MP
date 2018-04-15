//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 15
// Programa principal
//
// Demostración de las funciones desarrolladas en la biblioteca de Listas:
// MezclaListas
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
   Lista lista, lista1, lista2;

   // Se leen dos listas y se muestran
   LeeLista(lista1);
   cout << "- 1." << endl;
   PintaLista(lista1);
   LeeLista(lista2);
   cout << "- 2." << endl;
   PintaLista(lista2);

   // Se mezclan las listas
   MezclaListas(lista, lista1, lista2);
   cout << "- Mezcla." << endl;
   PintaLista(lista);

   return 0;
}