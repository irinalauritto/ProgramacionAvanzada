#include "filtromediana.h"

FiltroMediana::FiltroMediana()
{

}

void FiltroMediana::aplicarFiltro(Imagen &imagen)
{
    Imagen imagenAuxiliar = imagen;
    Pixel mediana;
    Pixel constante;
    constante.setComponentes(2, 2, 2);

    vector <Pixel>  listaPixeles;
    listaPixeles.resize(8);

    for(int fila = 1 ; fila < (imagen.getCantidadFilas() - 1); ++fila)
    {
        for(int columna = 1 ; columna < (imagen.getCantidadColumnas() - 1); ++columna)
        {
            listaPixeles = {imagenAuxiliar.devolverPixel(columna - 1, fila -1), imagenAuxiliar.devolverPixel(columna , fila -1), imagenAuxiliar.devolverPixel(columna + 1, fila -1), imagenAuxiliar.devolverPixel(columna - 1, fila),  imagenAuxiliar.devolverPixel(columna, fila), imagenAuxiliar.devolverPixel(columna + 1, fila), imagenAuxiliar.devolverPixel(columna - 1, fila +1), imagenAuxiliar.devolverPixel(columna, fila + 1), imagenAuxiliar.devolverPixel(columna + 1, fila + 1)};

            sort(listaPixeles.begin(),listaPixeles.end());

            mediana.setPrimerComponente((listaPixeles[4].getPrimerComponente()+listaPixeles[3].getPrimerComponente())/2);
            mediana.setSegundaComponente((listaPixeles[4].getSegundaComponente()+listaPixeles[3].getSegundaComponente())/2);
            mediana.setTercerComponente((listaPixeles[4].getTercerComponente()+listaPixeles[3].getTercerComponente())/2);

            imagen.setPrimerComponente(columna, fila, mediana.getPrimerComponente());
            imagen.setSegundaComponente(columna, fila, mediana.getSegundaComponente());
            imagen.setTercerComponente(columna, fila, mediana.getTercerComponente());
        }
    }

}

FiltroMediana::~FiltroMediana()
{

}
