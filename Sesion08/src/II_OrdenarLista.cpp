//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 13
// Programa principal
//
// Demostración de las funciones desarrolladas en la biblioteca de Listas:
// EstaOrdenada y OrdenaSeleccionLista
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"
using namespace std;

int main(){
   Lista lista;

   // Se pide una lista de números y se muestra 
   LeeLista(lista);
   PintaLista(lista);

   if (EstaOrdenada(lista)){
      cout << "La lista está ordenada" << endl;
   }
   else{
      cout << "La lista no está ordenada" << endl;
   }

   // Se ordena la lista, se muestra, y comprueba si está ordenada
   OrdenaSeleccionLista(lista);
   PintaLista(lista);

   if (EstaOrdenada(lista)){
      cout << "La lista está ordenada" << endl;
   }
   else{
      cout << "La lista no está ordenada" << endl;
   }

   return 0;
}