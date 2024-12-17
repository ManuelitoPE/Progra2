import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Menu {
    List<Producto> productos;
    Scanner scanner;
    public Menu(Scanner archivo){
        productos = new ArrayList<>();
        scanner = archivo;
    } 
    public void cargarProductos(){
        Producto producto;
        String c;
        while(scanner.hasNext()){
            c = scanner.next();
            if(c.equals("FIN"))break;
            if(c.equals("I"))producto = new Platos();
            else producto = new Bebida();
            producto.cargar(scanner);
            producto.imprimir();
        }
    }
}
