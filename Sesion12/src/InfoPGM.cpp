//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI, Ejercicio 17
// Programa principal
//
// Recibe el nombre de un fichero PGM y muestra la información de su cabecera
//
//////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char ** argv){

   // Comprobar que el número de argumentos introducido es correcto
   if (argc != 2){

      cerr << "Error: número de argumentos introducido incorrecto" << endl;

      exit (1);

   }

   char tipo[50]; // Tipo de fichero
   int c;         // Ancho/número de columnas de la imagen: número de píxeles de una fila
   int f;         // Alto/filas de la imagen: número de píxeles de una columna
   int m;         // Valor máximo de gris (rango de valores [0, m])

   ifstream fi;      // Flujo de entrada del fichero
   fi.open(argv[1]); // Asociar el flujo de entrada al fichero
   string linea;     // Cada línea del fichero

   istringstream iss;
   
   fi >> tipo;
   cout << tipo << endl;

   getline(fi, linea);

   // Se pasan las líneas con comentarios que empiezan por #
   while (!fi.eof() && linea[0] == '#'){
         
      cout << linea << endl;
      getline(fi, linea);

   }
   
   iss.str(linea);

   iss >> c;
   iss >> f;
   fi >> m;

   // Se muestran los datos
   cout << "Ancho (c): " << c << " pixeles" << endl;
   cout << "Alto (f): " << f << " pixeles" << endl;
   cout << "Rango de valores para cada valor de luminosidad: " 
        << "[0, " << m << "]" << endl;

   fi.close();

   return 0;

}