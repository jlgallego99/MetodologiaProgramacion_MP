//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 6
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <random>
#include <chrono> 
using namespace std;

class GeneradorAleatorioEnteros{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
public:
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
    
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006
      
      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }
   
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
};

int main(){
   const int TOPE = 20;
   const int MY_MAX_RAND = 100.0; 
   double v[TOPE], primer_elemento;
   double *ptr_v, *ptr_final;
   time_t t;
   GeneradorAleatorioEnteros generador (0, 100);
   
   // Iniciar vector aleatoriamente
   for (int i = 0 ; i < TOPE ; i++) 
      v[i] = generador.Siguiente();
   
   // Almacenamos en un puntero el principio del vector, y en otro el final
   ptr_v = v;
   ptr_final = ptr_v + TOPE - 1;
   primer_elemento = *ptr_v;

   // Algoritmo
   while (ptr_v <= ptr_final){
      while (*ptr_v <= primer_elemento){
         ptr_v++;
      }
      
      while (*ptr_final >= primer_elemento){
         ptr_final--;
      }

      if (ptr_v < ptr_final){
         int intercambia = *ptr_v;
         *ptr_v = *ptr_final;
         *ptr_final = intercambia;

         ptr_v++;
         ptr_final--;
      }
   }

   int intercambia = *ptr_v;
   *v = *ptr_final;
   *ptr_final = intercambia;

   cout << "\nEl vector reorganizado: ";
   for (int i = 0 ; i < 20 ; i++){
      cout << v[i];
   }
}