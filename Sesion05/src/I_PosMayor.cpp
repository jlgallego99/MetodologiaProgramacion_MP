//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 18
// Programa principal
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cctype>
#include "VectorAleatorio.h"
#include "PosMayor.h"
using namespace std;

int main(int argc, char *argv[]){
   const int TOPE = 100;
   int vector[TOPE];
   int *pos_mayor;

   // El programa se ejecuta sin argumentos: Se rellena completamente
   // Calcula el mayor valor de todo el vector
   if (argc == 1){
      VectorAleatorio(vector, 0, TOPE);
      pos_mayor = PosMayor(vector, 0, TOPE - 1);
   }
   // El programa se ejecuta con un argumento n: Se rellenan n casillas
   // Calcula el mayor valor entre ellas
   else if (argc == 2){
      VectorAleatorio(vector, 0, atoi(argv[1]));
      pos_mayor = PosMayor(vector, 0, atoi(argv[1]) - 1);
   }
   // El programa se ejecuta con dos argumentos n y d: Se rellenan n casillas
   // Calcula el mayor valor entre las casillas 0 y d
   else if (argc == 3){
      VectorAleatorio(vector, 0, atoi(argv[1]));
      pos_mayor = PosMayor(vector, 0, atoi(argv[2]) - 1);
   }
   // El programa se ejecuta con tres argumentos n, i y d: Se rellenan n casillas
   // Calcula el mayor valor entre las casillas i y d
   else if (argc == 4){
      VectorAleatorio(vector, 0, atoi(argv[1]));
      pos_mayor = PosMayor(vector, atoi(argv[2]), atoi(argv[3]) - 1);
   }
   // El programa se ejecuta con más de tres argumentos: Mensaje de error
   else if (argc > 4){
      cout << "Error, demasiados argumentos introducidos" << endl;
   }

   cout << "El elemento mayor es: " << *pos_mayor << endl;;

   return 0;
}