#ifndef SPDI_H
#define SPDI_H

#include <iostream>
#include <string>
#include <vector>
#include <QApplication>

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

    int opcionDirectorio; /**< Atributo que se corresponde con el número asignado a un determinado directorio. */

    vector<string> listaDeArchivos; /**< Lista con las rutas de los archivos de imagen. */

    vector<string> listaArchivosLUT; /**< Lista con las rutas de los archivos LUT*/

    EspacioDeTrabajo espacioDeTrabajo; /**< Atributo que se corresponde al espacio de trabajo del SPDI.*/

    InterfazDeUsuario interfaz; /**< Atributo que se corresponde con la interfaz de usuario del SPDI. */

    Visualizador visualizador; /**< Atributo que se corresponde al visualizador de imágenes del SPDI. */

    QApplication *ptrApp; /**< Puntero a un objeto QApplication. */

    /**
     * @brief elegirDirectorio Método que permite la elección de directorios.
     */
    void elegirDirectorio();

    /**
     * @brief mostrarImagen Método encargado de mostrar la imagen.
     */
    void mostrarImagen();

public:

    /**
     * @brief SPDI Constructor de la clase SPDI.
     */
    SPDI();

    /**
     * @brief procesarImagenes Método que permite que se lleve a cabo el procesamiento de imágenes.
     */
    void procesarImagenes();

    /**
     * @brief setPtrApp
     * @param pPtrApp Nuevo valor del atributo ptrApp.
     */
    void setPtrApp(QApplication *pPtrApp);
};

#endif // SPDI_H
