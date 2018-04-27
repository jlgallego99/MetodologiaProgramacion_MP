//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas III
// Declaración de la clase "Matriz2D_1"
//
// Clase que trabaja con matrices dinámicas de datos de tipo TipoBase
//
//////////////////////////////////////////////////////////////////////////

#ifndef MATRIZ2D_1
#define MATRIZ2D_1

// Definición del tipo de datos

typedef int TipoBase;

// Declaración de la clase Matriz2D_1

class Matriz2D_1{
	private:
	
		TipoBase ** matriz;  // Puntero a la matriz de datos de tipo TipoBase
		int filas;           // Número de filas de la matriz
		int columnas;        // Número de columnas de la matriz

	public:
	
		// Constructor sin argumentos: 
		// Crea una matriz vacía
		Matriz2D_1();

		// Constructor con un argumento: 
		// Crea una matriz cuadrado con mismo número de filas y columnas
		// PRECONDICIÓN: Filas y columnas positivas
		Matriz2D_1(int);

		// Constructor con dos argumentos:
		// Crea una matriz con un número de filas y columnas
		// PRECONDICIÓN: Filas y columnas positivas
		Matriz2D_1(int, int);

		// Constructor con tres argumentos:
      // Crea una matriz con un número de filas y columnas
      // Inicia todas las casillas a un valor indicado
		Matriz2D_1(int, int, TipoBase);
		
		// Constructor de copia
		Matriz2D_1(const Matriz2D_1 &);
		
		// Destructor
		~Matriz2D_1();
		
		// Proporciona el número de filas
		int GetFilas() const;
		
		// Proporciona el número de columnas
		int GetColumnas() const;
		
		// Consulta si la matriz está vací­a
		bool MatrizVacia() const;
		
		// Escribir un valor
		void ModificarValor(int, int, TipoBase) const;
		
		// Modificar un valor
		// PRECONDICIÓN: Filas y columnas positivas y correctas
		TipoBase LeerValor(int, int) const;
		
		// Inicializa todas las casillas de la matriz al valor del argumento
      // Si no se especifica ninguno, inicia todas las casillas al valor nulo
		void InicializaMatriz(TipoBase);
		void InicializaMatriz();
		
		// Muestra por completo una matriz
		void MuestraMatriz() const;

	private:
	
	   // Reserva memoria para una matriz
		// PRECONDICIÓN: Filas y columnas positivas
		void ReservaMemoria(const int, const int);
		
		// Libera por completo la memoria de una matriz
		void LiberaMemoria();
		
		// Copia una matriz en otra
		void CopiaMatriz(const Matriz2D_1 &);
		
		// Rellena una matriz por completo a un valor
		void RellenaMatriz(TipoBase);

};

#endif
