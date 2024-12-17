import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Cafeteria {
    //Datos
    private Inventario inventario;
    private Menu menu;
    private Scanner archivo;
    //Funciones
    public Cafeteria(){
        inventario = new Inventario();
        menu = new Menu();
        archivo = new Scanner(System.in);
    }
    public Cafeteria(String nombreArchivo) throws FileNotFoundException{
        inventario = new Inventario();
        menu = new Menu();
        archivo = new Scanner(new File(nombreArchivo));
    }
    
    public void cargarInventario(){
        inventario.cargarInsumos(archivo);
    }

    public void cargarMenu(){
        menu.cargarBebidas(archivo);
    }

    public void reporteMenu(){
        
    }
}
