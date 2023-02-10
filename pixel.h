#ifndef PIXEL_H
#define PIXEL_H

#include <string>

using namespace std;

/**
 * @brief La clase Pixel modela un píxel, ya sea RGB, monocromático o perteneciente a una imagen de intensidades.
 * @author Irina Esmeralda Lauritto
 */
class Pixel
{
private:

    float componentes[3]; /**< Arreglo estático que modela las componentes de un píxel. */

    int maximoValor; /**< Atributo que guarda el máximo valor que puede llevar una componente de una píxel. */

public:

    /**
     * @brief Pixel método constructor de la clase Pixel
     */
    Pixel();

    /**
     * @brief setMaximoValor
     * @param newMaximoValor
     */
    void setMaximoValor(int pMaximoValor);

    /**
     * @brief setComponentes método que permite asignarle un valor a las tres componentes del pixel.
     * @param primer representa la primer componente del pixel.
     * @param segunda Representa la segunda componente del pixel
     * @param tercer Representa la tercer componente del pixel
     */
    void setComponentes(float primer, float segunda, float tercer);

    /**
     * @brief setPrimerComponente método que permite asignarle un valor a las primer componente del pixel.
     * @param pPrimerComponente representa la primer componente del pixel.
     */
    void setPrimerComponente(float pPrimerComponente);

    /**
     * @brief setSegundaComponente método que permite asignarle un valor a la segunda componente del pixel.
     * @param pSegundaComponente representa la segunda componente del pixel.
     */
    void setSegundaComponente(float pSegundaComponente);

    /**
    * @brief setTercerComponente método que permite asignarle un valor a la tercer componente del pixel.
    * @param pTercerComponente representa la tercer componente del pixel.
    */
    void setTercerComponente(float pTercerComponente);

    /**
     * @brief getPrimerComponente método que permite devolver el valor de la primer componente del pixel.
     * @return devuelve el valor de la primer componente del pixel.
    */
    float getPrimerComponente();

    /**
    * @brief getSegundaComponente método que permite devolver el valor de la segunda componente del pixel.
    * @return devuelve el valor de la segunda componente del pixel.
    */
    float getSegundaComponente();

    /**
    * @brief getTercerComponente método que permite devolver el valor de la tercer componente del pixel.
    * @return devuelve el valor de la tercer componente del pixel.
    */
    float getTercerComponente();

    /**
     * @brief operator == Sobrecarga del operador ==
     * @param pPixel Objeto Pixel con el cual se comparará el pixel actual.
     * @return En caso de igualdad devuelve true, caso contrario devuelve false.
     */
    bool operator == (Pixel pPixel);

    /**
     * @brief operator - Sobrecarga del operador -
     * @param pPixel Objeto Pixel con el cual se efectuará la sustracción entre pixeles.
     * @return Devuelve el resultado de la sustracción entre pixeles, es decir, la resta.
     */
    Pixel operator - (Pixel pPixel);

    /**
     * @brief operator + Sobrecarga del operador +
     * @param pPixel Objeto Pixel con el cual se efectuará la adición de pixeles.
     * @return Devuelve el resultado de la adición entre pixeles, es decir, la suma.
     */
    Pixel operator + (Pixel pPixel);

    /**
     * @brief operator * Sobrecarga del operador *
     * @param pPixel Objeto Pixel con el cual se efectuará la multiplicación de pixeles.
     * @return Devuelve el resultado de la multiplicación entre pixeles, es decir, el producto.
     */
    Pixel operator* (Pixel pPixel);

    /**
     * @brief operator /  Sobreacrga del operador /
     * @param pPixel Objeto Pixel con el cual se efectuará la división de pixeles
     * @return Devuelve el resultado de la division de pixeles, es decir, el cociente.
     */
    Pixel operator / (Pixel pPixel);


    /**
     * @brief operator * Sobreacrga del operador *
     * @param valor Valor flotante con el que se efectuará la multiplicación.
     * @return Devuelve el resultado de la multiplicación entre el píxel y el valor, es decir, el producto.
     */
    Pixel operator * (float valor);

    bool operator < (Pixel pPixel);
};

#endif // PIXEL_H
