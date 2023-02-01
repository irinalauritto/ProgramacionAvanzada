#ifndef DETECTORAREA_H
#define DETECTORAREA_H

#include "imagen.h"
#include <cmath>

class DetectorArea
{
private:

    int areaTotal = 0;

    float tolerancia = 0.15;

    Pixel pixelAuxiliar;

    vector<vector<bool>> areaDetectada;

    Imagen *imagen;


public:
    DetectorArea();

    void detectarArea(Imagen *pImagen, int pColumna, int pFila);

    void pintarImagen();

    int getAreaTotal();
};

#endif // DETECTORAREA_H
