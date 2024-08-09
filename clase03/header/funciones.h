//Author: MAKO
#ifndef FUNCIONES_H 
#define FUNCIONES_H 

void lecturaDeProductos(const char* nomProductos,
                        char ***&productos,int *&stock,
                        double *&precios);
char* lecturaExacta(ifstream& arch,char deli);
void preubaDeLecturaDeProductos(const char* nomReporte,
                                char ***productos,int *stock,
                                double *precios);
void encabezadoProductos(ofstream& report);
void linea(ofstream& report,int n,char c);
void lecturaDePedidos(const char* nomPedidos,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char* nomReporte,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos);
void ingresarDatos(char ***bufferCodigoPedidos,int ***bufferDniCantPedidos,
                   int *bufferFechaPedidos,int &cantDatos,char *code,
                   int fecha,int dni,int cant);
int buscarFecha(int *bufferFechaPedidos,int fecha,int cantDatos);
void ingresarPedido(int **bufferDniCantPedidos,char** bufferCodigoPedidos,
                    char *code,int cant,int dni);
void comprimirPedidos(char ***bufferCodigoPedidos,
                      int ***bufferDniCantPedidos);
void reporteDeEnvioDePedidos(const char* nomReporte,char*** productos,
                             int *&stock,double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos);
void encabezadoPedidos(ofstream& report);
void encabezadoPedidos2(ofstream& report);
void encabezado(ofstream& report);
void imprimirFecha(ofstream& report,int fecha);
void encabezado2(ofstream& report);
int buscarProducto(char ***productos,char* codigoPedidos);

#endif