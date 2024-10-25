//Author: MAKO
#include "header/cafeteria.h"

int main(){
    //Datos
    void *inventario, *menu;
    //Funciones
    // cargarInventario("docs/inventario.csv",inventario);
    // probarCargaInventario("docs/prueba-inventario.txt",inventario);
    cargarMenu("docs/menu.csv",menu);
    // pruebaCargaMenu("docs/menu-inicial.txt",menu);
    // actualizarMenu("docs/insumos-bebidas.csv",inventario,menu);
    // reporteMenu("docs/menu.txt",menu);
    // void** productoss = (void**)menu;
    // void** infoProducto;
    // for (int i = 0;productoss[i]; i++){
    //     infoProducto = (void**)productoss[i];
    //     cout<<left<<setw(10)<<(char*)infoProducto[INVENTARIO::CODE]
    //           <<setw(20)<<(char*)infoProducto[INVENTARIO::NAME]<<endl;
    // }
    return 0;
}
