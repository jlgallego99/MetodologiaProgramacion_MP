//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 17
// Definición de la función "MaximoMinimo" necesaria para I_MaxMin_Array.cpp
//
// Calcula el mínimo y el máximo valor de un vector
// Recibe las posiciones inicial y final entre las que realizar la búsqueda y
// el mínimo y el máximo por referencia
// Devuelve mediante referencias los valores de mínimo y máximo calculados
//
//////////////////////////////////////////////////////////////////////////

void MaximoMinimo(int *pos_izda, int *pos_dcha, int &minimo, int &maximo){
   // Se inicializan el máximo y el mínimo al primer valor
   minimo = *pos_izda;
   maximo = *pos_izda;

   /* Algoritmo: Se recorre el vector delimitado por los dos extremos izda y 
   dcha. Se va adelantando el puntero de izquierda a derecha hasta llegar al 
   final delimitado, y se va controlando si se encuentra un valor menor que el
   mínimo o mayor que el máximo y se almacena por referencia */
   while (pos_izda <= pos_dcha){
      if (*pos_izda > maximo){
         maximo = *pos_izda;
      }
      
      if (*pos_izda < minimo){
         minimo = *pos_izda;
      }

      pos_izda++;
   }
}