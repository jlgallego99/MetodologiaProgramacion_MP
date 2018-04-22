//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Programa principal
//
// Realiza varias pruebas sobre la clase "Lista"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista_ConstructorCopia.h"

using namespace std;

int main(){
   int n;
   TipoBase val;

   cout << "Introduzca el tamaño de la lista: ";
   cin >> n;
   cout << "Introduzca el valor para inicializar la lista: ";
   cin >> val;

   Lista l1;         // Lista vacía
   Lista l2(n);      // Lista con n nodos
   Lista l3(n, val); // Lista con n nodos, inicializada a un valor
   Lista l4(l3);     // Lista copia de l3

   // Se muestran las listas
   cout << "Lista 3: ";
   l3.PintaLista();
   cout << "Lista 4: ";
   l4.PintaLista(); 

   // Pide insertar un valor en la lista
   cout << "Valor a insertar en la lista 4: ";
   cin >> val;
   cout << "Posición en la que insertarlo: ";
   cin >> n;

   l4.Insertar(val, n);

   cout << "Lista 4: ";
   l4.PintaLista();

   // Muestra un valor de la lista
   cout << "El valor introducido ha sido: " << l4.LeerValor(n) << endl;

   // Modifica un valor de la lista
   cout << "Posición del valor que quiere cambiar: ";
   cin >> n;
   cout << "Valor a insertar: ";
   cin >> val;

   l4.ModificarValor(n, val);

   cout << "Lista 4: ";
   l4.PintaLista();

   // Añadir un valor al final de la lista
   cout << "Introduzca el valor para añadir al final de la lista: ";
   cin >> val;

   l4.AniadirValor(val);

   cout << "Lista 4: ";
   l4.PintaLista();

   // Borrar un nodo en la lista
   cout << "Introduzca el nodo que quiere borrar: ";
   cin >> n;

   l4.Borrar(n);

   cout << "Lista 4: ";
   l4.PintaLista();

   return 0;

}