#include "SistemaAcademico.h"
#include "../servicios/CargadorArchivos.h"
#include "../servicios/Estadisticas.h"
#include <iostream>

void SistemaAcademico::cargarEstudiantes(string ruta) {
    estudiantes = CargadorArchivos::cargarEstudiantes(ruta);
    cout << "Total estudiantes cargados: " << estudiantes.size() << endl;
}

void SistemaAcademico::cargarCursos(string ruta) {
    cursos = CargadorArchivos::cargarCursos(ruta);
    cout << "Total cursos cargados: " << cursos.size() << endl;
}

void SistemaAcademico::cargarNotas(string ruta) {
    notas = CargadorArchivos::cargarNotas(ruta);
    cout << "Total notas cargadas: " << notas.size() << endl;
}
void SistemaAcademico::reporteEstadisticasCurso() {

    if (cursos.empty() || notas.empty()) {
        cout << "Debe cargar cursos y notas primero." << endl;
        return;
    }

    cout << "\n===== REPORTE ESTADISTICAS POR CURSO =====\n";

    for (const Curso& curso : cursos) {

        vector<double> notasCurso;

        // Buscar notas asociadas al curso
        for (const Nota& nota : notas) {
            if (nota.codigoCurso == curso.codigo) {
                notasCurso.push_back(nota.nota);
            }
        }

        if (notasCurso.empty()) continue;

        double promedio = Estadisticas::promedio(notasCurso);
        double mediana = Estadisticas::mediana(notasCurso);
        double desviacion = Estadisticas::desviacionEstandar(notasCurso);

        double minimo = *min_element(notasCurso.begin(), notasCurso.end());
        double maximo = *max_element(notasCurso.begin(), notasCurso.end());

        cout << "\nCurso: " << curso.nombre << endl;
        cout << "Cantidad estudiantes: " << notasCurso.size() << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Mediana: " << mediana << endl;
        cout << "Desviacion estandar: " << desviacion << endl;
        cout << "Nota minima: " << minimo << endl;
        cout << "Nota maxima: " << maximo << endl;
    }
}

void SistemaAcademico::reporteRendimientoEstudiante() {

    if (estudiantes.empty() || notas.empty() || cursos.empty()) {
        cout << "Debe cargar estudiantes, cursos y notas primero." << endl;
        return;
    }

    cout << "\n===== REPORTE RENDIMIENTO POR ESTUDIANTE =====\n";

    for (const Estudiante& est : estudiantes) {

        vector<double> notasEst;
        int aprobados = 0;
        int reprobados = 0;
        int creditos = 0;

        for (const Nota& n : notas) {
            if (n.carnet == est.carnet) {
                notasEst.push_back(n.nota);

                if (n.nota >= 61) aprobados++;
                else reprobados++;

                // Buscar créditos del curso
                for (const Curso& c : cursos) {
                    if (c.codigo == n.codigoCurso && n.nota >= 61) {
                        creditos += c.creditos;
                    }
                }
            }
        }

        if (notasEst.empty()) continue;

        double promedio = Estadisticas::promedio(notasEst);

        cout << "\nEstudiante: " << est.nombre << " " << est.apellido << endl;
        cout << "Carnet: " << est.carnet << endl;
        cout << "Carrera: " << est.carrera << endl;
        cout << "Semestre: " << est.semestre << endl;
        cout << "Promedio General: " << promedio << endl;
        cout << "Aprobados: " << aprobados << endl;
        cout << "Reprobados: " << reprobados << endl;
        cout << "Creditos acumulados: " << creditos << endl;
    }
}
void SistemaAcademico::reporteTop10() {}
void SistemaAcademico::reporteReprobacion() {}
void SistemaAcademico::reportePorCarrera() {}