#ifndef PSEUDOCOLOREADOR_H
#define PSEUDOCOLOREADOR_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "pixel.h"
#include "imagen.h"

using namespace std;

/**
 * @brief Pseudocoloreador clase concreta que permite leer los archivos que contienen las tablas LUT y realizar la conversion de imagenes de intensidades a RGB.
 * @author Irina Esmeralda Lauritto
 */
class Pseudocoloreador
{
private:

    vector <Pixel> tablaLUT; /**< atributo en el cual se guarda la tabla LUT. */

public:

    /**
     * @brief Pseudocoloreador Constructor de la clase.
     */
    Pseudocoloreador();

    /**
     * @brief colorearImagen Método que permite el pseudocoloreo de las imágenes.
     * @param imagenIntensidad
     */
    void colorearImagen(Imagen &imagenIntensidad);

    /**
     * @brief leerArchivoLUT Método que permite leer los archivos LUT
     * @param rutaLUT ruta del archivo
     */
    void leerArchivoLUT(string rutaLUT);
};

#endif // PSEUDOCOLOREADOR_H
