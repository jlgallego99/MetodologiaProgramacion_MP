//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VII, Ejercicio 5
// Programa principal
//
// Divide un fichero de cualquier tipo en diferentes ficheros.
// Recibe el nombre del fichero original y el máximo número de bytes que
// contendrá cada fichero resultante.
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char ** argv){

   const int TAM_BUFFER = 256;
   
   ifstream fi;   // Flujo de entrada
   ofstream fo;   // Flujo de salida

   // Asociar el flujo de entrada al primer fichero
   fi.open(argv[1]);

   // Número máximo de bytes que contendrá cada fichero resultante
   const int MAX_BYTES = atoi(argv[2]);

   // Se calcula el tamaño del fichero
	ifstream fi2 (argv[1]);

	fi.seekg (0, ios::end);
	int tam = fi2.tellg();

	fi2.close();

   // Número de ficheros que se van a generar
   int n_ficheros = tam / MAX_BYTES;
   if (tam % MAX_BYTES) n_ficheros++;

   int bytes_escritos = 0;
   int bytes_restantes = tam;

   for (int i = 1 ; i <= n_ficheros ; i++){

      ostringstream oss_nombre;
      oss_nombre << argv[1] << "_" << i;
      string nombre = oss_nombre.str();

      ofstream fo (nombre.c_str());
      if (!fo){

         cerr << "Error: El fichero no pudo crearse" << endl;
         exit (1);

      }

      // Cálculo de bytes que caben en el bloque actual
      int bytes_actual;

      if (bytes_restantes >= MAX_BYTES){

         bytes_actual = MAX_BYTES;  // Bloque completo

      }
      else{

         bytes_actual = bytes_restantes;  // Resto de lo que queda del bloque

      }

      unsigned char buffer[TAM_BUFFER];
      int bytes_escritos = 0;
      int bytes_quedan = bytes_actual;

      while (bytes_escritos < bytes_actual){

         int a_leer;

         if (bytes_quedan > TAM_BUFFER){

            a_leer = TAM_BUFFER;

         }
         else{

            a_leer = bytes_quedan;

         }

         fi.read(reinterpret_cast <char *> (buffer), a_leer);
         int bytes_leidos = fi.gcount();

         fo.write((const char *) buffer, bytes_leidos);

         bytes_quedan -= bytes_leidos;
         bytes_escritos += bytes_leidos;

      }

   }

   fo.close();

   cout << endl;

   return 0;

}