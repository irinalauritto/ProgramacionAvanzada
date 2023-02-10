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

    if(ptrImagen->getTipoImagen() == "Monocromatica")
    {
        glOrtho(-50, anchoVentana +50, 0 , altoVentana , -1, 1);
    }
    else
    {
        glOrtho(-5, anchoVentana +5, 0 , altoVentana , -1, 1);
    }

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
    primerasComponentes = ptrProcesadorEstadistico->getPrimerosValores();
    segundasComponentes = ptrProcesadorEstadistico->getSegundosValores();
    tercerasComponentes = ptrProcesadorEstadistico->getTercerosValores();
    promedioComponentes = ptrProcesadorEstadistico->getValoresPromedio();


    glLineWidth(1.5f);

    float escalaX = (width()*1.0f)/(ptrImagen->getMaximoValor()+5)*1.0f;
    float escalaY = (height()*1.0f)/(ptrProcesadorEstadistico->getRepeticionValorMasFrecuente()*1.0f);

    if(ptrImagen->getTipoImagen() == "Intensidades" or ptrImagen->getTipoImagen() =="IntensidadesC" or ptrImagen->getTipoImagen() == "Monocromatica")
    {
        if(ptrImagen->getTipoImagen() == "Monocromatica")
        {
            escalaX = width()*1.0f/ptrImagen->getMaximoValor()*1.0f;
            glLineWidth(4.5f);
        }

        glPushMatrix();
        {
            for(unsigned int i = 0; i < (promedioComponentes.size());i++)
            {
                glBegin(GL_LINES);
                {
                    glColor3f(0.3f,0.3f,0.3f);
                    glVertex2i(i * escalaX,0);
                    glVertex2i(i * escalaX, promedioComponentes[i] * escalaY);
                }
                glEnd();
            }
        }
        glPopMatrix();
    }

    else
    {
        glPushMatrix();
        {
            for(unsigned int i = 0; i <  primerasComponentes.size(); i++)
            {
                glBegin(GL_LINES);
                {
                    glColor3f(1.0f,0.0f,0.0f);
                    glVertex2i((i -0.3) * escalaX,0);
                    glVertex2i((i -0.3)* escalaX, primerasComponentes[i]* escalaY);
                }
                glEnd();
            }

            for(unsigned int i = 0; i <  segundasComponentes.size(); i++)
            {
                glBegin(GL_LINES);
                {
                    glColor3f(0.0f,1.0f,0.0f);
                    glVertex2i(i * escalaX,0);
                    glVertex2i(i * escalaX, segundasComponentes[i]* escalaY);
                }
                glEnd();
            }


            for(unsigned int i = 0; i <  tercerasComponentes.size(); i++)
            {
                glBegin(GL_LINES);
                {
                    glColor3f(0.0f,0.0f,1.0f);
                    glVertex2i((i + 0.3)* escalaX,0);
                    glVertex2i((i + 0.3) * escalaX, tercerasComponentes[i]* escalaY);
                }
                glEnd();
            }
        }
        glPopMatrix();
    }

    primerasComponentes.clear();
    tercerasComponentes.clear();
    segundasComponentes.clear();
    promedioComponentes.clear();
}


void VisualizadorHistograma::mostrar(Imagen *pImagen, ProcesadorEstadistico *pProcesadorEstadistico)
{
    ptrImagen = pImagen;
    ptrProcesadorEstadistico = pProcesadorEstadistico;
    ptrProcesadorEstadistico->setValores();
    resize(900,500);
    this->show();
}

VisualizadorHistograma::~VisualizadorHistograma()
{

}
