//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV
// Programa principal
//
// Realiza varias pruebas sobre la clase "Lista"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
   int n;
   TipoBase val;

   // PRECONDICIÓN: Número de nodos positivo
   do{

      cout << "Introduzca el tamaño de la lista: ";
      cin >> n;

   }while (n <= 0);

   cout << "Introduzca el valor para inicializar la lista: ";
   cin >> val;

   Lista l1(n, val); // Lista con n nodos, inicializada a un valor
   Lista l3;         // Lista vacía

   cout << "Lista 1: ";
   l1.PintaLista();

   /***********************************************************************/
   // a) Copia de una lista en otra

   Lista l2 = l1;

   cout << "Lista 2: ";
   l2.PintaLista(); 

   /***********************************************************************/
   // b) Inicializa la lista a un valor

   cout << "Introduzca un valor para inicializar la lista 1: ";
   cin >> val;

   l1 = val;

   cout << "Lista 1: ";
   l1.PintaLista();

   /***********************************************************************/
   // c) Modifica un valor de la lista y lo muestra

   // PRECONDICIÓN: Número de nodos positivo
   do{
      
      cout << "Introduzca el nodo que quiere modificar de la lista 2: ";
      cin >> n;

   }while (n <= 0);
   
   cout << "Introduzca el valor a introducir en el nodo número " << n << ": ";
   cin >> val;

   l2[n] = val;

   cout << "El valor introducido ha sido: " << l2[n] << endl;

   cout << "Lista 2: ";
   l2.PintaLista(); 

   /***********************************************************************/
   // d) Añade y elimina un nodo

   cout << "Introduzca el valor del nodo que quiere añadir a la lista 1: ";
   cin >> val;

   l1 += val;

   cout << "Lista 1: ";
   l1.PintaLista();

   cout << "Introduzca el valor del nodo que quiere eliminar en la lista 1: ";
   cin >> val;

   l1 -= val;

   cout << "Lista 1: ";
   l1.PintaLista();


   /***********************************************************************/
   // e) Suma y resta dos listas, y suma y resta un número a una lista
   /*
   l3 = l1 + l2;

   cout << "Lista 3 (suma de lista 1 y lista 2): ";
   l3.PintaLista();

   l3 = l3 + 1;
   l3 = 1 + l3;

   cout << "Lista 3 con dos 1 al final: ";
   l3.PintaLista();

   l3 = l3 - 1;
   l3 = 1 - l3;

   cout << "Lista 3 sin los dos 1 anteriores: ";
   l3.PintaLista();

   l3 = l1 - l2;

   cout << "Lista 3 (resta de lista 1 y lista 2): ";
   l3.PintaLista(); */

   /***********************************************************************/
   // f) Comparación de listas
   cout << "Comparación de las listas 1 y 3: " << endl;

   cout << "(Listas iguales: 1. Listas distintas = 0): " << (l1 == l3) << endl;
   cout << "(Lista 1 mayor que 3: 1. Lista 1 menor que 3 = 0): " << (l1 > l3)
        << endl;

   return 0;
   
}