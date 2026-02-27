#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

// Estructura que representa la información básica de un estudiante
struct Estudiante {
    int carnet;          // Identificador único del estudiante
    string nombre;       // Nombre del estudiante
    string apellido;     // Apellido del estudiante
    string carrera;      // Carrera que cursa
    int semestre;        // Semestre actual (1-10)
};

#endif