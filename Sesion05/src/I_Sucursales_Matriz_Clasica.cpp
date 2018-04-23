//////////////////////////////////////////////////////////////////////////
//
// Metodología de la Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
// Relación de problemas I, Ejercicio 24
// Programa principal y funciones
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const char MAX_PRODUCTOS = 'j';
const int NUM_SUCURSALES = 100;
const int NUM_PRODUCTOS = 'j' - 'a' + 1;
const int TERMINADOR = -1;

/* Declaración de las funciones utilizadas */
int LeerVentas(int[][NUM_PRODUCTOS]);
void VentasSucursal(int *, int[][NUM_PRODUCTOS]);
int MayorSucursal(int *);
void MostrarSucursales(int *);
int SucursalesConVentas(int *);
int TotalVendidasSucursales(int *);
void VentasProductos(int *, int[][NUM_PRODUCTOS]);
char MayorProducto(int *);
void MostrarProductos(int *);
int ProductosConVentas(int *);
int TotalVendidasProductos(int *);
void TablaResumen(int [][NUM_PRODUCTOS], int, int);

int main(){
	int ventas[NUM_SUCURSALES][NUM_PRODUCTOS] = {0};
	int ventas_sucursal[NUM_SUCURSALES] = {0};
	int ventas_productos[NUM_PRODUCTOS] = {0};

	// a) Se leen los datos de la matriz y se obtiene el número de operaciones
	int num_operaciones = LeerVentas(ventas);
	cout << "Número total de operaciones de venta: " << num_operaciones << endl;

	// Ventas de todas las sucursales
	VentasSucursal(ventas_sucursal, ventas);
	// b) Sucursal con más ventas
	int mayor_sucursal = MayorSucursal(ventas_sucursal);

	cout << "La mayor sucursal es la número " << mayor_sucursal
		  << " con un total de: " << ventas_sucursal[mayor_sucursal] << " ventas"
		  << endl;

	// c) Listado de las sucursales que hayan vendido algun producto
	MostrarSucursales(ventas_sucursal);

	// d) El número de sucursales que hayan vendido algún producto
	cout << "Número de sucursales con ventas: "
		  << SucursalesConVentas(ventas_sucursal) << endl;

	/* e) Número total de unidades vendidas (calculado como suma de las ventas 
	por sucursales) */
	cout << "Se han vendido en total: " 
	     << TotalVendidasSucursales(ventas_sucursal)
		  << " unidades" << endl;

	// Ventas de todos los productos
	VentasProductos(ventas_productos, ventas);
	// f) Producto más vendido y cuántas unidades
	int mayor_producto = MayorProducto(ventas_productos);

	cout << "El producto más vendido es " << mayor_producto
		  << " con un total de: " << ventas_productos[mayor_producto] << " ventas"
		  << endl;

	// g) Listado de los productos que hayan tenido alguna venta
	MostrarProductos(ventas_productos);

	// h) El número de productos que hayan vendido algun producto
	cout << "Número de productos con ventas: "
		  << ProductosConVentas(ventas_productos) << endl;

	/* i) Número total de unidades vendidas (calculado como suma de las ventas 
	por producto) */
	cout << "Se han vendido en total: " 
	     << TotalVendidasProductos(ventas_productos)
		  << " unidades" << endl;

	// j) Tabla-resumen con toda la información
	TablaResumen(ventas, SucursalesConVentas(ventas_sucursal),
	ProductosConVentas(ventas_productos));

	return 0;
}

/* Definición de las funciones */
int LeerVentas(int ventas[][NUM_PRODUCTOS]){
	int id_sucursal, vendidos, operaciones = 0;
	char codigo;

	cout << "Introduzca identificador de sucursal, código de producto y número "
		  << "de unidades vendidas. Para terminar de introducir datos, introduzca"
		  << " el terminador -1." << endl;

	/* Va leyendo datos y almacenándolos en una matriz hasta introducir como
   id de la sucursal el terminador -1 */
	cin >> id_sucursal;
	while (id_sucursal != TERMINADOR){
		cin >> codigo;
		cin >> vendidos;

		ventas[id_sucursal - 1][codigo - 'a'] = vendidos;
		operaciones++;

		cin >> id_sucursal;
	}

	return operaciones;
}

void VentasSucursal(int ventas_sucursal[], int ventas[][NUM_PRODUCTOS]){
	for (int i = 0 ; i < NUM_SUCURSALES ; i++){
		for (int j = 0 ; j < NUM_PRODUCTOS ; j++){
			// Se van sumando todas las ventas de la sucursal (fila) en una posicion
			ventas_sucursal[i] += ventas[i][j];
		}
	}
}

int MayorSucursal(int *ventas){
	// Inicio del máximo a la primera sucursal
	int maximo = ventas[0];
	int sucursal_maximo = 1;

	/* Se recorre todo el vector buscando un máximo, que se va actualizando
   cada vez que se encuentre uno mayor */
	for (int i = 0 ; i <= NUM_SUCURSALES ; i++){
		if (ventas[i] > maximo){
			maximo = ventas[i];
			sucursal_maximo = i;
		}
	}

	return sucursal_maximo;
}

void MostrarSucursales(int *ventas_sucursal){
	cout << "Listado de ventas por sucursal: " << endl;

	for (int i = 0 ; i <= NUM_SUCURSALES ; i++){
		if (ventas_sucursal[i] > 0){
			cout << "La sucursal número: " << i << " tiene "
				  << ventas_sucursal[i] << " ventas." << endl;
		}
	}

	cout << endl;
}

int SucursalesConVentas(int *ventas_sucursal){
	int sucursales_con_ventas = 0;

	for (int i = 0 ; i <= NUM_SUCURSALES ; i++){
		if (ventas_sucursal[i] > 0){
			sucursales_con_ventas++;
		}
	}

	return sucursales_con_ventas;
}

int TotalVendidasSucursales(int *ventas_sucursal){
	int total_vendidas = 0;

	for (int i = 0 ; i < NUM_SUCURSALES ; i++){
		total_vendidas += ventas_sucursal[i];
	}

	return total_vendidas;
}

void VentasProductos(int ventas_producto[], int ventas[][NUM_PRODUCTOS]){
	for (int i = 0 ; i < NUM_PRODUCTOS ; i++){
		for (int j = 0; j < NUM_SUCURSALES; j++){
			ventas_producto[i] += ventas[j][i];
		}
	}
}

char MayorProducto(int *ventas_producto){
	// Inicio del máximo al primer producto
	int maximo = ventas_producto[0];
	int producto_maximo = 'a';

	// Se recorre todo el vector buscando un máximo, que se va actualizando
	// cada vez que se encuentre uno mayor
	for (char i = 'a' ; i <= MAX_PRODUCTOS ; i++){
		if (ventas_producto[i] > maximo){
			maximo = ventas_producto[i];
			producto_maximo = i;
		}
	}

	return producto_maximo;
}

void MostrarProductos(int *ventas_productos){
	cout << "Listado productos vendidos: " << endl;

	for (char i = 'a' ; i <= MAX_PRODUCTOS ; i++){

		if (ventas_productos[i] > 0){
			cout << "El producto " << i << " tiene "
				  << ventas_productos[i] << " ventas." << endl;
		}
	}

	cout << endl;
}

int ProductosConVentas(int *ventas_productos){
	int productos_con_ventas = 0;

	for (char i = 'a' ; i <= MAX_PRODUCTOS ; i++)
		if (ventas_productos[i - 'a'] > 0)
			productos_con_ventas++;

	return (productos_con_ventas);
}

int TotalVendidasProductos(int *ventas_productos){
	int total_vendidas = 0;

	for (char i = 'a' ; i < NUM_PRODUCTOS ; i++){
		total_vendidas += ventas_productos[i];
	}

	return total_vendidas;
}

void TablaResumen(int ventas[][NUM_PRODUCTOS], int num_sucursales, 
                  int num_productos){

	cout << "Tabla resumen con toda la información: " << endl;
	for (int i = 0 ; i < num_sucursales ; i++){
		cout << i << " | ";
		for (int j = 0 ; j < num_productos ; j++){
			cout << ventas[i][j] << " ";
		}
		cout << "| " << endl;
	}
}