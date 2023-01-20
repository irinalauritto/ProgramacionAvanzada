#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "imagen.h"

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

public:
    Visualizador();

    void initializeGL() override;

    void resizeGL(int pAncho, int pAlto) override;

    void paintGL() override;

    void keyPressEvent(QKeyEvent*evento) override;

    void wheelEvent(QWheelEvent*evento) override;

    void mostrar(Imagen *pImagen);

    void dibujarImagen();

    unsigned int getAuxIndiceArchivo() const;

    void setAuxIndiceArchivo(int newAuxIndiceArchivo);

    ~Visualizador();
};

#endif // VISUALIZADOR_H
