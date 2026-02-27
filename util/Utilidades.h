#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Clase de apoyo con funciones reutilizables
class Utilidades {
public:

    // Divide una línea de texto usando un delimitador (ej: coma)
    // Retorna un vector con cada valor separado
    static vector<string> split(const string& linea, char delimitador) {
        vector<string> resultado;
        stringstream ss(linea);
        string item;

        while (getline(ss, item, delimitador)) {
            resultado.push_back(item);
        }

        return resultado;
    }
};

#endif