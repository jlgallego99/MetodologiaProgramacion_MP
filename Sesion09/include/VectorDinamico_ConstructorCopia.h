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

typedef int TipoBase;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando, Ajustar};

class VectorDinamico{
   private:
      static const int TAM_INICIAL = 5;

      TipoBase * vector;
      int ocupadas;
      int reservadas;
      TipoRedimension tipo_redimension;

   public:
      VectorDinamico();
      VectorDinamico(int);
      VectorDinamico(const VectorDinamico &);
      ~VectorDinamico();
      bool EstaVacio();
      int GetCasillasOcupadas();
      int GetCasillasReservadas();
      TipoBase GetValor(int);
      void SetValor(TipoBase);
      void SetTipoRedimension(TipoRedimension);
      TipoRedimension GetTipoRedimension();

   private:
      TipoBase CasillasReservadas();
      void Redimensiona();
      void AjustaTamanio();
      void ReservaMemoria(int);
      void LiberaMemoria();
      void CopiaVector(const VectorDinamico &);

};

#endif