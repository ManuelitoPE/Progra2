//Author: MAKO
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>  
using namespace std;
#include "AperturaArch.h"
#include "Enums.h"
#include "MuestraPunteros.h"
#define MAX_LINEA 120
#define NO_ENCONTRADO -1
#define MAX 200
//Funciones main
void cargaproductos(void*& productos);

void cargaclientes(void*& clientes);

void cargapedidos(void*& productos,void*& clientes);

void imprimereporte(void*& clientes);

//Funciones Auxiliares
void imprimeProducto(void* productos);

//Busquedas
int buscar(void* clientes,int dni);

int buscar(void* productos,char* codigo);

//Lecturas
bool lectura(char*& codigoProducto,char*& descripcion,
             char*& tipoDeProducto,double*& precio,ifstream& arch);

bool lectura(ifstream& arch,int*& dni,char*& nombre,double*& lineCredito);

bool lectura(ifstream& arch,char*& codigo,int& dni,int& cant);

char* lecturaExacta(ifstream& arch,char deli);

//INGRESOS
void ingresoDeProducto(void*& producto,char* codigoProducto,
                       char* descripcion,char* tipoDeProducto,double* precio);

void ingresoCliente(void*& cliente,char* nombre,int* dni,
                    double* lineCredito);

void ingresarPedido(void*& lista,void**& infoProducto,
                    int cant);

void linea(ofstream& report,int n,char c);

int contador(void* lista);

void comprimirClientes(void*& clientes);

//Encabezados
void encabezadoProducto(ofstream& report); 


#endif