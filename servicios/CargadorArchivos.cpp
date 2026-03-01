#include "CargadorArchivos.h"
#include <iostream>

// Carga estudiantes desde archivo
vector<Estudiante> CargadorArchivos::cargarEstudiantes(string ruta) {

    vector<Estudiante> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo de estudiantes." << endl;
        return lista;
    }

    string linea;

    while (getline(archivo, linea)) {

        vector<string> datos = Utilidades::split(linea, ',');

        if (datos.size() == 5) {
            Estudiante e;
            e.carnet = stoi(datos[0]);
            e.nombre = datos[1];
            e.apellido = datos[2];
            e.carrera = datos[3];
            e.semestre = stoi(datos[4]);

            lista.push_back(e);
        }
    }

    archivo.close();
    cout << "Estudiantes cargados correctamente." << endl;

    return lista;
}
vector<Curso> CargadorArchivos::cargarCursos(string ruta) {

    vector<Curso> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo de cursos." << endl;
        return lista;
    }

    string linea;

    while (getline(archivo, linea)) {

        vector<string> datos = Utilidades::split(linea, ',');

        if (datos.size() == 5) {
            Curso c;
            c.codigo = stoi(datos[0]);
            c.nombre = datos[1];
            c.creditos = stoi(datos[2]);
            c.semestre = stoi(datos[3]);
            c.carrera = datos[4];

            lista.push_back(c);
        }
    }

    archivo.close();
    cout << "Cursos cargados correctamente." << endl;

    return lista;
}
vector<Nota> CargadorArchivos::cargarNotas(string ruta) {

    vector<Nota> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo de notas." << endl;
        return lista;
    }

    string linea;

    while (getline(archivo, linea)) {

        vector<string> datos = Utilidades::split(linea, ',');

        if (datos.size() == 5) {
            Nota n;
            n.carnet = stoi(datos[0]);
            n.codigoCurso = stoi(datos[1]);
            n.nota = stod(datos[2]);
            n.ciclo = datos[3];
            n.anio = stoi(datos[4]);

            lista.push_back(n);
        }
    }

    archivo.close();
    cout << "Notas cargadas correctamente." << endl;

    return lista;
}