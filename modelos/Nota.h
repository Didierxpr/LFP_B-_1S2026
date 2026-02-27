#ifndef NOTA_H
#define NOTA_H

#include <string>
using namespace std;

// Estructura que almacena la nota obtenida por un estudiante en un curso
struct Nota {
    int carnet;          // Carnet del estudiante
    int codigoCurso;     // Código del curso
    double nota;         // Calificación obtenida (0-100)
    string ciclo;        // Ciclo académico (1S o 2S)
    int anio;            // Año en que se cursó
};

#endif