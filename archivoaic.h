#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "archivo.h"

class ArchivoAIC : public Archivo
{
public:
    ArchivoAIC();
    void leerArchivoImagen(string ruta, Imagen &i) override;
    void guardarImagen(Imagen &i) override;

};

#endif // ARCHIVOAIC_H
