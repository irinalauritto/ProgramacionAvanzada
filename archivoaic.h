#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "archivo.h"

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
     * @brief leerArchivoImagen Método que permite la lectura de archivos AIC y la carga de los datos obtenidos en un objeto Imagen.
     * @param ruta posee la ruta del archivo que se desea abrir.
     * @param i objeto de tipo Imagen en el que se cargarán los datos del archivo.
     */
    void leerArchivoImagen(string ruta, Imagen &i) override;

    /**
     * @brief guardarImagen Método que permite guardar una imagen como archivo AIC.
     * @param i objeto Imagen que proporcionará los datos que se desea guardar.
     */
    void guardarImagen(Imagen &i) override;

};

#endif // ARCHIVOAIC_H
