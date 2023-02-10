#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include <algorithm>

#include "filtro.h"

using namespace std;

/**
 * @brief  FiltroMediana clase concreta que permite aplicar el filtro de mediana
 * @author Irina Esmeralda Lauritto
 */
class FiltroMediana : public Filtro
{
public:
    /**
     * @brief FiltroMediana constructor de la clase
     */
    FiltroMediana();

    /**
     * @brief aplicarFiltro Método que permite aplicar el filtro de mediana
     * @param imagen Imagen a modificar
     */
    void aplicarFiltro(Imagen &imagen) override;

    /**
     * Destructor de la clase
     */
    ~FiltroMediana();
};

#endif // FILTROMEDIANA_H
