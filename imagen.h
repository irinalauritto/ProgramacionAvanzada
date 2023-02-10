#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>
#include <iostream>
#include "pixel.h"

using namespace std;

/**
 * @brief Imagen clase concreta que modela una imagen virtual y nos permite trabajar con ella.
 * @author Irina Esmeralda Lauritto
 */
class Imagen
{
private:

    vector<vector<Pixel> > pixeles; /**< Atributo que modela la matriz de pixeles que posee una imagen. */

    unsigned int cantidadColumnas; /**< cantidad de columnas de pixeles de la imagen. */

    unsigned int cantidadFilas; /**< Cantidad de filas de pixeles de la imagen. */

    int maximoValor; /**< Mámimo valor de rango dinámico de la imagen. */

    string comentarios; /**< Comentarios que decriben la imagen. */

    string tipoImagen; /**< Atributo en el cual se especifica si la imagen es RGB, Monocromática, de Intensidades o de IntensidadesC (proveniente de archivo comprimido). */

    bool estaAlterada = false; /**< Si la imagen está alterada es true, caso contrario es false. */

public:

    /**
     * @brief Imagen Constructor por defecto de la clase Imagen.
     */
    Imagen();

    /**
     * @brief Imagen Constructor de la clase Imagen.
     * @param pAncho Cantidad de columnas que deberá tener la imagen.
     * @param pAlto Cantidad de filas que deberá tener la imagen.
     */
    Imagen(int pCantidadColumnas, int pCantidadFilas);

    /**
     * @brief getAncho Método que permite devolver el atributo cantidadColumnas.
     * @return Devuelve la cantidad de columnas de la imagen.
     */
    int getCantidadColumnas();

    /**
     * @brief getAlto Método que permite devolver el atributo cantidadFilas.
     * @return Devuelve la cantidad de filas de la imagen.
     */
    int getCantidadFilas();

    /**
     * @brief getMaximoValor Método que devuelve el máximo valor del rango dinámico.
     * @return Devuelve el atributo máximoValor.
     */
    int getMaximoValor() const;

    /**
     * @brief getComentarios Método que devuelve los comentarios.
     * @return Devuelve el atributo comentarios.
     */
    const string &getComentarios() const;

    /**
     * @brief getTipoImagen
     * @return
     */
    const string &getTipoImagen() const;

    /**
     * @brief getEstaAlterada
     * @return
     */
    bool getEstaAlterada() const;

    /**
     * @brief setMaximoValor Método que permite modificar el máximo valor del rango dinámico.
     * @param pMaximoValor nuevo valor del parámetro máximoValor.
     */
    void setMaximoValor(int pMaximoValor);

    /**
     * @brief setComentarios Método que permite modificar los comemtarios.
     * @param pComentarios nuevo valor del parámetro comentarios.
     */
    void setComentarios(string pComentarios);

    /**
     * @brief setTipoImagen Método que permite modificar el tipo de imagen.
     * @param pTipoImagen nuevo valor del parámetro tipoImagen.
     */
    void setTipoImagen(string pTipoImagen);

    /**
     * @brief setEstaAlterada
     * @param newEstaAlterada
     */
    void setEstaAlterada(bool pEstaAlterada);

    /**
     * @brief getPrimerComponente Método que permite conocer el valor de la primer componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @return Devuelve el valor de la primer componente de un píxel en una posición determinada.
     */
    float getPrimerComponente(int columna, int fila);

    /**
     * @brief getSegundaComponente Método que permite conocer el valor de la segunda componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @return Devuelve el valor de la segunda componente de un píxel en una posición determinada.
     */
    float getSegundaComponente(int columna, int fila);

    /**
     * @brief getTercerComponente Método que permite conocer el valor de la tercer componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @return Devuelve el valor de la tercer componente de un píxel en una posición determinada.
     */
    float getTercerComponente(int columna, int fila);

    /**
     * @brief setPrimerComponente Método que permite settear el valor de la primer componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @param valor Valor a settear
     */
    void setPrimerComponente(int columna, int fila, float valor);

    /**
     * @brief setSegundaComponente Método que permite settear el valor de la segunda componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @param valor Valor a settear
     */
    void setSegundaComponente(int columna, int fila, float valor);

    /**
     * @brief setTercerComponente Método que permite settear el valor de la tercer componente de un píxel en determinada posición de la imagen.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifíca la fila del píxel que nos interesa.
     * @param valor Valor a settear
     */
    void setTercerComponente(int columna, int fila, float valor);

    /**
     * @brief setTamanio Método permite modificar el tamaño de la imagen.
     * @param pCantidadColumnas Se corresponde a la cantidad de columnas de la imagen.
     * @param pCantidadFilas Se corresponde a la cantidad de filas de la imagen.
     */
    void setTamanio(int pCantidadColumnas, int pCantidadFilas);

    /**
     * @brief modificarPixel Método que permite modificar un pixel de la imagen.
     * @param columna Determina la posicion del píxel a modificar.
     * @param fila Determina la posicion del píxel a modificar
     * @param pPrimerComponente nuevo valor de la primer componente de dicho píxel.
     * @param pSegundaComponente nuevo valor de la segunda componente de dicho píxel.
     * @param pTercerComponente nuevo valor de la tecer componente de dicho píxel.
     */
    void modificarPixel(int columna, int fila, float pPrimerComponente, float pSegundaComponente, float pTercerComponente);

    /**
     * @brief devolverPixel Método que permite que la imagen devuleva un pixel determinado.
     * @param columna Especifica la columna del pixel que nos interesa.
     * @param fila Especifica la fila del pixel que nos interesa.
     * @return pixel[fila][columna]
     */
    Pixel devolverPixel(int columna, int fila);


};

#endif // IMAGEN_H
