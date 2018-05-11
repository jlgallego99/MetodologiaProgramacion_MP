//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 9
// Declaración de las clases "PoliLinea" y "Punto"
//
// Clase que trabaja con figuras planas
//
//////////////////////////////////////////////////////////////////////////

#ifndef POLILINEA
#define POLILINEA

// Declaración de la clase Punto

class Punto{
   private:

      // Coordenadas de un punto 2D
      int x;
      int y;   

   public:

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta sus dos coordenadas
      // Compara si dos puntos son iguales
      bool operator == (const Punto &) const;
      // Compara si dos puntos son distintos
      bool operator != (const Punto &) const;

};

// Declaración de la clase PoliLinea

class PoliLinea{
   private:

      Punto * p;  // Vector de puntos
      int num;    // Número de puntos

   public:

      /*******************************************************************/
      // Constructor sin argumentos:
      // Crea una línea poligonal vacía
      PoliLinea();
      
      /*******************************************************************/
      // Constructor de copia:
      // Crea una línea poligonal copia de otra
      PoliLinea(const PoliLinea &);

      /*******************************************************************/
      // Destructor
      ~PoliLinea();

      /*******************************************************************/
      // Copia una línea poligonal en otra
      void CopiaPoliLinea(const PoliLinea &);

      /*******************************************************************/
      // Añade un punto a la polilinea
      void AniadePunto(const Punto);

      /*******************************************************************/
      // Sobrecarga del operador []
      // Permite acceder a un dato de tipo Punto en una PoliLinea
      Punto & operator [] (const int) const;

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta el número de puntos, si son iguales y si están en orden
      // Compara si dos datos PoliLinea son iguales
      bool operator == (const PoliLinea &) const;
      // Compara si dos datos PoliLinea son distintos
      bool operator != (const PoliLinea &) const;

      /*******************************************************************/
      // Sobrecarga del operador binario +
      // Añade un punto al final de una línea poligonal
      friend PoliLinea operator + (const PoliLinea &, const Punto &);
      // Añade un punto al principio de una línea poligonal
      friend PoliLinea operator + (const Punto &, const PoliLinea &);

   private:

      /*******************************************************************/
      // Reserva memoria para el vector de punteros
      void ReservaMemoria(int);

      /*******************************************************************/
      // Libera la memoria del vector de puntos
      void LiberaMemoria();

      /*******************************************************************/
      // Redimensiona el vector de puntos
      void Redimensiona(int);

};

#endif