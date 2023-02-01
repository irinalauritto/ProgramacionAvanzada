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

    vector<float> primerosValores = procesadorEstadistico->getPrimerosValores();
    vector<float> segundosValores = procesadorEstadistico->getSegundosValores();
    vector<float> tercerosValores = procesadorEstadistico->getTercerosValores();
    vector<float> valoresPromedio = procesadorEstadistico->getValoresPromedio();

    glScalef((width()*1.0f)/256.0f, (height()*1.0f)/(procesadorEstadistico->getRepeticionValorMasFrecuente()*1.0f), 0.0f);

    glPushMatrix();
    {
        for(unsigned int i = 0; i < valoresPromedio.size();i++)
        {
            glBegin(GL_QUADS);
            {
                glColor3f(0.5f,0.5f,0.5f);
                glVertex2i(i,0);
                glVertex2i(i, valoresPromedio[i]);
                glVertex2i(i+1,valoresPromedio[i+1]);
                glVertex2i(i+1,0);
            }
            glEnd();
        }

        if(imagen->getTipoImagen() == "RGB")
        {
            for(unsigned int i = 0; i < primerosValores.size(); i++)
            {
                glBegin(GL_LINE_STRIP);
                {
                    glColor3f(1.0f,0.0f,0.0f);
                    glVertex2i(i, primerosValores[i]);
                    glVertex2i(i+1,primerosValores[i+1]);
                }
                glEnd();
            }

            for(unsigned int i = 0; i < segundosValores.size(); i++)
            {
                glBegin(GL_LINE_STRIP);
                {
                    glColor3f(0.0f,1.0f,0.0f);
                    glVertex2i(i, segundosValores[i]);
                    glVertex2i(i+1,segundosValores[i+1]);
                }
                glEnd();
            }
            for(unsigned int i = 0; i < tercerosValores.size(); i++)
            {
                glBegin(GL_LINE_STRIP);
                {
                    glColor3f(0.0f,0.0f,1.0f);
                    glVertex2i(i, tercerosValores[i]);
                    glVertex2i(i+1, tercerosValores[i+1]);
                }
                glEnd();
            }

        }
    }
    glPopMatrix();

    cout<<"se mostro el histograma. "<<endl;
}


void VisualizadorHistograma::mostrar(Imagen *pImagen, ProcesadorEstadistico *pProcesadorEstadistico)
{
    imagen = pImagen;
    procesadorEstadistico = pProcesadorEstadistico;
    resize(400,400);
    show();
}

VisualizadorHistograma::~VisualizadorHistograma()
{

}
