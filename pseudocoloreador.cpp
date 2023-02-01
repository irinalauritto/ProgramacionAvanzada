#include "pseudocoloreador.h"

Pseudocoloreador::Pseudocoloreador()
{

}

void Pseudocoloreador::leerArchivoLUT(string rutaLUT)
{
    tablaLUT.resize(256);

    int pValor, sValor, tValor;

    fstream archivoLUT;
    archivoLUT.open(rutaLUT.c_str());

    string auxiliarLectura;

    if(archivoLUT.is_open())
    {
        getline(archivoLUT, auxiliarLectura, '\n');

        for(unsigned int i = 0; i<256;++i)
        {
            archivoLUT>>pValor>>sValor>>tValor;
            tablaLUT[i].setPrimerComponente(pValor);
            tablaLUT[i].setSegundaComponente(sValor);
            tablaLUT[i].setTercerComponente(tValor);
        }
    }

    archivoLUT.close();
}

void Pseudocoloreador::colorearImagen(Imagen *iIntensidad)
{
    iIntensidad->setTipoImagen("RGB");

    for(int fila = 0; fila < iIntensidad->getCantidadFilas() ; ++fila)
    {
        for(int columna = 0; columna < iIntensidad->getCantidadColumnas(); ++columna)
        {
            int pValor = 0, sValor = 0, tValor = 0;
            int indice = iIntensidad->getPrimerComponente(columna, fila);
            pValor = tablaLUT[indice].getPrimerComponente();
            sValor = tablaLUT[indice].getSegundaComponente();
            tValor = tablaLUT[indice].getTercerComponente();

            iIntensidad->setPrimerComponente(columna, fila, pValor);
            iIntensidad->setSegundaComponente(columna, fila, sValor);
            iIntensidad->setTercerComponente(columna, fila, tValor);

        }
    }
}


