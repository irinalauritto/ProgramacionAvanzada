#include "pseudocoloreador.h"

Pseudocoloreador::Pseudocoloreador()
{

}

void Pseudocoloreador::leerArchivoLUT(string rutaLUT)
{
    tablaLUT.resize(256);

    unsigned int indice, pValor, sValor, tValor;

    fstream archivoLUT;
    archivoLUT.open(rutaLUT.c_str());

    string auxiliarLectura;

    if(archivoLUT.is_open())
    {
        getline(archivoLUT, auxiliarLectura, '\n');

        for(unsigned int i = 0; i<256;++i)
        {
            archivoLUT>>indice>>pValor>>sValor>>tValor;
            tablaLUT[i].setPrimerComponente(pValor);
            tablaLUT[i].setSegundaComponente(sValor);
            tablaLUT[i].setTercerComponente(tValor);
        }
    }

    archivoLUT.close();
}

void Pseudocoloreador::colorearImagen(Imagen &imagenIntensidad)
{
    imagenIntensidad.setTipoImagen("RGB");

    for(int fila = 0; fila < imagenIntensidad.getCantidadFilas() ; ++fila)
    {
        for(int columna = 0; columna < imagenIntensidad.getCantidadColumnas(); ++columna)
        {
            int pValor = 0, sValor = 0, tValor = 0;
            int indice = (int) imagenIntensidad.getPrimerComponente(columna, fila);
            pValor = tablaLUT[indice].getPrimerComponente();
            sValor = tablaLUT[indice].getSegundaComponente();
            tValor = tablaLUT[indice].getTercerComponente();

            imagenIntensidad.setPrimerComponente(columna, fila, pValor);
            imagenIntensidad.setSegundaComponente(columna, fila, sValor);
            imagenIntensidad.setTercerComponente(columna, fila, tValor);

        }
    }
}


