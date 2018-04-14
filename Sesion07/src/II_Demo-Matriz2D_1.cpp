//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 6
// Programa principal
//
// Demostración de las funciones desarrolladas en Matriz2D_1
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matriz2D_1.h"
using namespace std;

int main(){
   int fils, cols;
   int fil_inicio, col_inicio, fil_final, col_final;
   int borrar_fila, borrar_columna;

   cout << "Introduzca el número de filas y columnas de la matriz: ";
   cin >> fils >> cols;

   // a) Crea una matriz vacía
   Matriz2D_1 matriz_vacia = CreaMatriz2DVacia(fils, cols);

   // b) Libera la memoria de la matriz
   LiberaMatriz2D_1(matriz_vacia);

   // c) Crea una matriz rellenándola completamente
   Matriz2D_1 matriz = CreaMatriz2DLlena(fils, cols);

   // d) Crea una matriz rellenándola con valores aleatorios
   Matriz2D_1 matriz_aleatoria = CreaMatriz2DAleatoria(fils, cols);

   // e) Muestra los valores de las matrices
   cout << "Matriz: " << endl;
   MuestraMatriz2D(matriz);
   cout << "Matriz aleatoria: " << endl;
   MuestraMatriz2D(matriz_aleatoria);

   // f) Copia una matriz en otra y se muestra
   cout << "Matriz copia de Matriz: " << endl;
   Matriz2D_1 copia = CopiaMatriz2D(matriz);
   MuestraMatriz2D(copia);
   
   // g) Extrae una submatriz y se muestra
   cout << "Extremos entre los que extraer la submatriz: ";
   cin >> fil_inicio >> col_inicio >> fil_final >> col_final;
   Matriz2D_1 submatriz = ExtraeSubmatriz2D(copia, fil_inicio, col_inicio, 
                                            fil_final, col_final);
   cout << "Submatriz: " << endl;
   MuestraMatriz2D(submatriz);
   LiberaMatriz2D_1(submatriz);

   // h) Elimina una fila de una matriz y se muestra
   cout << "Introduzca la fila a borrar: ";
   cin >> borrar_fila;
   matriz = EliminaFilaMatriz2D(matriz, borrar_fila);
   cout << "Matriz sin la fila número " << borrar_fila << ":" << endl;
   MuestraMatriz2D(matriz);
   
   // i) Elimina una columna de una matriz y se muestra
   cout << "Introduzca la columna a borrar: ";
   cin >> borrar_columna;
   copia = EliminaColumnaMatriz2D(copia, borrar_columna);
   cout << "Matriz copia sin la columna número " << borrar_columna << ":" << endl;
   MuestraMatriz2D(copia); 

   // j) Calcula la matriz traspuesta y la muestra
   Matriz2D_1 traspuesta = TraspuestaMatriz2D(matriz);
   cout << "Matriz traspuesta de Matriz: " << endl;
   MuestraMatriz2D(traspuesta); 

   // k) Invierte las filas de la matriz
   Matriz2D_1 invertida = InvierteFilasMatriz2D(matriz_aleatoria);
   cout << "Matriz invertida de Matriz: " << endl;
   MuestraMatriz2D(matriz); 

   LiberaMatriz2D_1(traspuesta);
   LiberaMatriz2D_1(invertida);
   LiberaMatriz2D_1(matriz_aleatoria);
   LiberaMatriz2D_1(matriz);
   LiberaMatriz2D_1(copia);

   return 0;
}