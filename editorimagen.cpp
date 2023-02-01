#include "editorimagen.h"

EditorImagen::EditorImagen()
{

}

void EditorImagen::binarizarImagen(Imagen *imagen, int umbral)
{
    float auxiliarUmbral = (float)imagen->getMaximoValor()*(umbral/100.0f);

    float valorPrimerComponente, valorSegundaComponente, valorTercerComponente, promedio;

    for(int fila = 0; fila < imagen->getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen->getCantidadColumnas(); columna++)
        {
            imagen->setTipoImagen("Monocromatica");

            valorPrimerComponente = imagen->getPrimerComponente(columna, fila);
            valorSegundaComponente = imagen->getSegundaComponente(columna, fila);
            valorTercerComponente = imagen->getTercerComponente(columna, fila);

            promedio = (valorPrimerComponente + valorSegundaComponente + valorTercerComponente)/3.0f;

            if(promedio >= auxiliarUmbral)
            {
                imagen->setPrimerComponente(columna, fila, 255.0);
                imagen->setSegundaComponente(columna, fila, 255.0);
                imagen->setTercerComponente(columna, fila, 255.0);            }
            else
            {
                imagen->setPrimerComponente(columna, fila, 0.0);
                imagen->setSegundaComponente(columna, fila, 0.0);
                imagen->setTercerComponente(columna, fila, 0.0);
            }
        }
    }
}

void EditorImagen::negativizarImagen(Imagen *imagen)
{
    float valorPrimerComponente, valorSegundaComponente, valorTercerComponente;

    if(imagen->getTipoImagen() == "Intensidades" or imagen->getTipoImagen() == "IntensidadesC")
    {
        imagen->setTipoImagen("RGB");
    }

    for(int fila = 0; fila < imagen->getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen->getCantidadColumnas(); columna++)
        {
            valorPrimerComponente = imagen->getMaximoValor() - imagen->getPrimerComponente(columna, fila);
            valorSegundaComponente = imagen->getMaximoValor() - imagen->getSegundaComponente(columna, fila);
            valorTercerComponente = imagen->getMaximoValor() - imagen->getTercerComponente(columna, fila);

            if (valorPrimerComponente < 0.0f)
                valorPrimerComponente = 0.0f;

            if (valorSegundaComponente < 0.0f)
                valorSegundaComponente = 0.0f;

            if (valorTercerComponente < 0.0f)
                valorTercerComponente = 0.0f;

            imagen->setPrimerComponente(columna, fila, valorPrimerComponente);
            imagen->setSegundaComponente(columna, fila, valorSegundaComponente);
            imagen->setTercerComponente(columna, fila, valorTercerComponente);
        }
    }
}

void EditorImagen::aumentarBrillo(Imagen *imagen, int unidadesAumento)
{
    Pixel pixelAuxiliar;
    float aumento = imagen->getMaximoValor() * (unidadesAumento/100.0);
    pixelAuxiliar.setComponentes(aumento, aumento, aumento);
    float pValor, sValor, tValor;

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


            float p, s, t;

            p = imagen->getPrimerComponente(c, f);
            s = imagen->getSegundaComponente(c,f);
            t = imagen->getTercerComponente(c,f);

            if(p > 255.0)
            {
                imagen->setPrimerComponente(c, f, 255.0);
            }

            if(s > 255.0)
            {
                imagen->setSegundaComponente(c, f, 255.0);
            }

            if(t > 255.0)
            {
                imagen->setTercerComponente(c, f, 255.0);
            }
        }
    }
}

void EditorImagen::disminuirBrillo(Imagen *imagen, int unidadesDisminucion)
{
    Pixel pixelAuxiliar;
    float disminucion = imagen->getMaximoValor() * (unidadesDisminucion/100.0);
    pixelAuxiliar.setComponentes(disminucion, disminucion, disminucion);
    float pValor, sValor, tValor;

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


            float p, s, t;

            p = imagen->getPrimerComponente(c, f);
            s = imagen->getSegundaComponente(c,f);
            t = imagen->getTercerComponente(c,f);

            if(p < 0)
            {
                imagen->setPrimerComponente(c, f, 0);
            }

            if(s < 0)
            {
                imagen->setSegundaComponente(c, f, 0);
            }

            if(t < 0)
            {
                imagen->setTercerComponente(c, f, 0);
            }
        }
    }
}

void EditorImagen::ajustarContraste(Imagen *imagen, Pixel pMaximo, Pixel pMinimo)
{
    Pixel auxiliar;
    Pixel actual;
    Pixel diferencia = pMaximo - pMinimo;

    int M = imagen->getMaximoValor();

    for(int fila = 0; fila < imagen->getCantidadFilas(); fila++)
    {
        for(int columna = 0 ; columna < imagen->getCantidadColumnas(); columna++)
        {
            actual = imagen->devolverPixel(columna, fila) ;
            auxiliar = ((actual - pMinimo)/(pMaximo - pMinimo)) * M;

            float p, s, t;
            p = auxiliar.getPrimerComponente();
            s = auxiliar.getSegundaComponente();
            t = auxiliar.getTercerComponente();

            imagen->setPrimerComponente(columna, fila, p);
            imagen->setSegundaComponente(columna, fila, s);
            imagen->setTercerComponente(columna, fila, t);


        }
    }

}
