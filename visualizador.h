#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>


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
 * @brief The Visualizador class
 */
class Visualizador : public QOpenGLWidget , protected QOpenGLFunctions
{
private:

    /**
     * @brief anchoVentana
     */
    int anchoVentana;

    /**
     * @brief altoVentana
     */
    int altoVentana;
    /**
     * @brief escala
     */
    float escala;

    /**
     * @brief desplazamientoX
     */
    int desplazamientoX;

    /**
     * @brief desplazamientoY
     */
    int desplazamientoY;

    int posicionInicialX;

    int posicionInicialY;

    /**
     * @brief imagen
     */
    Imagen imagen;

    InterfazDeUsuario *interfaz;

    /**
     * @brief auxIndiceArchivo
     */
    int auxIndiceArchivo; //controla la imagen que vemos

    bool controlPresionada = false;

    bool flechaDerechaPresionada = false;

    bool flechaIzquierdaPresionada = false;

    bool clickIzquierdoPresionadoandControl = false;

    bool clickIzquierdoOff;

    bool unoPresionado = false;

    bool dosPresionado = false;

    bool aPresionada = false;

    bool bPresionada = false;

    bool cPresionada = false;

    bool gPresionada = false;

    bool hPresionada = false;

    bool mPresionada = false;

    bool nPresionada = false;

    bool qPresionada = false;

    bool sPresionada = false;

    bool menosPresionada = false;

    bool masPresionada = false;

    bool escapePresionada = false;

    bool mostrarHistograma = false;

    vector<string> listaArchivosImagen;

    vector<string> listaArchivosLUT;

public:
    Visualizador();

    void initializeGL() override;

    void resizeGL(int pAncho, int pAlto) override;

    void paintGL() override;

    void keyPressEvent(QKeyEvent *evento) override;

    void mousePressEvent(QMouseEvent *evento) override;

    void keyReleaseEvent(QKeyEvent *evento) override;

    void mouseReleaseEvent(QMouseEvent *evento) override;

    void cargarImagen();

    void mostrar();

    void dibujarImagen();

    unsigned int getAuxIndiceArchivo() const;

    void setAuxIndiceArchivo(int newAuxIndiceArchivo);

    ~Visualizador();

    void setListaArchivosImagen(const vector<string> &pListaArchivosImagen);

    void setInterfaz(InterfazDeUsuario *newInterfaz);

    string &getNombreUltimaImagen();

    void setListaArchivosLUT(const vector<string> &pListaArchivosLUT);
};

#endif // VISUALIZADOR_H
