#include "editorimagen.h"

EditorImagen::EditorImagen()
{

}

void EditorImagen::binarizarImagen(Imagen *imagen, int umbral)
{

}

void EditorImagen::negativizarImagen(Imagen *imagen)
{

}

void EditorImagen::aumentarBrillo(Imagen *imagen, int unidadesAumento)
{
    Pixel pixelAuxiliar;
    pixelAuxiliar.setComponentes(0.01, 0.01, 0.01);

    float pValor, sValor, tValor;

    for(int i = 0; i < unidadesAumento; i++)
    {
        for(int f = 0; f < imagen->getCantidadFilas(); f++)
        {
            for(int c = 0; c < imagen->getCantidadColumnas(); c++)
            {
                pValor = imagen->getPrimerComponente(c, f) + pixelAuxiliar.getPrimerComponente();
                sValor = imagen->getSegundaComponente(c, f) + pixelAuxiliar.getSegundaComponente();
                tValor = imagen->getTercerComponente(c, f) + pixelAuxiliar.getTercerComponente();


                imagen->setPrimerComponente(c, f, pValor);
                imagen->setSegundaComponente(c, f, sValor);
                imagen->setTercerComponente(c, f, tValor);

                if(imagen->getPrimerComponente(c, f) > 1)
                {
                    imagen->setPrimerComponente(c, f, 1);
                }

                if(imagen->getSegundaComponente(c, f) > 1)
                {
                    imagen->setSegundaComponente(c, f, 1);
                }

                if(imagen->getTercerComponente(c, f) > 1)
                {
                    imagen->setTercerComponente(c, f, 1);
                }
            }
        }
    }


}

void EditorImagen::disminuirBrillo(Imagen *imagen, int unidadesDisminucion)
{
    Pixel pixelAuxiliar;
    pixelAuxiliar.setComponentes(0.01, 0.01, 0.01);

    float pValor, sValor, tValor;

    for(int i = 0; i < unidadesDisminucion; i++)
    {
        for(int f = 0; f < imagen->getCantidadFilas(); f++)
        {
            for(int c = 0; c < imagen->getCantidadColumnas(); c++)
            {
                pValor = imagen->getPrimerComponente(c, f) - pixelAuxiliar.getPrimerComponente();
                sValor = imagen->getSegundaComponente(c, f) - pixelAuxiliar.getSegundaComponente();
                tValor = imagen->getTercerComponente(c, f) - pixelAuxiliar.getTercerComponente();


                imagen->setPrimerComponente(c, f, pValor);
                imagen->setSegundaComponente(c, f, sValor);
                imagen->setTercerComponente(c, f, tValor);

                if(imagen->getPrimerComponente(c, f) < 0)
                {
                    imagen->setPrimerComponente(c, f, 0);
                }

                if(imagen->getSegundaComponente(c, f) < 0)
                {
                    imagen->setSegundaComponente(c, f, 0);
                }

                if(imagen->getTercerComponente(c, f) < 0)
                {
                    imagen->setTercerComponente(c, f, 0);
                }
            }
        }
    }

}

void EditorImagen::ajustarContraste(Imagen *imagen, Pixel pMaximo, Pixel pMinimo)
{
    Pixel auxiliar;
    Pixel diferencia = pMaximo - pMinimo;

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0 ; c < imagen->getCantidadColumnas(); c++)
        {
            auxiliar = (imagen->devolverPixel(c, f) - pMinimo)/(diferencia) * pMaximo;
            imagen->modificarPixel(c, f, auxiliar.getPrimerComponente(), auxiliar.getSegundaComponente(), auxiliar.getTercerComponente());

        }
    }

}
