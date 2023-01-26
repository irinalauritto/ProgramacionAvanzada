#include "imagen.h"

const string &Imagen::getTipoImagen() const
{
    return tipoImagen;
}

Imagen::Imagen()
{
    maximoValor = 0;
}

Imagen::Imagen(int pCantidadColumnas, int pCantidadFilas)
{
    cantidadColumnas = pCantidadColumnas;
    cantidadFilas = pCantidadFilas;

    pixeles.resize(cantidadFilas);
    for(unsigned int f = 0; f < cantidadFilas; f++)
    {
        pixeles[f].resize(cantidadColumnas);
    }
}

int Imagen::getCantidadColumnas()
{
    return cantidadColumnas;
}
int Imagen::getCantidadFilas()
{
    return cantidadFilas;
}

int Imagen::getMaximoValor() const
{
    return maximoValor;
}

const string &Imagen::getComentarios() const
{
    return comentarios;
}

void Imagen::setMaximoValor(int pMaximoValor)
{
    maximoValor = pMaximoValor;
}
void Imagen::setComentarios(string pComentarios)
{
    comentarios = pComentarios;
}

void Imagen::setTipoImagen(string pTipoImagen)
{
    tipoImagen = pTipoImagen;
}

float Imagen::getPrimerComponente(int columna, int fila)
{
    return pixeles[fila][columna].getPrimerComponente();

}

float Imagen::getSegundaComponente(int columna, int fila)
{
    return pixeles[fila][columna].getSegundaComponente();
}

float Imagen::getTercerComponente(int columna, int fila)
{
    return pixeles[fila][columna].getTercerComponente();
}

void Imagen::setPrimerComponente(int columna, int fila, float valor)
{
    pixeles[fila][columna].setPrimerComponente(valor);
}

void Imagen::setSegundaComponente(int columna, int fila, float valor)
{
    pixeles[fila][columna].setSegundaComponente(valor);
}

void Imagen::setTercerComponente(int columna, int fila, float valor)
{
    pixeles[fila][columna].setTercerComponente(valor);
}

void Imagen::setTamanio(int pCantidadColumnas, int pCantidadFilas)
{
    cantidadColumnas = pCantidadColumnas;
    cantidadFilas = pCantidadFilas;

    pixeles.resize(cantidadFilas);
    for(unsigned int f = 0; f < cantidadFilas; f++)
    {
        pixeles[f].resize(cantidadColumnas);
    }
}

void Imagen::modificarPixel(int columna, int fila, float pPrimerComponente, float pSegundaComponente, float pTercerComponente)
{
    pixeles[fila][columna].setPrimerComponente(pPrimerComponente);
    pixeles[fila][columna].setSegundaComponente(pSegundaComponente);
    pixeles[fila][columna].setTercerComponente(pTercerComponente);
}


Pixel Imagen::devolverPixel(int columna, int fila)
{
    return pixeles[fila][columna];
}


