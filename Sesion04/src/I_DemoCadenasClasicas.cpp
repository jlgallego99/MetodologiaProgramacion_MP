//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicios 9, 10, 11, 12, 13, 14 y 15
// Programa principal, prueba todas las funciones de MiCadenaClasica.h
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MiCadenaClasica.h"
using namespace std;

int main(){
   const int TAMANIO = 80;
   int comparacion, p, l;
   char cadena1[TAMANIO], cadena2[TAMANIO];

   cout << "Introduzca una primera cadena de caracteres: ";
   cin.getline(cadena1, TAMANIO);
   cout << "Introduzca una segunda cadena de caracteres: ";
   cin.getline(cadena2, TAMANIO);

   // Ejercicio 9
   cout << "Longitud de la cadena1: " << longitud_cadena(cadena1) << endl;
   cout << "Longitud de la cadena2: " << longitud_cadena(cadena2) << endl;

   // Ejercicio 10
   if (palindromo(cadena1)){
      cout << "La primera cadena es palindromo" << endl;
   }
   else{
      cout << "La primera cadena no es palindromo" << endl;
   }

   // Ejercicio 11
   comparacion = comparar_cadenas(cadena1, cadena2);
   if (comparacion > 0){
      cout << "La primera cadena es más grande" << endl;
   }
   else if(comparacion < 0){
      cout << "La primera cadena es más pequeña" << endl;
   }
   else if (comparacion == 0){
      cout << "Las cadenas son iguales" << endl;
   }

   // Ejercicio 12
   copiar_cadena(cadena1, cadena2);
   cout << "Cadena 1 copiada de la 2: " << cadena1 << endl;

   // Ejercicio 13
   encadenar_cadena(cadena1, cadena2);
   cout << "Cadenas encadenadas: " << cadena1 << endl;

   // Ejercicio 14
   cout << "Introduzca la posicion de inicio y la longitud sobre la cadena 1: "
   cin >> p >> l;
   cout << "La cadena extraida de la cadena 1: " << extraer_subcadena(cadena1, p, l)
        << endl;

   // Ejercicio 15
   cout << "La cadena 1 invertida: " << invertir_cadena(cadena1) << endl;

   return 0;
}
