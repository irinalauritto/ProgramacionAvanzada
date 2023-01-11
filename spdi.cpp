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

        cout<<"archivo: "<<listaDeArchivos[0];

        //Se crea el objeto archivo correspondiente, se lo lee y se carga la imagen
        if(listaDeArchivos[indice].find(".ppm") or listaDeArchivos[indice].find(".pbm") or listaDeArchivos[indice].find(".pgm" ))
        {
            ArchivoPNM archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);
            cout<<"Se leyo el archivo"<<endl;
        }
        else
        {
            ArchivoAIC archivo;
            archivo.leerArchivoImagen(listaDeArchivos[indice], imagen);
        }


        //        //Se muestra la imagen
        //        visualizador.dibujarImagen(imagen);

        ///PRUEBA DE CARGA DE LA IMAGEN

        cout<<"La opcion de directorio escogida fue "<<opcionDirectorio<<endl;
        cout<<"Nombre del archivo: "<<listaDeArchivos[indice]<<endl;
        cout<<"Cantidad de columnas de la imagen: "<<imagen.getCantidadColumnas()<<endl;
        cout<<"Cantidad de filas de la imagen: "<<imagen.getCantidadFilas()<<endl;
        cout<<"Máximo valor de rango dinámico: "<<imagen.getMaximoValor()<<endl;
        cout<<"Comentarios: "<<imagen.getComentarios();

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                cout<<"1: "<<imagen.getPrimerComponente(columna, fila)<<" ";
                cout<<"2: "<<imagen.getSegundaComponente(columna, fila)<<" ";
                cout<<"3: "<<imagen.getTercerComponente(columna, fila)<<"\t";
            }
            cout<<endl;
        }



    }
}


