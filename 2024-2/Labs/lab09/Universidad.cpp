//Author: MAKO

#include "header/Universidad.h"
// #include <iterator>
Universidad::Universidad(){
    alumnos = {};
    cursos =  {};
    inscripciones = {};
    matriculados = {};
}

Universidad::~Universidad(){
}

void Universidad::cargarAlumnos(){
    ifstream arch("docs/Alumnos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: Alumnos.csv"<<endl;
        exit(1);
    }
    //Datos
    AlumnoUniversitario alumno;
    while(alumno.leer(arch))
        alumnos.push_back(alumno);
    sort(alumnos.begin(),alumnos.end(),OrdenaAlumnoPorNombre());
}
void Universidad::imprimirAlumnos(){
    ofstream arch("docs/ReporteAlumnos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: Reporte Alumnos"<<endl;
        exit(1);
    }
    // Ejemplo con interadores
    for(vector<AlumnoUniversitario>::iterator it = alumnos.begin(); it != alumnos.end(); it++){
        it->imprimir(arch);
    }
        // cout<<*it;

    // for(AlumnoUniversitario alum : alumnos)
    //     alum.imprimir(arch);
}
void Universidad::cargarCursos(){
    ifstream arch("docs/Cursos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR:: Curso"<<endl;
        exit(1);
    }
    Curso curso;
    while(curso.leer(arch))
        cursos.push_back(curso);
}
void Universidad::imprimirCursos(){
    ofstream arch("docs/ReporteCursos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: Cursos Reporte"<<endl;
        exit(1);
    }
    for (vector<Curso>::iterator it = cursos.begin(); it != cursos.end(); it++){
        it->imprimir(arch);
    }
    
}
void Universidad::matricular(){
    ifstream arch("docs/Inscripciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: Inscripciones"<<endl;
        exit(1);
    }
    
    inscripcionesCursos(arch);

    for(vector<Curso>::iterator it = cursos.begin();it != cursos.end(); it++){
        //Nueva lista
        list<AlumnoUniversitario> listaAlumnos;
        //Saco la cola
        InscripcionesCurso inscripcionesCurso = inscripciones[*it];
        // Inserto los datos a la lista
        while(listaAlumnos.size() <= it->getCapacidades()){
            //Saco los alumnos de la cola
            AlumnoUniversitario alum = inscripcionesCurso.top();
            //Inserto a la lista
            listaAlumnos.push_back(alum);
            //Elimino
            inscripcionesCurso.pop();
        }
        //Asigno la lista 
        matriculados[*it] = listaAlumnos;
    }
}
void Universidad::inscripcionesCursos(ifstream& arch){
    //Datos
    int codCurso,codAlumno; 
    Curso curso;
    AlumnoUniversitario alumno;
    while(true){
        arch>>codCurso;
        if(arch.eof())break;
        arch.ignore();  arch>>codAlumno;
        
        for(Curso cur:cursos)
            if(cur.getCodigo() ==  codCurso)
                curso = cur;
        for(AlumnoUniversitario alum:alumnos)
            if(alum.getCodigo()==codAlumno)
                alumno = alum;
        
        if(curso.getCodigo() != 0 and alumno.getCodigo()!=0){
            if(inscripciones.find(curso) == inscripciones.end()){
                InscripcionesCurso colaCurso;
                inscripciones[curso] = colaCurso;
            }
            inscripciones[curso].push(alumno);
        }
    }
}
void Universidad::imprimirMatricula(){
    ofstream arch("docs/ReporteMatricula.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: ReporteMatricula"<<endl;
        exit(1);
    }
    for(vector<Curso>::iterator it = cursos.begin();
        it != cursos.end(); it++){
        it->imprimir(arch);
        list<AlumnoUniversitario> lista = matriculados[*it];
        // while(!lista.empty()){
        //     AlumnoUniversitario alum = lista.
        // }
        arch<<"-----------------------------------------"<<endl;
        for(list<AlumnoUniversitario>::iterator it = lista.begin();
            it != lista.end(); it++){
            it->imprimir(arch);
        }
        arch<<"-----------------------------------------"<<endl;
    }
}