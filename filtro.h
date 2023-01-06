#ifndef FILTRO_H
#define FILTRO_H

#include "imagen.h"

class Filtro
{
public:
    Filtro();
    virtual void aplicarFiltro(Imagen &i)=0;
};

#endif // FILTRO_H
