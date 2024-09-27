#include "funciones.h"

//funciones secundarias
void leerArchivo(ifstream & archivo, const char* nomArch){
    archivo.open(nomArch, ios::in);
    if(not archivo.is_open()){
        cout<<"no se pudo abrir "<<nomArch;
        exit(1);
    }
}
void escribirArchivo(ofstream & archivo, const char* nomArch){
    archivo.open(nomArch, ios::out);
    if(not archivo.is_open()){
        cout<<"no se pudo abrir "<<nomArch;
        exit(1);
    }
}
char *leerCadena(ifstream &archivo, char limite){
    char *cadena, cadena2[100]{};
    archivo.getline(cadena2, 100, limite);
    
    cadena = new char[strlen(cadena2) + 1]{};
    strcpy(cadena, cadena2);
    return cadena;
}
int buscarCliente(const void *clientes, int *dni){
    void** listaClientes = (void**)clientes;
    for(int i=0; listaClientes[i]; i++){
        void** regCliente = (void**)listaClientes[i];
        if(*(int *)regCliente[0] == *dni){
            return i;
        }
    }
    return -1;
}
int hallarProducto(void *productos, char *codProdPed){
    void** listaProd = (void**)productos;
    for(int i=0; listaProd[i]; i++){
        void** regProd = (void**)listaProd[i];
        if(strcmp((char *)regProd[0], codProdPed) == 0){
            return i;
            
        }
    }
    return -1;
}
void agregar_a_lista_de_pedidos(void *&listadoPedidos, int *cantidad, char *codProdPed, double * monto){
    
    //crear reg pedido
    void**regPedidos = new void*[3]{};
    regPedidos[0] = codProdPed;
    regPedidos[1] = cantidad;
    regPedidos[2] = monto;
    
    //si lista está vacia
    if(listadoPedidos == nullptr){
        listadoPedidos = new void*[20]{};
        
    }
    
    //hallo la posición en donde quiero poner mi registro
    int nDatos = hallarCantidadDatos(listadoPedidos);
    void** lista = (void**)listadoPedidos;
    lista[nDatos] = regPedidos;
    
}
int  hallarCantidadDatos(void *listadoPedidos){
    void** lista = (void**)listadoPedidos;
    int contador = 0;
    for(int i=0; lista[i]; i++){
        contador++;
    }
    return contador;
}
void escribirCliente(ofstream &archivo, void *cliente){
    void** regCliente = (void**)cliente;
    escribirLinea(archivo, 100, '=');
    archivo<<left<<setw(20)<<"DNI"<<setw(43)<<"Nombre"<<setw(20)<<"Credito"<<endl;
    archivo<<right<<setw(8)<<(int *)regCliente[0]<<setw(12)<<" "<<left<<setw(40)<<(char *)regCliente[1]<<right<<setw(10)<<(double *)regCliente[3]<<endl;
    escribirLinea(archivo, 100, '-');
    archivo<<left<<setw(25)<<"Pedidos atendido:"<<endl;
    escribirLinea(archivo, 100, '-');
    archivo<<left<<setw(5)<<" "<<setw(15)<<"Codigo"<<setw(10)<<"Cantidad"<<setw(10)<<"Total"<<endl;
    escribirLinea(archivo, 100, '-');
    void** listaPedidos = (void**)regCliente[2];
//    for(int i=0; listaPedidos[i]; i++){
////        escribirPedido_Cliente(archivo, listaPedidos[i]);
//    }
}
void escribirPedido_Cliente(ofstream &archivo, void *pedido){
    void** regPedido = (void**)pedido;
//    archivo<<left<<setw(5)<<" "<<setw(12)<<(char*)regPedido[0]<<right<<setw(3)<<(int *)regPedido[1]<<setw(12)<<(double *)regPedido[2]<<endl;
    
}

void escribirLinea(ofstream &archivo, int largo, char limite){
    for(int i=0; i<largo; i++){
        archivo<<limite;
    }
    archivo<<endl;
}
//funciones principales
void cargaproductos(void *&productos){
    ifstream archProd;
    leerArchivo(archProd, "docs/Productos2.csv");
    
    //se crean los valores buff
    void *arrProdutosBuff[200]{}, **arrProductosExacto;
    int nProd =0 ;
    while(leerUnProd(arrProdutosBuff[nProd], archProd)){
        nProd++;
    }
    //cargar void exacto
    arrProductosExacto = new void *[nProd + 1]{};
    for(int i=0; i<nProd; i++){
        arrProductosExacto[i] = arrProdutosBuff[i];
    }
    arrProductosExacto[nProd] = nullptr;
    productos = arrProductosExacto;
}
bool leerUnProd(void *&arrProdutosBuff, ifstream &archProd){
    //se usará el arrprobuff como un void ** así que se castea
    
    //declarar variales en punteros
    char *codigo, *descripcion, *tipoLinea;
    double *precio;
    
    codigo = leerCadena(archProd, ',');
    
    if(archProd.eof())return false;
    descripcion = leerCadena(archProd, ',');
    //leer un double en puntero
    precio = new double;
    archProd>>*precio;
    archProd.get();
    //leer un caracter en puntero
    tipoLinea = new char;
    *tipoLinea = archProd.get();
    archProd.get();
    //llenar registro de un producto
    void **registro;
    registro = new void*[5]{};
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = tipoLinea;

    arrProdutosBuff = registro;
    
    return true;
}
void cargaclientes(void  *&clientes){
    //abrir archivo
    ifstream archClientes;
    leerArchivo(archClientes, "docs/Clientes2.csv");
    
    //declaro los buff
    void *arrClientesBuff[150]{}, **arrClientesExacto;
    int nClientes=0;
    while(leerUnCliente(arrClientesBuff[nClientes], archClientes))nClientes++;
    
    arrClientesExacto = new void*[nClientes + 1]{};
    for(int i=0; arrClientesBuff[i];i++){
        arrClientesExacto[i] = arrClientesBuff[i];
    }
    
    clientes = arrClientesExacto;
    
    
}
bool leerUnCliente(void *&arrClientesBuff, ifstream & archClientes){
    
    //declarar variables
    int *dni,  *telefono;
    double *lineaCred;
    char *nombre;
    dni = new int;
    archClientes>>*dni;
    if(archClientes.eof())return false;
    archClientes.get();
    nombre = leerCadena(archClientes, ',');
    telefono = new int;
    archClientes>>*telefono;
    archClientes.get();
    lineaCred = new double;
    archClientes>>*lineaCred;
    archClientes.get();
    
    //cargar valores
    void **regCliente;
    regCliente = new void*[5]{};
    regCliente[0] = dni;
    regCliente[1] = nombre;
    regCliente[2] = nullptr;
    regCliente[3] = lineaCred;
    
    arrClientesBuff = regCliente;
    return true;
}

void cargapedidos(void *productos, void *&clientes){
    //abrir archivo
    ifstream archPed;
    leerArchivo(archPed, "docs/Pedidos2.csv");
    
    
    int i=0;
    while(true){
        if(not leerUnPedido(productos, clientes, archPed))break;
        
        
        i++;
    }
        //imprimo de uevo
        void **listado = (void**)clientes;
        for(int i=0; listado[i]; i++){
            void** registro = (void**)listado[i];
            if(registro[2]==nullptr)continue;            void** producto = (void**)registro[2];

            cout<<(char*)registro[1]<<endl;
            for (int k = 0; producto[k]; k++){
                void** info = (void**)producto[k];
                cout<<(char*)info[0]<<endl;
            }
        }
    
    
}
bool leerUnPedido(void *productos, void  *&clientes, ifstream &archPed){
    //crear variables
    //JXD-139,50375303,6
    char *codProdPed;
    int *dni, *cantidad;
    void** listaClientes = (void**)clientes;
    
    codProdPed = leerCadena(archPed, ',');
    if(archPed.eof())return false;
    dni = new int;
    archPed>>*dni;
    archPed.get();
    cantidad = new int;
    archPed>>*cantidad;
    archPed.get();
    
    
          
            
    int posCliente = buscarCliente(clientes, dni);
    if(posCliente!=-1)
        lenarClienteConPedido(listaClientes[posCliente], productos, dni, cantidad, codProdPed);
    // return false;       
    return true;
}
void lenarClienteConPedido(void *&cliente, void *productos, int *dni, int *cantidad, char *codProdPed){
    //llamar datos clientes
    void **regCliente = (void **)cliente;
    double credito = *(double *)regCliente[3];
    void** listadoPedidos =  (void**)regCliente[2];
    
    //llamar datos prod
    int posProd = hallarProducto(productos, codProdPed);
    void **listaProd = (void **)productos;
    void** regProd = (void **)listaProd[posProd];
    double precioProd = *(double *)regProd[2];
    char tipoCred = *(char *)regProd[3];
    // cout<<(char*)regProd[0]<<endl;
    //calcular monto de pedido
    int cant = *cantidad;
    double monto = precioProd*(double)cant;
    double * monto2;
    monto2 = new double;
    monto2 = &monto;
    //si requiere linea de credito es s
    if(tipoCred == 'S'){
        if(credito >= monto){
            //si se tiene credito entonces se llena la lista del cliente
            agregar_a_lista_de_pedidos(regCliente[2], cantidad, codProdPed, monto2);
            credito = credito - monto;
        }
    } else {
        //si no requiere se llena la lista con prod
        agregar_a_lista_de_pedidos(regCliente[2], cantidad, codProdPed, monto2);
        
    }
    
    regCliente[3] = insertar_double(credito);
}
double *insertar_double(double lineaCredito){
    double *valor;
    valor = new double;
    *valor = lineaCredito;
    return valor;
}
void imprimereporte(void *clientes){
    //abrir archivo
    ofstream archReporte; 
    escribirArchivo(archReporte, "ReporteDePedidos.txt");
    
    //iterar lista de clientes
    void** listadoClientes = (void **)clientes;
    for(int i=0; listadoClientes[i]; i++){
        escribirCliente(archReporte, listadoClientes[i]);
    }
}