#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QApplication>


#include "imagen.h"
#include "archivo.h"
#include "archivoaic.h"
#include "archivopnm.h"
#include "detectorarea.h"
#include "editorimagen.h"
#include "filtro.h"
#include "filtromediana.h"
#include "filtropasabajos.h"
#include "interfazdeusuario.h"
#include "procesadorestadistico.h"
#include "pseudocoloreador.h"
#include "visualizadorhistograma.h"

/**
 * @brief Visualizador clase conreta que permite la visualización de las imágenes y cuya ventana gráfica responde a eventos.
 * @author Irina Esmeralda Lauritto
 */
class Visualizador : public QOpenGLWidget , protected QOpenGLFunctions
{
private:

    int anchoVentana; /**< Ancho de la ventana de graficación. */

    int altoVentana; /**< Alto de la ventana de graficación. */

    float escala; /**< Escala de la imagen respecto de la altura y el ancho de la ventana de gaficación. */

    int desplazamientoX; /**< Desplazamiento en el eje "x" de la imagen respecto de la ventana de graficación. */

    int desplazamientoY; /**< Desplazamiento en el eje "y" de la imagen respecto de la ventana de graficación. */

    int posicionInicialX; /**< Posición inicial en el eje "y". Utilizada para la llamada del detector de área. */

    int posicionInicialY; /**< Posición inicial en el eje "y". Utilizada para la llamada del detector de área. */

    Imagen imagen; /**< Imagen sobre la cual trabajamos. */

    InterfazDeUsuario *interfaz; /**< Puntero a interfaz de usuario. Este puntero objeto comunica al usuario  con esta clase del programa. */

    VisualizadorHistograma visualizadorHistograma; /**< Objeto que permite la visualización del histograma de la imagen actual. */

    ProcesadorEstadistico procesadorEstadistico; /**< Objeto que lleva  acabo el procesamiento estadísticos de los datos de la imagen actual. */

    int auxIndiceArchivo; /**< Atributo que permite modificar el archivo que se lee y, por consecuente, permite la visualización de una imagen distinta. */

    bool controlPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool flechaDerechaPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool flechaIzquierdaPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool clickIzquierdoPresionadoandControl = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool clickIzquierdoOff; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool unoPresionado = false;/**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool dosPresionado = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool aPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool bPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool cPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool gPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool lPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool mPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool nPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool qPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool sPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool menosPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool masPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool mostrarHistograma = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool escapePresionada = false;/**< Variable Booleana utilizadas en la respuesta a eventos. */

    bool hPresionada = false; /**< Variable Booleana utilizadas en la respuesta a eventos. */

    vector<string> listaArchivosImagen; /**< Lista que posee las rutas de los archivos de imagen. */

    vector<string> listaArchivosLUT; /**< Lista que posee las rutas de los archivos LUT. */

    /**
     * @brief initializeGL Método que permite inicializar la ventana de graficación.
     */
    void initializeGL() override;

    /**
     * @brief resizeGL Método que permite modificar el tamaño de la ventana de graficación.
     * @param pAncho Nuevo valor de ancho de la ventana.
     * @param pAlto Nuevo valor de alto de la ventana.
     */
    void resizeGL(int pAncho, int pAlto) override;

    /**
     * @brief paintGL Método que permite pintar en la ventana de graficación.
     */
    void paintGL() override;

    /**
     * @brief cargarImagen Método que permite la carga de la imagen.
     */
    void cargarImagen();

    /**
     * @brief dibujarImagen Método que permite dibujar la imagen.
     */
    void dibujarImagen();

public:

    /**
     * @brief Visualizador Constructor de la clase.
     */
    Visualizador();

    /**
     * @brief keyPressEvent Método que permite capturar eventos relacionados al teclado.
     * @param evento
     */
    void keyPressEvent(QKeyEvent *evento) override;

    /**
     * @brief mousePressEvent Método que permite capturar eventos relacionados al clic del mouse.
     * @param evento
     */
    void mousePressEvent(QMouseEvent *evento) override;

    /**
     * @brief mouseReleaseEvent Método que permite capturar eventos relacionados al teclado.
     * @param evento
     */
    void mouseReleaseEvent(QMouseEvent *evento) override; 

    /**
     * @brief mostrar Método que permite mostrar la imagen y responder a la espera de eventos.
     * @param ptrApp
     */
    void mostrar(QApplication *ptrApp);

    /**
     * @brief setListaArchivosImagen Método que permite settear la lista de archivos de imagen.
     * @param pListaArchivosImagen
     */
    void setListaArchivosImagen(const vector<string> &pListaArchivosImagen);

    /**
     * @brief setInterfaz Método que permite settear el puntero a InterfazDeUsuario.
     * @param newInterfaz
     */
    void setInterfaz(InterfazDeUsuario *newInterfaz);

    /**
     * @brief setListaArchivosLUT Método que permite settear la lista de archivosLUT.
     * @param pListaArchivosLUT
     */
    void setListaArchivosLUT(const vector<string> &pListaArchivosLUT);

    /**
     * @brief ~Visualizador Destructor de la clase.
     */
    ~Visualizador();

};

#endif // VISUALIZADOR_H
