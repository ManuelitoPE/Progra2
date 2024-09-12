//Author: MAKO
#ifndef FUNCIONES_H
#define FUNCIONES_H

//Funciones Main
void lecturaDeProductos(const char* nomProductos,char***& productos,
                        int*& stock,double*& precios);
void pruebaDeLecturaDeProductos(const char* nomReporte,char***& productos,
                        int*& stock,double*& precios);
void lecturaDePedidos(const char* nomPedidos,int*& fechaPedidos,
                      char***& codigoPedidos,int***& dniCantPedidos);
void pruebaDeLecturaDePedidos(const char* nomReporte,
                              int* fechaPedidos,char*** codigoPedidos,
                              int*** dniCantPedidos);
void reporteDeEnvioDePedidos(const char* nomReport,char*** productos,
                             int*& stock,double* precios,int* fechaPedidos,
                             char*** codigoPedidos,int*** dniCantPedidos);
//Funciones Auxiliares
ifstream aperturaArch(const char* nomProductos);
ofstream aperturaReport(const char* nomArch);
char* lecturaExacta(ifstream& arch,char deli);

void linea(ofstream& report,int n,char c);

void linea(ofstream& report,int n,char c);
void ingresarPedido(char* codigo,int dni,int cant,int fecha,
                     char*** bufferCodigoPedidos,
                     int*** bufferDniCantPedidos,
                     int* bufferFechaPedidos,int& numDatos);
void ingresarPedido(char** bufferCodigoPedidos,
                    int** bufferDniCantPedidos,char* codigo,
                    int dni,int cant);
int buscar(int* bufferFechaPedidos,int fecha);
int buscar(char* codigo,char*** productos);

int contador(int** bufferDniCantPedidos);
void comprimirPedidos(char*** bufferCodigoPedidos,
                      int*** bufferDniCantPedidos);
// Encabezados
void encabezadoProductos(ofstream& report);
void encabezadoPedidos(ofstream& report);
void encabezadoPedidos(ofstream& report,int fecha);
void encabezadoReporte(ofstream& report);
void encabezado(ofstream& report,int fecha);

#endif