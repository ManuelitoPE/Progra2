//Author: MAKO
#include "header/funciones.h" 

char* lecturaExacta(ifstream& arch,char deli){
    //Datos
    char buffer[500],*ptr;
    arch.getline(buffer,500,deli);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}