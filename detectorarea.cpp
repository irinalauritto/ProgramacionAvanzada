#include "detectorarea.h"


DetectorArea::DetectorArea()
{

}

void DetectorArea::detectarArea(Imagen *pPtrImagen, int pColumna, int pFila)
{
    ptrImagen = pPtrImagen;
    areaDetectada.clear();

    if(0 <= pColumna and 0 <= pFila and pFila <= ptrImagen->getCantidadFilas() and pColumna <= ptrImagen->getCantidadColumnas())
    {
        pixelAuxiliar = ptrImagen->devolverPixel(pColumna, pFila);

        areaTotal = 0;
        profundidad = 0;

        areaDetectada.resize(ptrImagen->getCantidadFilas());

        for(int i = 0; i < ptrImagen->getCantidadFilas(); i++)
        {
            areaDetectada[i].resize(ptrImagen->getCantidadColumnas(), false);
        }


        buscarAreaImagen(pFila, pColumna);

        for(unsigned int fila = 0; fila < (unsigned int)ptrImagen->getCantidadFilas(); fila++)
        {
            for(unsigned int columna = 0; columna < (unsigned int)ptrImagen->getCantidadColumnas(); columna++)
            {
                if(areaDetectada[fila][columna])
                {
                    ptrImagen->setPrimerComponente(columna, fila , 79.0);
                    ptrImagen->setSegundaComponente(columna, fila , 125.0);
                    ptrImagen->setTercerComponente(columna, fila , 220.0);

                }
            }
        }
    }
}

void DetectorArea::buscarAreaImagen(int pFila, int pColumna)
{
    float diferencia = sqrt((pow(ptrImagen->getPrimerComponente(pColumna, pFila) - pixelAuxiliar.getPrimerComponente(), 2) + pow((ptrImagen->getSegundaComponente(pColumna, pFila) - pixelAuxiliar.getSegundaComponente()), 2) + pow((ptrImagen->getTercerComponente(pColumna, pFila) - pixelAuxiliar.getTercerComponente()),2)));

    profundidad++;

    if(profundidad < 100)
    {
        if((pFila >= 0) and (pColumna >= 0) and (pFila <= ptrImagen->getCantidadFilas()) and (pColumna <= ptrImagen->getCantidadColumnas()) and (diferencia <= tolerancia) and !areaDetectada[pFila][pColumna])
        {
            areaTotal++;
            areaDetectada[pFila][pColumna] = true;

            for(int i = 0; i < 8; i++)
            {
                buscarAreaImagen((unsigned int)(pFila + vecinosF[i]), (unsigned int)(pColumna + vecinosC[i]));
            }

        }
    }

    profundidad--;

}

int DetectorArea::getAreaTotal()
{
    return areaTotal;
}
