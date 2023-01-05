#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H

#include <fstream>
#include <iostream>

#include "archivo.h"

class ArchivoPNM : public Archivo
{
private:
    string tipoArchivo;
public:
    ArchivoPNM();
    string getTipoArchivo();
    void setTipoArchivo(string newTipoArchivo);
    void leerArchivoImagen(string ruta, Imagen &i) override;
    void guardarImagen(Imagen &i) override;
};

#endif // ARCHIVOPNM_H
