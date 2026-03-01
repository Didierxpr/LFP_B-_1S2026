#include "Estadisticas.h"

// Calcula promedio
double Estadisticas::promedio(const vector<double>& datos) {
    if (datos.empty()) return 0;

    double suma = 0;
    for (double v : datos) suma += v;
    return suma / datos.size();
}

// Calcula mediana
double Estadisticas::mediana(vector<double> datos) {
    if (datos.empty()) return 0;

    sort(datos.begin(), datos.end());
    int n = datos.size();

    if (n % 2 == 0)
        return (datos[n/2 - 1] + datos[n/2]) / 2.0;
    else
        return datos[n/2];
}

// Calcula desviación estándar
double Estadisticas::desviacionEstandar(const vector<double>& datos) {
    if (datos.empty()) return 0;

    double prom = promedio(datos);
    double suma = 0;

    for (double v : datos)
        suma += pow(v - prom, 2);

    return sqrt(suma / datos.size());
}