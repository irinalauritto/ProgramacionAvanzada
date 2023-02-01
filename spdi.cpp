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
            case 5:
                espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio5());
                listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

                for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
                {
                    listaDeArchivos[i] = espacioDeTrabajo.getDirectorio5() + "/" + listaDeArchivos[i];
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

        vector<string> listaArchivosLUT;

        espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio6());
        listaArchivosLUT = espacioDeTrabajo.getListadoDeArchivos();

        for(unsigned int  i = 0; i<listaArchivosLUT.size();i++)
        {
            listaArchivosLUT[i] = espacioDeTrabajo.getDirectorio6() + "/" + listaArchivosLUT[i];
        }



        interfaz.atajosDeTeclado();

        visualizador.setInterfaz(&interfaz);
        visualizador.setListaArchivosLUT(listaArchivosLUT);
        visualizador.setListaArchivosImagen(listaDeArchivos);
        visualizador.cargarImagen();
        visualizador.mostrar();


    }

}
