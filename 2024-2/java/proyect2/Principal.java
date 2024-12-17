public class Principal {
    public static void main(String[] args) throws Exception{
        CafeteriaUniversitaria  cafeteria = new CafeteriaUniversitaria("datos.txt");
        cafeteria.cargarMenu();
        cafeteria.cargarPedidos();
        cafeteria.imprimirReporte();
    }
    
}