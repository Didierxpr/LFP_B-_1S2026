#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <vector>
#include "../modelos/Estudiante.h"
#include "../modelos/Curso.h"
#include "../modelos/Nota.h"

// Clase principal que coordina el funcionamiento del sistema
class SistemaAcademico {
private:
    vector<Estudiante> estudiantes;  // Lista de estudiantes cargados
    vector<Curso> cursos;            // Lista de cursos cargados
    vector<Nota> notas;              // Lista de notas cargadas

public:

    // Carga los estudiantes desde un archivo y los almacena en memoria
    void cargarEstudiantes(string ruta);

    // Carga los cursos desde un archivo
    void cargarCursos(string ruta);

    // Carga las notas desde un archivo
    void cargarNotas(string ruta);

    // Genera reporte estadístico por curso
    void reporteEstadisticasCurso();

    // Genera reporte de rendimiento por estudiante
    void reporteRendimientoEstudiante();

    // Genera el Top 10 de mejores promedios
    void reporteTop10();

    // Genera reporte de cursos con mayor reprobación
    void reporteReprobacion();

    // Genera análisis general por carrera
    void reportePorCarrera();
};

#endif