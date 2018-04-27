//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Declaración de la clase "Lista"
//
// Clase que trabaja con listas dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

// Definición del tipo de datos

typedef int TipoBase;

// Declaración de la clase Lista y el TipoNodo

struct TipoNodo{

   TipoBase valor;
	TipoNodo * sig;

};

class Lista{
   private:

      TipoNodo * primero;	// Puntero al primer nodo
      int num_nodos;    	// Número total de nodos

   public:

      // Constructor sin argumentos:
      // Crea una lista vacía
      Lista();

      // Constructor con un argumento:
      // Crea una lista con el número de nodos indicados en el argumento
      Lista(int);

      // Constructor con dos argumentos:
      // Crea una lista con el número de nodos indicados en el primer argumento 
      // e inicia todos ellos al valor indicado en el segundo argumento
      Lista(int, TipoBase);

      // Constructor de copia
      Lista(const Lista &);

      // Destructor
      ~Lista();

      // Consulta si la lista está vacía
      bool ListaVacia() const;

      // Consulta el número de nodos de la lista
      int GetNumNodos() const;

      // Inserta un valor en la lista
		// PRECONDICIÓN: Posición del nodo correcta
      void Insertar(TipoBase, int);

      // Borra un nodo en la lista
      void Borrar(int pos);
      
      // Añade un valor al final de la lista
      void AniadirValor(TipoBase);
      
      // Leer el valor de una posición
	// PRECONDICIÓN: Posición del nodo correcta
      TipoBase LeerValor(int pos) const;

      // PRECONDICIÓN: Posición del nodo correcta
      // Escribir un valor en una posición
      void ModificarValor(int pos, TipoBase val);
      
      // Pinta por completo una lista
      void PintaLista();

   private:

      // Inicializa todos los nodos al valor indicado como argumento
      void InicializaLista(TipoBase);
      
      // Reserva memoria para n nodos
      void ReservaMemoria(int);

      // Libera la memoria de una lista
      void LiberaMemoria();

      // Copia una lista en otra
      void CopiaLista(const Lista &);

};

typedef TipoNodo * PNodo;	// Para los punteros a nodos

#endif