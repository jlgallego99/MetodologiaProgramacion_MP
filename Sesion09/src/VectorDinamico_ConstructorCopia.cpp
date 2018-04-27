//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Definición de la clase "VectorDinamico"
//
// Clase que trabaja con vectores dinámicos de TipoBase
//
//////////////////////////////////////////////////////////////////////////

#include <cstring>
#include "VectorDinamico_ConstructorCopia.h"

VectorDinamico :: VectorDinamico()
   : ocupadas(0), reservadas(TAM_INICIAL)
{

   ReservaMemoria(TAM_INICIAL);

}

VectorDinamico :: VectorDinamico(int num_casillas)
   : ocupadas(0), reservadas(num_casillas)
{

   ReservaMemoria(num_casillas);

}

VectorDinamico :: VectorDinamico(const VectorDinamico & v)
   : ocupadas(v.ocupadas), reservadas(v.reservadas)
{

   ReservaMemoria(v.reservadas);
   CopiaVector(v);

}

VectorDinamico :: ~VectorDinamico(){

   LiberaMemoria();

}

bool VectorDinamico :: VectorVacio() const{

   return (ocupadas == 0);

}

int VectorDinamico :: GetCasillasOcupadas() const{

   return ocupadas;

}

int VectorDinamico :: GetCasillasReservadas() const{

   return reservadas;

}

TipoBase VectorDinamico :: GetValor(int pos) const{
	
	// Controla que la posición introducida es correcta
	if (pos < ocupadas){

   	return vector[pos];

	}

}

void VectorDinamico :: SetValor(TipoBase valor){

	if (reservadas == ocupadas){

   	Redimensiona();

	}

	vector[ocupadas] = valor;
	ocupadas++;

}

void VectorDinamico :: AjustaTamanio(){

   tipo_redimension = Ajustar;
	
	Redimensiona();

}

void VectorDinamico :: SetTipoRedimension(TipoRedimension tipo){

   tipo_redimension = tipo;

}

TipoRedimension VectorDinamico :: GetTipoRedimension() const{

   return tipo_redimension;

}

void VectorDinamico :: ReservaMemoria(int tamanio){

   vector = new TipoBase [tamanio];

   reservadas = tamanio;

}

void VectorDinamico :: LiberaMemoria(){

   // Comprueba previamente que el vector no esté vacío
   if (!VectorVacio()){
      delete [] vector;
      vector = 0;
   }
}

void VectorDinamico :: CopiaVector(const VectorDinamico & v){

   memcpy(vector, v.vector, ocupadas*sizeof(TipoBase));

}

void VectorDinamico :: Redimensiona(){
   const int TAM_BLOQUE = 3;

   // Se reservan tantas casillas según el tipo de redimensión
   if (tipo_redimension == DeUnoEnUno){
      reservadas++;
   }  
   else if (tipo_redimension == EnBloques){
      reservadas += TAM_BLOQUE;
   }
   else if (tipo_redimension == Duplicando){
      reservadas *= 2;
   }
	else if (tipo_redimension == Ajustar){
		reservadas = ocupadas;
	}

   // Copia del vector en el temporal
   VectorDinamico tmp (*this);

   // Liberación del vector
   LiberaMemoria();

   // Se reserva de nuevo memoria para el vector
   ReservaMemoria(tmp.reservadas);

   // Se devuelven los datos al vector
   ocupadas = tmp.ocupadas;
   CopiaVector(tmp);

}