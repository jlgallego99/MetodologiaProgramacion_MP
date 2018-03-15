//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 7
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;

int main(){
   const int TAMANIO = 80;
   const char A_BUSCAR = ' ';
   char cadena[TAMANIO];
   char *ptr_cadena, *ultimo;
   bool blanco = false;
   int i = 0;
   
   cout << "Introduzca la cadena de caracteres: ";
   cin.getline(cadena, TAMANIO);
	
	// Puntero que apunta al final de la cadena tipo C.
   ultimo = &cadena[strlen(cadena)];

   // Puntero que apunta al principio de la cadena tipo C.
   ptr_cadena = cadena;

   // Algoritmo. Recorre todo el vector mientras el carácter no sea blanco.
   // Si lo es, se sale del bucle. Si nunca llega a un blanco, termina cuando
   // llegue al final. Para ello, se va incrementando un contador "i".
   while (!blanco && (ptr_cadena + i) < ultimo){
      if (*(ptr_cadena + i) == A_BUSCAR){
         blanco = true;
      }
      else{
         i++;
      }
   }

   if (blanco)
      cout << "El primer blanco de la cadena está en la posición: " << i << endl;
   else
      cout << "No hay espacios" << endl;

   return 0;
}

