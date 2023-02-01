#ifndef EDITORIMAGEN_H
#define EDITORIMAGEN_H

#include "imagen.h"
#include <iostream>

using namespace std;

class EditorImagen
{
public:
    EditorImagen();
    void binarizarImagen(Imagen *imagen, int umbral);
    void negativizarImagen(Imagen *imagen);
    void aumentarBrillo(Imagen *imagen, int unidadesAumento);
    void disminuirBrillo(Imagen *imagen, int unidadesDisminucion);
    void ajustarContraste(Imagen *imagen, Pixel pMaximo, Pixel pMinimo);

};

#endif // EDITORIMAGEN_H
