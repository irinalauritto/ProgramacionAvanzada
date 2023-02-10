#ifndef DETECTORAREA_H
#define DETECTORAREA_H

#include "imagen.h"
#include <cmath>

const int vecinosC[]={-1,0,1,-1,1,-1,0,1};
const int vecinosF[]={-1,-1,-1,0,0,1,1,1};

/**
 * @brief DetectorArea clase concreta que a partir de un pixel determinado barre la imagen y encuentra todos aquellos que poseen valores de intensidad o colores similares y devuelve el área ocupada por los mismos.
 * @author Irina Esmeralda Lauritto
 */
class DetectorArea
{
private:

    int areaTotal; /**< Atributo en el cual se guarda el area total. */

    int profundidad; /**< Atributo con el cual se maneja la profundidad de la recursividad del algoritmo del pintor. */

    float tolerancia = 15.0f; /**< Atributo con el que se maneja la la tolerancia de la diferencia entre píxeles. Si la diferencia entre píxeles es menor o igual a este valor, los píxeles son similares. */

    Pixel pixelAuxiliar; /**< atributo de tipo Pixel en el cual se guarda el píxel con el que se llama a la funcion recursiva buscarAreaImagen. */

    vector<vector<bool>> areaDetectada; /**< Mattriz booleana en la cual se marcan como true aquellas posiciones de la imagen que son del mismo color o intensidad que el pixel auxiliar. */

    Imagen *ptrImagen; /**< Puntero a la imagen estudiada. */

    /**
     * @brief pintarImagen Método recursivo que utiliza el algoritmo del pintor para hallar todos los píxeles similares al elegido.
     * @param pFila Fila del píxel a estudiar.
     * @param pColumna Columna del píxel a estudiar.
     */
    void buscarAreaImagen(int pFila, int pColumna);

public:

    /**
     * @brief DetectorArea Constructor de la clase.
     */
    DetectorArea();

    /**
     * @brief detectarArea Método público que permite la detección del area.
     * @param pImagen
     * @param pColumna
     * @param pFila
     */
    void detectarArea(Imagen *pPtrImagen, int pColumna, int pFila);

    /**
     * @brief getAreaTotal Devuelve el área total encontrada.
     * @return areaTotal
     */
    int getAreaTotal();
};

#endif // DETECTORAREA_H
