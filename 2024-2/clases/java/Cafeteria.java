import java.io.FileNotFoundException;
import java.io.File;

public class Cafeteria {
    private Inventario inventario;
    private Menu menu;

    public Cafeteria(){
        inventario = new Inventario();
        menu =  new Menu();
    }
    public void cargarInventario(final String nombreArchivo) throws FileNotFoundException{
            File archivo = new File(nombreArchivo);
            inventario.cargarInsumos(archivo);
    }
}