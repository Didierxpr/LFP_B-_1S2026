#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

// Estructura que representa un curso del pensum
struct Curso {
    int codigo;          // Código único del curso
    string nombre;       // Nombre del curso
    int creditos;        // Cantidad de créditos
    int semestre;        // Semestre en que se imparte
    string carrera;      // Carrera a la que pertenece
};

#endif