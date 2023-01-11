#include "imagen.h"

Imagen::Imagen()
{

}

Imagen::Imagen(int pCantidadColumnas, int pCantidadFilas)
{
    cantidadColumnas = pCantidadColumnas;
    cantidadFilas = pCantidadFilas;

    pixeles.resize(cantidadFilas);
    for(unsigned int f = 0; f < cantidadFilas; f++)
        pixeles[f].resize(cantidadColumnas);
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

void Imagen::setTamanio(int pCantidadColumnas, int pCantidadFilas)
{
    cantidadColumnas = pCantidadColumnas;
    cantidadFilas = pCantidadFilas;

    pixeles.resize(cantidadFilas);
    for(unsigned int f=0; f<cantidadFilas;f++)
        pixeles[f].resize(cantidadColumnas);
}

void Imagen::modificarPixel(int columna, int fila, int pPrimerComponente, int pSegundaComponente, int pTercerComponente)
{
    pixeles[fila][columna].setPrimerComponente(pPrimerComponente);
    pixeles[fila][columna].setSegundaComponente(pSegundaComponente);
    pixeles[fila][columna].setTercerComponente(pTercerComponente);
}

void Imagen::aumentarBrillo()
{
    for(unsigned int f = 0; f < cantidadFilas; f++)
        for(unsigned int c = 0; c < cantidadColumnas; c++)
        {
            pixeles[f][c].setPrimerComponente(pixeles[f][c].getPrimerComponente()+0.1);
            pixeles[f][c].setSegundaComponente(pixeles[f][c].getSegundaComponente()+0.1);
            pixeles[f][c].setTercerComponente(pixeles[f][c].getTercerComponente()+0.1);
        }
}

void Imagen::disminuirBrillo()
{
    for(unsigned int f = 0; f < cantidadFilas; f++)
        for(unsigned int c = 0; c < cantidadColumnas; c++)
        {
            pixeles[f][c].setPrimerComponente(pixeles[f][c].getPrimerComponente()-0.1);
            pixeles[f][c].setSegundaComponente(pixeles[f][c].getSegundaComponente()-0.1);
            pixeles[f][c].setTercerComponente(pixeles[f][c].getTercerComponente()-0.1);
        }
}


