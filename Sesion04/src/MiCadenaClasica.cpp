//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicios 9, 10, 11, 12, 13, 14 y 15
// Definición de funciones
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "MiCadenaClasica.h"

// Longitud de una cadena
// Recibe una cadena tipo C y calcula su longitud sin tener en cuenta
// el caracter nulo \0. Devuelve su valor
int longitud_cadena(char *ptr_cadena){
   int longitud = 0;
   bool final_cadena = false;
   const char FIN_CADENA = '\0';

   /* Algoritmo: Se recorre toda la cadena mientras que no se haya llegado
   al carácter nulo \0, aumentando la variable longitud */
   while (!final_cadena){
      if (*(ptr_cadena + longitud) == FIN_CADENA){
         final_cadena = true;
      }
      else{
         longitud++;
      }
   }

   return longitud;
}

// Palindromo
// Recibe una cadena tipo C y calcula si es un palindromo (se lee igual de
// principio a fin que de fin a principio). Devuelve un valor verdadero o falso
bool palindromo(char *ptr_cadena){
   int izda = 0, dcha = longitud_cadena(ptr_cadena) - 1;
   const char FIN_CADENA = '\0';
   bool es_palindromo = false;

   /* Algoritmo: Se recorre la cadena desde la izquierda (aumentando el 
   contador izda) y desde la derecha (decrementando el contador dcha, que ha
   sido inicializado al final de la cadena) siempre que no se lleguen a 
   a encontrar (que la izquierda esté antes que la derecha). Las dos variables 
   aumentan y decrementan respectivamente a la vez, y si hay un caracter distinto
   entonces no puede ser palindromo. Si nunca encuentra un carácter distinto, se
   sale del bucle y devuelve finalmente true porque es palindromo. */
   while (izda < dcha){
      if (*(ptr_cadena + izda) != *(ptr_cadena + dcha)){
         return false;
      }
      izda++;
      dcha--;
   }

   return true;
} 

// Comparar cadenas
// Recibe dos cadenas tipo C y las compara devolviendo un valor entre los siguientes:
//    Negativo (cadena1 menor que cadena2)
//    Positivo (cadena1 mayor que cadena2)
//    0 (Las dos son iguales)
int comparar_cadenas(char *ptr_cadena1, char *ptr_cadena2){
   int comparacion = 0;
   bool comparadas = false;
   const char FIN_CADENA = '\0';

   /* Algoritmo: Se recorren todos los caracteres de las dos cadenas, si alguna 
   de las dos llega a su fin, se termina el bucle. Mientras los dos caracteres
   tengan el mismo valor ASCII, se seguirá en el bucle y se incrementará el 
   puntero hacia el siguiente caracter de las dos cadenas. */
   while (!comparadas && (*ptr_cadena1 != FIN_CADENA) && (*ptr_cadena2 != FIN_CADENA)){
      if (*ptr_cadena1 == *ptr_cadena2){
         ptr_cadena1++;
         ptr_cadena2++;
      }
      else{
         comparadas = true;
      }
   }

   /* Ha salido del bucle y los punteros tienen ahora distintos valores, por lo 
   que se restan para que salga el valor de la comparación */
   return (*ptr_cadena1 - *ptr_cadena2);
}

// Copiar cadena
// Recibe dos cadenas y copia una cadena encima de otra
void copiar_cadena(char *ptr_cadena1, char *ptr_cadena2){
   /* Algoritmo: Se copia caracter a caracter de la segunda cadena a la primera
   desde el principio de esta. Se incluye el último caracter que acaba la 
   cadena, es decir, \0. */
   for (int i = 0 ; i <= longitud_cadena(ptr_cadena2) ; i++){
      *(ptr_cadena1 + i) = *(ptr_cadena2 + i);
   }
} 

// Encadenar cadena
// Recibe dos cadenas tipo c y concatena una con otra
void encadenar_cadena(char *ptr_cadena1, char *ptr_cadena2){
   /* La variable i es el contador en cadena1, y empieza justo en la posición
   del carácter nulo \0 */
   int i = longitud_cadena(ptr_cadena1);

   /* Algoritmo: Se copia caracter a caracter de la segunda cadena a la primera,
   pero a partir del final de la primera. Al final se incluye el caracter nulo
   que termina la cadena. Se van incrementando las dos variables contadoras
   a la vez */
   for (int j = 0 ; j <= longitud_cadena(ptr_cadena2) ; j++, i++){
      *(ptr_cadena1 + i) = *(ptr_cadena2 + j);
   }
}

// Extraer subcadena
// Recibe una cadena tipo c, una posición de inicio y una longitud de subcadena.
// Devuelve un puntero a la subcadena creada desde la posicion p y con longitud l.
char * extraer_subcadena(char *ptr_cadena, int p, int l){
   const int TAMANIO = longitud_cadena(ptr_cadena);
   char subcadena[TAMANIO];
   char *ptr_subcadena;
   const char FIN_CADENA = '\0';
   bool fin = false;
   int i = 0;

   ptr_subcadena = subcadena;

   /* Algoritmo: Se copia caracter a caracter de la cadena a la subcadena creada
   anteriormente, pero se empieza a copiar a partir de la posición de inicio p
   y hasta p+l. Se van incrementando las dos variables contadoras a la vez.
   Además, se tiene en cuenta que, si la longitud se sale de la cadena original,
   no copie más caracteres, por lo que se para de copiar una vez llegado al
   caracter nulo \0 */
   for (int j = p ; j < (p + l) && !fin ; j++, i++){
      if (*(ptr_cadena + i) == FIN_CADENA){
         fin = true;
         *(ptr_subcadena + i) = FIN_CADENA;
      }
      else{
         *(ptr_subcadena + i) = *(ptr_cadena + j);
      }
   }

   return ptr_subcadena;
} 

// Invertir cadena
// Recibe una cadena tipo c. 
// Devuelve esa misma cadena escrita de final a principio.
char * invertir_cadena(char *ptr_cadena){
   const int TAMANIO = 80;
   char cadena_invertida[TAMANIO];
   char *ptr_cadena_invertida;
   const char FIN_CADENA = '\0';
   int i, j = longitud_cadena(ptr_cadena) - 1;

   // Puntero que apunta a la cadena invertida
   ptr_cadena_invertida = cadena_invertida;

   /* Algoritmo: Se recorre toda la cadena desde el final, copiando caracter a 
   caracter en la cadena invertida. La variable contadora i aumenta a la misma
   vez que decrementa la variable contadora j, que hace que se recorra la cadena
   de final a principio. */
   for (i = 0 ; i < longitud_cadena(ptr_cadena) ; i++){
      *(ptr_cadena_invertida + i) = *(ptr_cadena + j);
      j--;
   }

   // Por último se añade el final de la cadena
   *(ptr_cadena_invertida + i) = FIN_CADENA;

   return ptr_cadena_invertida;
}
