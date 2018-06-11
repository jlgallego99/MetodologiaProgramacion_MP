//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Examen Convocatoria Ordinaria - 14 de Junio de 2017
// Declaración de la clase RedCiudades
//
//////////////////////////////////////////////////////////////////////////

#ifndef REDCIUDADES
#define REDCIUDADES

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InfoCiudad{

   char * nombre; // Nombre
   int poblacion; // Número de habitantes

};

class RedCiudades{

   private:

      int num_ciudades;    // Número de ciudades
      InfoCiudad * info;   // info[i]: info de la ciudad i
      double ** distancia; // distancia[i][j]: distancia
                           // entre las ciudades i y j

   public:

      /*******************************************************************/
      // Constructor por defecto: Crea una red vacía
      RedCiudades();

      /*******************************************************************/
      // Constructor con un argumento: Recibe el nombre de un fichero de texto
      // con la información sobre una red
      RedCiudades(const char *);

      /*******************************************************************/
      // Constructor de copia
      RedCiudades(RedCiudades &);

      /*******************************************************************/
      // Destructor
      ~RedCiudades();

      /*******************************************************************/
      // Devuelve el número de ciudades
      int NumCiudades();

      /*******************************************************************/
      // Devuelve la distancia entre dos ciudades
      double Distancia(int, int);

      /*******************************************************************/
      // Devuelve el nombre de una ciudad (en realidad, la dirección de inicio)
      char * NombreCiudad(int);

      /*******************************************************************/
      // Devuelve el número de habitantes de una ciudad
      int PoblacionCiudad(int);

      /*******************************************************************/
      // Indica si una red está vacía
      bool EstaVacia();

      /*******************************************************************/
      // Actualiza el contenido de una red con los datos de un fichero de texto
      void LeerRedCiudades(const char *);

      /*******************************************************************/
      // Guarda el contenido de una red en un fichero de texto
      void EscribirRedCiudades(const char *);

      /*******************************************************************/
      // Permite obtener el índice de la ciudad con mayor número de conexiones
      int CiudadMejorConectada();

      /*******************************************************************/
      // Dadas dos ciudades no conectadas directamente, devuelve aquella
      // ciudad intermedia que permita hacer el trayecto de la forma más
      // económica posible
      int MejorEscalaEntre(int, int);

      /*******************************************************************/
      // Sobrecarga del operador de salida << para poder insertar en un flujo
      // de salida el contenido de una red en formato texto
      friend ostream & operator << (ostream &, const RedCiudades &);

      /*******************************************************************/
      // Sobrecarga del operador de entrada >> para poder obtener desde un flujo
      // de entrada el contenido de un objeto
      friend istream & operator >> (istream &, RedCiudades &);

   private:

      /*******************************************************************/
      // Reserva memoria para una red de ciudades
      void ReservaMemoria();

      /*******************************************************************/
      // Libera la memoria de una red de ciudades
      void LiberaMemoria();
      
      /*******************************************************************/
      // Copia una red en otra
      void CopiaRed(RedCiudades &);

};

#endif