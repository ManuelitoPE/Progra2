//Author: MAKO 
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream> 
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Estructuras.h"

//Lectura 
bool operator>>(ifstream& arch,Producto& producto);
bool operator>>(ifstream& arch,Cliente& cliente);
bool operator>>(ifstream& arch,Pedido& pedido);
//Agregacion
void operator+=(Cliente* cliente,const Pedido& pedido);
bool operator+=(Producto* producto,Pedido& pedido);
//Impresion 
ofstream& operator<<(ofstream& os,const Cliente* cliente);
ofstream& operator<<(ofstream& os,const Producto* producto);
ofstream& operator<<(ofstream& os,const Pedido* pedido);

//Auxiliares 
char* lecturaExacta(ifstream& arch,char deli);
int buscar(Cliente* cliente,int dni);
int buscar(Producto* producto,char* codigo);
void ingresarCliente(int* clientes,int& cant,
                     double precio,Pedido& pedido);
#endif