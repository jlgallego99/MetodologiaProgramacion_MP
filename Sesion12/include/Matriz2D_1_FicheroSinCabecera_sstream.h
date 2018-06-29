//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas VI
// Declaración de una versión alternativa de la clase "Matriz2D_1"
//
// Clase que trabaja con matrices dinámicas de datos de tipo TipoBase
// El número de líneas de datos del fichero es el número de filas de la matriz
// El número de elementos de cada línea es el número de columnas
//
// PRECONDICIONES: 
// Filas y columnas positivas y correctas
// Cada dato del fichero está en una línea
//
//////////////////////////////////////////////////////////////////////////

#ifndef MATRIZ2D_1_FICHEROSINCABECERA
#define MATRIZ2D_1_FICHEROSINCABECERA

// Definición del tipo de datos

typedef int TipoBase;

// Declaración de la versión alternativa de la clase Matriz2D_1

class Matriz2D_1{
	private:
	
		TipoBase ** matriz;  // Puntero a la matriz de datos de tipo TipoBase
		int filas;           // Número de filas de la matriz
		int columnas;        // Número de columnas de la matriz

	public:

		/*******************************************************************/
		// Constructor sin argumentos: 
		// Crea una matriz vacía
		Matriz2D_1();

		/*******************************************************************/
		// Constructor con un argumento: 
		// Crea una matriz cuadrado con mismo número de filas y columnas
		Matriz2D_1(int);

		/*******************************************************************/
		// Constructor con dos argumentos:
		// Crea una matriz con un número de filas y columnas
		Matriz2D_1(int, int);

		/*******************************************************************/
		// Constructor con tres argumentos:
      // Crea una matriz con un número de filas y columnas
      // Inicia todas las casillas a un valor indicado
		Matriz2D_1(int, int, TipoBase);
		
		/*******************************************************************/
		// Constructor de copia
		Matriz2D_1(const Matriz2D_1 &);

		/*******************************************************************/
		// Constructor que recibe el nombre de un fichero de texto y rellena
		// las casillas de la matriz con los datos del fichero
		Matriz2D_1(const char *);
		
		/*******************************************************************/
		// Destructor
		~Matriz2D_1();
		
		/*******************************************************************/
		// Proporciona el número de filas
		int GetFilas() const;
		
		/*******************************************************************/
		// Proporciona el número de columnas
		int GetColumnas() const;
		
		/*******************************************************************/
		// Consulta si la matriz está vací­a
		bool MatrizVacia() const;
		
		/*******************************************************************/
		// Escribir un valor
		void ModificarValor(int, int, TipoBase) const;
		
		/*******************************************************************/
		// Modificar un valor
		TipoBase LeerValor(int, int) const;
		
		/*******************************************************************/
		// Inicializa todas las casillas de la matriz al valor del argumento
      // Si no se especifica ninguno, inicia todas las casillas al valor nulo
		void InicializaMatriz(TipoBase);
		void InicializaMatriz();

		/*******************************************************************/
		// Guarda en el fichero de texto *nombre* el contenido de la matriz
		void EscribirMatriz2D_1(const char *) const;

		/*******************************************************************/
		// Sustituye el contenido de la matriz por los valores que están
		// en el fichero de texto *nombre*
		void LeerMatriz2D_1(const char *);
		
		/*******************************************************************/
		// Sobrecarga del operador =
		// Realiza una copia profunda
		Matriz2D_1 & operator = (const Matriz2D_1 &);
		// Inicia toda la matriz al valor especificado
		Matriz2D_1 & operator = (TipoBase);

		/*******************************************************************/
		// Sobrecarga del operador ()
		// Acceso a los elementos de la matriz como lvalue y rvalue
		TipoBase & operator () (const int, const int);

		/*******************************************************************/
		// Sobrecarga de los operadores unarios + y -
		// Devuelve la matriz 
		Matriz2D_1 operator + ();
		// Devuelve la matriz con todas sus casillas negativas
		Matriz2D_1 operator - ();
		
		/*******************************************************************/
		// Sobrecarga de los operadores binarios + y -
		// Suma dos matrices
		Matriz2D_1 operator + (const Matriz2D_1 &);
		// Suma un número a todas las casillas de una matriz
		Matriz2D_1 operator + (const TipoBase);
		// Resta dos matrices
		Matriz2D_1 operator - (const Matriz2D_1 &);
		// Resta un número a todas las casillas de una matriz
		Matriz2D_1 operator - (const TipoBase);

		/*******************************************************************/
		// Sobrecarga de los operadores combinados += y -=
		// Realiza la copia profunda de la suma de una matriz a un valor
		Matriz2D_1 & operator += (const TipoBase);
		// Realiza la copia profunda de la resta de una matriz a un valor
		Matriz2D_1 & operator -= (const TipoBase);

		/*******************************************************************/
		// Sobrecarga de los operadores == y !=
		// Compara si dos matrices son iguales (según número de filas y columnas)
		bool operator == (const Matriz2D_1 &);
		// Compara si dos matrices son distintas (según número de filas y columnas)
		bool operator != (const Matriz2D_1 &);

	private:

		/*******************************************************************/
	   // Reserva memoria para una matriz
		void ReservaMemoria(const int, const int);
		
		/*******************************************************************/
		// Libera por completo la memoria de una matriz
		void LiberaMemoria();
		
		/*******************************************************************/
		// Copia una matriz en otra
		void CopiaMatriz(const Matriz2D_1 &);
		
		/*******************************************************************/
		// Rellena una matriz por completo a un valor
		void RellenaMatriz(TipoBase);

      /*******************************************************************/
		// Redimensiona la memoria de una matriz
      void Redimensiona();

};

/*******************************************************************/
// Muestra por completo una matriz
void MuestraMatriz(const Matriz2D_1 &);


#endif