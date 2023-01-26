#include "procesadorestadistico.h"

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

void ProcesadorEstadistico::encontrarMaximo()
{
    Pixel auxiliar;
    float primer = 0;
    float segunda = 0;
    float tercer = 0;

    for(int f = 0; f < imagen->getCantidadFilas() ; f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas() ; c++)
        {
            auxiliar.setPrimerComponente(imagen->getPrimerComponente(c, f));
            auxiliar.setSegundaComponente(imagen->getSegundaComponente(c, f));
            auxiliar.setTercerComponente(imagen->getTercerComponente(c, f));

            if(auxiliar.getPrimerComponente() > primer)
            {
                primer = auxiliar.getPrimerComponente();
            }

            if(auxiliar.getSegundaComponente() > segunda)
            {
                segunda = auxiliar.getSegundaComponente();
            }

            if(auxiliar.getTercerComponente() > tercer)
            {
                tercer = auxiliar.getTercerComponente();
            }
        }
    }

    maximo.setComponentes(primer, segunda, tercer);
}

void ProcesadorEstadistico::encontrarMinimo()
{
    Pixel auxiliar;
    float primer = imagen->getPrimerComponente(0 ,0);
    float segunda = imagen->getSegundaComponente(0, 0);
    float tercer = imagen->getTercerComponente(0, 0);

    for(int f = 0; f < imagen->getCantidadFilas() ; f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas() ; c++)
        {
            auxiliar.setPrimerComponente(imagen->getPrimerComponente(c, f));
            auxiliar.setSegundaComponente(imagen->getSegundaComponente(c, f));
            auxiliar.setTercerComponente(imagen->getTercerComponente(c, f));

            if(auxiliar.getPrimerComponente() < primer)
            {
                primer = auxiliar.getPrimerComponente();
            }

            if(auxiliar.getSegundaComponente() < segunda)
            {
                segunda = auxiliar.getSegundaComponente();
            }

            if(auxiliar.getTercerComponente() < tercer)
            {
                tercer = auxiliar.getTercerComponente();
            }
        }
    }

    minimo.setComponentes(primer, segunda, tercer);
}

void ProcesadorEstadistico::calcularMedia()
{
    float sumaPrimer = 0;
    int cantidadElementos = imagen->getCantidadColumnas() * imagen->getCantidadFilas();

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           sumaPrimer += imagen->getPrimerComponente(c, f);
        }
    }

    media.setPrimerComponente(sumaPrimer/cantidadElementos);

    float sumaSegunda = 0;

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           sumaSegunda += imagen->getSegundaComponente(c, f);
        }
    }

    media.setSegundaComponente(sumaSegunda/cantidadElementos);

    float sumaTercer = 0;

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           sumaTercer += imagen->getTercerComponente(c, f);
        }
    }

    media.setTercerComponente(sumaTercer/cantidadElementos);
}

void ProcesadorEstadistico::calcularDesvioEstandar()
{
    float pSumaDesviosCuadrados = 0;
    float pDesvioCuadrado;
    int cantidadElementos = imagen->getCantidadColumnas() * imagen->getCantidadFilas();


    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           pDesvioCuadrado = (imagen->getPrimerComponente(c, f) - media.getPrimerComponente()) * (imagen->getPrimerComponente(c, f) - media.getPrimerComponente());
           pSumaDesviosCuadrados += pDesvioCuadrado;
        }
    }

    desvioEstandar.setPrimerComponente(sqrt(pSumaDesviosCuadrados / cantidadElementos ));

    float sSumaDesviosCuadrados = 0;
    float sDesvioCuadrado;

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           sDesvioCuadrado = (imagen->getSegundaComponente(c, f) - media.getSegundaComponente()) * (imagen->getSegundaComponente(c, f) - media.getSegundaComponente());
           sSumaDesviosCuadrados += sDesvioCuadrado;
        }
    }

    desvioEstandar.setSegundaComponente(sqrt(sSumaDesviosCuadrados / cantidadElementos ));

    float tSumaDesviosCuadrados = 0;
    float tDesvioCuadrado;

    for(int f = 0; f < imagen->getCantidadFilas(); f++)
    {
        for(int c = 0; c < imagen->getCantidadColumnas(); c++)
        {
           tDesvioCuadrado = (imagen->getTercerComponente(c, f) - media.getTercerComponente()) * (imagen->getTercerComponente(c, f) - media.getTercerComponente());
           tSumaDesviosCuadrados += tDesvioCuadrado;
        }
    }

    desvioEstandar.setTercerComponente(sqrt(tSumaDesviosCuadrados / cantidadElementos ));

}

void ProcesadorEstadistico::hallarModa()
{
    map < float, int > primerasComponentes;

    map < float, int > segundasComponentes;

    map < float, int > tercerasComponentes;

    Pixel auxiliar;

    for(int fila = 0; fila < imagen->getCantidadFilas(); ++fila)
    {
        for(int columna = 0; columna < imagen->getCantidadColumnas(); ++columna)
        {
            auxiliar = imagen->devolverPixel(columna, fila);

            float pPrimerComponente = auxiliar.getPrimerComponente();
            float pSegundaComponente = auxiliar.getSegundaComponente();
            float pTercerComponente = auxiliar.getTercerComponente();


            if(primerasComponentes.find(pPrimerComponente) == primerasComponentes.end())
            {
                primerasComponentes[pPrimerComponente] = 1;
            }
            else
            {
                primerasComponentes[pPrimerComponente] += 1;
            }

            if(segundasComponentes.find(pSegundaComponente) == segundasComponentes.end())
            {
                segundasComponentes[pSegundaComponente] = 1;
            }
            else
            {
                segundasComponentes[pSegundaComponente] += 1;
            }

            if(tercerasComponentes.find(pTercerComponente) == tercerasComponentes.end())
            {
                tercerasComponentes[pTercerComponente] = 1;
            }
            else
            {
                tercerasComponentes[pTercerComponente] += 1;
            }

         }
    }

    pair<float,unsigned int> parPrimerComponente;
    pair<float,unsigned int> parSegundaComponente;
    pair<float,unsigned int> parTercerComponente;

    float pMaximo = 0;
    for(auto iterator = primerasComponentes.begin(); iterator != primerasComponentes.end(); ++iterator)
    {
           if(iterator->second > pMaximo)
           {
               pMaximo = iterator->second;
               parPrimerComponente.first = iterator->first;
               parPrimerComponente.second = iterator->second;
           }
    }

    float sMaximo = 0;
    for(auto iterator = segundasComponentes.begin(); iterator != segundasComponentes.end(); ++iterator)
    {
           if(iterator->second > sMaximo)
           {
               sMaximo = iterator->second;
               parSegundaComponente.first = iterator->first;
               parSegundaComponente.second = iterator->second;
           }
    }

    float tMaximo = 0;
    for(auto iterator = tercerasComponentes.begin(); iterator != tercerasComponentes.end(); ++iterator)
    {
           if(iterator->second > tMaximo)
           {
               tMaximo = iterator->second;
               parTercerComponente.first = iterator->first;
               parTercerComponente.second = iterator->second;
           }
    }

    moda.setComponentes(parPrimerComponente.first, parSegundaComponente.first, parTercerComponente.first);
}

void ProcesadorEstadistico::procesarDatos()
{
    encontrarMaximo();
    encontrarMinimo();
    calcularMedia();
    calcularDesvioEstandar();
    hallarModa();

}

void ProcesadorEstadistico::setImagen(Imagen *pImagen)
{
    imagen = pImagen;
    procesarDatos();
}

Pixel &ProcesadorEstadistico::getMaximo()
{
    return maximo;
}

Pixel &ProcesadorEstadistico::getMinimo()
{
    return minimo;
}

Pixel &ProcesadorEstadistico::getMedia()
{
    return media;
}

Pixel &ProcesadorEstadistico::getDesvioEstandar()
{
    return desvioEstandar;
}

Pixel &ProcesadorEstadistico::getModa()
{
    return moda;
}


