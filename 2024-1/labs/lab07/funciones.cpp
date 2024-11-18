//Author: mako

#include "header/funciones.h"

void aperturaArchLeer(const char* nomArch,ifstream& arch){
    arch.open(nomArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
}
void aperturaArchEscr(const char* nomArch,ofstream& arch){
    arch.open(nomArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
}
char* lecturaExacta(ifstream& arch, char deli){
    //Datos
    char* ptr,buffer[500];
    arch.getline(buffer,500,deli);
    ptr = new char[strlen(buffer)+1]{};
    strcpy(ptr,buffer);
    return ptr;
}
void linea(ofstream& report,int n,char c){
    for(int i=0;i<n;i++)report<<c;
    report<<endl;
}
void encabezado(ofstream& report){
    linea(report,MAX_LINEA,'=');
    report<<setw(50)<<"Informacion del posicionamiento de Libros"<<endl
          <<setw(45)<<"en los estantes de la Biblioteca"<<endl;
    linea(report,MAX_LINEA,'=');
}
void encabezado2(ofstream& report){
    linea(report,MAX_LINEA,'-');
    report<<left<<setw(10)<<"CODIGO"
          <<setw(29)<<"NOMBRE"
          <<setw(8)<<"ANCHO"
          <<setw(8)<<"ALTO"
          <<setw(8)<<"PESO"<<endl;
    linea(report,MAX_LINEA,'-');
}

