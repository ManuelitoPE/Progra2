import java.util.Scanner;

public class Platos extends Producto{
    private int cantDisponible;
    private String unidadMedida;

    public int getCantDisponible(){
        return cantDisponible;
    }

    public String getUnidadMedida(){
        return unidadMedida;
    }

    public void setCantDisponible(final int cantDisponible){
        this.cantDisponible = cantDisponible;
    }

    public void getUnidadMedida(final String unidadMedida){
        this.unidadMedida = unidadMedida;
    }
    @Override
    public boolean cargar(Scanner scanner){
        if(super.cargar(scanner)){
            cantDisponible = scanner.nextInt();
            unidadMedida = scanner.next();
            return true;
        }
        return false;
    }

    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Cantidad Disponible : " + cantDisponible);
        System.out.println("Unidad de Medida: " + unidadMedida);
    }
}
