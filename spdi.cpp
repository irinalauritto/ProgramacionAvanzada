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
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio4() + "/" + listaDeArchivos[i];
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
        if((int)visualizador.getAuxIndiceArchivo() == -1)
        {
            visualizador.setAuxIndiceArchivo(listaDeArchivos.size() - 1);
        }
        else if(visualizador.getAuxIndiceArchivo() >= listaDeArchivos.size())
        {
            visualizador.setAuxIndiceArchivo(0);
        }
        indice = visualizador.getAuxIndiceArchivo();
        listaDeArchivos[indice];

        Archivo *archivo;

        fstream auxiliarArchivo;
        string auxiliarTipo;

        auxiliarArchivo.open(listaDeArchivos[indice]);
        getline(auxiliarArchivo, auxiliarTipo, '\n');

        //POLIMORFISMO
        if(auxiliarTipo == "P1" or auxiliarTipo == "P2" or auxiliarTipo == "P3" or auxiliarTipo == "P4" or auxiliarTipo == "P5" or auxiliarTipo == "P6")
        {
            archivo = new ArchivoPNM;
        }
        else
        {
            archivo = new ArchivoAIC;
        }

        archivo->leerArchivoImagen(listaDeArchivos[indice], &imagen);

        //Se muestra la imagen
        visualizador.mostrar(&imagen);


        //         for(int i = 0; i < imagen.getCantidadFilas(); ++i)
        //         {
        //             for (int j = 0; j < imagen.getCantidadColumnas(); ++j)
        //             {
        //                 cout<<imagen.getPrimerComponente(i, j)<<" "<<imagen.getSegundaComponente(i,j)<<" "<<imagen.getTercerComponente(i,j)<<endl;
        //             }
        //         }

        //cout<<imagen.getPrimerComponente(0,0);


//        ArchivoAIC archi2;
//        archi2.guardarImagen(&imagen, "P2C", "prueba_random_a_p2c");


        //p1 funciona
        //p2 funciona
        //rgb a p2 funciona
        //p3 funciona
        //p4 funciona
        //p5 funciona
        //p6 funciona
        //probar rgb a p4
        //arreglar aic guardar




    }
}


