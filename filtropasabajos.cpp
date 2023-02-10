#include "filtropasabajos.h"
#include <iostream>

using namespace std;

FiltroPasaBajos::FiltroPasaBajos()
{

}

void FiltroPasaBajos::aplicarFiltro(Imagen &imagen)
{
    Imagen imagenAuxiliar = imagen;

    vector<vector<Pixel>> matriz;

    matriz.resize(imagen.getCantidadFilas());
    for(int i = 0; i < imagen.getCantidadFilas(); i++)
    {
        matriz[i].resize(imagen.getCantidadColumnas());
    }

    for(int f = 0; f<imagen.getCantidadFilas(); f++)
    {
        for(int c = 0; c<imagen.getCantidadColumnas(); c++)
        {
            matriz[f][c].setComponentes(0.0,0.0,0.0);
        }
    }

    Pixel kernel;
    kernel.setComponentes(9.0,9.0,9.0);


    for(int fila = 1 ; fila < (imagen.getCantidadFilas() - 1); ++fila)
    {
        for(int columna = 1 ; columna < (imagen.getCantidadColumnas() - 1); ++columna)
        {
            for( int i  = -1; i<2; ++i)
                for(int j = -1; j<2;++j)
                {
                    matriz[fila][columna] = matriz[fila][columna] +  (imagenAuxiliar.devolverPixel(columna+i , fila+j)/kernel);
                }
            imagen.setPrimerComponente(columna, fila, matriz[fila][columna].getPrimerComponente());
            imagen.setSegundaComponente(columna, fila, matriz[fila][columna].getSegundaComponente());
            imagen.setTercerComponente(columna, fila, matriz[fila][columna].getTercerComponente());

        }
    }
}

FiltroPasaBajos::~FiltroPasaBajos()
{

}
