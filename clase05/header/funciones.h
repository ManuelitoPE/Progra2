//Author: MAKO
#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargarProductos(void *&productos);
void *lecturaProductos(ifstream& arch);
char* lecturaExactar(ifstream& arch,char deli);
void incrementarEspacio(void **&prod,int &cantDatos,int &capDat);
void* lecturaClientes(ifstream& arch);
void cargarClientes(void *& clientes);
void imprimeProductos(void *productos);
void imprimeClientes(void* clientes);
void cargaPedidos(void *&productos,void *&clientes);
void procesarDatos(void *&productos,void *&clientes,
                   char* code,int dni,int cant);
int busqueda(void **listaProductos,char* code);
int busqueda(void** listaClientes, int dni);    
void ingresarProducto(void *&dataCliente,char*code,int cant,
                      double precio);

#endif