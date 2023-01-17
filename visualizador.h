#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <deque>
#include <iostream>

#include "imagen.h"

using namespace std;

class Visualizador : public QOpenGLWidget , protected QOpenGLFunctions
{
private:
    //deque <Imagen*> imagenes; //ver como usarlo
    int anchoVentana;
    int altoVentana;
    float escala;
    int desplazamientoX;
    int desplazamientoY;
    Imagen *imagen;
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
