//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Declaración de la clase "VectorDinamico"
//
// Clase que trabaja con vectores dinámicos de TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef VECTORDINAMICO
#define VECTORDINAMICO

// Definición del tipo de datos

typedef int TipoBase;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando, Ajustar};

// Declaración de la clase VectorDinamico

class VectorDinamico{
   private:
      static const int TAM_INICIAL = 5;

      TipoBase * vector;
      int ocupadas;
      int reservadas;
      TipoRedimension tipo_redimension;

   public:

      // Constructor sin argumentos:
      // Crea un vector dinámico con un número de casillas predeterminado 
      VectorDinamico();

      // Constructor con un argumento:
      // Crea un vector dinámico con el número de casillas del argumento
      // PRECONDICIÓN: Número de casillas positivo
      VectorDinamico(int);

      // Constructor de copia
      VectorDinamico(const VectorDinamico &);

      // Destructor
      ~VectorDinamico();

      // Consulta si el vector está vacío
      bool VectorVacio() const;

      // Consulta el número de casillas ocupadas
      int GetCasillasOcupadas() const;

      // Consulta el número de casillas reservadas
      int GetCasillasReservadas() const;

      // Devuelve el valor que ocupa una posición dada
      // PRECONDICIÓN: Posición positiva y correcta
      TipoBase GetValor(int) const;

      // Añade un valor. Si no hay espacio, redimensiona el vector
      void SetValor(TipoBase);

      // Asigna un tipo de redimensión
      void SetTipoRedimension(TipoRedimension);

      // Consulta el tipo de redimensión
      TipoRedimension GetTipoRedimension() const;

   private:

      // Redimensiona un vector
      void Redimensiona();

      // Ajusta el tamaño del vector 
      // Su capacidad coincidirá con el número de casillas ocupadas
      void AjustaTamanio();

      // Reserva memoria para un vector
      // PRECONDICIÓN: Número de casillas positivo
      void ReservaMemoria(int);

      // Libera la memoria de un vector
      void LiberaMemoria();

      // Copia un vector en otro
      void CopiaVector(const VectorDinamico &);

};

#endif