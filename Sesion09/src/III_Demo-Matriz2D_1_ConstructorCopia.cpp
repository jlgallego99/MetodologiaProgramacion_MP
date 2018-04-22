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
// Realiza varias pruebas sobre la clase "Matriz2D_1"
//
//////////////////////////////////////////////////////////////////////////

#include "Matriz2D_1_ConstructorCopia.h"
#include <iostream>

using namespace std;

int main(){
   TipoBase valor;
   int fil, col;

   cout << "Introduzca el número de filas y columnas para la matriz: ";
   cin >> fil >> col;
   cout << "Valor para inicializar la matriz: ";
   cin >> valor;

   Matriz2D_1 m1;                   // Matriz vacía
   Matriz2D_1 m2(fil);              // Matriz cuadrada con las filas pedidas
   Matriz2D_1 m3(fil, col);         // Matriz con filas y columnas pedidas
   Matriz2D_1 m4(fil, col, valor);  // Matriz con filas y columnas inicializada

   // Comprueba si las matrices están vacías

   cout << "Matriz vacía: 1, Matriz no vacía: 0" << endl;
   cout << "M1: " << m1.EstaVacia() << endl;
   cout << "M2: " << m2.EstaVacia() << endl;
   cout << "M3: " << m3.EstaVacia() << endl;
   cout << "M4: " << m4.EstaVacia() << endl;
   
   // Muestra la matriz 4, pide que modifique un valor, y se vuelve a mostrar

   cout << "Matriz 4: " << endl;
   m4.MuestraMatriz();

   cout << "¿Qué valor desea modificar? "
        << "Introduzca el valor, y la fila y columna donde desea colocarlo: ";
   cin >> valor >> fil >> col;

   m4.ModificarValor(fil, col, valor);

   cout << "Se ha modificado la fila " << fil << ", columna " << col
        << ". El valor introducido ha sido: " << m4.LeerValor(fil, col) << endl;

   cout << "Matriz 4: " << endl;
   m4.MuestraMatriz();

   return 0;

}