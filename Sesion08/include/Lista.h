//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II
// Declaración de funciones
//
// Funciones relativas a una lista dinámica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef LISTA
#define LISTA

typedef double TipoBase;

struct Nodo{
	TipoBase valor;
	Nodo * sig;
};

typedef Nodo * PNodo;	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista

void LeeLista(Lista &);
void PintaLista(const Lista);
void LiberaLista(Lista &);
bool ListaVacia(const Lista);
int CuentaElementos(const Lista);
bool EstaOrdenada (const Lista);
void OrdenaSeleccionLista (Lista &);
void CreaListaAleatoria(Lista &, int, int, int);
bool EstaOrdenada (const Lista);
void OrdenaSeleccionLista (Lista &);
void InsertaOrdenadamente (Lista &, TipoBase);
void EliminaValor (Lista &, TipoBase);
void MezclaListas (Lista &, Lista &, Lista &);

#endif
