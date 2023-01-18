#ifndef BINARIZADOR_H
#define BINARIZADOR_H

#include "imagen.h"

class Binarizador
{
public:
    Binarizador();
    void binarizar(Imagen &iIntensidad, int valor);
};

#endif // BINARIZADOR_H
