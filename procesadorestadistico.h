#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include <vector>
#include <math.h>
#include <map>

#include "imagen.h"

using namespace std;

/**
 * @brief ProcesadorEstadistico clase concreta que se encarga de realizar el procesamiento estadístico de una imagen.
 * @author Irina Esmeralda Lauritto
 */
class ProcesadorEstadistico
{
private:

    /**
     * @brief imagen Puntero a la imagen que será procesada.
     */
    Imagen *imagen;

    /**
     * @brief maximo Pixel en el que se guardan los valores máximos de cada componente de los pixeles de la imagen.
     */
    Pixel maximo,

    /**
     * @brief minimo Pixel en el que se guardan los valores mínimos de cada componente de los pixeles de la imagen.
     */
    minimo,

    /**
     * @brief media Pixel en el que se guardan los valores medios de cada componente de los pixeles de la imagen.
     */
    media,

    /**
     * @brief desvioEstandar Pixel en el que se guardan los valores de desvío estándar de cada componente de los pixeles de la imagen.
     */
    desvioEstandar,

    /**
     * @brief moda Pixel en el que se guardan los valores con mayor repeticiones de cada componente de los pixeles de la imagen.
     */
    moda;

public:

    /**
     * @brief ProcesadorEstadistico constructor de la clase ProcesadorEstadistico
     */
    ProcesadorEstadistico();

    /**
     * @brief encontrarMaximo Método que permite hallar el máximo valor de cada componente de los pixeles de una imagen.
     */
    void encontrarMaximo();

    /**
     * @brief encontrarMinimo Método que permite hallar el mínimo valor de cada componente de los pixeles de una imagen.
     */
    void encontrarMinimo();

    /**
     * @brief calcularMedia Método que permite calcular el valor medio de cada componente de los pixeles de una imagen.
     */
    void calcularMedia();

    /**
     * @brief calcularDesvioEstandar Método que permite calcular el valor del  desvio estandar de cada componente de los pixeles de una imagen.
     */
    void calcularDesvioEstandar();

    /**
     * @brief hallarModa Método que permite calcular el valor con mayor frecuencia de cada componente de los pixeles de una imagen.
     */
    void hallarModa();

    /**
     * @brief procesarDatos Método que obtiene todos los estadísticos de una imagen y los guarda.
     */
    void procesarDatos();

    /**
     * @brief setImagen Método que permite modificar el atributo imagen.
     * @param pImagen
     */
    void setImagen(Imagen *pImagen);

    /**
     * @brief getMaximo Devuelve el pixel con los valores máximos de cada componente.
     * @return maximo
     */
    Pixel &getMaximo();

    /**
     * @brief getMinimo Devuelve el pixel con los valores mínimos de cada componente.
     * @return minimo
     */
    Pixel &getMinimo();

    /**
     * @brief getMedia Devuelve el pixel con los valores medios de cada componente.
     * @return media
     */
    Pixel &getMedia();

    /**
     * @brief getDesvioEstandar Devuelve el pixel con los valores de los desvíos estándar de cada componente.
     * @return desvioEstandar
     */
    Pixel &getDesvioEstandar();

    /**
     * @brief getModa Devuelve el pixel con los valores mas frecuentes de cada componente.
     * @return moda
     */
    Pixel &getModa();
};

#endif // PROCESADORESTADISTICO_H
