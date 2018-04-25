//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Examen prácticas 1 (2016 - 2017)
// Declaración de la función "Lista"
//
// Funciones que trabajan con listas dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

typedef int TipoBase;

struct Nodo{
   TipoBase valor;
   Nodo * sig;
};

typedef Nodo * PNodo;   // Para los punteros a nodos
typedef Nodo * Lista;   // Para la lista

// Crea una lista y rellena sus nodos con los valores leidos de cin.
// El número de valores es indefinido --> en esta implementación la lectura 
// se detiene al leer un valor negativo
void LeeLista(Lista &);

// Libera la memoria ocupada por los nodos de una lista
void LiberaLista(Lista &);
 
// Muestra los valores guardados en los nodos de una lista enlazada
void PintaLista(const Lista);

// Cuenta el número de nodos de la lista
int CuentaElementos(const Lista);

// Consulta si una lista está vacía (sin nodos)   
bool ListaVacia(const Lista);

// Devuelve una nueva lista, nueva, conteniendo algunos valores seleccionados 
// de la lista l. Los valores seleccionados en la nueva lista están en el 
// mismo orden en el que aparecen en la lista l.
// La lista l no se modifica.
// El criterio de selección es el siguiente: se selecciona el nodo de la 
// posición "inicio", después el que está "salto" posiciones por delante, 
// y así sucesivamente.
// Recibe y devuelve (a través de referencia): 
//			nueva, la lista que crea la función.
//			l, la lista original. No se modifica.
// Recibe:  inicio, posición del primer nodo de la selección.
//			salto, número de nodos entre cada dos nodos seleccionados. 

void Selecciona(Lista &, const Lista, const int, const int);

#endif