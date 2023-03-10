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
public:

    /**
     * @brief ArchivoPNM Constructor de la clase ArchivoPNM
     */
    ArchivoPNM();

    /**
     * @brief getTipoArchivo Método que permite conocer el tipo de archivo PNM.
     * @return Devuelve el tipo de archivo PNM.
     */
    string devolverTipo() override;

    /**
     * @brief setTipoArchivo Método que permite modificar el parámetro tipoArchivo.
     * @param pTipoArchivo nuevo valor de tipoArchivo.
     */
    void setTipoArchivo(const string pTipoArchivo);

    /**
     * @brief setNombreArchivo Método que permite modificar el parametro nombreArchivo.
     * @param pNombreArchivo nuevo valor del atributo nombreArchivo.
     */
    void setNombreArchivo(const string &newNombreArchivo);

    /**
     * @brief getNombreArchivo Método que permite devolver el nombre del archivo
     * @return nombreArchivo
     */
    const string &getNombreArchivo() const;

    /**
     * @brief leerArchivoImagen Método que permite la lectura de archivos PNM y la carga de los datos obtenidos en un objeto Imagen.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    void leerArchivoImagen(string ruta, Imagen &imagen) override;

    /**
     * @brief guardarImagen Método que permite guardar una imagen como archivo PNM.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    void guardarImagen(Imagen &imagen, string pTipoArchivo, string pNombreArchivo) override;

    /**
     * @brief Destructor de la clase.
     * */
    ~ArchivoPNM();

};

#endif // ARCHIVOPNM_H
