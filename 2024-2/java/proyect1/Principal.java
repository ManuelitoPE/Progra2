import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class Principal {

    public static void main(String[] args) throws Exception {
        Cafeteria cafeteria =  new Cafeteria("datos.txt");
        cafeteria.cargarInventario();
        cafeteria.cargarMenu();
        cafeteria.reporteMenu();
    }   
}