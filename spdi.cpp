#include "spdi.h"

SPDI::SPDI()
{
    //Le asignamos un valor a la variable con la cual controlamos la apertura de directorios.
    opcionDirectorio = 0;
}

void SPDI::procesarImagenes( )
{
    cout<<"Se ha iniciado el procesamiento de imágenes."<<endl<<endl;

    //Variable booleana auxiliar
    bool auxiliarProcesamiento = 1;

    //Creamos un vector en el cual copiaremos los nombres de los archivos otorgados por espacioDeTrabajo
    vector<string> listaDeArchivos;

    switch(opcionDirectorio)
    {
    case 1:
        espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio1());
        listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

        for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
        {
            listaDeArchivos[i] = espacioDeTrabajo.getDirectorio1() + listaDeArchivos[i];
        }

    case 2:
        espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio2());
        listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

        for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
        {
            listaDeArchivos[i] = espacioDeTrabajo.getDirectorio2() + listaDeArchivos[i];
        }

    case 3:
        espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio3());
        listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

        for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
        {
            listaDeArchivos[i] = espacioDeTrabajo.getDirectorio3() + listaDeArchivos[i];
        }
    }

    while(auxiliarProcesamiento ==  1)
    {
        unsigned int indice;

        //Se verifica que el índice de la variable auxiliar que posee el visulizador, para permitir el uso de atajos de teclado, se halle en el rango correcto
        if(visualizador.getAuxIndiceArchivo() < 0)
            visualizador.setAuxIndiceArchivo(listaDeArchivos.size() - 1);
        else if(visualizador.getAuxIndiceArchivo() >= listaDeArchivos.size())
            visualizador.setAuxIndiceArchivo(0);

        indice = visualizador.getAuxIndiceArchivo();
        listaDeArchivos[indice];

        //Se crea el objeto archivo correspondiente, se lo lee y se carga la imagen
        if(listaDeArchivos[indice].find(".ppm") or listaDeArchivos[indice].find(".pbm") or listaDeArchivos[indice].find(".pgm" ))
        {
            ArchivoPNM archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);
        }
        else
        {
            ArchivoAIC archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);
        }


        //Se muestra la imagen
        visualizador.dibujarImagen(imagen);

    }

    }

    void SPDI::setOpcionDirectorio(int newOpcionDirectorio)
    {
        opcionDirectorio = newOpcionDirectorio;
    }
