#include "spdi.h"

SPDI::SPDI()
{
    //Le asignamos un valor a la variable con la cual controlamos la apertura de directorios.
    opcionDirectorio = 0;
}

void SPDI::procesarImagenes( )
{
    if(interfaz.menuInicial())
    {
        cout<<"Se ha iniciado el procesamiento de imágenes."<<endl<<endl;

        //Variable booleana auxiliar
        procesar = 1;

        //Creamos un vector en el cual copiaremos los nombres de los archivos otorgados por espacioDeTrabajo
        vector<string> listaDeArchivos;

        //Se crea esta variable con el fin de controlar la elección del directorio;
        unsigned int auxiliarControlTamanio = 0;

        while (auxiliarControlTamanio == 0)
        {
            //Se muestran las opciones de directorio
            opcionDirectorio = interfaz.opcionesDirectorio();

            switch(opcionDirectorio)
            {
            case 1:
                espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio1());
                listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

                for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
                {
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio1() + "/" + listaDeArchivos[i];
                }

                break;

            case 2:
                espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio2());
                listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

                for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
                {
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio2() + "/" + listaDeArchivos[i];
                }

                break;

            case 3:
                espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio3());
                listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

                for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
                {
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio3() + "/" + listaDeArchivos[i];
                }

                break;
            case 4:
                espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio4());
                listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

                for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
                {
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio3() + "/" + listaDeArchivos[i];
                }

                break;
            }

            auxiliarControlTamanio = listaDeArchivos.size();
            if (auxiliarControlTamanio == 0)
            {
                interfaz.alertaDeError();
                interfaz.opcionesDirectorio();
            }
        }

        interfaz.atajosDeTeclado();

        unsigned int indice;

        //Se verifica que el índice de la variable auxiliar que posee el visulizador, para permitir el uso de atajos de teclado, se halle en el rango correcto
        if(visualizador.getAuxIndiceArchivo() < 0)
            visualizador.setAuxIndiceArchivo(listaDeArchivos.size() - 1);
        else if(visualizador.getAuxIndiceArchivo() >= listaDeArchivos.size())
            visualizador.setAuxIndiceArchivo(0);

        indice = visualizador.getAuxIndiceArchivo();
        listaDeArchivos[indice];

        //Se crea el objeto archivo correspondiente, se lo lee y se carga la imagen
        if(listaDeArchivos[indice].find(".ppm") or listaDeArchivos[indice].find(".pbm") or listaDeArchivos[indice].find(".pgm" ) or listaDeArchivos[indice].find(".pnm" ))
        {
            ArchivoPNM archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);

        }
        else
        {
            ArchivoAIC archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);
        }


        cout<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas();

        //Se muestra la imagen
        visualizador.mostrar(&imagen);
        visualizador.setVisualizadorHistograma(&visualizadorHistograma);





    }
}


