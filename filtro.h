#ifndef FILTRO_H
#define FILTRO_H

#include "imagen.h"

/**
 * @brief Filtro clase de base abstracta creada con la función de aplicar filtros a través de sus clases hijas.
 * @author Irina Esmeralda Lauritto
 */
class Filtro
{
public:

    /**
     * @brief Filtro constructor de la clase Filtro.
     */
    Filtro();

    /**
     * @brief aplicarFiltro Método virtual puro a definir en las clases hijas de esta clase.
     * @param imagen Objeto Imagen sobre el cual trabajará este método.
     */
    virtual void aplicarFiltro(Imagen &imagen) = 0;

    /**
     * Destructor de la clase
     */
    virtual ~Filtro() = 0;
};

#endif // FILTRO_H
