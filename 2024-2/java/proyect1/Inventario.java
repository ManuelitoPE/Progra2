import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Inventario {
    private List<Insumo> insumos;

    public Inventario(){
        insumos = new ArrayList<>();
    }
    
    public void cargarInsumos(Scanner archivo){
        while(archivo.hasNext()){
            String codigo = archivo.next();
            if(codigo.equals("FIN")) break;
            Insumo insumo = new Insumo();
            insumo.setCodigo(codigo);
            insumo.setNombre(archivo.next());
            insumo.setCantidadDisponible(archivo.nextDouble());
            insumo.setUnidadMedida(archivo.next());
            insumos.add(insumo);
        }
    }
}