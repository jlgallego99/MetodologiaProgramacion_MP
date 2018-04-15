//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II
// Definición de funciones
//
// Funciones relativas a una lista dinámica de datos TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Lista.h"
#include "GeneradorAleatorios.h"
using namespace std;

// Lee valores y los introduce en una lista dinámica
void LeeLista(Lista & l){

	TipoBase n;
	// Punteros
	PNodo primero;  // Puntero al primer nodo
	PNodo fin;      // Puntero al último nodo

	cout << "Introduzca un valor en la lista (negativo para terminar): ";
	cin >> n;

	if (n >= 0){
		
		// Pedimos memoria para el primer nodo
		primero = new Nodo;
		
		primero->valor = n;	// Guardar "n" en el nuevo nodo
		primero->sig = 0;		// Este nodo es, por ahora, el último

		// El último también es el primero (solo hay uno)
		fin = primero;

		cout << "Introduzca un valor en la lista (negativo para terminar): ";
		cin >> n;

		while (n >= 0){
			
			// Pedimos memoria para el siguiente nodo, y enlazamos
			fin->sig = new Nodo;

			fin = fin->sig;	// Actualizar posición del último

			fin->valor = n;	// Guardar "n" en el nuevo nodo
			fin->sig = 0;		// Este nodo es, por ahora, el último

			cout << "Introduzca un valor en la lista (negativo para terminar): ";
			cin >> n;

		}
			
	}	
	
	// La lista empieza con el primer nodo
	l = primero;
	
}

// Muestra una lista completa por pantalla
void PintaLista(const Lista l){

	// Comprobar si la lista está vacía antes de pintarla
	if (!ListaVacia(l)){

		PNodo aux = l;	// Colocar "aux" al principio

		cout << "Lista: " << endl;
		while (aux != 0){
		
			cout << (aux->valor) << endl;	// Mostrar valor
			aux = aux->sig;					// Adelantar aux          
		
		}	
	}

	cout << endl;
}

// Libera la memoria de una lista
void LiberaLista(Lista & l){

	// Comprobar si la lista esta vacía antes de borrar nada
	if (!ListaVacia(l)){

		PNodo aux = l;	// Colocar "aux" al principio

		while (aux != 0){

			aux = aux->sig;	// Actualizar "aux"
			delete l;			// Borrar el nodo
			l = aux;				// Adelantar "l"

		}

		delete l;	// Borrar el único nodo que queda
	}

	// Puntero que da acceso a la lista se convierte en nulo
	l = 0;
}

// Comprueba si una lista está vacía o no
bool ListaVacia(const Lista l){

	// Se comprueba si el puntero a la lista está vacío
	return (l == 0);

}

// Calcula cuantos elementos tiene una lista
int CuentaElementos(const Lista l){

	// Contador del número de elementos
	int elementos = 0;

	// Comprueba antes si la lista está vacía
	if (!ListaVacia(l)){
		
		PNodo aux = l;	// Colocar "aux" al principio

		while (aux != 0){

			elementos++;		// Se incrementa el número de elementos de la lista
			aux = aux->sig;	// Actualizar "aux"

		}
	}

	return elementos;
}

// Crea una lista con números aleatorios entre un mínimo y un máximo
void CreaListaAleatoria(Lista & l, int min, int max, int tamanio){

	GeneradorAleatorioEnteros generador(min, max);
	TipoBase n;

	// Punteros
	PNodo primero;  // Puntero al primer nodo
	PNodo fin;      // Puntero al último nodo
		
	// Pedimos memoria para el primer nodo
	primero = new Nodo;
	
	// Genera un número aleatorio
	n = generador.Siguiente();

	primero->valor = n;	// Guardar "n" en el nuevo nodo
	primero->sig = 0;		// Este nodo es, por ahora, el último

	// El último también es el primero (solo hay uno)
	fin = primero;

	for (int i = 1 ; i < tamanio ; i++){

		// Genera un número aleatorio
		n = generador.Siguiente();

		fin->sig = new Nodo;

		fin = fin->sig;	// Actualizar posición del último
		fin->valor = n;	// Guardar "n" en el nuevo nodo
		fin->sig = 0;		// Este nodo es, por ahora, el último

	}
	
	// La lista empieza con el primer nodo
	l = primero;

}

// Comprueba si la lista está ordenada
bool EstaOrdenada(const Lista l){

	bool ordenada = true;	// Controla si la lista está ordenada

	// Comprobar si la lista esta vacía 
	if (!ListaVacia(l)){

		PNodo aux = l;							// Colocar "aux" al principio
		TipoBase anterior = aux->valor;	// Valor del primer nodo

		while (aux != 0 && ordenada){
			
			if (anterior <= aux->valor){
				// Se va actualizando el valor anterior siempre que sea menor 
				anterior = aux->valor;	

				aux = aux->sig;	// Adelantar "aux"
			}
			else{
				ordenada = false; // Si el anterior no es menor, no está ordenada
			}

		}
	}

	return ordenada;
}

// Ordena una lista usando el método de ordenación por selección
void OrdenaSeleccionLista(Lista & l){

	// Comprobar si la lista esta vacía 
	if (!ListaVacia(l)){

		PNodo primero = l;

		while (primero->sig != 0){
			
			// Se supone que el menor es el primero
			TipoBase minimo = primero->valor;
			PNodo pos_min = primero;   

			PNodo aux = primero->sig;  

			while (aux != 0) {

				if (aux->valor < minimo){

					minimo = aux->valor;
					pos_min = aux;

				}

				aux = aux->sig;  // Avanza "aux"

			}

			// Se intercambia el menor en la posición de "primero"
			TipoBase intercambia = primero->valor; 
			primero->valor = pos_min->valor;
			pos_min->valor = intercambia; 

			primero = primero->sig; // Avanza "primero"
		}

	}
}

// Inserta un valor de forma ordenada en la lista
void InsertaOrdenadamente (Lista & l, TipoBase v){

	// Se comprueba si la lista está vacía
	if (!ListaVacia(l)){

		// Asegura que la lista esté ordenada
		if (!EstaOrdenada(l)){
			OrdenaSeleccionLista(l);
		}

		PNodo primero = l;		// Guarda la dirección del primer nodo
		bool aparicion = false;	// Controla si ha aparecido el valor que se pide

		while (l != 0 && !aparicion){
			
			if (l->valor == v){
				aparicion = true;
			}
			else{
				l = l->sig;	// Actualizar "l"
			}

		}

		PNodo siguiente = l->sig;	// Se guarda el valor del siguiente
		l->sig = new Nodo;			// Nodo para el nuevo valor
		l = l->sig;
		l->valor = v;					// Se almacena el nuevo valor en el nuevo nodo
		/* La siguiente dirección del nuevo nodo, es la siguiente al nodo de 
		aparición */
		l->sig = siguiente;		

		// La lista empieza con el primer nodo
		l = primero;
	}
}

// Se elimina la celda que contiene un determinado valor
void EliminaValor (Lista & l, TipoBase v){

	// Se comprueba si la lista está vacía
	if (!ListaVacia(l)){

		// Asegura que la lista esté ordenada
		if (!EstaOrdenada(l)){
			OrdenaSeleccionLista(l);
		}

		PNodo primero = l;		// Guarda la dirección del primer nodo
		PNodo anterior = l;		// Guarda la dirección del nodo anterior
		bool eliminado = false;	// Controla si ya se ha eliminado el valor pedido

		while (l != 0 && !eliminado){
			
			if (l->valor == v){
				eliminado = true;
			}
			else{
				anterior = l;	// Se va guardando el anterior
				l = l->sig;		// Actualizar "l"
			}

		}

		// El siguiente al anterior, es el siguiente del borrado
		anterior->sig = l->sig;	
		delete l;

		// La lista empieza con el primer nodo
		l = primero;

	}
}

void MezclaListas (Lista & l, Lista & l1, Lista & l2){

	l = 0;	// Se inicializa la lista mezcla como vacía

	// Se comprueba si las listas están vacías
	if (!ListaVacia(l1) && !ListaVacia(l2)){

		// Asegura que las listas estén ordenadas
		if (!EstaOrdenada(l1)){
			OrdenaSeleccionLista(l1);
		}

		if (!EstaOrdenada(l2)){
			OrdenaSeleccionLista(l2);
		}
		
		/* Se procesa el primer nodo
		Se inicializa la lista a la que tiene el primer valor menor */
		if (l1->valor < l2->valor){
			l = l1;	
			l1 = l1->sig;	// Se actualiza l1
		}
		else{
			l = l2;
			l2 = l2->sig;	// Se actualiza l2
		}

		PNodo aux = l;	// Colocar "aux" al principio

		// Las listas se van "vaciando"
		while (!ListaVacia(l1) && !ListaVacia(l2)){
			
			// Se procesa valor a valor, y se va adelantando la que sea menor
			if (l1->valor < l2->valor){
				aux->sig = l1;
				l1 = l1->sig;
			}
			else{
				aux->sig = l2;
				l2 = l2->sig;
			}

			aux = aux->sig;

		}
	}
	// Alguna está vacía
	else{
		// Primera vacía
		if (ListaVacia(l1) && !ListaVacia(l2)){
			l = l2;	// La lista es enteramente l2
			l2 = 0;	// Se "borra" l2
		}
		// Segunda vacía
		else if (!ListaVacia(l1) && ListaVacia(l2)){
			l = l1;	// La lista es enteramente l1
			l1 = 0;	// Se "borra" l1
		}
	}
}