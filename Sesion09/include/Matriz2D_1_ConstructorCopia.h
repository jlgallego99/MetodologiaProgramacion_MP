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

typedef int TipoBase;

class Matriz2D_1{
	private:
		TipoBase ** matriz;
		int filas;
		int columnas;

	public:
		Matriz2D_1();
		Matriz2D_1(int);
		Matriz2D_1(int, int);
		Matriz2D_1(int, int, TipoBase);
		Matriz2D_1(const Matriz2D_1 &);
		~Matriz2D_1();
		bool EstaVacia();
		void ModificarValor(int, int, TipoBase);
		TipoBase LeerValor(int, int) const;
		void InicializaMatriz(TipoBase);
		void InicializaMatriz();
		void MuestraMatriz();

	private:
		void ReservaMemoria();
		void LiberaMemoria();
		void CopiaMatriz(const Matriz2D_1 &);
		void RellenaMatriz(TipoBase);

};

#endif
