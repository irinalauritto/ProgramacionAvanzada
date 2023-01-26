#include "visualizadorhistograma.h"

VisualizadorHistograma::VisualizadorHistograma()
{

}

void VisualizadorHistograma::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void VisualizadorHistograma::resizeGL(int pAncho, int pAlto)
{
    anchoVentana = pAncho;
    altoVentana = pAlto;

    glViewport(0,0, anchoVentana, altoVentana);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, anchoVentana, 0 , altoVentana, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void VisualizadorHistograma::paintGL()
{
    setWindowTitle("Histograma");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    dibujarHistograma();
}

void VisualizadorHistograma::dibujarHistograma()
{
//    string tipoImagen = imagen->getTipoImagen();

//    if(tipoImagen == "monocromática")
//    {

//    }

//    if(tipoImagen == "intensidades")
//    {

//    }

//    if (tipoImagen == "RGB")
//    {

//    }

}

void VisualizadorHistograma::mostrar(Imagen *pImagen)
{
    imagen = pImagen;
    resize(400,400);
    show();
}

VisualizadorHistograma::~VisualizadorHistograma()
{

}
