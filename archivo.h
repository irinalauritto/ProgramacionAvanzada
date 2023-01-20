#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <fstream>

#include "imagen.h"

using namespace std;

/**
 * @brief Archivo clase de base abstracta creada con el fin de una lectura y escritura en memoria de datos desde sus clases hijas.
 * @author Irina Esmeralda Lauritto
 */

class Archivo
{
private:

    /**
     * @brief archivo modela el archivo físico con el cual se trabajará.
     */
    fstream archivo;
public:
    /**
     * @brief Archivo constructor de la clase Archivo
     */
    Archivo();

    /**
     * @brief leerArchivoImagen método virtual puro que se definirá en las clases hijas de esta clase.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    virtual void leerArchivoImagen(string ruta, Imagen *i) = 0;

    /**
     * @brief guardarImagen método virtual puro que se definirá en las clases hijas de esta clase.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    virtual void guardarImagen(Imagen *i, string pTipoArchivo, string pNombreArchivo) = 0;

};

#endif // ARCHIVO_H
