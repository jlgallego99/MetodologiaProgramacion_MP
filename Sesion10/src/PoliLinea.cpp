//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 9
// Definición de las clases "PoliLinea" y "Punto"
//
// Clase que trabaja con figuras planas
//
//////////////////////////////////////////////////////////////////////////

#include "PoliLinea.h"
#include <cstring>

/*******************************************************************/
// 
//    CLASE PUNTO
//
/*******************************************************************/

/*************************************************************************/
// Métodos públicos

/*************************************************************************/
// Sobrecarga de operadores

bool Punto :: operator == (const Punto & p) const{

   return (x == p.x && y == p.y);

}

bool Punto :: operator != (const Punto & p) const{

   return (!((*this) == p));

}

/*******************************************************************/
// 
//    CLASE POLILINEA
//
/*******************************************************************/

/*************************************************************************/
// Métodos públicos

PoliLinea :: PoliLinea()
   :p(0), num(0)
{
}

PoliLinea :: PoliLinea(const PoliLinea & poli)
   :num(poli.num)
{

   ReservaMemoria(num);
   CopiaPoliLinea(poli);

}

PoliLinea :: ~PoliLinea(){

   LiberaMemoria();

}

void PoliLinea :: CopiaPoliLinea(const PoliLinea & poli){

   num = poli.num;

   memcpy(p, poli.p, num * sizeof(Punto));

} 

void PoliLinea :: AniadePunto(const Punto punto){

   Redimensiona(num + 1);

   p[num - 1] = punto;

}

/*************************************************************************/
// Sobrecarga de operadores

Punto & PoliLinea :: operator [] (const int pos) const{

   return p[pos];

}

bool PoliLinea :: operator == (const PoliLinea & p) const{

   bool igual = (num == p.num);

   // Si tienen el mismo número de puntos
   if (igual){

      // Se recorren todos los puntos viendo si tienen las mismas coordenadas
      for (int i = 0 ; i < num && igual ; i++){

         if (p[i] != p.p[i] && p[i] != p.p[num - 1 - i]){

            igual = false;

         }
      }
   }

   return igual;

}

bool PoliLinea :: operator != (const PoliLinea & p) const{

   return (!((*this) == p));

}

PoliLinea operator + (const PoliLinea & poli, const Punto & punto){

   PoliLinea nueva (poli); // Nueva polilinea

   nueva.AniadePunto(punto);  // Añadir punto al final

   return nueva;

}

PoliLinea operator + (const Punto & punto, const PoliLinea & poli){

   PoliLinea nueva;  // Nueva polilinea vacia

   nueva.AniadePunto(punto);  // Se añade el punto primero

   // Se añaden el resto de puntos
   for (int i = 0 ; i < poli.num ; i++){

      nueva.AniadePunto(poli[i]);

   }

   return nueva;

}

/*************************************************************************/
// Métodos privados

void PoliLinea :: ReservaMemoria(int n){

   p = new Punto [n];

}

void PoliLinea :: LiberaMemoria(){

   delete [] p;
   
   p = 0;

}

void PoliLinea :: Redimensiona(int n){

   PoliLinea tmp (*this);

   LiberaMemoria();
   ReservaMemoria(n);
   CopiaPoliLinea(tmp);

}