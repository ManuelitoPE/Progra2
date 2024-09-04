//Author: MAKO
#include "header/funciones.h"

//Lectura 
bool operator>>(ifstream& arch,Cliente& cliente){
    if(!arch.eof()){
        arch>>cliente.dni;
        arch.ignore();
        cliente.nombre = lecturaExacta(arch,',');
        arch>>cliente.telefono;
        return true;
    }
    cliente.dni = 0; 
    return false;
} 
bool operator>>(ifstream& arch,Producto& producto){ 
    char c;
    if(!arch.eof()){
        producto.codigo = lecturaExacta(arch,',');
        producto.descripcion = lecturaExacta(arch,',');
        arch>>producto.precio>>c>>producto.stock;
        arch.get();
        return true;
    }
    producto.precio = 0; 
    return false;
} 
ostream& operator<<(ostream& os,const Cliente* cliente){
    os<<left<<setw(10)<<cliente->dni
      <<setw(50)<<cliente->nombre
      <<right<<setw(10)<<cliente->telefono
      <<endl;
    return os;
}
ostream& operator<<(ostream& os,const Producto* producto){
    os<<left<<setw(10)<<producto->codigo
      <<setw(50)<<producto->descripcion
      <<right<<setw(10)<<producto->precio
      <<right<<setw(10)<<producto->stock
      <<endl;
    return os;
}

char* lecturaExacta(ifstream& arch,char deli){
    //DATOS
    char buffer[150],*ptr;
    arch.getline(buffer,150,deli);
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr; 
}
