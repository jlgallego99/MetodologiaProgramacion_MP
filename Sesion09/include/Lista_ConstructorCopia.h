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

typedef int TipoBase;

class Lista{
   private:
      TipoBase valor;
      Lista * sig;
      int num_nodos;

   public:
      Lista();
      Lista(int);
      Lista(int, TipoBase);
      Lista(const Lista &);
      ~Lista();
      bool EstaVacia();
      int GetNumNodos();
      void Insertar(TipoBase, int);
      void Borrar(int pos);
      void AniadirValor(TipoBase);
      TipoBase LeerValor(int pos);
      void ModificarValor(int pos, TipoBase val);
      void PintaLista();

   private:
      void InicializaLista(TipoBase);
      void ReservaMemoria(int);
      void LiberaMemoria();
      void CopiaLista(const Lista &);

};

typedef Lista * PNodo;	// Para los punteros a nodos

#endif