#include "visualizador.h"

unsigned int Visualizador::getAuxIndiceArchivo() const
{
    return auxIndiceArchivo;
}

void Visualizador::setAuxIndiceArchivo(unsigned int newAuxIndiceArchivo)
{
    auxIndiceArchivo = newAuxIndiceArchivo;
}

Visualizador::Visualizador()
{
    auxIndiceArchivo = 0;
}

void Visualizador::dibujarImagen(Imagen &i)
{

}
