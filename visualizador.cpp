#include "visualizador.h"


void Visualizador::keyPressEvent(QKeyEvent *evento)
{

}

void Visualizador::wheelEvent(QWheelEvent *evento)
{

}

void Visualizador::mostrar(Imagen *pImagen)
{
    imagen = pImagen;
    resize(600,600);
    show();
}

void Visualizador::setAuxIndiceArchivo(int newAuxIndiceArchivo)
{
    auxIndiceArchivo = newAuxIndiceArchivo;
}

void Visualizador::setVisualizadorHistograma(VisualizadorHistograma *pVisualizadorHistograma)
{
    visualizadorHistograma = pVisualizadorHistograma;
}

Visualizador::Visualizador()
{
    auxIndiceArchivo = 0;
}

unsigned int Visualizador::getAuxIndiceArchivo() const
{
    return auxIndiceArchivo;
}


void Visualizador::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void Visualizador::resizeGL(int pAncho, int pAlto)
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

void Visualizador::paintGL()
{
    setWindowTitle( "Sistema de Procesamiento Digital de Imágenes");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float escalaAncho = ((float)width())/imagen->getCantidadColumnas();
    float escalaAlto = ((float)height())/imagen->getCantidadFilas();

    escala = 1.0f;
    desplazamientoX = 0.0f;
    desplazamientoY = 0.0f;

    if(escalaAncho < escalaAlto)
    {
        escala = escalaAncho;
        desplazamientoY = ((height() - (float) imagen->getCantidadFilas() * escala) * 0.5f);
    }
    else
    {
        escala = escalaAlto;
        desplazamientoX = ((width() - (float) imagen->getCantidadColumnas()* escala) * 0.5f);

    }

    dibujarImagen();

    visualizadorHistograma->mostrar(imagen);
}

void Visualizador::dibujarImagen()
{
    glPushMatrix();
    {
        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);

        glScalef(escala,escala,1.0f);

        glBegin(GL_QUADS);

        for(int fila = 0; fila<imagen->getCantidadFilas();++fila)
        {
            for(int columna = 0; columna<imagen->getCantidadColumnas();++columna)
            {
                glColor3f(imagen->getPrimerComponente(columna, fila)/255.0,imagen->getSegundaComponente(columna, fila)/255.0,imagen->getTercerComponente(columna, fila)/255.0);
                glVertex2i(columna,imagen->getCantidadFilas()-fila);
                glVertex2i(columna,imagen->getCantidadFilas()-(fila+1));
                glVertex2i(columna+1,imagen->getCantidadFilas()-(fila+1));
                glVertex2i(columna+1,imagen->getCantidadFilas()-fila);
            }
        }

        glEnd();
    }
    glPopMatrix();
}

Visualizador::~Visualizador()
{

}
