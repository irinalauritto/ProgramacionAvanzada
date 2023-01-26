#include "filtropasabajos.h"

FiltroPasaBajos::FiltroPasaBajos()
{

}

void FiltroPasaBajos::aplicarFiltro(Imagen *imagen)
{
    vector<float> kernel;
    kernel.resize(9, 9);

    Pixel auxiliar;
    auxiliar.setComponentes(0.0, 0.0, 0.0);

    vector<Pixel> auxiliares;
    auxiliares.resize(9);

    for(int fila = 1 ; fila < (imagen->getCantidadFilas() - 1); ++fila)
    {
        for(int columna = 1 ; columna < (imagen->getCantidadColumnas() - 1); ++columna)
        {
          //  auxiliar = /kernel[4] + imagen->devolverPixel(columna +1 , fila)/kernel[5] + imagen->devolverPixel(columna - 1, fila + 1)/kernel[6] + imagen->devolverPixel(columna, fila + 1)/kernel[7] +  imagen->devolverPixel(columna + 1, fila +1)/kernel[8] };

            auxiliares[0].setPrimerComponente(imagen->getPrimerComponente(columna -1, fila-1)/9);
            auxiliares[0].setSegundaComponente(imagen->getPrimerComponente(columna -1, fila-1)/9);
            auxiliares[0].setTercerComponente(imagen->getTercerComponente(columna -1, fila-1)/9);

            auxiliares[1].setPrimerComponente(imagen->getPrimerComponente(columna , fila-1)/9);
            auxiliares[1].setSegundaComponente(imagen->getPrimerComponente(columna , fila-1)/9);
            auxiliares[1].setTercerComponente(imagen->getTercerComponente(columna , fila-1)/9);

            auxiliares[2].setPrimerComponente(imagen->getPrimerComponente(columna + 1, fila-1)/9);
            auxiliares[2].setSegundaComponente(imagen->getPrimerComponente(columna + 1, fila-1)/9);
            auxiliares[2].setTercerComponente(imagen->getTercerComponente(columna + 1, fila-1)/9);

            auxiliares[3].setPrimerComponente(imagen->getPrimerComponente(columna -1, fila)/9);
            auxiliares[3].setSegundaComponente(imagen->getPrimerComponente(columna -1, fila)/9);
            auxiliares[3].setTercerComponente(imagen->getTercerComponente(columna -1, fila)/9);

            auxiliares[4].setPrimerComponente(imagen->getPrimerComponente(columna , fila)/9);
            auxiliares[4].setSegundaComponente(imagen->getPrimerComponente(columna , fila)/9);
            auxiliares[4].setTercerComponente(imagen->getTercerComponente(columna , fila)/9);

            auxiliares[5].setPrimerComponente(imagen->getPrimerComponente(columna +1, fila)/9);
            auxiliares[5].setSegundaComponente(imagen->getPrimerComponente(columna +1, fila)/9);
            auxiliares[5].setTercerComponente(imagen->getTercerComponente(columna +1, fila)/9);

            auxiliares[6].setPrimerComponente(imagen->getPrimerComponente(columna -1, fila +1)/9);
            auxiliares[6].setSegundaComponente(imagen->getPrimerComponente(columna -1, fila +1)/9);
            auxiliares[6].setTercerComponente(imagen->getTercerComponente(columna -1, fila +1)/9);

            auxiliares[7].setPrimerComponente(imagen->getPrimerComponente(columna , fila +1)/9);
            auxiliares[7].setSegundaComponente(imagen->getPrimerComponente(columna , fila +1)/9);
            auxiliares[7].setTercerComponente(imagen->getTercerComponente(columna , fila +1)/9);

            auxiliares[8].setPrimerComponente(imagen->getPrimerComponente(columna + 1, fila + 1)/9);
            auxiliares[8].setSegundaComponente(imagen->getPrimerComponente(columna + 1, fila + 1)/9);
            auxiliares[8].setTercerComponente(imagen->getTercerComponente(columna + 1, fila + 1)/9);

            for(int i = 0; i < 9; i++)
            {
                auxiliar = auxiliar + auxiliares[i];
            }

            imagen->setPrimerComponente(columna, fila, auxiliar.getPrimerComponente());
            imagen->setSegundaComponente(columna, fila, auxiliar.getSegundaComponente());
            imagen->setTercerComponente(columna, fila, auxiliar.getTercerComponente());
        }
    }
}
