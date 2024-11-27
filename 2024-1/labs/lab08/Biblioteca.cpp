//Author: MAKO
#include "header/Biblioteca.h"


Biblioteca::Biblioteca(){
}

Biblioteca::Biblioteca(const Biblioteca& orig){
}

Biblioteca::~Biblioteca(){
}

void Biblioteca::carga(){
    ifstream arch("docs/Estantes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERRO: No se pudo abrir Estantes"<<endl;
        exit(1);
    }
    //Datos
    int i = 0;
    while(AEstantes[i].lee(arch))i++;
}

void Biblioteca::llena(){
    ifstream arch("docs/Libros3.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Libros"<<endl;
        exit(1);
    }
    //Datos
    Libro* libro;
    char c;
    while (true){
        arch>>c;
        if(arch.eof())break;
        arch.ignore();
        if(c == 'N')
            libro = new Novela;
        else if(c == 'E')
            libro = new Enciclopedia;
        else
            libro = new Revista;
        libro->lee(arch);
        insertarLibro(libro);
    }
    muestra();
}

void Biblioteca::insertarLibro(Libro* libro){
    //Datos
    bool insertado = false;
    for (int i = 0; AEstantes[i].GetId(); i++){
        if(AEstantes[i].insertar(libro)){
            insertado = true;
            break;
        }
    }
    if(not insertado)delete libro;
}

void Biblioteca::baja(){
    for (int i = 0; AEstantes[i].GetId(); i++)
        AEstantes[i].actualiza();
}

void Biblioteca::muestra(){
    ofstream arch("docs/Report.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir Libros"<<endl;
        exit(1);
    }
    for (int i = 0;AEstantes[i].GetId(); i++)
        AEstantes[i].imprime(arch); 
}