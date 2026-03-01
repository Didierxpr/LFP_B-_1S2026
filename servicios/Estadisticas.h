#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Clase que contiene métodos para cálculos estadísticos
class Estadisticas {
public:

    // Calcula el promedio de un conjunto de datos
    static double promedio(const vector<double>& datos);

    // Calcula la mediana (valor central ordenado)
    static double mediana(vector<double> datos);

    // Calcula la desviación estándar
    static double desviacionEstandar(const vector<double>& datos);

    // Calcula el percentil indicado (ej: 25, 50, 75)
    static double percentil(vector<double> datos, double p);
};

#endif