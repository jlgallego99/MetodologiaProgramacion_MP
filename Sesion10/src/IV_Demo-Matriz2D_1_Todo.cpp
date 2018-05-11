//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 2
// Programa principal
//
// Realiza varias pruebas sobre la clase "Matriz2D_1"
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"

using namespace std;

int main(){
   TipoBase valor;
   int fil, col;
   
   // PRECONDICIÓN: Filas y columnas positivas
   do{
   
      cout << "Introduzca el número de filas y columnas para la matriz: ";
      cin >> fil >> col;
   
   }while (fil <= 0 || col <= 0);
     
   cout << "Valor para inicializar la matriz: ";
   cin >> valor;

   Matriz2D_1 m1;                   // Matriz vacía
   Matriz2D_1 m2(fil);              // Matriz cuadrada con las filas pedidas
   Matriz2D_1 m3(fil, col);         // Matriz con filas y columnas pedidas
   Matriz2D_1 m4(fil, col, valor);  // Matriz con filas y columnas inicializada
   
   /***********************************************************************/
   // a) Copia de una matriz en otra
   m1 = m4;

   cout << "Matriz copia: " << endl;
   m1.MuestraMatriz();

   /***********************************************************************/
   // b) Inicializa una matriz a un valor
   m2 = valor;

   cout << "Matriz inicializada: " << endl;
   m2.MuestraMatriz();

   /***********************************************************************/
   // c) Accede a los elementos de la matriz dinámica y modifica su valor
   // PRECONDICIÓN: Filas y columnas correctas
   do{   
   
      cout << "Introduzca la fila y la columna que desea consultar"
           << " y asignarle el valor: ";
      cin >> fil >> col;
      
   }while(fil <= 0 || fil > m4.GetFilas() || col <= 0 || col > m4.GetColumnas());

   m4(fil, col) = 1;

   cout << "La posición introducida tiene el valor: " << m4(fil, col) << endl;

   cout << "Matriz: " << endl;
   m4.MuestraMatriz();

   /***********************************************************************/
   // d) Muestra la matriz negativa
   m4 = -m4;

   cout << "Matriz negativa: " << endl;
   m4.MuestraMatriz();
   
   /***********************************************************************/
   // e) Suma y resta dos matrices
   m1 = m4 + m2;
   
   cout << "Matriz suma: " << endl;
   m1.MuestraMatriz();

   m1 = m4 - m2;

   cout << "Matriz resta: " << endl;
   m1.MuestraMatriz();

   /***********************************************************************/
   // f) Incrementar la matriz en 1 valor
   m1 += 1;

   cout << "Matriz: " << endl;
   m1.MuestraMatriz();

   /***********************************************************************/
   // g) Comprueba si las matrices son iguales

   cout << "(Matrices iguales: 1, Distintas: 0) = " << (m1 == m4) << endl; 
   
   return 0;
   
}