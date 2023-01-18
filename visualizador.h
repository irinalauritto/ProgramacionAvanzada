#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "imagen.h"
#include "visualizadorhistograma.h"

/**
 * @brief The Visualizador class
 */
class Visualizador : public QOpenGLWidget , protected QOpenGLFunctions
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
     * @brief escala
     */
    float escala;

    /**
     * @brief desplazamientoX
     */
    int desplazamientoX;

    /**
     * @brief desplazamientoY
     */
    int desplazamientoY;

    /**
     * @brief imagen
     */
    Imagen *imagen;

    /**
     * @brief auxIndiceArchivo
     */
    int auxIndiceArchivo; //controla la imagen que vemos

    /**
     * @brief visualizadorHistograma
     */
    VisualizadorHistograma *visualizadorHistograma;

public:

    /**
     * @brief Visualizador
     */
    Visualizador();

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
     * @brief keyPressEvent
     * @param evento
     */
    void keyPressEvent(QKeyEvent*evento) override;

    /**
     * @brief wheelEvent
     * @param evento
     */
    void wheelEvent(QWheelEvent*evento) override;

    /**
     * @brief mostrar
     * @param pImagen
     */
    void mostrar(Imagen *pImagen);

    /**
     * @brief dibujarImagen
     */
    void dibujarImagen();

    /**
     * @brief getAuxIndiceArchivo
     * @return
     */
    unsigned int getAuxIndiceArchivo() const;

    /**
     * @brief setVisualizadorHistograma
     * @param pVisualizadorHistograma
     */
    void setVisualizadorHistograma(VisualizadorHistograma *pVisualizadorHistograma);

    /**
     * @brief setAuxIndiceArchivo
     * @param newAuxIndiceArchivo
     */
    void setAuxIndiceArchivo(int newAuxIndiceArchivo);

    ~Visualizador();
};

#endif // VISUALIZADOR_H
