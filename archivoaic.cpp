#include "archivoaic.h"

ArchivoAIC::ArchivoAIC()
{

}

void ArchivoAIC::setNombreArchivo(const string &pNombreArchivo)
{
    nombreArchivo = pNombreArchivo;
}

void ArchivoAIC::leerArchivoImagen(string ruta, Imagen *i)
{
    ifstream archivoAIC;
    string comentarios;
    int pColumnas, pFilas, pMaximoValor;

    //Abro el archivo
    archivoAIC.open(ruta);

    i->setTipoImagen("IntensidadesC");

    //Leo el tipo de archivo
    getline(archivoAIC, tipoArchivo,'\n');

    //Leo los comentarios hasta el fin de linea
    getline(archivoAIC, comentarios,'\n');

    //Guardo los comentarios extraídos
    i->setComentarios(comentarios); //ver como escribirlos correctaremente

    //Leo el número de columnas
    archivoAIC>>pColumnas>>pFilas;

    //Cargo el número de columnas y filas de la imagen
    i->setTamanio(pColumnas, pFilas);

    //Leo el valor máximo del rango dinámico
    archivoAIC>>pMaximoValor;

    //Guardo el valor máximo del rango dinámico
    i->setMaximoValor(pMaximoValor);

    //Leo los pixeles y los cargo
    int cantidadRepeticiones;
    float valorIntensidad;

    archivoAIC>>valorIntensidad>>cantidadRepeticiones;

    for(int fila = 0; fila<i->getCantidadFilas();fila++)
    {
        for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
        {
            if(cantidadRepeticiones == 0)
            {
                archivoAIC>>valorIntensidad>>cantidadRepeticiones;
                // cout<<valorIntensidad<<" "<<cantidadRepeticiones<<endl;
            }

            i->modificarPixel(columna, fila, valorIntensidad,valorIntensidad,valorIntensidad);
            cantidadRepeticiones--;
        }
    }
}

void ArchivoAIC::guardarImagen(Imagen *i, string pTipoArchivo, string pNombreArchivo)
{
    ofstream archivoAIC;
    string nombre = pNombreArchivo + ".aic";

    string auxiliarComentarios;

    //Abro el archivo
    archivoAIC.open(nombre.c_str());

    if(archivoAIC.is_open())
    {
        //Se escribe el tipo de archivo
        archivoAIC<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        auxiliarComentarios = i->getComentarios();

        if(i->getTipoImagen() != "IntensidadesC")
        {
            size_t aparicion =  auxiliarComentarios.find("comprimido:no");
            auxiliarComentarios.replace(aparicion, 13 , "comprimido:si");
        }

        archivoAIC<<auxiliarComentarios<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoAIC<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Se carga el valor máximo del rango dinámico
        archivoAIC<<i->getMaximoValor()<<endl;

        float valorIntensidad = (i->getPrimerComponente(0,0) + i->getSegundaComponente(0,0) + i->getTercerComponente(0,0) ) / 3.0;
        int cantidadRepeticiones = 1;

        for(int fila = 1; fila < i->getCantidadFilas();++fila)
        {
            for(int columna = 1; columna < i->getCantidadColumnas();++columna)
            {

                float pValorIntensidad = (i->getPrimerComponente(columna,fila) + i->getSegundaComponente(columna,fila) + i->getTercerComponente(columna,fila) ) / 3.0;

                if(valorIntensidad == pValorIntensidad)
                    cantidadRepeticiones++;

                else
                {
                    archivoAIC<<valorIntensidad<<" "<<cantidadRepeticiones<<" ";
                    valorIntensidad = pValorIntensidad;
                    cantidadRepeticiones = 1;
                }
            }

            archivoAIC<<valorIntensidad<<" "<<cantidadRepeticiones<<" ";

            cantidadRepeticiones = 1;
        }
    }
}

string ArchivoAIC::devolverTipo()
{
    return tipoArchivo;
}
