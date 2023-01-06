#ifndef SPDI_H
#define SPDI_H

#include <iostream>
#include <string>
#include <vector>

#include "archivoaic.h"
#include "archivopnm.h"
#include "espaciodetrabajo.h"
#include "filtromediana.h"
#include "filtropasaaltos.h"
#include "filtropasabajos.h"
#include "imagen.h"
#include "interfazdeusuario.h"
#include "visualizador.h"
#include "visualizadorhistograma.h"



using namespace std;

class SPDI
{
private:

    //Este atributo se corresponde con el número asignado a un determinado directorio.
    //Se debe realizar el procesamiento sobre los archivos de imagen que se hallan en el mismo.
    int opcionDirectorio;
    bool procesar;
    EspacioDeTrabajo espacioDeTrabajo;
    Imagen imagen;
    InterfazDeUsuario interfaz;
    Visualizador visualizador;
    VisualizadorHistograma visualizadorHistograma;

public:
    SPDI();
    void procesarImagenes();
    void setOpcionDirectorio(int newOpcionDirectorio);
};

#endif // SPDI_H
