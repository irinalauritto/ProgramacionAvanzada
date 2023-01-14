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
    int posicionInicialX;
    int posicionInicialY;
    int escala;
    int relacionAspectoAncho;
    int relacionAspectoAlto;
    int desplazamientoX;
    int desplazamientoY;
    Imagen *imagen;
    int auxIndiceArchivo; //controla la imagen que vemos

public:
    Visualizador();
    Visualizador(Imagen *pImagen);
    void initializeGL() override;
    void resizeGL(int pAncho, int pAlto) override;
    void paintGL() override;
    //void keyPressEvent(QKeyEvent*evento) override;
    //void wheelEvent(QWheelEvent*evento) override;
    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
    void dibujarImagen();
    // ~Visualizador();
    unsigned int getAuxIndiceArchivo() const;
    void setAuxIndiceArchivo(unsigned int newAuxIndiceArchivo);
    void setImagen(Imagen *newImagen);
};

#endif // VISUALIZADOR_H
