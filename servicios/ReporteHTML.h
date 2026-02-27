#ifndef REPORTE_HTML_H
#define REPORTE_HTML_H

#include <string>
using namespace std;

// Clase encargada de generar archivos HTML con los reportes
class ReporteHTML {
public:

    // Genera un archivo HTML con el contenido recibido
    static void generarReporte(string contenido, string nombreArchivo);
};

#endif