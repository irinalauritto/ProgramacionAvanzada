#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <fstream>

#include "imagen.h"
#include "excepcionimagencorruptas.h"

using namespace std;

/**
 * @brief Archivo clase de base abstracta creada con el fin de una lectura y escritura en memoria de archivos de imagen desde sus clases hijas.
 * @author Irina Esmeralda Lauritto
 */

class Archivo
{
protected:

    string tipoArchivo; /**< Tipo de archvivo de imagen. */

    string nombreArchivo; /**< Este parámetro se utiliza con el fin de guardar un archivo de imagen. */

    ExcepcionImagenCorrupta err; /**<  Objeto utilizado para el manejo de excepciones. */

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
    virtual void leerArchivoImagen(string ruta, Imagen &imagen) = 0;

    /**
     * @brief guardarImagen método virtual puro que se definirá en las clases hijas de esta clase.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    virtual void guardarImagen(Imagen &imagen, string pTipoArchivo, string pNombreArchivo) = 0;

    /**
     * @brief devolverTipo Devuelve el tipo de archivo
     * @return tipoArchivo
     */
    virtual string devolverTipo() = 0;

    /**
     * @brief ~Archivo Destructor de la clase.
     */
    virtual ~Archivo() = 0;

};

#endif // ARCHIVO_H
