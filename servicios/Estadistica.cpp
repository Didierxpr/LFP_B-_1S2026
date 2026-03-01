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

// Calcula el percentil p de un conjunto de datos
double Estadisticas::percentil(vector<double> datos, double p) {

    if (datos.empty()) return 0;

    // Ordenamos los datos
    sort(datos.begin(), datos.end());

    // Fórmula de posición
    double posicion = (p / 100.0) * (datos.size() - 1);

    int indiceInferior = floor(posicion);
    int indiceSuperior = ceil(posicion);

    // Si ambos índices son iguales, devolvemos el valor directo
    if (indiceInferior == indiceSuperior)
        return datos[indiceInferior];

    // Interpolación lineal si no es entero
    double fraccion = posicion - indiceInferior;

    return datos[indiceInferior] +
           fraccion * (datos[indiceSuperior] - datos[indiceInferior]);
}