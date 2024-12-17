import java.util.Scanner;

abstract class Producto {
    //Datos 
    private String codigo;
    private String nombre;  
    
    public String getCodigo(){
        return codigo;
    }
    
    public String getNombre(){
        return nombre;
    }
    
    public void setCodigo(final String codigo){
        this.codigo = codigo;
    }
    
    public void setNombre(final String nombre){
        this.nombre = nombre;
    }

    public boolean cargar(Scanner scanner){
        codigo = scanner.next();
        nombre = scanner.next();
        return true;
    }
    public void imprimir(){
        System.out.println("Codigo: " + codigo);
        System.out.println("Nombre: " + nombre);
    }
}
