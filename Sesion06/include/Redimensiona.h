//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas II
// Declaración de la función Redimensiona
//
// Función que realoja y redimensiona un vector dinámico, ampliándolo, cuando no
// haya espacio para almacenar un nuevo valor. 
// Se puede realizar de tres maneras:
// En una casilla, en bloques o duplicando su tamaño 
//
//////////////////////////////////////////////////////////////////////////

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

int * Redimensiona(int *, TipoRedimension, int &);
int * AumentaVector(int *, int, int);