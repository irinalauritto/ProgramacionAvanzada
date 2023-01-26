#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtro.h"

class FiltroPasaBajos : public Filtro
{
public:
    FiltroPasaBajos();
    void aplicarFiltro(Imagen *imagen) override;
};

#endif // FILTROPASABAJOS_H
