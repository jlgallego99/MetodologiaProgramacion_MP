//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Examen Convocatoria Ordinaria - 14 de Junio de 2017
// Definición de la clase RedCiudades
//
//////////////////////////////////////////////////////////////////////////

#include "RedCiudadesExamen.h"

RedCiudades :: RedCiudades()
   :num_ciudades(0), info(0), distancia(0)
{   
}

RedCiudades :: RedCiudades(RedCiudades & red)
   :num_ciudades(red.num_ciudades)
{

   ReservaMemoria();
   CopiaRed(red);

}

RedCiudades :: RedCiudades(const char * nombre){

   LeerRedCiudades(nombre);

}

RedCiudades :: ~RedCiudades(){

   LiberaMemoria();

}

int RedCiudades :: NumCiudades(){

   return num_ciudades;

}

double RedCiudades :: Distancia(int ciudad1, int ciudad2){

   return distancia[ciudad1][ciudad2];

}

char * RedCiudades :: NombreCiudad(int ciudad){

   return info[ciudad].nombre;

}

int RedCiudades :: PoblacionCiudad(int ciudad){

   return info[ciudad].poblacion;

}

bool RedCiudades :: EstaVacia(){

   return (num_ciudades == 0);   // Una red está vacía si no tiene ciudades 

}

void RedCiudades :: LeerRedCiudades(const char * nombre){

   ifstream fi (nombre);
   char cadena[100];

   fi >> cadena;

   if (!strcmp(cadena, "RED")){

      fi >> (*this);

   }

}

void RedCiudades :: EscribirRedCiudades(const char * nombre){

   ofstream fo (nombre);

   fo << "RED" << endl;
   fo << (*this);

}

int RedCiudades :: CiudadMejorConectada(){

   int mayor_conexiones = 0, mayor_ciudad = 0, conexiones = 0;

   for (int i = 0 ; i < num_ciudades ; i++){

      for (int j = 0 ; j < num_ciudades ; j++){

         if (distancia[i][j] > 0){

            conexiones++;

         }
      }

      if (conexiones > mayor_conexiones){

         mayor_conexiones = conexiones;
         mayor_ciudad = i;
         conexiones = 0;

      }
   }

   return mayor_ciudad;

}

int RedCiudades :: MejorEscalaEntre(int ciudad1, int ciudad2){

   int costo = 0, intermedia = -1, menor_costo = 99999;

   for (int i = ciudad1 ; i < num_ciudades ; i++){

      for (int j = 0 ; j < num_ciudades ; j++){

         if (distancia[i][j] > 0){

            costo = distancia[i][j] + distancia[ciudad2][i];

            if (costo < menor_costo){

               menor_costo = costo;
               intermedia = j;

            }
         }
      }
   }

   return intermedia;

}

ostream & operator << (ostream & out, const RedCiudades & red){

   out << red.NumCiudades() << endl;

   for (int i = 0 ; i < red.NumCiudades() ; i++){

      out << i << " " << red.NombreCiudad(i) << " " << red.PoblacionCiudad(i);
      out << endl;

   }

   for (int i = 0 ; i < num_ciudades ; i++){

      for (int j = 0 ; j < num_ciudades ; j++){

         if (red.Distancia[i][j] > 0){

            out << i << " " << j << " " << red.Distancia(i, j) << endl;

         }
      }
   }

   return out;

}

istream & operator >> (istream & in, RedCiudades & red){

   red.LiberaMemoria();

   in >> red.num_ciudades;

   red.ReservaMemoria();

   int indice;

   for (int i = 0 ; i < red.NumCiudades() ; i++){

      in >> indice;
      in >> red.info[indice].nombre;
      in >> red.info[indice].poblacion;

   }

   int i, j;

   while (in >> i){

      in >> j;

      in >> red.distancia[i][j];

      red.distancia[j][i] = red.distancia[i][j];

   }

   return in;

}

void RedCiudades :: ReservaMemoria(){

   const int MAX_NOMBRE = 50; // Longitud máxima del nombre de la ciudad

   info = new InfoCiudad [num_ciudades];  // Memoria para el vector de info

   // Memoria para los distintos nombres
   for (int i = 0 ; i < num_ciudades ; i++){

      info[i].nombre = new char [MAX_NOMBRE];

   }

   // Memoria para la matriz de distancias
   distancia = new double * [num_ciudades];

   for (int i = 0 ; i < num_ciudades ; i++){

      distancia[i] = new double [num_ciudades]; 

      for (int j = 0 ; j < num_ciudades ; j++){

         // Inicializar todas las casillas a 0
         distancia[i][j] = 0;

      }
   }

}

void RedCiudades :: LiberaMemoria(){

   if (info != 0){

      for (int i = 0 ; i < num_ciudades ; i++){

         delete [] info.nombre[i];

      }

      delete [] info;

      info = 0;

   }

   if (distancia != 0){

      for (int i = 0 ; i < num_ciudades ; i++){

         delete [] distancia[i];

      }

      delete [] distancia;

      distancia = 0;

   }

   num_ciudades = 0;

}

void RedCiudades :: CopiaRed(RedCiudades & red){

   num_ciudades = red.num_ciudades;

   for (int i = 0 ; i < num_ciudades ; i++){

      info[i].nombre = red.info[i].nombre;
      info[i].poblacion = red.info[i].poblacion;

   }

   for (int i = 0 ; i < num_ciudades ; i++){

      memcpy(distancia[i], red.distancia[i], num_ciudades*sizeof(double));

   }

}