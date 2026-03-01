#include <iostream>
#include "sistema/SistemaAcademico.h"

using namespace std;

int main() {

    SistemaAcademico sistema; // Objeto principal que controla todo el programa
    int opcion;

    do {
        cout << "==========================================" << endl;
        cout << " SISTEMA DE ANALISIS ACADEMICO" << endl;
        cout << "==========================================" << endl;
        cout << "1. Cargar archivo de estudiantes" << endl;
        cout << "2. Cargar archivo de cursos" << endl;
        cout << "3. Cargar archivo de notas" << endl;
        cout << "4. Generar Reporte: Estadisticas por Curso" << endl;
        cout << "5. Generar Reporte: Rendimiento por Estudiante" << endl;
        cout << "6. Generar Reporte: Top 10 Mejores Estudiantes" << endl;
        cout << "7. Generar Reporte: Cursos con Mayor Reprobacion" << endl;
        cout << "8. Generar Reporte: Analisis por Carrera" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.cargarEstudiantes("data/estudiantes.lfp");
                break;

            case 2:
                sistema.cargarCursos("data/cursos.lfp");
                break;

            case 3:
                sistema.cargarNotas("data/notas.lfp");
                break;

            case 4:
                sistema.reporteEstadisticasCurso();
                break;

            case 5:
                sistema.reporteRendimientoEstudiante();
                break;

            case 6:
                sistema.reporteTop10();
                break;

            case 7:
                sistema.reporteReprobacion();
                break;

            case 8:
                sistema.reportePorCarrera();
                break;

            case 9:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 9);

    return 0;
}