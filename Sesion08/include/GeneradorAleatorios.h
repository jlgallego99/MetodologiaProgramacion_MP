//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Declaración de clase
//
// Clase GeneradorAleatoriosEnteros
//
//////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// CLASE GeneradorAleatorioEnteros
//
//  Ejemplo de uso:
/*
	int menor, mayor;
	......
	
	// Objeto generador de n?meros aleatorios
	GeneradorAleatorioEnteros generador_aleat (menor, mayor);
	
	int valor_generado = generador_aleat.Siguiente();
*/   
   
/***************************************************************************/

#ifndef GENERADORALEATORIOS
#define GENERADORALEATORIOS

#include <cstdlib>
#include <cctype>
#include <random>  
#include <chrono>  

using namespace std;

class GeneradorAleatorioEnteros{  
private: 
	mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec();
public:
   GeneradorAleatorioEnteros();  
   GeneradorAleatorioEnteros(int, int);
   int Siguiente();
};

#endif