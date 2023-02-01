#include "filtropasabajos.h"
#include <iostream>

using namespace std;

FiltroPasaBajos::FiltroPasaBajos()
{

}

void FiltroPasaBajos::aplicarFiltro(Imagen *imagen)
{
    vector<Pixel> kernel;
    kernel.resize(9);

    for(int i = 0; i < 9; i++)
    {
        kernel[i].setComponentes(1/9, 1/9, 1/9);
    }

    Pixel auxiliar;
    auxiliar.setComponentes(0.0, 0.0, 0.0);

    vector<Pixel> auxiliares;
    auxiliares.resize(9);

    float pValor, sValor, tValor;
    for(int fila = 1 ; fila < (imagen->getCantidadFilas() - 1); ++fila)
    {
        for(int columna = 1 ; columna < (imagen->getCantidadColumnas() - 1); ++columna)
        {
            auxiliar = {(imagen->devolverPixel(columna - 1, fila -1)*kernel[0]) + (imagen->devolverPixel(columna , fila -1)*kernel[1] ) + (imagen->devolverPixel(columna +1, fila -1)*kernel[2] )+ (imagen->devolverPixel(columna -1   , fila)*kernel[3])  + (imagen->devolverPixel(columna, fila)*kernel[4])  + (imagen->devolverPixel(columna +1, fila)*kernel[5]) + (imagen->devolverPixel(columna -1, fila +1)*kernel[6]) + (imagen->devolverPixel(columna, fila +1)*kernel[7]) + (imagen->devolverPixel(columna +1 , fila +1)*kernel[8]) };

            Pixel prueba = imagen->devolverPixel(columna, fila);
            cout<<prueba.getPrimerComponente()<<endl;

            pValor = auxiliar.getPrimerComponente();
            sValor = auxiliar.getSegundaComponente();
            tValor = auxiliar.getTercerComponente();

            cout<<pValor<<" "<<sValor<<" "<<tValor<<endl;

            imagen->setPrimerComponente(columna, fila, pValor);
            imagen->setSegundaComponente(columna, fila, sValor);
            imagen->setTercerComponente(columna, fila, tValor);
        }

    }
}
