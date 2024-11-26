//Author: MAKO

#include "header/Flota.h"

Flota::Flota(){
    lista = {};
}
Flota::~Flota(){
}

void Flota::cargarFlota(){
    ifstream arch("docs/Vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir vehiculos"<<endl;
        exit(1);
    }
    //Datos 
    Vehiculo* vehiculo;
    char c;
    while(true){
        arch>>c;
        if(arch.eof())break;
        if(c == 'C')
             vehiculo = new Camion;
        else 
            vehiculo = new Furgon;
        vehiculo->lee(arch);
        lista.insertar(vehiculo);
    }
}


void Flota::cargarPedidos(){
    ifstream arch("docs/Pedidos3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir vehiculos"<<endl;
        exit(1);
    }
    //Datos 
    NPedido nuevo;
    int cliente;
    while(true){
        arch>>cliente;
        if(arch.eof())break;
        arch.ignore();  
        nuevo.lee(arch);
        lista.ingresaPedido(cliente,nuevo);
    }
}

void Flota::muestraCarga(){
    ofstream report("docs/Reporte.txt",ios::out);
    if(not report.is_open()){
        cout<<"ERROR: No se pudo abrir Pedidos"<<endl;
        exit(1);
    }
    encabezado(report);
    lista.mostrar(report);
}