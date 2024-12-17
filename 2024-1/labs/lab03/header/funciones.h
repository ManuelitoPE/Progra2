//Author: MAKO
#ifndef FUNCIONES_H 
#define FUNCIONES_H

//Funciones Main
void lecturaDeLibros(const char* nomLibros,char***& libros,
                     int**& stock);

void pruebaDeLecturaDeLibros(const char* nomReporte,char*** libros,
                     int** stock);

void atencionDePedidos(const char* nomPedidos,char***& libros,
                    int**& stock,int**& pedidosClientes,
                    char***& pedidosLibros,bool**& pedidosAtendidos);

void ordenarPedidosClientes(int**& pedidosClientes);

void reporteDeEntregaDePedidos(const char* nomReporte,int** pedidosClientes,
                    char*** pedidosLibros,bool** pedidosAtendidos);

//Funciones Auxiliares
char* lecturaExacta(ifstream& arch,char deli);

void ingresarDatos(char**& infoLibros,int*& infostock,char* codigo,
                   char* titulo,char* autor,int aux_stock);

void linea(ofstream& report,int n,char c);

void lecturaDeLibrosPedido(ifstream& arch,char**& listaLibros);

void agregarLibro(char*& libro,char* codigo);

void agregarCliente(int**& pedidosClientes,int dniCliente,int numPedido,
                    int& cantClientes);

int buscarCliente(int** pedidosClientes,int dni,int cantClientes);

//Incrementos
void incrementar(char***& libros,int**& stock,int& capacidad,int& cantDatos);

void incrementar(char**& listaLibros,int& capacidad,int& cantLibro);

void incrementar(char***& pedidosLibros,bool**& pedidosAtendidos,
                 int& capacidad,int& cantDatos,int numPedido);

void incrementar(int* cliente);


void incrementar(int**& pedidosClientes,int& capacidadClientes,
                 int& cantClientes);
//Encabezados
void encabezadoLibros(ofstream& report);



#endif