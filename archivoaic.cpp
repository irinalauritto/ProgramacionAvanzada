#include "archivoaic.h"

ArchivoAIC::ArchivoAIC()
{

}

void ArchivoAIC::setNombreArchivo(const string &pNombreArchivo)
{
    nombreArchivo = pNombreArchivo;
}

void ArchivoAIC::leerArchivoImagen(string ruta, Imagen &i)
{
    ifstream archivoAIC;
    string comentarios;
    string tipoImagen = "intensidades";
    int pColumnas, pFilas, pMaximoValor;

    //Se abre el archivo
    archivoAIC.open(ruta);

    //Se carga el tipo de imagen
    i.setTipoImagen(tipoImagen);

    //Se leen los comentarios hasta el fin de linea
    getline(archivoAIC, comentarios,'\n');

    //Se guardan los comentarios extraídos
    i.setComentarios(comentarios);

    //Se lee el número de columnas
    archivoAIC>>pColumnas>>pFilas;

    //Cargo el número de columnas y filas de la imagen
    i.setTamanio(pColumnas, pFilas);

    //Leo el valor máximo del rango dinámico
    archivoAIC>>pMaximoValor;

    //Guardo el valor máximo del rango dinámico
    i.setMaximoValor(pMaximoValor);

    //Leo los pixeles y los cargo
    for(int fila = 0; fila<i.getCantidadFilas();fila++)
    {
        for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
        {
            int cantidadRepeticiones = 1;
            float valorIntensidad;
            archivoAIC>>valorIntensidad>>cantidadRepeticiones;

            for(int control = 0; control<cantidadRepeticiones; control++)
            {
             i.modificarPixel(columna, fila, valorIntensidad, valorIntensidad, valorIntensidad);
             ++columna;
            }

        }

    }

}

void ArchivoAIC::guardarImagen(Imagen &i)
{
    ofstream archivoAIC;

    string archivo = "./ImagenesModificadas/" + nombreArchivo + ".aic";

    //Abro el archivo
    archivoAIC.open(archivo.c_str());

    //Se escriben los comentarios
    archivoAIC<<i.getComentarios()<<endl;

    //Se cargan el numero de  columnas y de filas
    archivoAIC<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

    //Se carga el valor máximo del rango dinámico
    archivoAIC<<i.getMaximoValor()<<endl;

    for(int fila = 0; fila<i.getCantidadFilas();fila++)
    {
        for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
        {
            int cantidadRepeticiones = 1;
            float valorIntensidad;
            valorIntensidad = i.getPrimerComponente(columna,fila);

            if(valorIntensidad == i.getPrimerComponente(columna+1, fila+1))
            {
                cantidadRepeticiones++;
            }
            else
            {
                archivoAIC<<valorIntensidad<<" "<<cantidadRepeticiones<<" ";
            }

        }

    }

}
