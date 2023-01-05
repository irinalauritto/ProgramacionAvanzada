#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <fstream>

#include "imagen.h"

using namespace std;

class Archivo
{
private:
    fstream archivo;
public:
    Archivo();
    virtual void leerArchivoImagen(string ruta, Imagen &i) = 0;
    virtual void guardarImagen(Imagen &i) = 0;

};

#endif // ARCHIVO_H
