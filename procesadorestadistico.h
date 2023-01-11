#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include <vector>

#include "imagen.h"

using namespace std;

class GestorEstadistico
{
private:
    vector<float> intensidadesRGB; //En este atributo se guardan las intensidades de cada pÃ­xel RGB
public:
    GestorEstadistico();
    void caLculoIntensidadesRGB(Imagen &i, vector<float> &intensidades);
    float promedio(Imagen &i);
    float desvioEstandar(Imagen &i);
    float moda(Imagen &i);
    float maximo(Imagen &i);

    //MÃ©todos relacionados al cÃ¡lculo de parÃ¡metros estadÃ­sticos de imÃ¡genes con pÃ­xeles RGB
    float promedioR(Imagen &i);
    float desvioEstaandarR(Imagen &i);
    float modaR(Imagen &i);
    float maximoR(Imagen &i);
    float minimoR(Imagen &i);

    float promedioG(Imagen &i);
    float desvioEstandarG(Imagen &i);
    float modaG(Imagen &i);
    float maximoG(Imagen &i);
    float minimoG(Imagen &i);

    float promedioB(Imagen &i);
    float desvioEstandarB(Imagen &i);
    float modaB(Imagen &i);
    float maximoB(Imagen &i);
    float minimoB(Imagen &i);
};

#endif // PROCESADORESTADISTICO_H
