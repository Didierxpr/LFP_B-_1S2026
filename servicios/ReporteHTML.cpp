#include "ReporteHTML.h"
#include <fstream>
#include <iostream>

// Genera un archivo HTML con el contenido recibido
void ReporteHTML::generarReporte(string contenido, string nombreArchivo) {

    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al generar el archivo HTML." << endl;
        return;
    }

    // Estructura básica HTML con estilo simple
    archivo << "<!DOCTYPE html>\n";
    archivo << "<html>\n<head>\n";
    archivo << "<meta charset='UTF-8'>\n";
    archivo << "<title>Reporte Academico</title>\n";

    // Estilos básicos
    archivo << "<style>\n";
    archivo << "body { font-family: Arial; background-color: #f4f4f4; }\n";
    archivo << "table { border-collapse: collapse; width: 100%; }\n";
    archivo << "th, td { border: 1px solid black; padding: 8px; text-align: center; }\n";
    archivo << "th { background-color: #2c3e50; color: white; }\n";
    archivo << "</style>\n";

    archivo << "</head>\n<body>\n";

    // Inserta contenido dinámico del reporte
    archivo << contenido;

    archivo << "\n</body>\n</html>";

    archivo.close();

    cout << "Reporte generado correctamente: " << nombreArchivo << endl;
}