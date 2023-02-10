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
public:

    /**
     * @brief ArchivoAIC Constructor de la clase ArchivoAIC
     */
    ArchivoAIC();

    /**
     * @brief devolverTipo Devuelve el tipo de archivo, parámetro protected en la clase de la cual hereda ésta.
     * @return tipoArchivo
     */
    string devolverTipo()override;

    /**
     * @brief setTipoArchivo Método que permite modificar el parámetro tipoArchivo.
     * @param pTipoArchivo nuevo valor de tipoArchivo.
     */
    void setTipoArchivo(const string pTipoArchivo);

    /**
     * @brief setNombreArchivo Método que permite modificar el parametro nombreArchivo.
     * @param pNombreArchivo nuevo valor del atributo nombreArchivo.
     */
    void setNombreArchivo(const string &pNombreArchivo);

    /**
     * @brief getNombreArchivo Método que permite devolver el nombre del archivo
     * @return nombreArchivo
     */
    const string &getNombreArchivo() const;

    /**
     * @brief leerArchivoImagen Método que permite la lectura de archivos AIC y la carga de los datos obtenidos en un objeto Imagen.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    void leerArchivoImagen(string ruta, Imagen &imagen) override;

    /**
     * @brief guardarImagen Método que permite guardar una imagen como archivo AIC.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    void guardarImagen(Imagen &imagen, string pTipoArchivo, string pNombreArchivo) override;

    /**
     * @brief Destructor de la clase.
     * */
    ~ArchivoAIC();

};

#endif // ARCHIVOAIC_H
