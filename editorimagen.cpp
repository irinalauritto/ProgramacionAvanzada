#include "editorimagen.h"

EditorImagen::EditorImagen()
{

}

void EditorImagen::binarizarImagen(Imagen &imagen, int umbral)
{
    float auxiliarUmbral = (float)imagen.getMaximoValor()*(umbral/100.0f);

    int valorPrimerComponente, valorSegundaComponente, valorTercerComponente, promedio;

    for(int fila = 0; fila < imagen.getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen.getCantidadColumnas(); columna++)
        {
            imagen.setTipoImagen("Monocromatica");

            valorPrimerComponente = imagen.getPrimerComponente(columna, fila);
            valorSegundaComponente = imagen.getSegundaComponente(columna, fila);
            valorTercerComponente = imagen.getTercerComponente(columna, fila);

            promedio = (valorPrimerComponente + valorSegundaComponente + valorTercerComponente)/3.0f;

            if(promedio >= auxiliarUmbral)
            {
                imagen.setPrimerComponente(columna, fila, 255.0);
                imagen.setSegundaComponente(columna, fila, 255.0);
                imagen.setTercerComponente(columna, fila, 255.0);            }
            else
            {
                imagen.setPrimerComponente(columna, fila, 0.0);
                imagen.setSegundaComponente(columna, fila, 0.0);
                imagen.setTercerComponente(columna, fila, 0.0);
            }
        }
    }
}

void EditorImagen::negativizarImagen(Imagen &imagen)
{
    int valorPrimerComponente, valorSegundaComponente, valorTercerComponente;

    for(int fila = 0; fila < imagen.getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen.getCantidadColumnas(); columna++)
        {
            valorPrimerComponente = imagen.getMaximoValor() - imagen.getPrimerComponente(columna, fila);
            valorSegundaComponente = imagen.getMaximoValor() - imagen.getSegundaComponente(columna, fila);
            valorTercerComponente = imagen.getMaximoValor() - imagen.getTercerComponente(columna, fila);

            if (valorPrimerComponente < 0)
                valorPrimerComponente = 0;

            if (valorSegundaComponente < 0)
                valorSegundaComponente = 0;

            if (valorTercerComponente < 0)
                valorTercerComponente = 0;

            imagen.setPrimerComponente(columna, fila, valorPrimerComponente);
            imagen.setSegundaComponente(columna, fila, valorSegundaComponente);
            imagen.setTercerComponente(columna, fila, valorTercerComponente);
        }
    }
}

void EditorImagen::aumentarBrillo(Imagen &imagen, int unidadesAumento)
{
    Pixel pixelAuxiliar;
    float aumento = imagen.getMaximoValor() * (unidadesAumento/100.0f);
    aumento = (int) aumento;
    pixelAuxiliar.setComponentes(aumento, aumento, aumento);
    float pValor, sValor, tValor;

    for(int fila = 0; fila < imagen.getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen.getCantidadColumnas(); columna++)
        {
            pValor = imagen.getPrimerComponente(columna, fila) + pixelAuxiliar.getPrimerComponente();
            sValor = imagen.getSegundaComponente(columna, fila) + pixelAuxiliar.getSegundaComponente();
            tValor = imagen.getTercerComponente(columna, fila) + pixelAuxiliar.getTercerComponente();


            imagen.setPrimerComponente(columna, fila, pValor);
            imagen.setSegundaComponente(columna, fila, sValor);
            imagen.setTercerComponente(columna, fila, tValor);


            int p, s, t;

            p = imagen.getPrimerComponente(columna, fila);
            s = imagen.getSegundaComponente(columna,fila);
            t = imagen.getTercerComponente(columna,fila);

            if(p > 255)
            {
                imagen.setPrimerComponente(columna, fila, 255);
            }

            if(s > 255)
            {
                imagen.setSegundaComponente(columna, fila, 255);
            }

            if(t > 255)
            {
                imagen.setTercerComponente(columna, fila, 255);
            }
        }
    }
}

void EditorImagen::disminuirBrillo(Imagen &imagen, int unidadesDisminucion)
{
    Pixel pixelAuxiliar;
    float disminucion = imagen.getMaximoValor() * (unidadesDisminucion/100.0f);
    disminucion = (int)disminucion;
    pixelAuxiliar.setComponentes(disminucion, disminucion, disminucion);
    float pValor, sValor, tValor;

    for(int fila = 0; fila < imagen.getCantidadFilas(); fila++)
    {
        for(int columna = 0; columna < imagen.getCantidadColumnas(); columna++)
        {
            pValor = imagen.getPrimerComponente(columna, fila) - pixelAuxiliar.getPrimerComponente();
            sValor = imagen.getSegundaComponente(columna, fila) - pixelAuxiliar.getSegundaComponente();
            tValor = imagen.getTercerComponente(columna, fila) - pixelAuxiliar.getTercerComponente();


            imagen.setPrimerComponente(columna, fila, pValor);
            imagen.setSegundaComponente(columna, fila, sValor);
            imagen.setTercerComponente(columna, fila, tValor);


            int p, s, t;

            p = imagen.getPrimerComponente(columna, fila);
            s = imagen.getSegundaComponente(columna,fila);
            t = imagen.getTercerComponente(columna,fila);

            if(p < 0)
            {
                imagen.setPrimerComponente(columna, fila, 0);
            }

            if(s < 0)
            {
                imagen.setSegundaComponente(columna, fila, 0);
            }

            if(t < 0)
            {
                imagen.setTercerComponente(columna, fila, 0);
            }
        }
    }
}

void EditorImagen::ajustarContraste(Imagen &imagen, Pixel pMaximo, Pixel pMinimo)
{
    Pixel auxiliar;
    Pixel actual;

    float M = (float)imagen.getMaximoValor();

    for(int fila = 0; fila < imagen.getCantidadFilas(); fila++)
    {
        for(int columna = 0 ; columna < imagen.getCantidadColumnas(); columna++)
        {
            actual = imagen.devolverPixel(columna, fila) ;
            auxiliar = ((actual - pMinimo)/(pMaximo - pMinimo)) * M;

            float p, s, t;
            p = auxiliar.getPrimerComponente();
            s = auxiliar.getSegundaComponente();
            t = auxiliar.getTercerComponente();

            imagen.setPrimerComponente(columna, fila, p);
            imagen.setSegundaComponente(columna, fila, s);
            imagen.setTercerComponente(columna, fila, t);


        }
    }

}
