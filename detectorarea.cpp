#include "detectorarea.h"

vector<int> vecinosC{-1,0,1,-1,1,-1,0,1}, vecinosF{-1,-1,-1,0,0,1,1,1};

DetectorArea::DetectorArea()
{

}

void DetectorArea::detectarArea(Imagen *pImagen, int pColumna, int pFila)
{
    imagen = pImagen;

    pixelAuxiliar = imagen->devolverPixel(pColumna, pFila);

    areaDetectada.resize(imagen->getCantidadFilas());
    for(int i = 0; i < imagen->getCantidadFilas(); i++)
    {
        areaDetectada[i].resize(imagen->getCantidadColumnas(), false);
    }

    if(imagen->getTipoImagen() == "Monocromatica")
    {
        tolerancia = 0;
    }

    float diferencia;

    diferencia = sqrt(pow((imagen->getPrimerComponente(pColumna, pFila) - pixelAuxiliar.getPrimerComponente()),2) + pow((imagen->getSegundaComponente(pColumna, pFila) - pixelAuxiliar.getSegundaComponente()),2) + pow((imagen->getTercerComponente(pColumna, pFila) - pixelAuxiliar.getTercerComponente()),2));

    if(diferencia <= tolerancia)
    {
        areaTotal++;
        areaDetectada[pFila][pColumna] = true;

        for(int i = 0 ; i < 8 ; i++)
        {
            unsigned int posicionX = pColumna + vecinosC[i];
            unsigned int posicionY = pFila + vecinosF[i];

            if(posicionX < areaDetectada[0].size() and posicionY < areaDetectada.size())
                detectarArea(imagen,pColumna + vecinosC[i],pFila+ vecinosF[i]);
        }
//        detectarArea(imagen, pColumna -1, pFila-1);
//        detectarArea(imagen, pColumna -1, pFila+1);
//        detectarArea(imagen, pColumna -1, pFila);
//        detectarArea(imagen, pColumna +1, pFila+1);
//        detectarArea(imagen, pColumna, pFila+1);
//        detectarArea(imagen, pColumna, pFila-1);
//        detectarArea(imagen, pColumna +1, pFila-1);
//        detectarArea(imagen, pColumna +1, pFila);
    }

    pintarImagen();
}

void DetectorArea::pintarImagen()
{
    for(int fila = 0; fila < imagen->getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen->getCantidadColumnas(); columna++)
        {
            if(areaDetectada[fila][columna])
            {
                imagen->setPrimerComponente(columna, fila , 79.0);
                imagen->setSegundaComponente(columna, fila , 125.0);
                imagen->setTercerComponente(columna, fila , 194.0);

            }
        }
    }

}

int DetectorArea::getAreaTotal()
{
    return areaTotal;
}
