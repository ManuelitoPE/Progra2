//Author: MAKO
#include "funciones.h"
#define NO_ENCONTRADO -1
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
bool operator>>(ifstream& arch,Pedido& pedido){
    if(!arch.eof()){
        pedido.codigo = lecturaExacta(arch,',');
        arch>>pedido.dni; arch.ignore();
        return true;
    }
    pedido.dni = 0;
    return false;
} 
//Impresion 
ofstream& operator<<(ofstream& os,const Cliente* cliente){
    os<<left<<setw(10)<<cliente->dni
      <<setw(50)<<cliente->nombre
      <<right<<setw(10)<<cliente->telefono
      <<right<<setw(10)<<cliente->montoTotal
      <<setw(25)<<"Productos Entregados:";
    if(cliente->cantidadProductosEntregados>0){
        for (int i = 0; i < cliente->cantidadProductosEntregados; i++){
            os<<left<<setw(10)<<cliente->productosEntregados[i].codigo;
        }
        os<<endl;
    } else os<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
    return os;
}
ofstream& operator<<(ofstream& os,const Producto* producto){
    os<<left<<setw(10)<<producto->codigo
      <<setw(50)<<producto->descripcion
      <<right<<setw(10)<<producto->precio
      <<right<<setw(10)<<producto->stock
      <<endl<<left<<setw(25)<<"Clientes atendidos: ";
    if(producto->cantidadClientesServidos>0){
        for (int i = 0; i < producto->cantidadClientesServidos; i++){
            os<<left<<setw(10)<<producto->clientesServidos[i];
        }
        os<<endl;
    } else os<<"NO SE ATENDIERON PEDIDOS"<<endl;
    os<<left<<setw(25)<<"Clientes no atendidos: ";
    if(producto->cantidadClientesNoServidos>0){
        for (int i = 0; i < producto->cantidadClientesNoServidos; i++){
            os<<left<<setw(10)<<producto->clientesNoServidos[i];
        }
        os<<endl;
    } else os<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    return os;
}
ofstream& operator<<(ofstream& os,const Pedido* pedido){
    os<<left<<setw(10)<<pedido->codigo
      <<right<<setw(10)<<pedido->dni
      <<endl;
    return os;
}
//Agregacion
void operator+=(Cliente* cliente,const Pedido& pedido){
    int posCliente = buscar(cliente,pedido.dni);
    if(posCliente!=NO_ENCONTRADO){
        //Guardamos la posicion de lacantidad de productos entregados 
        int cant = cliente[posCliente].cantidadProductosEntregados;
        cliente[posCliente].productosEntregados[cant].codigo = new char[strlen(pedido.codigo)+1];
        strcpy(cliente[posCliente].productosEntregados[cant].codigo,pedido.codigo);
        cliente[posCliente].productosEntregados->precio = pedido.precioProducto;
        cliente[posCliente].cantidadProductosEntregados++;
    }
}
bool operator+=(Producto* producto,Pedido& pedido){
    int posProducto = buscar(producto,pedido.codigo);
    if(posProducto!=NO_ENCONTRADO){
        //Guardamos la posicion de la cantidad de productos entregados
        if(producto[posProducto].stock-1>=0){
            ingresarCliente(producto[posProducto].clientesServidos,
                            producto[posProducto].cantidadClientesServidos,
                            producto[posProducto].precio,pedido);
            producto[posProducto].stock-=1;
            return true;
        }else 
            ingresarCliente(producto[posProducto].clientesNoServidos,
              producto[posProducto].cantidadClientesNoServidos,
              producto[posProducto].precio,pedido);
            return false;
    }
    return false;
}
//Auxiliares 
char* lecturaExacta(ifstream& arch,char deli){
    //DATOS
    char buffer[150],*ptr;
    arch.getline(buffer,150,deli);
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr; 
}

int buscar(Cliente* cliente,int dni){
    for (int i = 0; cliente[i].dni; i++)
        if(cliente[i].dni==dni)return i;
    return NO_ENCONTRADO;
}
int buscar(Producto* producto,char* codigo){
    for (int i = 0; producto[i].precio; i++)
        if(strcmp(producto[i].codigo,codigo)==0)return i;
    return NO_ENCONTRADO;
}   
void ingresarCliente(int* clientesServidos,int& cant,double precio,
                     Pedido& pedido){
    clientesServidos[cant] = pedido.dni;
    pedido.precioProducto = precio;
    cant++;
}