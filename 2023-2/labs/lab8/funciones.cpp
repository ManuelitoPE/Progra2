//Author: mako
#include "header/Funciones.h"

void encabezado(ofstream& report){
    report<<setw(40)<<"REPORTE DE FLOTA"<<endl;
    linea(report,MAX_LINEA,'=');   
}

void linea(ofstream& report,int n,char c){
    for (int i = 0; i < n; i++)report<<c;
    report<<endl;
}