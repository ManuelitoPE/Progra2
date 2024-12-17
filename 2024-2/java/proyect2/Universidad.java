import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Universidad {
    //Datos
    private List<Alumno> alumnos;
    //Constructor
    public Universidad(){
        alumnos = new ArrayList<>();
    }
    //Funciones
    public void cargarAlumnos(String nombreArchivo)throws Exception{
        File archivo = new File(nombreArchivo);
        cargarAlumnos(archivo);
    }
    public void cargarAlumnos(File archivo)throws Exception{
        Scanner scanner = new Scanner(archivo);
        scanner.useDelimiter("[,|\\s]");
        while (scanner.hasNext()) {
            char tipo = scanner.next().charAt(0);
            Alumno alumno; //Como puntero
            if(tipo == 'I') alumno = new AlumnoIntercambio(tipo); 
            else alumno = new AlumnoRegular(tipo);
            alumno.cargar(scanner);
            alumnos.add(alumno);
        }
    }
    public void imprimir(){
        for(Alumno alumno : alumnos){
            alumno.imprimir();
            System.out.println("-------------------------------------");
        }   
    }
}
