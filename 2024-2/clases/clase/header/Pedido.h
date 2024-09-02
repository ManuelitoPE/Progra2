#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido
{
private:
    int codigo;
    char* nombre;
    int cantidad;
    int dni;
    int fecha;
public:
    Pedido(/* args */);
    ~Pedido();
    
    void SetCodigo(int Codigo);
    int GetCodigo() const;
    
    void SetCantidad(int Cantidad);
    int GetCantidad() const;
    
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
       
    void SetDni(int categoria);
    int GetDni() const;
    
    void SetFecha(int fecha);
    int GetFecha() const;
};

Pedido::Pedido(/* args */)
{
}

Pedido::~Pedido()
{
}



#endif