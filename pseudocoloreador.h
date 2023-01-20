#ifndef PSEUDOCOLOREADOR_H
#define PSEUDOCOLOREADOR_H

#include <vector>

#include "pixel.h"
#include "imagen.h"

using namespace std;

class Pseudocoloreador
{
private:
   vector <Pixel> tablaLUT1;
   vector <Pixel> tablaLUT2;
public:
    Pseudocoloreador();
    void colorearLUT1(Imagen *iIntensidad);
    void colorearLUT2(Imagen *iIntensidad); //recibir intensidad y devolver un pixel rgb
};

#endif // PSEUDOCOLOREADOR_H
