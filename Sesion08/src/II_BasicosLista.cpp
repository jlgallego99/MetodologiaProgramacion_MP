//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II, Ejercicio 12
// Programa principal
//
// Demostración de las funciones desarrolladas en la biblioteca de Listas:
// LeeLista, PintaLista, LiberaLista, ListaVacia y CuentaElementos
//
// Además desarrolla los siguientes cálculos ajenos a la biblioteca:
// Media, Varianza
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include "Lista.h"

using namespace std;

double Media(const Lista);
double Varianza(const Lista);

int main(){
   Lista lista, aleatoria;
   int tamanio, min, max;

   // Lectura de una lista
   LeeLista(lista);

   // Muestra por pantalla la lista
   PintaLista(lista);

   // Muestra cuantos elementos tiene la lista
   cout << "La lista tiene " << CuentaElementos(lista) << " elementos" << endl;

   // Muestra la media de la lista
   cout << "Media de la lista: " << Media(lista) << endl;

   // Muestra la varianza de la lista
   cout << "Varianza de la lista: " << Varianza(lista) << endl;

   // Se libera el espacio en memoria de la lista
   LiberaLista(lista);

   // Comprueba si la lista está vacía o no
   if (ListaVacia(lista)){
      cout << "La lista está vacía" << endl;
   }
   else{
      cout << "La lista no está vacía" << endl;
   }

	// Crea una lista con números aleatorios
	cout << "Introduzca entre qué valores rellenar la lista: ";
	cin >> min >> max;
	cout << "Introduzca el tamaño de la lista: ";
	cin >> tamanio;
	CreaListaAleatoria(aleatoria, min, max, tamanio);
	PintaLista(aleatoria);

   return 0;
}

// Calcula la media de los datos de una lista
double Media(const Lista l){

   // Comprueba antes si la lista está vacía
	if (!ListaVacia(l)){
      
      double total = 0;
		PNodo aux = l;    // Colocar "aux" al principio

		while (aux != 0){

			total += aux->valor; // Sumatoria de todos los valores de la lista
			aux = aux->sig;      // Actualizar "aux"

		}

      return (total/CuentaElementos(l));
	}
   else{
      return NAN; // Si la lista está vacía, devuelve NAN
   }
}

// Calcula la varianza de los datos de una lista
double Varianza(const Lista l){

   // Comprueba antes si la lista está vacía
	if (!ListaVacia(l)){

      double total = 0;
		PNodo aux = l;    // Colocar "aux" al principio

		while (aux != 0){

			total += pow(aux->valor, 2); // Sumatoria de todos los valores de la lista
			aux = aux->sig;      // Actualizar "aux"

		}

      return (total/CuentaElementos(l) - pow(Media(l), 2));
	}
   else{
      return NAN; // Si la lista está vacía, devuelve NAN
   }
}