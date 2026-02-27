#ifndef CARGADOR_ARCHIVOS_H
#define CARGADOR_ARCHIVOS_H

#include <fstream>
#include <vector>
#include "../modelos/Estudiante.h"
#include "../modelos/Curso.h"
#include "../modelos/Nota.h"
#include "../util/Utilidades.h"

// Clase encargada únicamente de leer y convertir archivos .lfp en objetos
class CargadorArchivos {
public:

    // Lee el archivo estudiantes.lfp y devuelve un vector de estudiantes
    static vector<Estudiante> cargarEstudiantes(string ruta);

    // Lee el archivo cursos.lfp y devuelve un vector de cursos
    static vector<Curso> cargarCursos(string ruta);

    // Lee el archivo notas.lfp y devuelve un vector de notas
    static vector<Nota> cargarNotas(string ruta);
};

#endif