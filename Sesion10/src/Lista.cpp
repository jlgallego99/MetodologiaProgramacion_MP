//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 4
// Definición de la clase "Lista"
//
// Clase que trabaja con listas dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"

using namespace std;

/*************************************************************************/
// Métodos públicos

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
      num_nodos--;

   }
}

void Lista :: AniadirValor(TipoBase val){

   // Comprobar que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero; // Auxiliar para recorrer los nodos

      for (int i = 1 ; i < num_nodos ; i++){

         aux = aux->sig;

      }

      // Memoria para el nuevo nodo al final de la lista
      aux->sig = new TipoNodo;   
      aux = aux->sig;
      aux->valor = val;

      num_nodos++;

   }
}

void Lista :: EliminarValor(TipoBase val){

   // Comprobar que la lista no esté vacía
   if (!ListaVacia()){

      PNodo aux = primero; // Auxiliar para recorrer los nodos
      int pos = 1;         // Posición del nodo

      while (aux != 0 && aux->valor != val){

         aux = aux->sig;
         pos++;

      }

      Borrar(pos);   // Se borra la posición donde está el valor val

   }
}

TipoBase Lista :: LeerValor(int pos) const{

   // Comprobar que la lista no esté vacía
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

/*************************************************************************/
// Sobrecarga de operadores

Lista & Lista :: operator = (const Lista & l){

   if (this != &l){  // Evitar autoasignación

      // Si la lista no está vacía, se libera su memoria
      if (!ListaVacia()){

         LiberaMemoria();

      }

      // Memoria para la nueva lista copia
      ReservaMemoria(l.num_nodos);

      // Se copia la lista
      CopiaLista(l);

   }

   // Devuelve una referencia al objeto implícito: izquierda de la asignación
	return (*this);

}

Lista & Lista :: operator = (const TipoBase valor){

   InicializaLista(valor);

   return (*this);

}

TipoBase & Lista :: operator [] (const int pos){

   PNodo aux = primero; // Auxiliar para recorrer los nodos
   int pos_actual = 1;  // Controla el número de nodos a recorrer

   for (int i = 1 ; i < pos ; i++){
	   
      aux = aux->sig;
   
   }

   return aux->valor;

}

Lista & Lista :: operator += (const TipoBase valor){

   AniadirValor(valor);
   
   return (*this);

}

Lista & Lista :: operator -= (const TipoBase valor){

   EliminarValor(valor);

   return (*this);

}

Lista operator + (const Lista & l1, const Lista & l2){

   Lista suma = l1;     // Lista suma
   PNodo aux = l2.primero;  // Para recorrer la segunda lista

   while (aux != 0){

      suma += aux->valor;
      aux = aux->sig;

   }

   return suma;

}

Lista operator + (const Lista & l, const TipoBase val){

   Lista l2;

   l2.AniadirValor(val);
   
   return (l + l2);

}

Lista operator + (const TipoBase val, const Lista & l){

   Lista l2;

   l2.AniadirValor(val);

   return (l + l2);

}

Lista operator - (const Lista & l1, const Lista & l2){

   Lista resta = l1;       // Lista resta
   PNodo aux = l2.primero; // Auxiliar para recorrer la segunda lista

   while (aux != 0){

      resta -= aux->valor;
      aux = aux->sig;

   }

   return resta;

}

Lista operator - (const Lista & l, const TipoBase val){

   Lista l2;

   l2.AniadirValor(val);

   return (l - l2);

}

Lista operator - (const TipoBase val, const Lista & l){

   Lista l2;

   l2.AniadirValor(val);

   return (l2 - l);

}

bool Lista :: operator == (const Lista & l){

   bool iguales = true;
   PNodo p1 = primero;     // Para recorrer los nodos de la lista implícita
   PNodo p2 = l.primero;   // Para recorrer los nodos de la lista explícita

   while (p1 != 0 && p2 != 0 && iguales){

      if (p1->valor == p2->valor){

         p1 = p1->sig;
         p2 = p2->sig;

      }
      else{
         iguales = false;
      }

   }

   return iguales;

}

bool Lista :: operator != (const Lista & l){

   return (!((*this) == l));

}

bool Lista :: operator > (const Lista & l){

   bool mayor = false;
   PNodo p1 = primero;     // Para recorrer los nodos de la lista implícita
   PNodo p2 = l.primero;   // Para recorrer los nodos de la lista explícita

   while (p1 != 0 && p2 != 0 && !mayor){

      if (p1->valor > p2->valor){

         mayor = true;

      }
      else{
         
         p1 = p1->sig;
         p2 = p2->sig;

      }

   }

   return mayor;

}

bool Lista :: operator >= (const Lista & l){

   bool mayor = false;
   PNodo p1 = primero;     // Para recorrer los nodos de la lista implícita
   PNodo p2 = l.primero;   // Para recorrer los nodos de la lista explícita

   while (p1 != 0 && p2 != 0 && !mayor){

      if (p1->valor >= p2->valor){

         mayor = true;

      }
      else{
         
         p1 = p1->sig;
         p2 = p2->sig;

      }

   }

   return mayor;

}

bool Lista :: operator < (const Lista & l){

   return (!((*this) > l));

}

bool Lista :: operator <= (const Lista & l){

   return (!((*this) >= l));

}

/*************************************************************************/
// Métodos privados

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