#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H

#include <iostream>
#include <windows.h>
#include <stdlib.h>

//#include "spdi.h"

using namespace std;

class InterfazDeUsuario
{
private:
   // SPDI *sistemaDeProcesamiento;
public:
    InterfazDeUsuario();

    //Método cuya función es llamar a los atajos de teclado
    void mostrarAtajosDeTeclado();
    bool mostrarMenuInicial();
    int mostrarOpcionesDirectorio();
   // void setSPDI(SPDI *pSistema);
};

#endif // INTERFAZDEUSUARIO_H
