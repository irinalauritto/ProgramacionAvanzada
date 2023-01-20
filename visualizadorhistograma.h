#ifndef VISUALIZADORHISTOGRAMA_H
#define VISUALIZADORHISTOGRAMA_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "imagen.h"

/**
 * @brief The VisualizadorHistograma class
 */
class VisualizadorHistograma : public QOpenGLWidget , protected QOpenGLFunctions
{
private:

    /**
     * @brief anchoVentana
     */
    int anchoVentana;

    /**
     * @brief altoVentana
     */
    int altoVentana;

    /**
     * @brief imagen
     */
    Imagen *imagen;
public:

    /**
     * @brief VisualizadorHistograma
     */
    VisualizadorHistograma();

    /**
     * @brief initializeGL
     */
    void initializeGL() override;

    /**
     * @brief resizeGL
     * @param pAncho
     * @param pAlto
     */
    void resizeGL(int pAncho, int pAlto) override;

    /**
     * @brief paintGL
     */
    void paintGL() override;

    /**
     * @brief dibujarHistograma
     */
    void  dibujarHistograma();

    /**
     * @brief mostrar
     * @param pImagen
     */
    void mostrar(Imagen *pImagen);

    ~VisualizadorHistograma();

};

#endif // VISUALIZADORHISTOGRAMA_H
