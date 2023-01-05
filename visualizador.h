#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <deque>

#include "imagen.h"

using namespace std;

class Visualizador : public QOpenGLWidget , protected QOpenGLFunctions
{
private:
    deque <Imagen*> imagenes;
    int ancho;
    int alto;
    int auxIndiceArchivo; //controla la imagen que vemos

public:
    Visualizador();
    //void initializeGL() override;
    //void resizeGL(int pAncho, int pAlto) override;
    //void paintGL() override;
    //void keyPressEvent(QKeyEvent*evento) override;
    //void wheelEvent(QWheelEvent*evento) override;
    void mostrar(int pAncho, int pAlto, QApplication *pPtrApp);
    void dibujarImagen(Imagen &i);
    // ~Visualizador();
    unsigned int getAuxIndiceArchivo() const;
    void setAuxIndiceArchivo(unsigned int newAuxIndiceArchivo);
};

#endif // VISUALIZADOR_H
