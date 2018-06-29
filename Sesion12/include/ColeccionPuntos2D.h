//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas IV, Ejercicio 9
// Declaración de las clases "ColeccionPuntos2D", "Circunferencia" y "Punto2D"
//
// Clase que trabaja con una colección de puntos
//
//////////////////////////////////////////////////////////////////////////

#ifndef COLECCIONPUNTOS2D
#define COLECCIONPUNTOS2D

// Declaración de la clase Punto2D

class Punto2D{
   private:

      // Coordenadas de un punto 2D
      int x;
      int y;   

   public:

      /*******************************************************************/
      // Constructor sin argumentos
      Punto2D();

      /*******************************************************************/
      // Constructor con dos argumentos:
      // Crea un punto mediante las dos coordenadas dadas
      Punto2D(double, double);

      /*******************************************************************/
      // Obtiene la coordenada X del punto
      int GetX();

      /*******************************************************************/
      // Obtiene la coordenada Y del punto
      int GetY();

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta sus dos coordenadas
      // Compara si dos puntos son iguales
      bool operator == (const Punto2D &) const;
      // Compara si dos puntos son distintos
      bool operator != (const Punto2D &) const;

};

// Declaración de la clase Circunferencia

class Circunferencia{
   private:

      Punto2D centro;
      double radio;

   public:

      /*******************************************************************/
      // Constructor sin argumentos
      Circunferencia();

      /*******************************************************************/
      // Constructor con dos argumentos:
      // Crea una circunferencia a partir de un centro y un radio
      Circunferencia(Punto2D, double);

      /*******************************************************************/
      // Obtiene la longitud del radio
      double GetRadio();

      /*******************************************************************/
      // Obtiene el centro de la circunferencia
      Punto2D GetCentro();

      /*******************************************************************/
      // Calcula si un punto está en la circunferencia
      bool Contiene(Punto2D);

};

// Declaración de la clase ColeccionPuntos2D

class ColeccionPuntos2D{
   private:

      Punto2D * p;   // Vector de puntos
      int num;       // Número de puntos

   public:

      /*******************************************************************/
      // Constructor sin argumentos:
      // Crea un conjunto de puntos vacío
      ColeccionPuntos2D();
      
      /*******************************************************************/
      // Constructor de copia:
      // Crea un conjunto de puntos copia de otro
      ColeccionPuntos2D(const ColeccionPuntos2D &);

      /*******************************************************************/
      // Constructor con un argumento:
      // Recibe el nombre de un fichero con las coordenadas de los puntos
      ColeccionPuntos2D(const char *);

      /*******************************************************************/
      // Destructor
      ~ColeccionPuntos2D();

      /*******************************************************************/
      // Obtiene el número de puntos
      int GetNum();

      /*******************************************************************/
      // Copia un conjunto de puntos en otro
      void CopiaColeccionPuntos2D(const ColeccionPuntos2D &);

      /*******************************************************************/
      // Añade un punto a la ColeccionPuntos2D
      void AniadePunto(const Punto2D);

      /*******************************************************************/
      // Sobrecarga del operador []
      // Permite acceder a un dato de tipo Punto2D en una ColeccionPuntos2D
      Punto2D & operator [] (const int) const;

      /*******************************************************************/
      // Sobrecarga de los operadores relacionales == y !=
      // Tiene en cuenta el número de puntos, si son iguales y si están en orden
      // Compara si dos datos ColeccionPuntos2D son iguales
      bool operator == (const ColeccionPuntos2D &) const;
      // Compara si dos datos ColeccionPuntos2D son distintos
      bool operator != (const ColeccionPuntos2D &) const;

      /*******************************************************************/
      // Sobrecarga del operador binario +
      // Añade un punto al final de una colección de puntos
      friend ColeccionPuntos2D operator + (const ColeccionPuntos2D &, const Punto2D &);
      // Añade un punto al principio de una colección de puntos
      friend ColeccionPuntos2D operator + (const Punto2D &, const ColeccionPuntos2D &);

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