#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtro.h"
#include <iostream>

using namespace std;

/**
 * @brief  FiltroPasaBajos clase concreta que permite aplicar el filtro pasa bajos o de suavizado
 * @author Irina Esmeralda Lauritto
 */
class FiltroPasaBajos : public Filtro
{
public:
    /**
     * @brief FiltroPasaBajos constructor de la clase
     */
    FiltroPasaBajos();

    /**
     * @brief Método que permite aplicar el filtro de suavizado
     * @param imagen Imagen a modificar
     */
    void aplicarFiltro(Imagen &imagen) override;

    /**
     * Destructor de la clase
     */
    ~FiltroPasaBajos();
};

#endif // FILTROPASABAJOS_H
