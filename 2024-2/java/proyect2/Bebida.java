import java.util.Scanner;

public class Bebida extends Producto{
    private String descripcion;
    private char tipo;
    private double precio;
    private int cantVent;
    private boolean disponible; 

    public String getDescripcion(){
        return descripcion;
    }
    
    public char getTipo(){
        return tipo;
    }
    
    public double getPrecio(){
        return precio;
    }
    
    public int getCantVent(){
        return cantVent;
    }
    
    public boolean getDisponible(){
        return disponible;
    }

    public void setDescripcion(final String descripcion){
        this.descripcion = descripcion;
    }
    
    public void setTipo(final char tipo){
        this.tipo = tipo;
    }
    
    public void setPrecio(final double precio){
        this.precio =  precio;
    }
    
    public void setCantVent(final int cantVent){
        this.cantVent = cantVent;
    }
    
    public void setDisponible(final boolean disponible){
        this.disponible = disponible;
    }

    @Override
    public boolean cargar(Scanner scanner){
        if(super.cargar(scanner)){
            descripcion = scanner.next();
            tipo = scanner.next().charAt(0);
            if(scanner.hasNextDouble())
                precio = scanner.nextDouble();
            else System.out.println(this.getNombre());
            cantVent = scanner.nextInt();
            return true;
        }
        return false;
    }
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Descripcion : " + descripcion);
        System.out.println("Tipo : " + tipo);
        System.out.println("Precio : " + precio);
        System.out.println("Cantidad Vendidad : " + cantVent);
    }
}