#include "visualizador.h"


Visualizador::Visualizador()
{
    auxIndiceArchivo = 0;
}

void Visualizador::setListaArchivosImagen(const vector<string> &pListaArchivosImagen)
{
    listaArchivosImagen = pListaArchivosImagen;
}

void Visualizador::setListaArchivosLUT(const vector<string> &pListaArchivosLUT)
{
    listaArchivosLUT = pListaArchivosLUT;
}
void Visualizador::setInterfaz(InterfazDeUsuario *newInterfaz)
{
    interfaz = newInterfaz;
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

    float escalaAncho = ((float)width())/imagen.getCantidadColumnas();
    float escalaAlto = ((float)height())/imagen.getCantidadFilas();

    escala = 1.0f;
    desplazamientoX = 0.0f;
    desplazamientoY = 0.0f;

    if(escalaAncho < escalaAlto)
    {
        escala = escalaAncho;
        desplazamientoY = ((height() - (float) imagen.getCantidadFilas() * escala) * 0.5f);
    }
    else
    {
        escala = escalaAlto;
        desplazamientoX = ((width() - (float) imagen.getCantidadColumnas()* escala) * 0.5f);

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

        if(imagen.getMaximoValor() != 0)
        {
            maximoValor = imagen.getMaximoValor();
        }
        else
        {
            maximoValor = 1;
        }

        for(int fila = 0; fila<imagen.getCantidadFilas();++fila)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas();++columna)
            {
                glColor3f(imagen.getPrimerComponente(columna, fila)/(float)maximoValor,imagen.getSegundaComponente(columna, fila)/(float)maximoValor,imagen.getTercerComponente(columna, fila)/(float)maximoValor);
                glVertex2i(columna,imagen.getCantidadFilas()-fila);
                glVertex2i(columna,imagen.getCantidadFilas()-(fila+1));
                glVertex2i(columna+1,imagen.getCantidadFilas()-(fila+1));
                glVertex2i(columna+1,imagen.getCantidadFilas()-fila);
            }
        }

        glEnd();
    }
    glPopMatrix();
}

void Visualizador::mostrar()
{
    resize(600,600);
    show();
}

void Visualizador::keyPressEvent(QKeyEvent *evento)
{
    EditorImagen editorImagen;
    FiltroMediana filtroMediana;
    FiltroPasaBajos filtroSuavizado;
    Pseudocoloreador pseudocoloreador;
    ProcesadorEstadistico procesadorEstadistico;
    VisualizadorHistograma visualizadorHistograma;

    if(evento->key() == Qt::Key_Control)
    {
        controlPresionada = true;
    }

    if(evento->key() == Qt::Key_Right)
    {
        flechaDerechaPresionada = true;
    }

    if(evento->key() == Qt::Key_Left)
    {
        flechaIzquierdaPresionada = true;
    }

    if(evento->key() == Qt::Key_B)
    {
        bPresionada = true;
    }

    if(evento->key() == Qt::Key_C)
    {
        cPresionada = true;
    }

    if(evento->key() == Qt::Key_G)
    {
        gPresionada = true;
    }

    if(evento->key() == Qt::Key_H)
    {
        hPresionada = true;
    }

    if(evento->key() == Qt::Key_M)
    {
        mPresionada = true;
    }

    if(evento->key() == Qt::Key_N)
    {
        nPresionada = true;
    }

    if(evento->key() == Qt::Key_Q)
    {
        qPresionada = true;
    }

    if(evento->key() == Qt::Key_S)
    {
        sPresionada = true;
    }

    if(evento->key() == Qt::Key_Minus)
    {
        menosPresionada = true;
    }

    if(evento->key() == Qt::Key_Plus)
    {
        masPresionada = true;
    }

    if(evento->key() == Qt::Key_1)
    {
        unoPresionado = true;
    }

    if(evento->key() == Qt::Key_2)
    {
        dosPresionado = true;
    }

    if(evento->key() == Qt::Key_Escape)
    {
        escapePresionada = true;
    }


    //-------------------------------------------------


    if(controlPresionada and flechaDerechaPresionada)
    {
        auxIndiceArchivo++;
        cargarImagen();
    }

    if(controlPresionada and flechaIzquierdaPresionada)
    {
        auxIndiceArchivo--;
        cargarImagen();
    }

    if(controlPresionada and bPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("B");
        editorImagen.binarizarImagen(&imagen, interfaz->getUmbralBinarizacion());
    }

    if(controlPresionada and cPresionada)
    {
        interfaz->atajosDeTeclado();
        procesadorEstadistico.setImagen(&imagen);
        interfaz->opcionAtajo("C");
        editorImagen.ajustarContraste(&imagen, procesadorEstadistico.getMaximo(), procesadorEstadistico.getMinimo());
    }

    if(controlPresionada and gPresionada)
    {
        interfaz->atajosDeTeclado();
        string nombre, tipoArchivo;
        string tipoImagen = imagen.getTipoImagen();

        interfaz->opcionAtajo("G");
        interfaz->guardarImagen(tipoArchivo, nombre, tipoImagen);

        Archivo *archivo;

        if(tipoArchivo == "P1" or tipoArchivo == "P2" or tipoArchivo == "P3" or tipoArchivo == "P4" or tipoArchivo == "P5" or tipoArchivo  == "P6")
        {
            archivo = new ArchivoPNM;
        }
        else
        {
            archivo = new ArchivoAIC;
        }

        string auxNombre, carpeta;
        carpeta = "./grupo_imagenes_modificadas/";
        auxNombre = "./grupo_imagenes_modificadas/" + nombre;

        archivo->guardarImagen(&imagen, tipoArchivo, auxNombre);

        interfaz->imagenGuardada(carpeta, nombre, tipoArchivo);

    }

    if(controlPresionada and hPresionada)
    {
        procesadorEstadistico.setImagen(&imagen);
//        visualizadorHistograma.mostrar(&imagen, &procesadorEstadistico);
        interfaz->opcionAtajo("H");
        interfaz->mostrarEstadisticos(procesadorEstadistico.getMaximo(), procesadorEstadistico.getMinimo(), procesadorEstadistico.getMedia(), procesadorEstadistico.getDesvioEstandar(),procesadorEstadistico.getModa());
    }

    if(controlPresionada and mPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("M");
        filtroMediana.aplicarFiltro(&imagen);

    }

    if(controlPresionada and nPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("N");
        editorImagen.negativizarImagen(&imagen);
    }

    if(controlPresionada and qPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("Q");
    }

    if(controlPresionada and sPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("S");
        filtroSuavizado.aplicarFiltro(&imagen);
    }

    if(controlPresionada and menosPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("-");
        lower();
        editorImagen.disminuirBrillo(&imagen, interfaz->disminucionBrillo());
        activateWindow();
        raise();
    }

    if(controlPresionada and masPresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("+");
        lower();
        editorImagen.aumentarBrillo(&imagen, interfaz->aumentoBrillo());
        activateWindow();
        raise();
    }

    if(controlPresionada and unoPresionado)
    {
        if(imagen.getTipoImagen() == "Intensidades" or imagen.getTipoImagen() == "IntensidadesC")
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("1");
            pseudocoloreador.leerArchivoLUT(listaArchivosLUT[0]);
            pseudocoloreador.colorearImagen(&imagen);
        }
        else
        {
            interfaz->errorTipoImagen(imagen.getTipoImagen());
        }
    }

    if(controlPresionada and dosPresionado)
    {

        if(imagen.getTipoImagen() == "Intensidades" or imagen.getTipoImagen() == "IntensidadesC")
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("2");
            pseudocoloreador.leerArchivoLUT(listaArchivosLUT[1]);
            pseudocoloreador.colorearImagen(&imagen);
        }
        else
        {
            interfaz->errorTipoImagen(imagen.getTipoImagen());
        }
    }

    if(escapePresionada)
    {
        interfaz->atajosDeTeclado();
        interfaz->opcionAtajo("escape");
        exit(0);
    }

    repaint();
}

void Visualizador::mousePressEvent(QMouseEvent *evento)
{
    clickIzquierdoPresionadoandControl = evento->modifiers()&Qt::ControlModifier and evento->button() == Qt::LeftButton;

    if(clickIzquierdoPresionadoandControl == true)
    {
        posicionInicialX = evento->x();
        posicionInicialY = evento->y();
    }

    clickIzquierdoPresionadoandControl = false;
}



void Visualizador::keyReleaseEvent(QKeyEvent *evento)
{

    if(evento->key() == Qt::Key_Control)
    {
        controlPresionada = false;
    }

    if(evento->key() == Qt::Key_Left)
    {
        flechaIzquierdaPresionada = false;
    }

    if(evento->key() == Qt::Key_Right)
    {
        flechaDerechaPresionada = false;
    }

    if(evento->key() == Qt::Key_B)
    {
        bPresionada = false;
    }

    if(evento->key() == Qt::Key_C)
    {
        cPresionada = false;
    }

    if(evento->key() == Qt::Key_G)
    {
        gPresionada = false;
    }

    if(evento->key() == Qt::Key_H)
    {
        hPresionada = false;
    }

    if(evento->key() == Qt::Key_M)
    {
        mPresionada = false;
    }

    if(evento->key() == Qt::Key_N)
    {
        nPresionada = false;
    }

    if(evento->key() == Qt::Key_Q)
    {
        qPresionada = false;
    }

    if(evento->key() == Qt::Key_S)
    {
        sPresionada = false;
    }

    if(evento->key() == Qt::Key_Minus)
    {
        menosPresionada = false;
    }

    if(evento->key() == Qt::Key_Plus)
    {
        masPresionada = false;
    }

    if(evento->key() == Qt::Key_1)
    {
        unoPresionado = false;
    }

    if(evento->key() == Qt::Key_2)
    {
        dosPresionado = false;
    }

    if(evento->key() == Qt::Key_Escape)
    {
        escapePresionada = false;
    }

}

void Visualizador::mouseReleaseEvent(QMouseEvent *evento)
{
    clickIzquierdoOff = evento->modifiers()&Qt::ControlModifier and evento->button() == Qt::LeftButton;

    DetectorArea detectorArea;
    if(clickIzquierdoOff)
    {
        interfaz->opcionAtajo("click izquierdo");
        detectorArea.detectarArea(&imagen, posicionInicialX, posicionInicialY);
        int area = detectorArea.getAreaTotal();
        interfaz->comunicarArea(area);
        repaint();
    }

}

void Visualizador::cargarImagen()
{

    interfaz->atajosDeTeclado();
    imagen.setMaximoValor(0);

    //Se verifica que el índice de la variable auxiliar que posee el visulizador, para permitir el uso de atajos de teclado, se halle en el rango correcto
    if(auxIndiceArchivo == -1)
    {
        auxIndiceArchivo = listaArchivosImagen.size() - 1;
    }
    else if((unsigned int)auxIndiceArchivo >= listaArchivosImagen.size())
    {
        auxIndiceArchivo = 0;
    }

    Archivo *archivo;

    fstream auxiliarArchivo;
    string auxiliarTipo;

    auxiliarArchivo.open(listaArchivosImagen[auxIndiceArchivo]);
    getline(auxiliarArchivo, auxiliarTipo, '\n');

    //POLIMORFISMO
    if(auxiliarTipo == "P1" or auxiliarTipo == "P2" or auxiliarTipo == "P3" or auxiliarTipo == "P4" or auxiliarTipo == "P5" or auxiliarTipo == "P6")
    {
        archivo = new ArchivoPNM;
    }
    else
    {
        archivo = new ArchivoAIC;
    }

    archivo->leerArchivoImagen(listaArchivosImagen[auxIndiceArchivo], &imagen);

    remove("./ultima_imagen_visualizada/ultimaImagen.aic");
    remove("./ultima_imagen_visualizada/ultimaImagen.ppm");
    remove("./ultima_imagen_visualizada/ultimaImagen.pgm");
    remove("./ultima_imagen_visualizada/ultimaImagen.pbm");

    archivo->guardarImagen(&imagen, archivo->devolverTipo(), "./ultima_imagen_visualizada/ultimaImagen");

    delete archivo;
}

Visualizador::~Visualizador()
{

}
