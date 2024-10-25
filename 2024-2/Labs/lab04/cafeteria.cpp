//Author: MAKO
#include "header/cafeteria.h"

//Funciones MAIN
void cargarInventario(const char* nomInventario,void*& inventario){
    ifstream arch;
    aperturaLeer(arch,nomInventario);
    //Datos
    void** bufferInventario = new void*[MAX_INVENTARIO]{};
    void* producto;
    int cantDatos = 0;
    //Proceso
    while(lecturaInventario(producto,arch)){
        bufferInventario[cantDatos] = producto;
        cantDatos++;
    }
    inventario = new void*[cantDatos+1]{};
    void** productos = (void**)inventario;
    for (int i = 0; i<cantDatos; i++)
        productos[i] = bufferInventario[i];
    //Liberamos memoria
    delete[] bufferInventario;
}
void cargarMenu(const char* nomMenu,void*& menu){
    ifstream arch;
    aperturaLeer(arch,nomMenu);
    // //Datos
    void** bufferMenu = new void*[MAX_MENU]{};
    void* producto;
    int cantDato = 0;
    while(lecturaMenu(producto,arch)){
        // bufferMenu[cantDato] = producto;
        // cantDato++;
    }
    // menu = new void*[cantDato+1]{};
    // void** productos = (void**)menu;
    // for (int i = 0; i < cantDato; i++){
    //     productos[i] = bufferMenu[i];
    // }
    // //Liberamos memoria
    // delete[] bufferMenu;
}
void actualizarMenu(const char* nomInsumos_bebidas,
                    void*& inventario,void*& menu){

}
void reporteMenu(const char* nomMenu,void*& menu){
    ofstream report;
    aperturaEscribir(report,nomMenu);
}

void probarCargaInventario(const char* nomPrueba,void* inventario){
    //Datos
    ofstream report;
    aperturaEscribir(report,nomPrueba);
    void** productos = (void**)inventario;
    void** infoProducto;
    for (int i = 0;productos[i]; i++){
        infoProducto = (void**)productos[i];
        report<<left<<setw(10)<<(char*)infoProducto[INVENTARIO::CODE]
              <<setw(20)<<(char*)infoProducto[INVENTARIO::NAME]
              <<right<<setw(10)<<*(int*)infoProducto[INVENTARIO::CANT_DIS]
              <<setw(10)<<*(int*)infoProducto[INVENTARIO::CANT_REQ]
              <<left<<setw(10)<<(char*)infoProducto[INVENTARIO::UNIDAD]<<endl;
    }   
}

//Lecturas
bool lecturaInventario(void*& producto,ifstream& arch){
    //Datos
    char *code,*name,*unidad,c;
    int  *cantDis = new int;
    int  *cantReq = new int;
    //Lectura
    code = lecturaExacta(arch,',');
    if(code == nullptr)return false;
    name = lecturaExacta(arch,',');
    arch>>*cantDis>>c; *cantReq = 0;
    unidad = lecturaExacta(arch,'\n');
    //Ingreso de la informarion
    producto = new void*[5];
    if (!producto) {
        cerr << "Error: no se pudo asignar memoria para el producto." << endl;
        return false;
    }
    void** infoProducto = (void**)producto;
    if (!infoProducto) {
        cerr << "Error: no se pudo asignar memoria para el producto." << endl;
        return false;
    }
    infoProducto[INVENTARIO::CODE] = code;
    infoProducto[INVENTARIO::NAME] = name;
    infoProducto[INVENTARIO::CANT_DIS] = cantDis;
    infoProducto[INVENTARIO::CANT_REQ] = cantReq;
    infoProducto[INVENTARIO::UNIDAD] = unidad;
    return true;
}
bool lecturaMenu(void*& producto,ifstream& arch){
    //Datos 
    char *code, *name, *description, *tipo,c;
    int *cantVentas = new int;
    double *precio = new double;
    bool *disponible = new bool;
    //Lectura
    code = lecturaExacta(arch,',');
    if(code == nullptr)return false;
    name = lecturaExacta(arch,',');
    description = lecturaExacta(arch,',');
    arch>>*tipo>>c>>*precio>>c>>*cantVentas;
    arch.get();
    //Ingresamos la info
    producto = new void*[7];
    if (!producto) {
        cerr << "Error: no se pudo asignar memoria para el producto." << endl;
        return false;
    }
    void** infoProducto = (void**)producto;
    if (!infoProducto) {
        cerr << "Error: no se pudo asignar memoria para el producto." << endl;
        return false;
    }
    // infoProducto[MENU::CODIGO] = code;
    // infoProducto[MENU::NOMBRE] = name;
    // infoProducto[MENU::DESCRIPCION] = description;
    // infoProducto[MENU::TIPO] = tipo;
    // infoProducto[MENU::DISPONIBLE] = disponible;
    // infoProducto[MENU::CANT_VENT] = cantVentas;
    return true;
}
//Ingresos

//Liberar Memoria


//Funciones Auxiliares
char* lecturaExacta(ifstream& arch,char delimitador){
    //Datos
    char buffer[200],*ptr;
    arch.getline(buffer,200,delimitador);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
