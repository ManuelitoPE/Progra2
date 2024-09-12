//Author: MAKO	
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "header/funciones.h"
#include "header/enums.h"
#define NO_ENCONTRADO -1

void lecturaDeProductos(const char* nomProductos,char***& productos,
                        int*& stock,double*& precios){
    ifstream arch = aperturaArch(nomProductos);
    //Datos
    char *bufferProductos[MAX::PRODUCTOS][2];
    int bufferStock[MAX::PRODUCTOS];
    double bufferPrecios[MAX::PRODUCTOS];
    int numProductos = 0; 
    
    //Lectura en el buffer
    while(true){
        bufferProductos[numProductos][PRODUCTOS_POS::CODIGO] = lecturaExacta(arch,',');
        if(arch.eof())break;
        bufferProductos[numProductos][PRODUCTOS_POS::NOMBRE] = lecturaExacta(arch,',');
        arch>>bufferPrecios[numProductos]; arch.ignore();
        arch>>bufferStock[numProductos]; arch.ignore();
        numProductos++;
    }
    // Asignacion de memoria exacta
    productos = new char**[numProductos+1]{}; 
    precios = new double[numProductos+1]{};
    stock = new int[numProductos+1]{};

    for(int i = 0; i<numProductos; i++){
        productos[i] = new char*[2];
        // productos[i] =  bufferProductos[i];
        precios[i] = bufferPrecios[i];
        stock[i] = bufferStock[i];   
        productos[i][PRODUCTOS_POS::CODIGO] = bufferProductos[i][PRODUCTOS_POS::CODIGO];
        productos[i][PRODUCTOS_POS::NOMBRE] = bufferProductos[i][PRODUCTOS_POS::NOMBRE];
    }
}
void pruebaDeLecturaDeProductos(const char* nomReporte,char***& productos,
                        int*& stock,double*& precios){
    ofstream report = aperturaReport(nomReporte);
    encabezadoProductos(report);
    for(int i = 0; productos[i] != nullptr; i++){
         report<<left<<setw(10)<<productos[i][PRODUCTOS_POS::CODIGO]
               <<left<<setw(60)<<productos[i][PRODUCTOS_POS::NOMBRE]
               <<right<<setw(10)<<precios[i]<<setw(10)<<stock[i]<<endl;
    }
    linea(report,MAX::LINEA1,'=');
}
void lecturaDePedidos(const char* nomPedidos,int*& fechaPedidos,
                      char***& codigoPedidos,int***& dniCantPedidos){
    ifstream arch = aperturaArch(nomPedidos);
    //Datos
    //Asignamos un espacio por un maximo de fechas
    int bufferFechaPedidos[MAX::PEDIDOS_FECHA]{};
    char** bufferCodigoPedidos[MAX::PEDIDOS_FECHA]{};
    int** bufferDniCantPedidos[MAX::PEDIDOS_FECHA]{};
    int numDatos = 0; 
    int dni,cant,dd,mm,aa,fecha;
    char* codigo,c; 
    while(true){
        codigo = lecturaExacta(arch,',');
        if(arch.eof())break;
        arch>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        fecha = aa*10000+mm*100+dd; //Comprimimos la fecha
        arch.ignore(); 
        //Ingresamos los pedidos, dnis y cantidades
        ingresarPedido(codigo,dni,cant,fecha,bufferCodigoPedidos,
                       bufferDniCantPedidos,bufferFechaPedidos,
                       numDatos);
    } 
    comprimirPedidos(bufferCodigoPedidos,bufferDniCantPedidos);
    fechaPedidos = new int[numDatos+1]{};
    codigoPedidos = new char**[numDatos+1]{};
    dniCantPedidos = new int**[numDatos+1]{};

    for (int i = 0; i < numDatos; i++){
        fechaPedidos[i] = bufferFechaPedidos[i];
        codigoPedidos[i] = bufferCodigoPedidos[i];
        dniCantPedidos[i] = bufferDniCantPedidos[i];
    }
}
void pruebaDeLecturaDePedidos(const char* nomReporte,
                              int* fechaPedidos,char*** codigoPedidos,
                              int*** dniCantPedidos){
    ofstream report = aperturaReport(nomReporte);
    encabezadoPedidos(report);
    for (int i = 0; fechaPedidos[i]; i++){
        encabezadoPedidos(report,fechaPedidos[i]);
        for (int j = 0; codigoPedidos[i][j]; j++){
            report<<setw(2)<<" "<<right<<setw(3)<<j+1<<") "
                  <<left<<setw(10)<<codigoPedidos[i][j]
                  <<right<<setw(10)<<dniCantPedidos[i][j][PEDIDOS_POS::DNI]
                  <<right<<setw(7)<<dniCantPedidos[i][j][PEDIDOS_POS::CANT]
                  <<endl;
        }
        linea(report,MAX::LINEA2,'=');
    }
}
void reporteDeEnvioDePedidos(const char* nomReport,char*** productos,
                             int*& stock,double* precios,int* fechaPedidos,
                             char*** codigoPedidos,int*** dniCantPedidos){
    ofstream report = aperturaReport(nomReport);
    // Variables
    int posNombreProducto;
    encabezadoReporte(report);
    for (int i = 0;fechaPedidos[i] ; i++){
        encabezado(report,fechaPedidos[i]);
        for (int j = 0; dniCantPedidos[i][j]; j++){
            posNombreProducto = buscar(codigoPedidos[i][j],productos);
            
            report<<setfill('0')<<right<<setw(2)<<j+1<<") "<<setfill(' ')
                  <<setw(15)<<left<<dniCantPedidos[i][j][PEDIDOS_POS::DNI]
                  <<setw(10)<<left<<codigoPedidos[i][j]
                  <<setw(60)<<left<<productos[posNombreProducto][PRODUCTOS_POS::NOMBRE]
                  <<setw(5)<<left<<dniCantPedidos[i][j][PEDIDOS_POS::CANT]
                  <<setw(10)<<right<<precios[posNombreProducto];
            if(stock[posNombreProducto]-dniCantPedidos[i][j][PEDIDOS_POS::CANT]>=0){
                report<<right<<setw(10)<<precios[posNombreProducto]*
                                         dniCantPedidos[i][j][PEDIDOS_POS::CANT];
                stock[posNombreProducto]-=dniCantPedidos[i][j][PEDIDOS_POS::CANT];
            }else report<<right<<setw(10)<<"SIN STOCK";
            report<<endl;
        }
    }
}
//Funciones Auxiliares
void comprimirPedidos(char*** bufferCodigoPedidos,
                      int*** bufferDniCantPedidos){
//Iteramos hasta ya no tener datos
    for (int i = 0; bufferCodigoPedidos[i]; i++){
        //Contamos el numero de codigos en la fecha
        int cantDatos = contador(bufferDniCantPedidos[i]);
        // Aperturamos espacio
        int **auxDnis = new int*[cantDatos+1]{};
        char **auxCodigo = new char*[cantDatos+1]{};
        int **dniCantPedido = bufferDniCantPedidos[i];
        char **codigoPedido = bufferCodigoPedidos[i];
        for (int j = 0; j < cantDatos; j++){
            //Creamos Espacio para dni y cant
            auxDnis[j] = new int[2]; 
            //Copiamos los datos 
            auxDnis[j][PEDIDOS_POS::DNI] = dniCantPedido[j][PEDIDOS_POS::DNI];
            auxDnis[j][PEDIDOS_POS::CANT] = dniCantPedido[j][PEDIDOS_POS::CANT];
            //Borramos el espacio
            delete[] dniCantPedido[j];
            //Creamos Espacio para el codigo
            auxCodigo[j] = new char[strlen(codigoPedido[j])+1];
            strcpy(auxCodigo[j],codigoPedido[j]);
            //Borramos el espacio
            delete[] codigoPedido[j];
        }
        //Borramos los buffer
        delete[] codigoPedido;
        delete[] dniCantPedido;
        bufferCodigoPedidos[i] = auxCodigo;
        bufferDniCantPedidos[i] = auxDnis;
    }
}
void ingresarPedido(char* codigo,int dni,int cant,int fecha,
                     char*** bufferCodigoPedidos,
                     int*** bufferDniCantPedidos,
                     int* bufferFechaPedidos,int& numDatos){
    //Datos
    int posFecha = buscar(bufferFechaPedidos,fecha);
    if(posFecha==NO_ENCONTRADO){
        //Asignamos espacio para los pedidos del dia 
        bufferCodigoPedidos[numDatos] = new char*[MAX::PEDIDOS]{};
        bufferDniCantPedidos[numDatos] = new int*[MAX::PEDIDOS]{};
        bufferFechaPedidos[numDatos] = fecha;
        ingresarPedido(bufferCodigoPedidos[numDatos],
                        bufferDniCantPedidos[numDatos],codigo,
                        dni,cant);
        numDatos++;
    }else ingresarPedido(bufferCodigoPedidos[posFecha],
                       bufferDniCantPedidos[posFecha],codigo,
                        dni,cant);
}
void ingresarPedido(char** bufferCodigoPedidos,
                    int** bufferDniCantPedidos,char* codigo,
                    int dni,int cant){
    //Datos
    int cantDatos = contador(bufferDniCantPedidos);
    //Copiamos el codigo
    bufferCodigoPedidos[cantDatos] = new char[strlen(codigo)+1];
    strcpy(bufferCodigoPedidos[cantDatos],codigo);
    delete[] codigo;
    //Copiamos el dni y la cantidad
    bufferDniCantPedidos[cantDatos] = new int[2];
    bufferDniCantPedidos[cantDatos][PEDIDOS_POS::DNI] = dni;
    bufferDniCantPedidos[cantDatos][PEDIDOS_POS::CANT] = cant;
}
int contador(int** bufferDniCantPedidos){
    //Datos
    int num = 0;
    while(bufferDniCantPedidos[num]!=nullptr)num++;
    return num;
}
char* lecturaExacta(ifstream& arch,char deli){
    //Datos
    char buffer[500],*ptr;
    if(arch.eof())return nullptr;
    arch.getline(buffer,500,deli);
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}

ifstream aperturaArch(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(!arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    return arch;
}
ofstream aperturaReport(const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if(!arch.is_open()){
        cout<<"ERROR: No se pudo abrir "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2); arch<<fixed;
    return arch;
}
void encabezadoProductos(ofstream& report){
    report<<setw(40)<<"REPORTE DE PRODUCTOS"<<endl;
    linea(report,MAX::LINEA1,'=');
    report<<left<<setw(10)<<"CODIGO"
          <<left<<setw(64)<<"NOMBRE"
          <<left<<setw(12)<<"PRECIO"
          <<left<<setw(10)<<"STOCK"<<endl;
    linea(report,MAX::LINEA1,'-');
}
void encabezadoPedidos(ofstream& report){
    report<<setw(40)<<"REPORTE DE PEDIDOS"<<endl;
    linea(report,MAX::LINEA2,'=');
}
void encabezadoPedidos(ofstream& report,int fecha){
    report<<"FECHA: "<<fecha<<endl;
        linea(report,MAX::LINEA2,'-');
        report<<left<<setw(3)<<" "<<setw(4)<<"No."<<setw(14)<<"CODIGO"
              <<setw(10)<<"DNI"
              <<setw(10)<<"CANT"<<endl;
        linea(report,MAX::LINEA2,'-');
}
void encabezado(ofstream& report,int fecha){
    report<<"FECHA: "<<fecha<<endl;
        linea(report,MAX::LINEA1,'-');
        report<<left<<setw(4)<<"No."<<setw(30)<<"DNI"
              <<setw(52)<<"Producto"
              <<setw(10)<<"Cantidad"
              <<setw(10)<<"Precio"
              <<setw(10)<<"Total de ingresos"<<endl;
        linea(report,MAX::LINEA1,'-');

}

void encabezadoReporte(ofstream& report){
    report<<setw(60)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    linea(report,MAX::LINEA1,'=');
}
void linea(ofstream& report,int n,char c){
    for (int i = 0; i < n; i++)report<<c;
    report<<endl;
}
int buscar(int* bufferFechaPedidos,int fecha){
    for (int i = 0;bufferFechaPedidos[i] ; i++)
        if(bufferFechaPedidos[i]==fecha)return i;
    return NO_ENCONTRADO;
}
int buscar(char* codigo,char*** productos){
    int i = 0;
    while(strcmp(codigo,productos[i][PRODUCTOS_POS::CODIGO])!=0)i++;
    return i;
}
