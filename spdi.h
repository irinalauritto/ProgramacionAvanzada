#ifndef SPDI_H
#define SPDI_H

#include <iostream>
#include <string>
#include <vector>

#include "archivoaic.h"
#include "archivopnm.h"
#include "espaciodetrabajo.h"
#include "filtromediana.h"
#include "filtropasaaltos.h"
#include "filtropasabajos.h"
#include "imagen.h"
#include "interfazdeusuario.h"
#include "visualizador.h"
#include "visualizadorhistograma.h"

using namespace std;

/**
 * @brief SPDI clase que lleva a cabo el procesamiento digital de imágenes.
 * @author Irina Esmeralda Lauritto
 */
class SPDI
{
private:

    /**
     * @brief opcionDirectorio Atributo que se corresponde con el número asignado a un determinado directorio.
     */
    int opcionDirectorio;

    /**
     * @brief procesar Atributo que controla el procesamiento.
     */
    bool procesar;

    /**
     * @brief espacioDeTrabajo Atributo que se corresponde al espacio de trabajo del SPDI.
     */
    EspacioDeTrabajo espacioDeTrabajo;

    /**
     * @brief imagen Atributo que se corresponde con la imagen virtual sobre la que se trabajará.
     */
    Imagen imagen;

    /**
     * @brief interfaz Atributo que se corresponde a la interfaz de usuario del SPDI.
     */
    InterfazDeUsuario interfaz;

    /**
     * @brief visualizador Atributo que se corresponde al visualizador de imágenes del SPDI.
     */
    Visualizador visualizador;

    /**
     * @brief visualizadorHistograma Atributo que se corresponde al visualizador de los histogramas de las imágenes del SPDI.
     */
    VisualizadorHistograma visualizadorHistograma;

public:

    /**
     * @brief SPDI Constructor de la clase SPDI.
     */
    SPDI();

    /**
     * @brief procesarImagenes Método que permite que se lleve a cabo el procesamiento de imágenes.
     */
    void procesarImagenes();

};

#endif // SPDI_H
