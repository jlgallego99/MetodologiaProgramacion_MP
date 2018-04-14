//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II
// Definición de funciones
//
// Funciones relativas a una matriz dinámica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include "Matriz2D_1.h"
#include "VectorAleatorio.h"
#include <iostream>
#include <cstring>
using namespace std;

/* a) Crea (reserva memoria) para una matriz de TipoBase. 
El contenido de la matriz queda indefinido */
Matriz2D_1 CreaMatriz2DVacia(int num_fils, int num_cols){
   Matriz2D_1 m;
   
   // Iniciadas filas y columnas por defecto a 0 (no hay matriz)
   m.fils = 0;
   m.cols = 0;

   // Si los datos son correctos (no tiene sentido filas o columnas negativas)
   if (num_fils > 0 && num_cols > 0){
      // Reserva de memoria para el vector de punteros
      m.datos = new TipoBase * [num_cols];

      // Reserva de memoria para cada fila de la matriz
      for (int f = 0 ; f < num_fils ; f++){
         m.datos[f] = new int [num_cols];
      }

      m.fils = num_fils;
      m.cols = num_cols;
   }

   return m;
}

/* b) Libera la memoria ocupada por una matriz de este tipo.
Deja la matriz vacía */
void LiberaMatriz2D_1(Matriz2D_1 & matriz){
   // Liberar la memoria ocupada por las filas
   for (int f = 0 ; f < matriz.fils ; f++){
      delete [] matriz.datos[f];
   }

   // Liberar la memoria que ocupa el vector de punteros
   delete [] matriz.datos;
}

/* c) Crea (reserva memoria) para una matriz de TipoBase y lee valores para
rellenar completamente la matriz */
Matriz2D_1 CreaMatriz2DLlena(int num_fils, int num_cols){
   Matriz2D_1 m = CreaMatriz2DVacia(num_fils, num_cols);
   TipoBase valor;

   cout << "Introduzca los datos en la matriz para rellenarla completamente: "
        << endl;
   for (int i = 0 ; i < num_fils ; i++){
      for (int j = 0 ; j < num_cols ; j++){
         cin >> valor;
         m.datos[i][j] = valor;
      }
   }

   return m;
}

// d) Crea una matriz y rellena todas las casillas con valores aleatorios 
Matriz2D_1 CreaMatriz2DAleatoria(int num_fils, int num_cols){
   Matriz2D_1 m = CreaMatriz2DVacia(num_fils, num_cols);

   for (int i = 0 ; i < num_fils ; i++){
      VectorAleatorio(m.datos[i], 0, num_cols);
   }

   return m;
}

// e) Muestra los valores guardados en la matriz
void MuestraMatriz2D(Matriz2D_1 matriz){
   for (int i = 0 ; i < matriz.fils ; i++){
      for (int j = 0 ; j < matriz.cols ; j++){
         cout << " " << matriz.datos[i][j];
      }
      cout << endl;
   }

   cout << endl;
}

/* f) Recibe una matriz y crea y devuelve una copia profunda. 
La copia es una nueva matriz */
Matriz2D_1 CopiaMatriz2D(Matriz2D_1 matriz){
   Matriz2D_1 matriz_copia = CreaMatriz2DVacia(matriz.fils, matriz.cols);

   for (int i = 0 ; i < matriz.fils ; i++){
      memcpy(matriz_copia.datos[i], matriz.datos[i], matriz.cols*sizeof(TipoBase));
   }

   return matriz_copia;
}

// g) Extrae una submatriz
Matriz2D_1 ExtraeSubmatriz2D(Matriz2D_1 matriz, int fil_inicio, int col_inicio, 
                             int fil_final, int col_final){
   // Dimensión de la submatriz (número de filas y columnas)
   int num_fils = fil_final - fil_inicio + 1;
   int num_cols = col_final - col_inicio + 1;
   Matriz2D_1 submatriz = CreaMatriz2DVacia(num_fils, num_cols);

   int a = 0, b;
   for (int i = fil_inicio ; i < fil_final ; i++){
      b = 0;
      for (int j = col_inicio ; j < col_final ; j++){
         submatriz.datos[a][b] = matriz.datos[i][j];
         b++;
      }
      a++;
   }  

   return submatriz;
}

// h) Elimina una fila de una matriz
Matriz2D_1 EliminaFilaMatriz2D(Matriz2D_1 matriz, int borrar_fila){
   // Se crea la nueva matriz con una fila menos
   Matriz2D_1 nueva_matriz = CreaMatriz2DVacia(matriz.fils - 1, matriz.cols);

   // Copia todas las filas hasta la fila que se quiere borrar (sin incluir)
   for (int i = 0 ; i < borrar_fila ; i++){
      memcpy(nueva_matriz.datos[i], matriz.datos[i], 
             matriz.cols*sizeof(TipoBase));
   }

   // Copia todas las filas desde la fila que se quiere borrar (sin incluir)
   for (int i = borrar_fila + 1 ; i < matriz.fils ; i++){
      memcpy(nueva_matriz.datos[i - 1], matriz.datos[i], 
             matriz.cols*sizeof(TipoBase));
   }

   return nueva_matriz;
}

// i) Elimina una columna de una matriz
Matriz2D_1 EliminaColumnaMatriz2D(Matriz2D_1 matriz, int borrar_columna){
   // Se crea la nueva matriz con una columna menos
   Matriz2D_1 nueva_matriz = CreaMatriz2DVacia(matriz.fils, matriz.cols - 1);

   for (int i = 0 ; i < matriz.fils ; i++){ 
      /* Se copian todas las columnas hasta la columna que se quiere borrar 
      (sin incluir) */
		memcpy (nueva_matriz.datos[i], matriz.datos[i], 
              borrar_columna*sizeof(TipoBase));

      /* Se copian todas las columnas desde la columna que se quiere borrar 
      (sin incluir) */
		memcpy (&(nueva_matriz.datos[i][borrar_columna]), 
             &(matriz.datos[i][borrar_columna+1]), 
			    (matriz.cols-borrar_columna-1)*sizeof(TipoBase));
	}
   
   return nueva_matriz;
}

// j) Devuelve una matriz traspuesta
Matriz2D_1 TraspuestaMatriz2D(Matriz2D_1 matriz){
   Matriz2D_1 traspuesta = CreaMatriz2DVacia(matriz.fils, matriz.cols);

   // Se copian los valores al revés (cambiando columnas por filas)
   for (int i = 0 ; i < matriz.fils ; i++){
      for (int j = 0 ; j < matriz.cols ; j++){
         traspuesta.datos[i][j] = matriz.datos[j][i];
      }
   }

   return traspuesta;
}

// k) Invierte las filas de una matriz
Matriz2D_1 InvierteFilasMatriz2D(Matriz2D_1 matriz){
   // La nueva matriz es primeramente una copia de la original
   Matriz2D_1 filas_invertidas = CopiaMatriz2D(matriz);

   // Variables con los extremos izquierdo y derecho de cada vector
   int izda = 0, dcha = matriz.fils - 1;
   // Copia temporal para intercambiar datos
   TipoBase * copia;

   while (izda < dcha){
      // Se intercambian las direcciones de principio en la del final y viceversa para que el final esté en el principio
      copia = filas_invertidas.datos[dcha];
      filas_invertidas.datos[izda] = filas_invertidas.datos[dcha];
      filas_invertidas.datos[dcha] = copia;
      
      // Se va achicando el intervalo de vector
      izda++;
      dcha--;
   }

   return filas_invertidas;
}