//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Definición de la clase "Lista"
//
// Clase que trabaja con listas dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista_ConstructorCopia.h"

using namespace std;

// a) Constructor sin argumentos:
// Crea una lista vacía
Lista :: Lista(){

   num_nodos = 0;
   sig = 0;
   
}

// b) Constructor con un argumento:
// Crea una lista con el número de nodos indicados en el argumento
Lista :: Lista(int n){

   ReservaMemoria(n);

}

// c) Constructor con dos argumentos:
// Crea una lista con el número de nodos indicados en el primer argumento 
// e inicia todos ellos al valor indicado en el segundo argumento
Lista :: Lista(int n, TipoBase val){

   ReservaMemoria(n);
   InicializaLista(val);

}

// d) Constructor de copia
Lista :: Lista(const Lista & l){

   ReservaMemoria(l.num_nodos);
   CopiaLista(l);

}

// e) Destructor
Lista :: ~Lista(){

   LiberaMemoria();

}

// f) Consulta si la lista está vacía
bool Lista :: EstaVacia(){

   return (num_nodos == 0 || sig == 0);

}

// g) Consulta el número de nodos de la lista
int Lista :: GetNumNodos(){

   return num_nodos;

}

// h) Inserta un valor en la lista
void Lista :: Insertar(TipoBase val, int pos){

   // Comprobar que la lista no está vacía y la posición es correcta
   if (pos <= num_nodos && !EstaVacia()){

      PNodo aux = sig;        // Auxiliar para recorrer los nodos
      PNodo anterior = sig;   // Guarda el nodo anterior
      int pos_actual = 1;     // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         anterior = aux;
         aux = aux->sig;
         pos_actual++;

      }

      anterior->sig = new Lista; // Se crea el nodo para el nuevo valor
      anterior = anterior->sig;

      anterior->valor = val;
      anterior->sig = aux;

      num_nodos++;

   }
}

// i) Borra un nodo en la lista
void Lista :: Borrar(int pos){

   // Comprueba previamente que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = sig;        // Auxiliar para recorrer los nodos
      PNodo anterior = sig;   // Guarda el nodo anterior
      int pos_actual = 1;     // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         anterior = aux;
         aux = aux->sig;
         pos_actual++;

      }      

      /* Se modifica la dirección del anterior nodo al borrado, 
      conteniendo ahora la dirección del siguiente al borrado */
      anterior->sig = aux->sig;  
      delete aux;

   }
}

// j) Añade un valor al final de la lista
void Lista :: AniadirValor(TipoBase val){

   // Comprobar que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = sig;  // Auxiliar para recorrer los nodos

      for (int i = 1 ; i < num_nodos ; i++){

         aux = aux->sig;

      }

      aux->sig = new Lista;   // Memoria para el nuevo nodo al final de la lista
      aux = aux->sig;
      aux->valor = val;

      num_nodos++;

   }
}

// k) Leer/Escribir un valor
TipoBase Lista :: LeerValor(int pos){

   // Comprobar que la lista no esté vacía y la posición sea correcta
   if (!EstaVacia() && pos <= num_nodos){

      PNodo aux = sig;     // Auxiliar para recorrer los nodos
      int pos_actual = 1;  // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         aux = aux->sig;
         pos_actual++;

      }

      return aux->valor;

   }
}

void Lista :: ModificarValor(int pos, TipoBase val){

   // Comprobar que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = sig;     // Auxiliar para recorrer los nodos
      int pos_actual = 1;  // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         aux = aux->sig;
         pos_actual++;

      }

      aux->valor = val;;

   }
}

// l) Inicializa todos los nodos al valor indicado como argumento
void Lista :: InicializaLista(TipoBase val){

   // Comprueba previamente que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = sig;

      while (aux != 0){
         
         aux->valor = val;
         aux = aux->sig;

      }
   }
}

// Reserva memoria para n nodos
void Lista :: ReservaMemoria(int n){

   num_nodos = 0;
   
   // Controla que el número de nodos introducidos no sea ninguno
   if (n > 0){

      // El primer nodo se trata distinto a los demás
      sig = new Lista;
      num_nodos++;

      PNodo aux = sig;  // Auxiliar para ir creando nodos en la lista

      // Crea los nodos restantes
      while (num_nodos < n){

         aux->sig = new Lista;   // Memoria para el siguiente nodo
         aux = aux->sig;         // Actualizar posición del siguiente nodo          

         num_nodos++;

      }

      aux->sig = 0; 

   }
   else{
      sig = 0; // No se crea ningún nodo
   }

}

// Libera la memoria de la lista
void Lista :: LiberaMemoria(){

   // Comprobar primero si la lista está vacía antes de borrar
   if (!EstaVacia()){

      PNodo aux = sig; // Nodo auxiliar al principio

      while (aux != 0){

         aux = aux->sig;
         delete sig;
         sig = aux;

      }

      delete sig; // Finalmente se borra el nodo que queda 
   }

   sig = 0;

}

// Copia una lista en otra
void Lista :: CopiaLista(const Lista & l){

   // Comprobar previamente que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = l.sig;   // Para recorrer los nodos de la lista argumento
      PNodo nueva = sig;   // Para recorrer los nodos de la nueva lista

      nueva->valor = aux->valor;

      while (aux->sig != 0){

         aux = aux->sig;
         nueva = nueva->sig;

         nueva->valor = aux->valor;

      }
   }
}

// Saca por pantalla la lista completa
void Lista :: PintaLista(){

   // Comprueba previamente que la lista no esté vacía
   if (!EstaVacia()){

      PNodo aux = sig;

      while (aux != 0){

         cout << (aux->valor) << " ";
         aux = aux->sig;

      }
   }

   cout << endl;

}