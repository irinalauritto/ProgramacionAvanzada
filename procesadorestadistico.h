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

    Imagen *imagen; /**< Puntero a la imagen procesada. */

    Pixel maximo, /**< Pixel en el que se guardan los valores máximos de cada componente de los pixeles de la imagen. */

    minimo, /**< Pixel en el que se guardan los valores mínimos de cada componente de los pixeles de la imagen. */

    media, /**< Pixel en el que se guardan los valores medios de cada componente de los pixeles de la imagen. */

    desvioEstandar, /**< desvioEstandar Pixel en el que se guardan los valores de desvío estándar de cada componente de los pixeles de la imagen. */

    moda; /**< Pixel en el que se guardan los valores con mayor repeticiones de cada componente de los pixeles de la imagen. */

    vector<int> primerosValores, /**< Vector en el cual se guardan los valores de las terceras componente de los píxeles. */

    segundosValores, /**< Vector en el cual se guardan los valores de las terceras componente de los píxeles. */

    tercerosValores, /**< Vector en el cual se guardan los valores de las terceras componente de los píxeles. */

    valoresPromedio; /**< Vector en el cual se guardan los valores promedios de los píxeles. */

    int cantidadRepeticionesRojoMasFrecuente; /**< Posee la cantidad de repeticiones del valor rojo mas frecuente. Se utiliza en el autotest. */

    int repeticionValorMasFrecuente; /**< Guarda la cantidad de repeticiones del valor más repetido.  */

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



public:

    /**
     * @brief ProcesadorEstadistico constructor de la clase ProcesadorEstadistico
     */
    ProcesadorEstadistico();

    /**
     * @brief procesarDatos Método que obtiene todos los estadísticos de una imagen y los guarda.
     */
    void procesarDatos();

    /**
     * @brief setImagen Método que permite modificar el atributo imagen.
     * @param pImagen
     */
    void setImagen(Imagen *ptrImagen);

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

    /**
     * @brief setValores Método que permite que se ralice el guardado de los valores de las componentes en los vectores correspondientes.
     */
    void setValores();

    /**
     * @brief getPrimerosValores Devuelve el vector en el cual se guardan los valores de las primeras componenetes y sus repeticiones
     * @return primerosValores
     */
    vector<int> &getPrimerosValores();

    /**
     * @brief getSegundosValores Devuelve el vector en el cual se guardan los valores de las segundas componenetes y sus repeticiones
     * @return segundosValores
     */
    vector<int> &getSegundosValores();

    /**
     * @brief getTercerosValores Devuelve el vector en el cual se guardan los valores de las terceras componenetes y sus repeticiones
     * @return tercerosValores
     */
    vector<int> &getTercerosValores();

    /**
     * @brief getValoresPromedio Devuelve el vector en el cual se guardan los valores promedio de las componenetes y sus repeticiones
     * @return valoresPromedio
     */
    vector<int> &getValoresPromedio();

    /**
     * @brief getRepeticionValorMasFrecuente Devuelve la cantidad de veces que se repite el valor mas frecuente.
     * @return  repeticionValorMasFrecuente
     */
    int getRepeticionValorMasFrecuente() const;

    /**
     * @brief getCantidadRepeticionesRojoMasFrecuente Devuelve la cantidad de veces que se repite el valor rojo mas frecuente.
     * @return
     */
    int getCantidadRepeticionesRojoMasFrecuente() const;
};

#endif // PROCESADORESTADISTICO_H
