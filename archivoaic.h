#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "archivo.h"
#include <iostream>

using namespace std;

/**
 * @brief  ArchivoAIC clase concreta que permite el manejo de archivos de tipo AIC.
 * @author Irina Esmeralda Lauritto
 */
class ArchivoAIC : public Archivo
{
private:

    /**
     * @brief nombreArchivo Este parámetro se utiliza con el fin de guardar un archivo de imagen
     */
    string nombreArchivo;

    /**
     * @brief tipoArchivo tipo de Archivo AIC
     */
    string tipoArchivo;

public:

    /**
     * @brief ArchivoAIC Constructor de la clase ArchivoAIC
     */
    ArchivoAIC();

    /**
     * @brief setNombreArchivo Método que permite modificar el parametro nombreArchivo.
     * @param pNombreArchivo nuevo valor del atributo nombreArchivo.
     */
    void setNombreArchivo(const string &pNombreArchivo);

    /**
     * @brief leerArchivoImagen Método que permite la lectura de archivos AIC y la carga de los datos obtenidos en un objeto Imagen.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    void leerArchivoImagen(string ruta, Imagen *i) override;

    /**
     * @brief guardarImagen Método que permite guardar una imagen como archivo AIC.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    void guardarImagen(Imagen *i, string pTipoArchivo, string pNombreArchivo) override;

};

#endif // ARCHIVOAIC_H
