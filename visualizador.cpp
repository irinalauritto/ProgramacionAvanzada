#include "visualizador.h"

Visualizador::Visualizador()
{
    auxIndiceArchivo = (1);
}

void Visualizador::setAuxIndiceArchivo(int newAuxIndiceArchivo)
{
    auxIndiceArchivo = newAuxIndiceArchivo;

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

    float xMin = -5.0f, xMax = anchoVentana + 5.0f, yMin = -5.0f, yMax = altoVentana + 5.0f;

    glOrtho(xMin, xMax, yMin, yMax, -1, 1);

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
}

void Visualizador::dibujarImagen()
{
    glPushMatrix();
    {
        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);

        glScalef(escala,escala,1.0f);

        glBegin(GL_QUADS);

        int maximoValor;

        if(imagen->getMaximoValor() != 0)
        {
            maximoValor = imagen->getMaximoValor();
        }
        else
        {
            maximoValor = 1;
        }

        for(int fila = 0; fila<imagen->getCantidadFilas();++fila)
        {
            for(int columna = 0; columna<imagen->getCantidadColumnas();++columna)
            {
                glColor3f(imagen->getPrimerComponente(columna, fila)/(float)maximoValor,imagen->getSegundaComponente(columna, fila)/(float)maximoValor,imagen->getTercerComponente(columna, fila)/(float)maximoValor);
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

void Visualizador::mostrar(Imagen *pImagen)
{
    imagen = pImagen;
    resize(600,600);
    show();
}

void Visualizador::keyPressEvent(QKeyEvent *evento)
{

}

void Visualizador::wheelEvent(QWheelEvent *evento)
{

}

Visualizador::~Visualizador()
{

}
