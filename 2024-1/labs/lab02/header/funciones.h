//Author: MAKO
#ifndef FUNCIONES_H 
#define FUNCIONES_H 

//Funciones Main

void lecturaDeLibros(const char* nomLibros,char***& libros,
                     int**& stock);
void pruebaDeLecturaDeLibros(const char* nomReporte,char*** libros,
                             int** stock);
void atencionDePedidos(const char* nomPedidos,char*** libros,
                       int**& stock,int**& pedidosClientes,
                       char***& pedidosLibros,bool**& pedidosAtendidos);
void pruebaDeLecturaDeLibros(const char* nomPedidos,char*** libros,
                             int** stock,int** pedidosClientes,
                             char*** pedidosLibros,bool** pedidosAtendidos);
void reporteDeEntregaDePedidos(const char* nomReporte,int**& pedidosClientes,
                               char*** pedidosLibros,bool** pedidosAtendidos);

//Funciones Auxiliares
void ingresarPedidoCliente(int** bufferPedidosClientes,int numDatos,int dniCliente,
                    int numeroPedido);
int buscarCliente(int** bufferPedidosClientes,int numDatos,
                  int dniCliente);
void linea(ofstream& report,int n,char c);
ofstream aperturaReporte(const char* nomReporte);
void lecturaStock(int*& stock,ifstream& arch);
char* lecturaExacta(ifstream& arch,char deli);
void lecturaDatosLibro(char**& libro,ifstream& arch);
ifstream aperturaArch(const char* nomLibros);

//Encabezados

void encabezadoReporteLibros(ofstream& report);


#endif