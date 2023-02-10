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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float escalaAncho = ((float)width())/imagen.getCantidadColumnas();
    float escalaAlto = ((float)height())/imagen.getCantidadFilas();

    if(imagen.getCantidadColumnas()!= 0 and imagen.getCantidadFilas() != 0)
    {
        imagen.setEstaAlterada(false);
    }

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

    if(imagen.getEstaAlterada())
    {
        setWindowTitle( "Sistema de Procesamiento Digital de Imágenes - IMAGEN ALTERADA");

        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }
    else
    {
        setWindowTitle( "Sistema de Procesamiento Digital de Imágenes");
        dibujarImagen();
    }
}

void Visualizador::dibujarImagen()
{
    glPushMatrix();
    {
        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);

        glScalef(escala,escala,1.0f);

        glBegin(GL_QUADS);

        int maximoValor;

        maximoValor = imagen.getMaximoValor();

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

void Visualizador::mostrar(QApplication *ptrApp)
{
    auxIndiceArchivo = 0;
    cargarImagen();
    resize(600,600);
    show();
    ptrApp -> exec();
}

void Visualizador::keyPressEvent(QKeyEvent *evento)
{
    EditorImagen editorImagen;
    Filtro *filtro;
    Pseudocoloreador pseudocoloreador;


    controlPresionada = evento->modifiers()&Qt::ControlModifier;
    flechaDerechaPresionada =  evento->key() == Qt::Key_Right;
    flechaIzquierdaPresionada = evento->key() == Qt::Key_Left;
    hPresionada = evento->key() == Qt::Key_H;
    gPresionada = evento->key() == Qt::Key_G;
    unoPresionado = evento->key() == Qt::Key_1;
    dosPresionado = evento->key() == Qt::Key_2;
    nPresionada = evento->key() == Qt::Key_N;
    mPresionada = evento->key() == Qt::Key_M;
    lPresionada = evento->key() == Qt::Key_L;
    sPresionada = evento->key() == Qt::Key_S;
    cPresionada = evento->key() == Qt::Key_C;
    bPresionada = evento->key() == Qt::Key_B;
    masPresionada = evento->key() == Qt::Key_Plus;
    menosPresionada = evento->key() == Qt::Key_Minus;

    //-------------------------------------------------

    if(controlPresionada and flechaDerechaPresionada )
    {
        auxIndiceArchivo++;
        cargarImagen();
        controlPresionada = false;
    }

    if(controlPresionada and flechaIzquierdaPresionada)
    {
        auxIndiceArchivo--;
        cargarImagen();
        controlPresionada = false;
    }

    if(!imagen.getEstaAlterada())
    {

        if(controlPresionada and bPresionada)
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("B");
            editorImagen.binarizarImagen(imagen, interfaz->getUmbralBinarizacion());
        }

        if(controlPresionada and cPresionada)
        {
            interfaz->atajosDeTeclado();
            procesadorEstadistico.setImagen(&imagen);
            interfaz->opcionAtajo("C");
            editorImagen.ajustarContraste(imagen, procesadorEstadistico.getMaximo(), procesadorEstadistico.getMinimo());
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

            archivo->guardarImagen(imagen, tipoArchivo, auxNombre);

            interfaz->imagenGuardada(carpeta, nombre, tipoArchivo);

        }

        if(controlPresionada and hPresionada)
        {
            procesadorEstadistico.setImagen(&imagen);
            visualizadorHistograma.mostrar(&imagen, &procesadorEstadistico);
            interfaz->opcionAtajo("H");
            interfaz->mostrarEstadisticos(procesadorEstadistico.getMaximo(), procesadorEstadistico.getMinimo(), procesadorEstadistico.getMedia(), procesadorEstadistico.getDesvioEstandar(),procesadorEstadistico.getModa());
        }

        if(controlPresionada and lPresionada)
        {
            interfaz->atajosDeTeclado();
            cargarImagen();
            interfaz->opcionAtajo("L");
        }

        if(controlPresionada and mPresionada)
        {
            filtro = new FiltroMediana;
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("M");
            filtro->aplicarFiltro(imagen);
        }

        if(controlPresionada and nPresionada)
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("N");
            editorImagen.negativizarImagen(imagen);
        }

        if(controlPresionada and qPresionada)
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("Q");
        }

        if(controlPresionada and sPresionada)
        {
            filtro = new FiltroPasaBajos;
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("S");
            filtro->aplicarFiltro(imagen);
        }

        if(controlPresionada and menosPresionada )
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("-");
            lower();
            editorImagen.disminuirBrillo(imagen, interfaz->disminucionBrillo());
            activateWindow();
            raise();
        }

        if(controlPresionada and masPresionada)
        {
            interfaz->atajosDeTeclado();
            interfaz->opcionAtajo("+");
            lower();
            editorImagen.aumentarBrillo(imagen, interfaz->aumentoBrillo());
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
                pseudocoloreador.colorearImagen(imagen);
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
                pseudocoloreador.colorearImagen(imagen);
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
    }

    if(controlPresionada and imagen.getEstaAlterada())
    {
        interfaz->atajosDeTeclado();
        interfaz->errorImagenAlterada();
    }

    update();
}

void Visualizador::mousePressEvent(QMouseEvent *evento)
{
    clickIzquierdoPresionadoandControl = evento->modifiers()&Qt::ControlModifier and evento->button() == Qt::LeftButton;

    if(clickIzquierdoPresionadoandControl == true and !imagen.getEstaAlterada())
    {
        posicionInicialX = ( evento->x() - desplazamientoX )/ escala;
        posicionInicialY = ( evento->y() - desplazamientoY )/escala;
    }

    clickIzquierdoPresionadoandControl = false;
}

void Visualizador::mouseReleaseEvent(QMouseEvent *evento)
{
    DetectorArea detectorArea;
    clickIzquierdoOff = evento->modifiers()&Qt::ControlModifier and evento->button() == Qt::LeftButton;

    if(clickIzquierdoOff and !imagen.getEstaAlterada() and imagen.getTipoImagen() != "Monocromatica")
    {
        cargarImagen();
        update();
        interfaz->opcionAtajo("click izquierdo");
        detectorArea.detectarArea(&imagen, posicionInicialX, posicionInicialY);
        int area = detectorArea.getAreaTotal();
        interfaz->comunicarArea(area);
        repaint();
    }
    if(clickIzquierdoOff and imagen.getEstaAlterada())
    {
        interfaz->atajosDeTeclado();
        interfaz->errorImagenAlterada();
    }

    if(clickIzquierdoOff and imagen.getTipoImagen() == "Monocromatica")
    {
        interfaz->errorTipoImagen(imagen.getTipoImagen());
    }

    update();
}

void Visualizador::cargarImagen()
{

    interfaz->atajosDeTeclado();

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

    if(auxiliarTipo == "P1" or auxiliarTipo == "P2" or auxiliarTipo == "P3" or auxiliarTipo == "P4" or auxiliarTipo == "P5" or auxiliarTipo == "P6")
    {
        archivo = new ArchivoPNM;
    }
    else
    {
        archivo = new ArchivoAIC;
    }

    archivo->leerArchivoImagen(listaArchivosImagen[auxIndiceArchivo], imagen);

    remove("./ultima_imagen_visualizada/ultimaImagen.aic");
    remove("./ultima_imagen_visualizada/ultimaImagen.ppm");
    remove("./ultima_imagen_visualizada/ultimaImagen.pgm");
    remove("./ultima_imagen_visualizada/ultimaImagen.pbm");

    archivo->guardarImagen(imagen, archivo->devolverTipo(), "./ultima_imagen_visualizada/ultimaImagen");

    delete archivo;
}

Visualizador::~Visualizador()
{
    visualizadorHistograma.~VisualizadorHistograma();
}
