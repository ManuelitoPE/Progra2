import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Menu {
    private List<Bebida> bebidas;

    public Menu(){
        bebidas = new ArrayList<>();
    }

    public void cargarBebidas(Scanner archivo){
        while (archivo.hasNext()) {
            String codigo = archivo.next();
            if(codigo.equals("FIN"))break;
            Bebida bebida =  new Bebida();
            bebida.setCodigo(codigo);
            bebida.setNombre(archivo.next());
            bebida.setDescripcion(archivo.next());
            bebida.setTipo(archivo.next().charAt(0));
            bebida.setPrecio(archivo.nextDouble());
            bebida.setCantVent(archivo.nextInt());
            bebida.setDisponible(true);
            bebidas.add(bebida);
        }
    }
}
