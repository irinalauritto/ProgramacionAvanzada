#include "imagen.h"

Imagen::Imagen()
{

}

Imagen::Imagen(int pAncho, int pAlto)
{
    ancho=pAncho;
    alto=pAlto;

    for(unsigned int f=0; f<alto;f++)
        pixeles[f].resize(ancho);
}

int Imagen::getAncho()
{
    return ancho;
}
int Imagen::getAlto()
{
    return alto;
}

float Imagen::getRed(int columna, int fila)
{
    return pixeles[columna][fila].getR();

}

float Imagen::getGreen(int columna, int fila)
{
    return pixeles[columna][fila].getG();
}

float Imagen::getBlue(int columna, int fila)
{
    return pixeles[columna][fila].getB();
}

int Imagen::getMaximoValor() const
{
    return maximoValor;
}

const string &Imagen::getComentarios() const
{
    return comentarios;
}

void Imagen::setMaximoValor(int newMaximoValor)
{
    maximoValor = newMaximoValor;
}
void Imagen::setComentarios(string newComentarios)
{
    comentarios = newComentarios;
}
void Imagen::setTamanio(int pAncho, int pAlto)
{
    ancho=pAncho;
    alto=pAlto;

    for(unsigned int f=0; f<alto;f++)
        pixeles[f].resize(ancho);
}

void Imagen::modificarPixel(int columna, int fila, int red, int green, int blue)
{
    pixeles[fila][columna].setR(red);
    pixeles[fila][columna].setG(green);
    pixeles[fila][columna].setB(blue);
}

void Imagen::aumentarBrillo()
{
    for(unsigned int f=0; f<alto; f++)
        for(unsigned int c=0; c<ancho; c++)
        {
            pixeles[f][c].setR(pixeles[f][c].getR()+0.1);
            pixeles[f][c].setG(pixeles[f][c].getG()+0.1);
            pixeles[f][c].setB(pixeles[f][c].getB()+0.1);
        }
}

void Imagen::disminuirBrillo()
{
    for(unsigned int f=0; f<alto; f++)
        for(unsigned int c=0; c<ancho; c++)
        {
            pixeles[f][c].setR(pixeles[f][c].getR()-0.1);
            pixeles[f][c].setG(pixeles[f][c].getG()-0.1);
            pixeles[f][c].setB(pixeles[f][c].getB()-0.1);
        }
}


