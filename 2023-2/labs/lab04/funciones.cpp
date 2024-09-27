#include "header/funciones.h"

//Funciones Main
void cargaproductos(void*& productos){
    ifstream arch; 
    aperturaArchLectura(arch,"docs/Productos2.csv");
    //Datos
    void** bufferProductos =  new void*[MAX];
    char *codigoProducto,*descripcion,*tipoDeProducto;
    double* precio;
    int cantDatos = 0;
    while(lectura(codigoProducto,descripcion,tipoDeProducto,
                 precio,arch)){
        ingresoDeProducto(bufferProductos[cantDatos],codigoProducto,
                          descripcion,tipoDeProducto,precio);
        cantDatos++;
    }

    productos = new void*[cantDatos+1]{};
    void** producto = (void**)productos;

    for (int i = 0; i < cantDatos; i++)
        producto[i] = bufferProductos[i];     

    imprimeproductos(productos);
}
void cargaclientes(void*& clientes){
    ifstream arch;
    aperturaArchLectura(arch,"docs/Clientes2.csv");
    //Datos
    void** bufferClientes =  new void*[MAX];
    char* nombre;
    int* dni, cantDatos = 0;
    double* lineCredito;
    while(lectura(arch,dni,nombre,lineCredito)){
        ingresoCliente(bufferClientes[cantDatos],nombre,dni,
                       lineCredito);
        cantDatos++;
    }
    clientes = new void*[cantDatos+1]{};
    void** cliente = (void**)clientes;

    for (int i = 0; i < cantDatos; i++)
        cliente[i] = bufferClientes[i];

    imprimeclientes(clientes);    
    
}
void cargapedidos(void*& productos,void*& clientes){
    ifstream arch;
    aperturaArchLectura(arch,"docs/Pedidos2.csv");
    //Datos
    char* codigo;
    int dni, cant,posCliente,posProducto;
    while(lectura(arch,codigo,dni,cant)){
        posCliente = buscar(clientes,dni);
        posProducto = buscar(productos,codigo);
        if(posCliente!=NO_ENCONTRADO and posProducto!=NO_ENCONTRADO){
            //Se ingresa el producto a la lista
            void** cliente = (void**)clientes;
            void**infoCliente = (void**)cliente[posCliente];
            void** producto = (void**)productos;
            void**infoProducto = (void**)producto[posProducto];
            //Si es la primera vez
            if(infoCliente[CLIENTE::LISTA]==nullptr) infoCliente[CLIENTE::LISTA] = new void*[MAX]{};
            //
            if(*(char*)infoProducto[PRODUCTOS::TIPO]!='S') ingresarPedido(infoCliente[CLIENTE::LISTA],infoProducto,cant);
            else if( (*(double*)infoProducto[PRODUCTOS::PRECIO]*cant) < *(double*)infoCliente[CLIENTE::LINEA_CREDITO]){

                *(double*)infoCliente[CLIENTE::LINEA_CREDITO] -= *(double*)infoProducto[PRODUCTOS::PRECIO]*cant;
                ingresarPedido(infoCliente[CLIENTE::LISTA],infoProducto,cant);

            }
        }
        delete codigo;
    }
    comprimirClientes(clientes);
    imprimerepfinal(clientes);
}
void imprimereporte(void*& clientes){

}




//Funciones Auxliares
void imprimeProducto(void* productos){
    ofstream report;
    aperturaArchEscritura(report,"docs/ReporteProductos.txt");
    encabezadoProducto(report);
    //Datos AUX
    void** producto = (void**)productos;
    void**infoProducto = (void**)producto[0];

    for (int i = 0;producto[i]; i++){
        infoProducto = (void**)producto[i];
        report<<left<<setw(10)<<(char*)infoProducto[PRODUCTOS::CODE]
          <<left<<setw(70)<<(char*)infoProducto[PRODUCTOS::DESCRIPCION]
          <<right<<setw(10)<<*(double*)infoProducto[PRODUCTOS::PRECIO]
          <<setw(10)<<(char*)infoProducto[PRODUCTOS::TIPO]<<endl;
    }
}
//Busquedas
int buscar(void* clientes,int dni){
    void** cliente = (void**)clientes;
    for (int i = 0; cliente[i]; i++){
        void** infoCliente = (void**)cliente[i];
        if(*(int*)infoCliente[CLIENTE::DNI]==dni)return i;
    }
    return NO_ENCONTRADO;
}
int buscar(void* productos,char* codigo){
    void** producto = (void**)productos;
    for (int i = 0; producto[i]; i++){
        void** infoProducto = (void**)producto[i];
        if(strcmp((char*)infoProducto[PRODUCTOS::CODE],codigo)==0)return i;
    }
    return NO_ENCONTRADO;
}
//Lecturas 
bool lectura(char*& codigoProducto,char*& descripcion,
             char*& tipoDeProducto,double*& precio,ifstream& arch){
    precio = new double;
    codigoProducto = lecturaExacta(arch,',');
    if(codigoProducto==nullptr)return false;
    descripcion = lecturaExacta(arch,',');
    arch>>(*precio);
    arch.ignore();
    tipoDeProducto = lecturaExacta(arch,'\n');
    return true;
}
bool lectura(ifstream& arch,int*& dni,char*& nombre,double*& lineCredito){
    dni = new int; lineCredito = new double;
    arch>>*(dni);
    if(arch.eof())return false;
    arch.ignore();
    nombre = lecturaExacta(arch,',');
    arch>>*lineCredito; 
    arch.ignore();
    arch>>*lineCredito;
    return true;    
}
bool lectura(ifstream& arch,char*& codigo,int& dni,int& cant){
    codigo = lecturaExacta(arch,',');
    if(codigo==nullptr)return false;
    arch>>dni;
    arch.ignore();
    arch>>cant;
    arch.ignore();
    return true;
}
char* lecturaExacta(ifstream& arch,char deli){
    //Datos
    char buffer[200], *ptr;
    arch.getline(buffer,200,deli);
    if(arch.eof())return nullptr;
    ptr = new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
//Ingresos
void ingresoDeProducto(void*& producto,char* codigoProducto,
                       char* descripcion,char* tipoDeProducto,double* precio){
    producto = new void*[4];
    void** productoAux = (void**)producto;
    productoAux[PRODUCTOS::CODE] = codigoProducto;
    productoAux[PRODUCTOS::DESCRIPCION] = descripcion;
    productoAux[PRODUCTOS::PRECIO] = precio;
    productoAux[PRODUCTOS::TIPO] = tipoDeProducto;
}
void ingresoCliente(void*& cliente,char* nombre,int* dni,
                    double* lineCredito){
    cliente = new void*[4]{};
    void** infoCliente = (void**)cliente;
    infoCliente[CLIENTE::DNI] = dni;
    infoCliente[CLIENTE::NOMBRE] = nombre;
    infoCliente[CLIENTE::LINEA_CREDITO] = lineCredito;
}
void ingresarPedido(void*& lista,void**& infoProducto,
                    int cant){
    //DATOS
    int cantProductos = contador(lista);
    void** productos = (void**)lista;
    int* cantidad = new int;
    double* total = new double;
    *cantidad = cant;
    *total = cant * (*(double*)infoProducto[PRODUCTOS::PRECIO]);
    //Asignamos el espacio
    productos[cantProductos] = new void*[3];
    void** pedido = (void**)productos[cantProductos];
    pedido[PEDIDO::CODIGO] = infoProducto[PRODUCTOS::CODE];
    pedido[PEDIDO::CANTIDAD] = cantidad;
    pedido[PEDIDO::TOTAL] = total;
}
int contador(void* lista){
    //Datos
    if(lista==nullptr)return 0;
    void** productos = (void**)lista;
    int cont = 0;
    while(productos[cont])cont++;
    return cont;
}
void linea(ofstream& report,int n,char c){
    for(int i = 0; i < n; i++)report<<c;
    report<<endl;
}
void comprimirClientes(void*& clientes){
    // Entro a los clientes
    void** cliente = (void**)clientes;
    for (int i = 0; cliente[i]; i++){
        //La informacion de cada cleiente
        void** infoCliente = (void**)cliente[i];
        //Cuento la cantidad de productos de la lista de clientes 
        int cant = contador(infoCliente[CLIENTE::LISTA]);
        if(cant!=0){
            //Asigno el espacio exacto de los pedidos
            void** pedido = new void*[cant+1]{};
            void** productos = (void**)infoCliente[CLIENTE::LISTA];
            for (int k = 0; k < cant; k++){
                pedido[i] = productos[i];
            }
            // delete (void**)infoCliente[CLIENTE::LISTA];
            infoCliente[CLIENTE::LISTA] = (void**)pedido;

        }else delete (void**)infoCliente[CLIENTE::LISTA];
    } 
}

//Encabezados
void encabezadoProducto(ofstream& report){
    report<<setw(50)<<"LISTA DE PRODUCTOS"<<endl;
    linea(report,MAX_LINEA,'=');
    report<<left<<setw(10)<<"CODIGO"
          <<left<<setw(70)<<"DESCRIPCION"
          <<left<<setw(10)<<"PRECIO"
          <<left<<setw(20)<<"TIPO DE PRODUCTO"<<endl;
    linea(report,MAX_LINEA,'-');
}