#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtro.h"
#include <iostream>

using namespace std;

class FiltroPasaBajos : public Filtro
{
public:
    FiltroPasaBajos();
    void aplicarFiltro(Imagen *imagen) override;
};

#endif // FILTROPASABAJOS_H
