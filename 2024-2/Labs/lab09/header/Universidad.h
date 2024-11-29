//Author: MAKO
#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
#include "AlumnoUniversitario.h"
#include "Curso.h"
#include "Comparadores.h"

using InscripcionesCurso = priority_queue<
    AlumnoUniversitario, //TIPO DE DATO
    vector<AlumnoUniversitario>, //TIPO DE ESTRUCTURA
    greater<AlumnoUniversitario> //COMPARADOR
>;

using MapaInscripciones = map<Curso, InscripcionesCurso>;
using MapaMatriculados  = map<Curso, list<AlumnoUniversitario>>;

class Universidad{
private:
    vector<AlumnoUniversitario> alumnos;
    vector<Curso> cursos;
    MapaInscripciones inscripciones;
    MapaMatriculados matriculados;
public:
    Universidad();
    ~Universidad();

    void cargarAlumnos();
    void imprimirAlumnos();
    void cargarCursos();
    void imprimirCursos();
    void matricular();
    void inscripcionesCursos(ifstream& arch);
    void imprimirMatricula();
};

#endif