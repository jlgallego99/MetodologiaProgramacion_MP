//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 11
// Definición de la clase "RedCiudades"
//
// Clase que trabaja con una red de ciudades
//
//////////////////////////////////////////////////////////////////////////

#include "RedCiudades.h"
#include <cstring>
#include <iostream>

using namespace std;

/*************************************************************************/
// Métodos públicos

RedCiudades :: RedCiudades()
   :num_ciudades(0), info(0), distancia(0)
{
}

RedCiudades :: RedCiudades(int n)
   :num_ciudades(n)
{

   ReservaMemoria(n);

   for (int i = 0 ; i < NumCiudades() ; i++){

      for (int j = 0 ; j < NumCiudades() ; j++){

         cin >> distancia[i][j];

      }
   }
}

RedCiudades :: RedCiudades(const RedCiudades & red)
   :num_ciudades(red.num_ciudades)
{

   ReservaMemoria(num_ciudades);
   CopiarDatos(red);

}

RedCiudades :: ~RedCiudades(){

   LiberaMemoria();

}

void RedCiudades :: SetDistancia(int c1, int c2, double d){

   distancia[c1][c2] = d;

}

int RedCiudades :: NumCiudades(){

   return num_ciudades;

}

double RedCiudades :: Distancia(int c1, int c2){

   return distancia[c1][c2];

}

char * RedCiudades :: NombreCiudad(int c){

   return info[c].nombre;

}

int RedCiudades :: PoblacionCiudad(int c){

   return info[c].poblacion;

}

bool RedCiudades :: EstaVacia(){

   return (num_ciudades == 0);

}

int RedCiudades :: CiudadMejorConectada(){

   int mayor = 0;
   int pos_mayor;

   for (int i = 0 ; i < num_ciudades ; i++){

      // Número de conexiones de cada ciudad
      int conexiones = 0;

      // Se recorren todas las ciudades
      for (int j = 0 ; j < num_ciudades ; j++){

         if (distancia[i][j] > 0){

            conexiones++;

         }
      }

      if (conexiones > mayor){

         // Nueva ciudad con mayor número de conexiones
         pos_mayor = i;
         mayor = conexiones;

      }
   }

   return pos_mayor;

}

int RedCiudades :: MejorEscalaEntre(int c1, int c2){

   int intermedia;
   int i = c1;
   int menor = 9999;
   bool encontrado = false;

   for (int j = 0 ; j < num_ciudades ; j++){

      if (distancia[i][j] > 0){

         if ((distancia[j][c2] + distancia[i][j]) < menor){

            // Nueva distancia mínima
            menor = distancia[j][c2] + distancia[i][j];
            intermedia = j;
            encontrado = true;

         }
      }
   }

   if (encontrado){

      return intermedia;

   }
   else{

      return -1;

   }
}

/*************************************************************************/
// Métodos privados

void RedCiudades :: ReservaMemoria(const int n){

   // Memoria para el vector de InfoCiudad
   info = new InfoCiudad [n];

   // Se crea el vector de punteros
   distancia = new double * [n];

   // Se crean todas las filas
   for (int i = 0 ; i < n ; i++){

      distancia[i] = new double [n];

   }
}

void RedCiudades :: LiberaMemoria(){

   if (info != 0){

      delete [] info;

   }

   if (distancia != 0){

      for (int i = 0 ; i < num_ciudades ; i++){

         delete [] distancia[i];

      }

      delete [] distancia;
   
   }

   info = 0;
   distancia = 0;
   
}

void RedCiudades :: CopiarDatos(const RedCiudades & red){

   const int n = red.num_ciudades;

   // Se copia el vector de InfoCiudad
   memcpy(info, red.info, n * sizeof(InfoCiudad));

   // Se copia la matriz de distancias
   for (int i = 0 ; i < n ; i++){

		memcpy(distancia[i], red.distancia[i], n * sizeof(double));		

	}

   num_ciudades = red.num_ciudades;

}