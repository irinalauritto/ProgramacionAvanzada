#ifndef VISUALIZADORHISTOGRAMA_H
#define VISUALIZADORHISTOGRAMA_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <vector>
#include <iostream>

#include "procesadorestadistico.h"
#include "imagen.h"

using namespace std;

/**
 * @brief VisualizadorHistograma clase concreta que permite la obtencion y graficacion del histograma de una imagen.
 * @author Irina Esmeralda Lauritto
 */
class VisualizadorHistograma : public QOpenGLWidget , protected QOpenGLFunctions
{
private:

    int anchoVentana; /**< Ancho de la ventana de graficación. */

    int altoVentana; /**< Alto de la ventana de graficación. */

    Imagen *ptrImagen; /**< Puntero a la imagen de estudio. */

    ProcesadorEstadistico *ptrProcesadorEstadistico; /**< Puntero al procesador estadístico que devolverá los datos de la imagen. */

    vector<int> primerasComponentes, /**< Vector en el cual se copian los valores de las primeras componentes [r] obtenidos por el procesadorEstadistico. */

    segundasComponentes, /**< Vector en el cual se copian los valores de las segundas componentes [g] obtenidos por el procesadorEstadistico. */

    tercerasComponentes, /**< Vector en el cual se copian los valores de las terceras componentes [b] obtenidos por el procesadorEstadistico. */

    promedioComponentes; /**< Vector en el cual se copian los valores promedio de las  componentes [promedio de intensidades] obtenidos por el procesadorEstadistico. */

    /**
     * @brief initializeGL Método que permite inicializar la ventana de graficación.
     */
    void initializeGL() override;

    /**
     * @brief resizeGL Método que permite modificar el tamaño de la ventana de graficación.
     * @param pAncho Nuevo valor de ancho de la ventana.
     * @param pAlto Nuevo valor de alto de la ventana.
     */
    void resizeGL(int pAncho, int pAlto) override;

    /**
     * @brief paintGL Método que permite pintar en la ventana de graficación.
     */
    void paintGL() override;

    /**
     * @brief dibujarHistograma Método que permite dibujar el histograma.
     */
    void  dibujarHistograma();


public:

    /**
     * @brief VisualizadorHistograma Constructor de la clase.
     */
    VisualizadorHistograma();

    /**
     * @brief mostrar Método que permite la visualización del histograma y que a su vez setea la imagen sobre la que se trabaja.
     * @param pImagen
     */
    void mostrar(Imagen *pImagen, ProcesadorEstadistico *pProcesadorEstadistico);

    /**
     * @brief ~VisualizadorHistograma Destructor de la clase.
     */
    ~VisualizadorHistograma();

};

#endif // VISUALIZADORHISTOGRAMA_H
