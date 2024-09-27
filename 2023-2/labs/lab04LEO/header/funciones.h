#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MuestraPunteros.h"

using namespace std;


//funciones secundarias
void leerArchivo(ifstream & archivo, const char* nomArch);
void escribirArchivo(ofstream & archivo, const char* nomArch);
int hallarProducto(void *productos, char *codProdPed);
void agregar_a_lista_de_pedidos(void *&listadoPedidos, int *cantidad, char *codProdPed, double *);
int  hallarCantidadDatos(void *listadoPedidos);
void escribirCliente(ofstream &archivo, void *cliente);
void escribirLinea(ofstream &archivo, int largo, char limite);
void escribirPedido_Cliente(ofstream &archivo, void *pedido);
double *insertar_double(double lineaCredito);
int buscarCliente(const void *clientes, int *dni);


//funciones principales
void cargaproductos(void *&productos);
bool leerUnProd(void *&arrProdutosBuff, ifstream &archProd);

void cargaclientes(void  *&clientes);
bool leerUnCliente(void *&arrClientesBuff, ifstream & archClientes);

void cargapedidos(void *productos, void *&clientes);
bool leerUnPedido(void *productos, void  *&clientes, ifstream &archPed);
void lenarClienteConPedido(void *&listaClientes, void *productos, int *dni, int *cantidad, char *codProdPed);

void imprimereporte(void *clientes);

#endif /* FUNCIONES_H */