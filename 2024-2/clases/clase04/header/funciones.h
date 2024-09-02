//Author:Mako
#ifndef FUNCIONES_H
#define FUNCIONES_H

void lecturaDeProductos(const char*nomArch, char ***&productos, int *&stock, double *&precios);
char* lecturaExacta(ifstream& arch,char deli);

void incrementarCapacidad(char ***&productos,int *&stock,double *&precios,
                          int &cantDatos, int &capacidad);
void guardarDatosProducto( char **&infoProd, char *codigo, char *nombre);

void pruebaDeLecturaDeProductos(const char*nomArch, char ***productos, int *stock, double *precios);
void lecturaDePedidos(const char *nomPedidos, int*fechasPedidos,
                     char***codigoPedidos,int ***dniCantPedidos);
void pruebaDeLecturaDePedidos(const char* nomReporteDePedidos,
                              int* fechasPedidos, char ***codigoPedidos,
                              int ***dniCantPedidos);


#endif