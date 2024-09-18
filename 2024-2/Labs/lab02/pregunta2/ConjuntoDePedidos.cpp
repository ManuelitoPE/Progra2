/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "header/ConjuntoDePedidos.hpp"
#include "header/Pedido.hpp"
#include "header/Comunes.hpp"
#include "header/ConjuntoDePlatos.hpp"
#include "libraries/AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    //Lectura simple
    ConjuntoDePedidos bufferConjuntoDeDatos{};
    //Inicializamos 
    inicializar_buffer_de_conjunto_de_pedidos(bufferConjuntoDeDatos,MAX_PEDIDOS);
    Pedido pedido;
    //La lectura del pedido es estatica
    while(archivo_de_pedidos>>pedido)bufferConjuntoDeDatos<<pedido;
    bufferConjuntoDeDatos >>conjuntoDePedidos;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad]; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    //Incluir un pedido en en el conjutnos de datos 
    int posCliente = buscar_cliente(buffer_de_conjuntoDePedidos,pedido.dni_cliente);
    int cantCliente = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
    char** bloqueCadena; 
    int* bloqueEntero;
    if(posCliente==CLIENTE_NO_ENCONTRADO){
        bloqueEntero = buffer_de_conjuntoDePedidos.enteros[cantCliente] = new int[MAX_PLATOS_PEDIDO+1]{};
        bloqueCadena = buffer_de_conjuntoDePedidos.cadenas[cantCliente] = new char*[MAX_PLATOS_PEDIDO+1]{};
        bloqueEntero[0] = pedido.dni_cliente;
        bloqueCadena[0] = mi_strdup(pedido.codigo_repartidor);
        ingresarPlato(bloqueCadena,bloqueEntero,pedido);
    }else{
        bloqueEntero = buffer_de_conjuntoDePedidos.enteros[posCliente];
        bloqueCadena = buffer_de_conjuntoDePedidos.cadenas[posCliente];
        ingresarPlato(bloqueCadena,bloqueEntero,pedido);
    }
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    //Pasar una una estructura a otra de manera exacta   
    int cant = obtener_cantidad_cliente(buffer_de_conjuntoDePedidos);
    conjuntoDePedidos.cadenas = new char**[cant+1]{};
    conjuntoDePedidos.enteros = new int*[cant+1]{};
    conjuntoDePedidos.reales = nullptr;
    for(int i=0; i<cant; i++){
        conjuntoDePedidos.cadenas[i] = buffer_de_conjuntoDePedidos.cadenas[i];
        conjuntoDePedidos.enteros[i] = buffer_de_conjuntoDePedidos.enteros[i];
    }
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    //Apertura de paltos 
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "docs/platos.csv");
    int cantPedidos = obtener_cantidad_cliente(conjuntoDePedidos);
    int cantTipos;
    double precio_plato;
    //Asignamos espacio a reales
    conjuntoDePedidos.reales = new double*[cantPedidos+1]{};
    //Aperturamos espacio para ingresar los precios
    for (int i = 0; i<cantPedidos; i++){
        cantTipos = conjuntoDePedidos.enteros[i][1];
        ingresarPrecios(conjuntoDePedidos.reales[i],conjuntoDePedidos.cadenas[i],
                        conjuntoDePedidos.enteros[i],conjuntoDePlatos,cantTipos);
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    //Apertura de paltos 
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "docs/platos.csv");
    int cantPedidos = obtener_cantidad_cliente(conjuntoDePedidos);
    int cantTipos;
    double precio_plato;
    //Asignamos espacio a reales
    conjuntoDePedidos.reales = new double*[MAX_PEDIDOS]{};
    //Aperturamos espacio para ingresar los precios
    for (int i = 0; i<cantPedidos; i++){
        cantTipos = conjuntoDePedidos.enteros[i][1];
        ingresarPrecios(conjuntoDePedidos.reales[i],conjuntoDePedidos.cadenas[i],
                        conjuntoDePedidos.enteros[i],conjuntoDePlatos,cantTipos);
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {
    int cant =  obtener_cantidad_cliente(conjuntoDePedidos);
    for (int i = 0; i < cant; i++){
        if(conjuntoDePedidos.cadenas[i]!=nullptr)
            delete conjuntoDePedidos.cadenas[i];
        if(conjuntoDePedidos.enteros[i]!=nullptr)
            delete conjuntoDePedidos.enteros[i];
    }
    if(conjuntoDePedidos.cadenas!=nullptr)
        delete conjuntoDePedidos.cadenas;
    if(conjuntoDePedidos.enteros!=nullptr)
        delete conjuntoDePedidos.enteros;
    if(conjuntoDePedidos.reales!=nullptr){
        for (int i = 0; i < cant; i++){
            if(conjuntoDePedidos.reales[i]!=nullptr)
                delete conjuntoDePedidos.reales[i];
        }
        delete conjuntoDePedidos.reales;
    }
}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    //Apertura de paltos 
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "docs/platos.csv");
    int cantPedidos = obtener_cantidad_cliente(conjuntoDePedidos);
    char** bloqueCadena,*nombre; 
    for (int i = 0; i<cantPedidos; i++){
        bloqueCadena = conjuntoDePedidos.cadenas[i];
        for (int k = 1; bloqueCadena[k]; k++){
            nombre = conjuntoDePlatos==bloqueCadena[k];
            delete[] bloqueCadena[k];
            bloqueCadena[k] = nombre;
        }
    }
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    //Apertura de arch
    int cant = obtener_cantidad_cliente(conjuntoDePedidos);
    char nombre[100];
    for (int i = 0; i < cant; i++){
        ofstream report;
        obtener_nombre_archivo(nombre,conjuntoDePedidos.enteros[i][0]);
        AperturaDeUnArchivoDeTextosParaEscribir(report,nombre);
        crearReporte(conjuntoDePedidos.enteros[i],conjuntoDePedidos.cadenas[i],
                     conjuntoDePedidos.reales[i],report);
        // cout<<conjuntoDePedidos.enteros[i][0]<<endl;
    }
}
void crearReporte(int *enteros,char **cadenas,double *reales,ofstream& arch){
    arch.precision(2);
    imprimir_linea(arch);
    arch<<fixed<<right<<setw(20)<<"D.N.I. CLIENTE:"<<left<<"  "<<setw(10)
        <<enteros[0]<<endl;
    arch<<right<<setw(20)<<"CODIGO REPARTIDOR:"<<left<<"  "<<setw(10)<<cadenas[0]
        <<endl;
    imprimir_linea(arch);
    arch<<left<<setw(5)<<"ITEM"<<setw(21)<<"PLATO"<<setw(5)<<"CANT"
        <<setw(15)<<"SUBTOTAL"<<endl;
    imprimir_linea(arch,'-');
    for (int i = 1; i < enteros[1]+1; i++) {
        arch<<"  "<<right<<setw(2)<<setfill('0')<<i<<setfill(' ')<<' '
           <<left<<setw(20)<<cadenas[i]<<right<<setw(4)<<enteros[i+1]
           <<setw(10)<<reales[i]<<endl;
    }
    imprimir_linea(arch,'-');
    arch<<right<<setw(30)<<"SUBTOTAL:"<<setw(9)<<reales[0]<<endl;
    arch<<right<<setw(30)<<"IGV:"<<setw(9)<<reales[0]*((double)18/100)<<endl;
    arch<<right<<setw(30)<<"TOTAL:"<<setw(9)<<reales[0]*((double)118/100)<<endl;
    imprimir_linea(arch);
}
void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "docs/Comprobantes/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos){
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}
void ingresarPlato(char**& bloqueCadena,int* bloqueEntero,
                   const Pedido pedido){
    int i = 0;
    while (bloqueCadena[i])i++;
    //Agregamos el plato
    bloqueCadena[i] = mi_strdup(pedido.codigo_plato);
    bloqueEntero[i+1] = pedido.cantidad_platos;
    bloqueEntero[1]++;
}

void ingresarPrecios(double*& reales,char** cadenas,int* entero,const ConjuntoDePlatos conjuntoDePlatos,int cantTipos){
    //Asignamos el espacio 
    reales = new double[cantTipos+1]{};
    double precio_plato;
    for (int k = 0; cadenas[k+1]; k++){
        precio_plato= conjuntoDePlatos+=cadenas[k+1];
        reales[k+1]+= precio_plato*entero[k+2];
        reales[0]+= precio_plato*entero[k+2];
    }
}