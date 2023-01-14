#include "visualizador.h"

void Visualizador::setImagen(Imagen *pImagen)
{
    imagen = pImagen;
}

Visualizador::Visualizador()
{
    auxIndiceArchivo = 0;
}

Visualizador::Visualizador(Imagen *pImagen)
{
    auxIndiceArchivo = 0;
    imagen = pImagen;
}
unsigned int Visualizador::getAuxIndiceArchivo() const
{
    return auxIndiceArchivo;
}

void Visualizador::setAuxIndiceArchivo(unsigned int newAuxIndiceArchivo)
{
    auxIndiceArchivo = newAuxIndiceArchivo;
}


void Visualizador::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void Visualizador::resizeGL(int pAncho, int pAlto)
{
    update();
    anchoVentana = pAncho;
    altoVentana = pAlto;
}

void Visualizador::paintGL()
{
    setWindowTitle( "Sistema de Procesamiento Digital de Imágenes");

    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0,0, anchoVentana, altoVentana);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0, width(), 0, height(), -1, 1);

    cout<<"width: "<<width()<<" columnas:"<<altoVentana;
    cout<<" height:"<<height()<<" filas: "<<anchoVentana;


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    dibujarImagen();
}

void Visualizador::dibujarImagen()
{
    glPushMatrix();
    {
//        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);

    glScalef(0.5f,0.5f,0.50f);

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
