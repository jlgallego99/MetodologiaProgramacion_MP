//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 19
// Definición de las distintas funciones sobrecargadas: "LeeEntero" necesarias
// para I_LeeEntero.cpp
//
// Lee y devuelve un número entero usando una cadena de caracteres.
// Comprueba que todos los caracteres son dígitos para convertirlos a enteros. 
// Si es correcto los devuelve, si no, vuelve a pedirlos
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

int LeeEntero(){
   const int TAMANIO = 100;
   int i = 0;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   cout << "Introduzca el número entero: ";
   cin.getline(cadena_enteros, TAMANIO);

   /* Algoritmo: Se analiza caracter a caracter viendo si es un entero.
   Mientras la cadena de caracteres no sea correcta (no contenga únicamente 
   números enteros) se volverá a pedir una cadena */
   while (!correcto){
      // Únicamente si se ha analizado toda la cadena se termina el bucle
      if (i == strlen(cadena_enteros)){
         correcto = true;
      }
      else if (isdigit(cadena_enteros[i])){
         i++; // Correcto. Sigue la comprobación con el siguiente carácter
      }
      else{
         cout << "Incorrecto. Introduzca de nuevo el número entero: ";
         cin.getline(cadena_enteros, TAMANIO);
         i = 0; // Se reinicia el contador de la cadena
      }
   }

   // Devolución de la cadena transformada a entero
   return atoi(cadena_enteros);
}

int LeeEntero(int pos_final){
   int numero;
   const int TAMANIO = 100;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   /* Algoritmo: Llamada a LeeEnteros sin argumentos para asegurarnos de que la 
   cadena sea un número entero, y luego nos aseguramos de que esté dentro del 
   intervalo. Si no lo está, se sigue pidiendo hasta que esté */
   numero = LeeEntero();
   while(!correcto){
      /* Sólo cuando el número esté entre el 0 y la posición final, entonces se
      saldrá del bucle y se terminará de pedir el número */
      if (numero >= 0 && numero <= pos_final){
         correcto = true;
      }
      else{
         numero = LeeEntero();
      }
   }

   return numero;
}

int LeeEntero(int pos_inicial, int pos_final){
   int numero;
   const int TAMANIO = 100;
   char cadena_enteros[TAMANIO];
   bool correcto = false;

   /* Algoritmo: Llamada a LeeEnteros sin argumentos para asegurarnos de que la 
   cadena sea un número entero, y luego nos aseguramos de que esté dentro del 
   intervalo. Si no lo está, se sigue pidiendo hasta que esté */
   numero = LeeEntero();
   while(!correcto){
      /* Sólo cuando el número esté entre la posición inicial y la posición 
      final, entonces se saldrá del bucle y se terminará de pedir el número */
      if (numero >= pos_inicial && numero <= pos_final){
         correcto = true;
      }
      else{
         cout << "Incorrecto. Introduzca de nuevo el número del intervalo: ";
         cin >> numero;
      }
   }

   return numero;
}