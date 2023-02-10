#ifndef EDITORIMAGEN_H
#define EDITORIMAGEN_H

#include "imagen.h"
#include <iostream>

using namespace std;

/**
 * @brief  EditorImagen clase concreta que permite realizar modificaciones sencillas en las imágenes.
 * @author Irina Esmeralda Lauritto
 */
class EditorImagen
{
public:
    /**
     * @brief EditorImagen Constructor de la clase EditorImagen.
     */
    EditorImagen();

    /**
     * @brief binarizarImagen Metodo que permite binarizar las imágenes
     * @param imagen Imagen a binarizar
     * @param umbral Umbral a partir del cual se binariza
     */
    void binarizarImagen(Imagen &imagen, int umbral);

    /**
     * @brief negativizarImagen Metodo que permite negativizar las imágenes
     * @param imagen Imagen a negativizar
     */
    void negativizarImagen(Imagen &imagen);

    /**
     * @brief aumentarBrillo Método que permite aumentar el brillo de una imagen
     * @param imagen Imagen a modificar
     * @param unidadesAumento Cantidad en la que se desea aumentar el brillo
     */
    void aumentarBrillo(Imagen &imagen, int unidadesAumento);

    /**
     * @brief disminuirBrillo Método que permite disminuir el brillo de una imagen
     * @param imagen Imagen a modificar
     * @param unidadesDisminucion Cantidad en la que se desea disminuir el brillo
     */
    void disminuirBrillo(Imagen &imagen, int unidadesDisminucion);

    /**
     * @brief ajustarContraste Método que permite ajustar el contraste de una imagen
     * @param imagen Imagen a modificar
     * @param pMaximo Pixel con los valores máximos de cada componente de la imagen
     * @param pMinimo Pixel con los valores mínimos de cada componente de la imagen
     */
    void ajustarContraste(Imagen &imagen, Pixel pMaximo, Pixel pMinimo);

};

#endif // EDITORIMAGEN_H
