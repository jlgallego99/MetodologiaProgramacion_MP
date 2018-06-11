//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Examen Convocatoria Ordinaria - 14 de Junio de 2017
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "RedCiudadesExamen.h"
using namespace std;

int main(int argc, char ** argv){

   if (argc != 2){

      cerr << "ERROR: Número de argumentos introducidos incorrecto" << endl;
      exit (1);

   }

   RedCiudades red (argv[1]);

   for (int i = 0 ; i < red.NumCiudades() - 1 ; i++){

      int intermedia = red.MejorEscalaEntre(i, i+1);

      if (intermedia != -1){

         cout << "La mejor escala para las ciudades " << i << " y " << i + 1 
              << "es la ciudad intermedia: " << intermedia << endl;

      }
   }

   return 0;

}  