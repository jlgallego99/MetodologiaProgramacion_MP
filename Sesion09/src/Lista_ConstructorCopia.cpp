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

Lista :: Lista()
   :num_nodos(0), primero(0)
{   
}

Lista :: Lista(int n)
   :num_nodos(n)
{

   ReservaMemoria(n);

}

Lista :: Lista(int n, TipoBase val)
   :num_nodos(n)
{

   ReservaMemoria(n);
   InicializaLista(val);

}

Lista :: Lista(const Lista & l){

   ReservaMemoria(l.num_nodos);
   CopiaLista(l);

}

Lista :: ~Lista(){

   LiberaMemoria();

}

bool Lista :: ListaVacia() const{

   return (num_nodos == 0 || primero == 0);

}

int Lista :: GetNumNodos() const{

   return num_nodos;

}

void Lista :: Insertar(TipoBase val, int pos){

   // Comprobar que la lista no está vacía y la posición es correcta
   if (ListaVacia()){

      PNodo aux = primero;       // Auxiliar para recorrer los nodos
      PNodo anterior = primero;  // Guarda el nodo anterior
      int pos_actual = 1;        // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         anterior = aux;
         aux = aux->sig;
         pos_actual++;

      }

      anterior->sig = new TipoNodo; // Se crea el nodo para el nuevo valor
      anterior = anterior->sig;

      anterior->valor = val;
      anterior->sig = aux;

      num_nodos++;

   }
}

void Lista :: Borrar(int pos){

   // Comprueba previamente que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero;       // Auxiliar para recorrer los nodos
      PNodo anterior = primero;  // Guarda el nodo anterior
      int pos_actual = 1;        // Controla el número de nodos a recorrer

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

void Lista :: AniadirValor(TipoBase val){

   // Comprobar que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero;  // Auxiliar para recorrer los nodos

      for (int i = 1 ; i < num_nodos ; i++){

         aux = aux->sig;

      }

      aux->sig = new TipoNodo;   // Memoria para el nuevo nodo al final de la lista
      aux = aux->sig;
      aux->valor = val;

      num_nodos++;

   }
}

TipoBase Lista :: LeerValor(int pos) const{

   // Comprobar que la lista no esté vacía y la posición sea correcta
   if (!ListaVacia()){

      PNodo aux = primero; // Auxiliar para recorrer los nodos
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
   if (!ListaVacia()){

      PNodo aux = primero; // Auxiliar para recorrer los nodos
      int pos_actual = 1;  // Controla el número de nodos a recorrer

      while (pos_actual < pos){

         aux = aux->sig;
         pos_actual++;

      }

      aux->valor = val;

   }
}

void Lista :: InicializaLista(TipoBase val){

   // Comprueba previamente que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero;

      while (aux != 0){
         
         aux->valor = val;
         aux = aux->sig;

      }
   }
}

void Lista :: ReservaMemoria(int n){

   // Controla que el número de nodos introducidos no sea ninguno
   if (n > 0){

      // El primer nodo se trata distinto a los demás
      primero = new TipoNodo;

      PNodo aux = primero;  // Auxiliar para ir creando nodos en la lista

      // Crea los nodos restantes
      for (int i = 1 ; i < n ; i++){

         aux->sig = new TipoNodo;   // Memoria para el siguiente nodo
         aux = aux->sig;         // Actualizar posición del siguiente nodo          

      }

      aux->sig = 0;  // Finalizar la lista

   }
   else{
      primero = 0; // No se crea ningún nodo
   }

}

void Lista :: LiberaMemoria(){

   // Comprobar primero si la lista está vacía antes de borrar
   if (!ListaVacia()){

      PNodo aux = primero; // Nodo auxiliar al principio

      while (aux->sig != 0){

         primero = primero->sig;
         delete aux;
         aux = primero;

      }

      delete primero;   // Se borra el nodo que queda 
      primero = 0;      // Quitar el acceso a la lista

   }
}

void Lista :: CopiaLista(const Lista & l){

   // Comprobar previamente que la lista no esté vacía
   if (!ListaVacia()){

      num_nodos = l.num_nodos;
   
      PNodo aux = l.primero;  // Para los nodos de la lista argumento
      PNodo nueva = primero;  // Para los nodos de la nueva lista

      nueva->valor = aux->valor;

      while (aux->sig != 0){

         aux = aux->sig;
         nueva = nueva->sig;

         nueva->valor = aux->valor;

      }
   }
}

void Lista :: PintaLista(){

   // Comprueba previamente que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero;

      while (aux != 0){

         cout << (aux->valor) << " ";
         aux = aux->sig;

      }
   }

   cout << endl;

}