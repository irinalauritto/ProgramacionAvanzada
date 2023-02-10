#include "spdi.h"

SPDI::SPDI()
{
    opcionDirectorio = 0;
}

void SPDI::procesarImagenes()
{
    int opcion;
    do
    {
        opcion = interfaz.menuInicial();
        if(opcion == 0)
        {
            exit(0);
        }

        elegirDirectorio();

        espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio7());
        listaArchivosLUT = espacioDeTrabajo.getListadoDeArchivos();
        for(unsigned int  i = 0; i<listaArchivosLUT.size();i++)
        {
            listaArchivosLUT[i] = espacioDeTrabajo.getDirectorio7() + "/" + listaArchivosLUT[i];
        }

        mostrarImagen();
    }
    while(opcion != 0);

}

void SPDI::elegirDirectorio()
{
    unsigned int auxiliarControlTamanio = 0;
    opcionDirectorio = interfaz.opcionesDirectorio();

    while (auxiliarControlTamanio == 0)
    {
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

        case 6:
            espacioDeTrabajo.extraerListadoDeArchivos(espacioDeTrabajo.getDirectorio6());
            listaDeArchivos = espacioDeTrabajo.getListadoDeArchivos();

            for(unsigned int  i = 0; i<listaDeArchivos.size();i++)
            {
                listaDeArchivos[i] = espacioDeTrabajo.getDirectorio6() + "/" + listaDeArchivos[i];
            }

            break;

        case 0:
            exit(0);
            break;
        }

        auxiliarControlTamanio = listaDeArchivos.size();

        if (auxiliarControlTamanio == 0)
        {
            interfaz.alertaDeError();
            interfaz.opcionesDirectorio();
        }
    }
}

void SPDI::mostrarImagen()
{
    interfaz.atajosDeTeclado();

    visualizador.setInterfaz(&interfaz);
    visualizador.setListaArchivosLUT(listaArchivosLUT);
    visualizador.setListaArchivosImagen(listaDeArchivos);
    visualizador.mostrar(ptrApp);
}


void SPDI::setPtrApp(QApplication *pPtrApp)
{
    ptrApp = pPtrApp;
}
