//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 9
// Definición de las clases "ColeccionPuntos2D", "Circunferencia" y "Punto2D"
//
// Clase que trabaja con una colección de puntos
//
//////////////////////////////////////////////////////////////////////////

#include "ColeccionPuntos2D.h"
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*******************************************************************/
// 
//    CLASE PUNTO2D
//
/*******************************************************************/

/*************************************************************************/
// Métodos públicos

Punto2D :: Punto2D()
   :x(0), y(0)
{  
}

Punto2D :: Punto2D(double abscisa, double ordenada)
   :x(abscisa), y(ordenada)
{
}

int Punto2D :: GetX(){

   return x;

}

int Punto2D :: GetY(){

   return y;

}

/*************************************************************************/
// Sobrecarga de operadores

bool Punto2D :: operator == (const Punto2D & p) const{

   return (x == p.x && y == p.y);

}

bool Punto2D :: operator != (const Punto2D & p) const{

   return (!((*this) == p));

}

/*******************************************************************/
// 
//    CLASE CIRCUNFERENCIA
//
/*******************************************************************/

Circunferencia :: Circunferencia()
   :radio(0)
{
}

Circunferencia :: Circunferencia(Punto2D c, double r)
   :radio(r), centro(c)
{
}

double Circunferencia :: GetRadio(){

   return radio;

}

Punto2D Circunferencia :: GetCentro(){

   return centro;

}

bool Circunferencia :: Contiene(Punto2D p){

   // Un punto pertenece a una circunferencia si cumple la ecuación:
   // (x - a)² + (y - b)² = r²

   double diferencia_x = pow (p.GetX() - centro.GetX(), 2);
	double diferencia_y = pow (p.GetY() - centro.GetY(), 2);
   double dist = diferencia_x + diferencia_y;

   return (dist == pow(radio, 2));

}

/*******************************************************************/
// 
//    CLASE COLECCIONPUNTOS2D
//
/*******************************************************************/

/*************************************************************************/
// Métodos públicos

ColeccionPuntos2D :: ColeccionPuntos2D()
   :p(0), num(0)
{
}

ColeccionPuntos2D :: ColeccionPuntos2D(const ColeccionPuntos2D & colec)
   :num(colec.num)
{

   ReservaMemoria(num);
   CopiaColeccionPuntos2D(colec);

}

int ColeccionPuntos2D :: GetNum(){

   return num;

}

ColeccionPuntos2D :: ColeccionPuntos2D(const char * nombre){

   num = 0;
   ifstream fi;      // Flujo de entrada del fichero
   fi.open(nombre);  // Asociar el flujo de entrada al fichero
   string linea;     // Cada línea del fichero

   getline(fi, linea);

   // Comprobar que en la primera línea pone "PUNTOS"
   if (linea == "PUNTOS"){

      // Se pasan las líneas con comentarios que empiezan por #
      while (!fi.eof() && linea[0] == '#'){

         getline(fi, linea);

      }

      // Se procesan los puntos y se añaden a la colección
      while (!fi.eof()){

         istringstream iss;
         iss.str(linea);

         double x, y;
         if (iss >> x){

            iss >> y;
            Punto2D p(x, y);
            AniadePunto(p);

         }

         getline(fi, linea);

      }
   }

   fi.close();

}

ColeccionPuntos2D :: ~ColeccionPuntos2D(){

   LiberaMemoria();

}

void ColeccionPuntos2D :: CopiaColeccionPuntos2D(const ColeccionPuntos2D & colec){

   num = colec.num;

   memcpy(p, colec.p, num * sizeof(Punto2D));

} 

void ColeccionPuntos2D :: AniadePunto(const Punto2D punto){

   Redimensiona(num + 1);

   p[num - 1] = punto;

}

/*************************************************************************/
// Sobrecarga de operadores

Punto2D & ColeccionPuntos2D :: operator [] (const int pos) const{

   return p[pos];

}

bool ColeccionPuntos2D :: operator == (const ColeccionPuntos2D & p) const{

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

bool ColeccionPuntos2D :: operator != (const ColeccionPuntos2D & p) const{

   return (!((*this) == p));

}

ColeccionPuntos2D operator + (const ColeccionPuntos2D & poli, const Punto2D & punto){

   ColeccionPuntos2D nueva (poli); // Nueva ColeccionPuntos2D

   nueva.AniadePunto(punto);  // Añadir punto al final

   return nueva;

}

ColeccionPuntos2D operator + (const Punto2D & punto, const ColeccionPuntos2D & poli){

   ColeccionPuntos2D nueva;  // Nueva ColeccionPuntos2D vacia

   nueva.AniadePunto(punto);  // Se añade el punto primero

   // Se añaden el resto de puntos
   for (int i = 0 ; i < poli.num ; i++){

      nueva.AniadePunto(poli[i]);

   }

   return nueva;

}

/*************************************************************************/
// Métodos privados

void ColeccionPuntos2D :: ReservaMemoria(int n){

   p = new Punto2D [n];

}

void ColeccionPuntos2D :: LiberaMemoria(){

   delete [] p;
   
   p = 0;

}

void ColeccionPuntos2D :: Redimensiona(int n){

   ColeccionPuntos2D tmp (*this);

   LiberaMemoria();
   ReservaMemoria(n);
   CopiaColeccionPuntos2D(tmp);

}