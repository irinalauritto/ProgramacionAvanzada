#include "archivoaic.h"

ArchivoAIC::ArchivoAIC()
{

}

void ArchivoAIC::setNombreArchivo(const string &pNombreArchivo)
{
    nombreArchivo = pNombreArchivo;
}

const string &ArchivoAIC::getNombreArchivo() const
{
    return nombreArchivo;
}

string ArchivoAIC::devolverTipo()
{
    return tipoArchivo;
}

void ArchivoAIC::setTipoArchivo(const string pTipoArchivo)
{
    tipoArchivo = pTipoArchivo;
}

void ArchivoAIC::leerArchivoImagen(string ruta, Imagen &imagen)
{
    ifstream archivoAIC;
    string comentarios;
    int pColumnas, pFilas, pMaximoValor;

    archivoAIC.open(ruta);

    imagen.setTipoImagen("IntensidadesC");

    try
    {

        getline(archivoAIC, tipoArchivo,'\n');

        getline(archivoAIC, comentarios,'\n');

        imagen.setComentarios(comentarios);

        archivoAIC>>pColumnas>>pFilas;

        imagen.setTamanio(pColumnas, pFilas);

        if(pColumnas == 0 or pFilas == 0)
        {
            imagen.setEstaAlterada(true);
            throw (err);
        }

        archivoAIC>>pMaximoValor;

        imagen.setMaximoValor(pMaximoValor);

        int cantidadRepeticiones;
        float valorIntensidad;

        archivoAIC>>valorIntensidad>>cantidadRepeticiones;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                if(cantidadRepeticiones == 0)
                {
                    archivoAIC>>valorIntensidad>>cantidadRepeticiones;
                }

                imagen.modificarPixel(columna, fila, valorIntensidad,valorIntensidad,valorIntensidad);
                cantidadRepeticiones--;
            }
        }
    }

    catch(runtime_error &e)
    {
        puts(e.what());
    }
}

void ArchivoAIC::guardarImagen(Imagen &imagen, string pTipoArchivo, string pNombreArchivo)
{
    ofstream archivoAIC;
    string nombre = pNombreArchivo + ".aic";

    string auxiliarComentarios;

    archivoAIC.open(nombre.c_str());

    if(archivoAIC.is_open())
    {
        archivoAIC<<pTipoArchivo<<endl;

        auxiliarComentarios = imagen.getComentarios();

        if(imagen.getTipoImagen() != "IntensidadesC")
        {
            size_t aparicion =  auxiliarComentarios.find("comprimido:no");
            auxiliarComentarios.replace(aparicion, 13 , "comprimido:si");
        }

        archivoAIC<<auxiliarComentarios<<endl;

        archivoAIC<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoAIC<<imagen.getMaximoValor()<<endl;

        float valorIntensidad = (imagen.getPrimerComponente(0,0) + imagen.getSegundaComponente(0,0) + imagen.getTercerComponente(0,0) ) / 3.0f;
        int cantidadRepeticiones = 1;

        for(int fila = 1; fila < imagen.getCantidadFilas();++fila)
        {
            for(int columna = 1; columna < imagen.getCantidadColumnas();++columna)
            {

                float pValorIntensidad = (imagen.getPrimerComponente(columna,fila) + imagen.getSegundaComponente(columna,fila) + imagen.getTercerComponente(columna,fila) ) / 3.0f;

                if(valorIntensidad == pValorIntensidad)
                    cantidadRepeticiones++;

                else
                {
                    archivoAIC<<(float)valorIntensidad<<" "<<cantidadRepeticiones<<" ";
                    valorIntensidad = pValorIntensidad;
                    cantidadRepeticiones = 1;
                }
            }

            archivoAIC<<valorIntensidad<<" "<<cantidadRepeticiones<<" ";

            cantidadRepeticiones = 1;
        }
    }
}

ArchivoAIC::~ArchivoAIC()
{

}


