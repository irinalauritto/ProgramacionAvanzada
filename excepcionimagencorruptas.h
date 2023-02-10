#ifndef EXCEPCIONIMAGENCORRUPTAS_H
#define EXCEPCIONIMAGENCORRUPTAS_H

#include <stdexcept>

using std::runtime_error;

/**
 * @brief ExcepcionImagenCorrupta clase concreta que permite llevar a cabo el manejo de excepciones
 * @author Irina Esmeralda Lauritto
 */
class ExcepcionImagenCorrupta : public runtime_error
{
public:
    /**
     * @brief ExcepcionImagenCorrupta contructor de la clase
     */
    ExcepcionImagenCorrupta()    
        : runtime_error ("Imagen corrupta. El archivo de imagen posee datos incorrectos.")
    {}
};

#endif // EXCEPCIONIMAGENCORRUPTAS_H
