import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CafeteriaUniversitaria {
    //Atributos 
    private Menu menu;
    private List<Alumno> clientes;
    private Scanner scanner;
    //Constructor
    public CafeteriaUniversitaria(String archivo) throws FileNotFoundException{
        clientes = new ArrayList<>();
        scanner = new Scanner(new File(archivo));
        menu = new Menu(scanner);
        
    }
    //Funciones
    public void cargarMenu(){
        //Cargamos el menu
        scanner.useDelimiter("[\\s]");
        //Cargamos
        menu.cargarProductos();
    }

    public void cargarPedidos(){

    }

    public void imprimirReporte(){

    }

}
