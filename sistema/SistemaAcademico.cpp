#include "SistemaAcademico.h"
#include "../servicios/CargadorArchivos.h"
#include "../servicios/Estadisticas.h"
#include "../servicios/ReporteHTML.h"
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

    // Construimos el contenido HTML dinámicamente
    string html = "<h1>Reporte Estadisticas por Curso</h1>";
    html += "<table>";
html += "<tr><th>Curso</th><th>Cantidad</th><th>Promedio</th><th>Mediana</th><th>P25</th><th>P75</th><th>Desv.Std</th><th>Min</th><th>Max</th></tr>";
    for (const Curso& curso : cursos) {

        vector<double> notasCurso;

        // Recolectar notas del curso
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
        double p25 = Estadisticas::percentil(notasCurso, 25);
        double p75 = Estadisticas::percentil(notasCurso, 75);

        // Agregar fila a la tabla HTML
        html += "<tr>";
        html += "<td>" + curso.nombre + "</td>";
        html += "<td>" + to_string(notasCurso.size()) + "</td>";
        html += "<td>" + to_string(promedio) + "</td>";
        html += "<td>" + to_string(mediana) + "</td>";
        html += "<td>" + to_string(desviacion) + "</td>";
        html += "<td>" + to_string(minimo) + "</td>";
        html += "<td>" + to_string(maximo) + "</td>";
        html += "<td>" + to_string(p25) + "</td>";
        html += "<td>" + to_string(p75) + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    // Generar archivo HTML
    ReporteHTML::generarReporte(html, "Reporte_Estadisticas_Curso.html");
}

// Genera el reporte de rendimiento por estudiante en formato HTML
void SistemaAcademico::reporteRendimientoEstudiante() {

    if (estudiantes.empty() || notas.empty() || cursos.empty()) {
        cout << "Debe cargar estudiantes, cursos y notas primero." << endl;
        return;
    }

    string html = "<h1>Reporte Rendimiento por Estudiante</h1>";
    html += "<table>";
    html += "<tr><th>Nombre</th><th>Carnet</th><th>Carrera</th><th>Semestre</th><th>Promedio</th><th>Aprobados</th><th>Reprobados</th><th>Creditos</th></tr>";

    for (const Estudiante& est : estudiantes) {

        vector<double> notasEst;
        int aprobados = 0;
        int reprobados = 0;
        int creditos = 0;

        for (const Nota& n : notas) {
            if (n.carnet == est.carnet) {

                notasEst.push_back(n.nota);

                if (n.nota >= 61) {
                    aprobados++;

                    // Buscar créditos del curso aprobado
                    for (const Curso& c : cursos) {
                        if (c.codigo == n.codigoCurso)
                            creditos += c.creditos;
                    }
                }
                else reprobados++;
            }
        }

        if (notasEst.empty()) continue;

        double promedio = Estadisticas::promedio(notasEst);

        html += "<tr>";
        html += "<td>" + est.nombre + " " + est.apellido + "</td>";
        html += "<td>" + to_string(est.carnet) + "</td>";
        html += "<td>" + est.carrera + "</td>";
        html += "<td>" + to_string(est.semestre) + "</td>";
        html += "<td>" + to_string(promedio) + "</td>";
        html += "<td>" + to_string(aprobados) + "</td>";
        html += "<td>" + to_string(reprobados) + "</td>";
        html += "<td>" + to_string(creditos) + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    ReporteHTML::generarReporte(html, "Reporte_Rendimiento_Estudiante.html");
}
// Genera el Top 10 de mejores estudiantes en HTML
void SistemaAcademico::reporteTop10() {

    if (estudiantes.empty() || notas.empty()) {
        cout << "Debe cargar estudiantes y notas primero." << endl;
        return;
    }

    struct Resultado {
        Estudiante est;
        double promedio;
    };

    vector<Resultado> ranking;

    for (const Estudiante& est : estudiantes) {

        vector<double> notasEst;

        for (const Nota& n : notas) {
            if (n.carnet == est.carnet)
                notasEst.push_back(n.nota);
        }

        if (!notasEst.empty()) {
            ranking.push_back({est, Estadisticas::promedio(notasEst)});
        }
    }

    sort(ranking.begin(), ranking.end(),
         [](Resultado a, Resultado b) {
             return a.promedio > b.promedio;
         });

    string html = "<h1>Top 10 Mejores Estudiantes</h1>";
    html += "<table>";
    html += "<tr><th>Posicion</th><th>Nombre</th><th>Carrera</th><th>Promedio</th></tr>";

    int limite = min(10, (int)ranking.size());

    for (int i = 0; i < limite; i++) {

        html += "<tr>";
        html += "<td>" + to_string(i+1) + "</td>";
        html += "<td>" + ranking[i].est.nombre + " " + ranking[i].est.apellido + "</td>";
        html += "<td>" + ranking[i].est.carrera + "</td>";
        html += "<td>" + to_string(ranking[i].promedio) + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    ReporteHTML::generarReporte(html, "Reporte_Top10.html");
}
// Genera reporte de cursos con mayor índice de reprobación
void SistemaAcademico::reporteReprobacion() {

    if (cursos.empty() || notas.empty()) {
        cout << "Debe cargar cursos y notas primero." << endl;
        return;
    }

    struct DatosCurso {
        Curso curso;
        int total;
        int reprobados;
        double porcentaje;
    };

    vector<DatosCurso> lista;

    for (const Curso& curso : cursos) {

        int total = 0;
        int reprobados = 0;

        for (const Nota& n : notas) {
            if (n.codigoCurso == curso.codigo) {
                total++;
                if (n.nota < 61) reprobados++;
            }
        }

        if (total > 0) {
            lista.push_back({curso, total, reprobados,
                             (double)reprobados / total * 100});
        }
    }

    sort(lista.begin(), lista.end(),
         [](DatosCurso a, DatosCurso b) {
             return a.porcentaje > b.porcentaje;
         });

    string html = "<h1>Cursos con Mayor Reprobacion</h1>";
    html += "<table>";
    html += "<tr><th>Curso</th><th>Total</th><th>Reprobados</th><th>% Reprobacion</th></tr>";

    for (const auto& d : lista) {
        html += "<tr>";
        html += "<td>" + d.curso.nombre + "</td>";
        html += "<td>" + to_string(d.total) + "</td>";
        html += "<td>" + to_string(d.reprobados) + "</td>";
        html += "<td>" + to_string(d.porcentaje) + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    ReporteHTML::generarReporte(html, "Reporte_Reprobacion.html");
}
// Genera análisis general por carrera en HTML
void SistemaAcademico::reportePorCarrera() {

    if (estudiantes.empty() || notas.empty()) {
        cout << "Debe cargar estudiantes y notas primero." << endl;
        return;
    }

    vector<string> carreras;

    for (const Estudiante& e : estudiantes) {
        if (find(carreras.begin(), carreras.end(), e.carrera) == carreras.end())
            carreras.push_back(e.carrera);
    }

    string html = "<h1>Analisis por Carrera</h1>";
    html += "<table>";
    html += "<tr><th>Carrera</th><th>Total Estudiantes</th><th>Promedio General</th></tr>";

    for (const string& carrera : carreras) {

        int totalEst = 0;
        vector<double> notasCarrera;

        for (const Estudiante& e : estudiantes) {
            if (e.carrera == carrera) {
                totalEst++;

                for (const Nota& n : notas)
                    if (n.carnet == e.carnet)
                        notasCarrera.push_back(n.nota);
            }
        }

        double promedio = Estadisticas::promedio(notasCarrera);

        html += "<tr>";
        html += "<td>" + carrera + "</td>";
        html += "<td>" + to_string(totalEst) + "</td>";
        html += "<td>" + to_string(promedio) + "</td>";
        html += "</tr>";
    }

    html += "</table>";

    ReporteHTML::generarReporte(html, "Reporte_Analisis_Carrera.html");
}