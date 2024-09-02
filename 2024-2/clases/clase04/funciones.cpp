// //Author:MAKO
// #include <iostream>
// #include <iomanip>
// #include <cstring>
// #include <fstream>
// using namespace std;
// #include "header/funciones.h"
// #define INC 5
 
// void lecturaDeProductos(const char*nomArch, char ***&productos, int *&stock, double *&precios){
//     ifstream archProd(nomArch, ios::in);
//     if(not archProd.is_open()){
//         cout<<"Error, no se puede abrir el archivo "<<nomArch<<endl;
//         exit(1);
//     }
//     //Variables 
//     char codigo[10], nombre[100], c;
//     int stockAux;
//     double precioAux;
    
//     productos = nullptr;
//     stock = nullptr;
//     precios = nullptr;
    
//     int cantDatos=0, cap=0;
//     while(true){
//         archProd.getline(codigo, 10, ',');
//         if(archProd.eof()) break;
//         archProd.getline(nombre, 100, ',');
//         archProd>>precioAux>>c>>stockAux;
//         archProd.get();
        
//         //guardar datos -> si es que hay espacio para guardar
//         if(cantDatos==cap)incrementarCapacidad(productos, stock, precios, cantDatos, cap);// cap:5  cant:0
        
        
//         guardarDatosProducto(productos[cantDatos-1], codigo, nombre);
//         stock[cantDatos-1] = stockAux;
//         precios[cantDatos-1] = precioAux;
        
//         cantDatos++;      
//     }    
    
//     cout<<"CAP: "<<cap<<endl;
//     cout<<"CAN: "<<cantDatos<<endl;
    
// }

// void incrementarCapacidad(char ***&productos, int *&stock, double *&precios, int &cantDatos, int &cap){
//     cap += INC;//0 -> 5 -> 10
//     if(productos==nullptr){//no he guardado nada -> reservo espacio por primera vez -> tamaño INC(5)
//         productos = new char**[cap]{};//todos nullptr
//         stock = new int[cap]{};//todos ceros
//         precios = new double[cap]{};//todos ceros
//         cantDatos=1;//siempre tendre un null al final de la estructura
//     }else{
        
//         char ***buffProd = new char**[cap]{};
//         int *buffStock = new int[cap]{};
//         double *buffPrecio = new double[cap]{};
//         for(int i=0 ; i<cantDatos ; i++){
//             buffProd[i] = productos[i];
//             buffStock[i] = stock[i];
//             buffPrecio[i] = precios[i];
//         }
        
//         delete productos;
//         delete stock;
//         delete precios;
        
//         productos = buffProd;
//         stock = buffStock;
//         precios = buffPrecio;
//     }
// }

// void guardarDatosProducto( char **&infoProd, char *codigo, char *nombre){
//     infoProd = new char*[2];// codigo y nombre
    
//     infoProd[0] = new char[strlen(codigo)+1];
//     strcpy(infoProd[0], codigo);
    
//     infoProd[1] = new char[strlen(nombre)+1];
//     strcpy(infoProd[1], nombre);
// }

// void pruebaDeLecturaDeProductos(const char*nomArch, char ***productos, int *stock, double *precios){
//     ofstream archRep(nomArch, ios::out);
    
//     for(int i=0 ; productos[i] ; i++){
//         archRep<<productos[i][0]<<"   "<<productos[i][1]<<"  "<<stock[i]<<"   "<<precios[i]<<endl;
//     }
// }
// void lecturaDePedidos(const char *nomPedidos, int*fechasPedidos,
//                      char***codigoPedidos,int ***dniCantPedidos){
//     ifstream archProd(nomPedidos, ios::in);
//     if(not archProd.is_open()){
//         cout<<"Error, no se puede abrir el archivo "<<nomPedidos<<endl;
//         exit(1);
//     }
    
//     char codigo[10], c;
//     int dni,cantidad,dd,mm,aa,fecha;
//     double precioAux;
    
//     fechasPedidos = nullptr;
//     codigoPedidos = nullptr;
//     dniCantPedidos = nullptr;
    
//     int cantDatos=0, cap=0;
//     while(true){
//         archProd.getline(codigo, 10, ',');
//         if(archProd.eof()) break;
//         archProd>>dni>>c>>cantidad>>c>>dd>>c>>mm>>c>>aa; 
//         fecha = aa*10000+mm*100+dd;
//         archProd.get();
        
//         //guardar datos -> si es que hay espacio para guardar
//         if(cantDatos==cap)
//             incrementarCapacidadPedidos(codigoPedidos,fechasPedidos,
//                                         dniCantPedidos,cantDatos,cap);// cap:5  cant:0
        
        
//         guardarDatosProducto(productos[cantDatos-1], codigo, nombre);
//         stock[cantDatos-1] = stockAux;
//         precios[cantDatos-1] = precioAux;
        
//         cantDatos++;      
//     }    
// }
// void incrementarCapacidadPedidos(char ***&codigoPedidos,
//                                  int *fechasPedidos,
//                                         dniCantPedidos,cantDatos,cap);
// void pruebaDeLecturaDePedidos(const char* nomReporteDePedidos,
//                               int* fechasPedidos, char ***codigoPedidos,
//                               int ***dniCantPedidos){

// }