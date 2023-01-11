#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H

#include <fstream>
#include <iostream>

#include "archivo.h"

/**
 * @brief ArchivoPNM lase concreta que permite el manejo de archivos de tipo PNM.
 * @author Irina Esmerlda Lauritto
 */
class ArchivoPNM : public Archivo
{
private:

    /**
     * @brief tipoArchivo tipo de Archivo PNM
     */
    string tipoArchivo;
public:

    /**
     * @brief ArchivoPNM Constructor de la clase ArchivoPNM
     */
    ArchivoPNM();

    /**
     * @brief getTipoArchivo Método que permite conocer el tipo de archivo PNM.
     * @return Devuelve el tipo de archivo PNM.
     */
    string getTipoArchivo();

    /**
     * @brief leerArchivoImagen Método que permite la lectura de archivos PNM y la carga de los datos obtenidos en un objeto Imagen.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    void leerArchivoImagen(string ruta, Imagen &i) override;

    /**
     * @brief guardarImagen Método que permite guardar una imagen como archivo PNM.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    void guardarImagen(Imagen &i) override;
};

#endif // ARCHIVOPNM_H
