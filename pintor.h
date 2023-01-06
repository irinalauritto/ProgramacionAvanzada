#ifndef PINTOR_H
#define PINTOR_H

#include "imagen.h"
#include "pixel.h"

class Pintor
{
public:
    Pintor();
    int pintar(Imagen &i, Pixel pPixel); //Devuelve la cantidad de pixeles pintados.
};

#endif // PINTOR_H
