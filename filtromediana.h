#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include <algorithm>

#include "filtro.h"

using namespace std;

/**
 * @brief The FiltroMediana class
 */
class FiltroMediana : public Filtro
{
public:
    FiltroMediana();
    void aplicarFiltro(Imagen *imagen) override;
};

#endif // FILTROMEDIANA_H
