//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Examen prácticas 1 (2016 - 2017)
// Programa principal
//
// Prueba la función "Lista" que trabaja con listas dinámicas
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Lista.h"
using namespace std;

int main(int argc, char * argv[]){

   int pos_inicio = 1;
   int salto = 1;

   if (argc > 3){

      cerr << "Error. Número de argumentos introducidos incorrecto." << endl
           << "Uso: Primer argumento posición inicial, segundo argumento salto"
           << endl;
      
      exit (1);

   }

   if (argc >= 2){

      pos_inicio = atoi(argv[1]);

      if (argc == 3){

         salto = atoi(argv[2]);

      }
   }

   cout << "Posición inicial: " << pos_inicio << endl;
   cout << "Salto: " << salto << endl;

   // Lee una secuencia de valores enteros positivos, los guarda en una lista 
   // enlazada y los muestra. 

   Lista l;

   LeeLista(l);
   PintaLista(l);

   cout << "Número de elementos: " << CuentaElementos(l) << endl;

   // Crear una nueva lista seleccionando algunos elementos de la lista original

   Lista l2;

   Selecciona(l2, l, pos_inicio, salto);
   PintaLista(l2);

   cout << "Número de elementos: " << CuentaElementos(l2) << endl;

   // Liberar el espacio de las listas

   LiberaLista(l);
   LiberaLista(l2);

   return 0;

}