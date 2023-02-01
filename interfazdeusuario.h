#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H

#include <iostream>
#include <windows.h>
#include <stdlib.h>

#include "pixel.h"

using namespace std;

/**
 * @brief InterfazDeUsuario clase concreta que permite que el usuario interactúe con el programa.
 * @author Irina Esmeralda Lauritto
 */
class InterfazDeUsuario
{

public:

    /**
     * @brief InterfazDeUsuario Constructor de la clase InterfazDeUsuario.
     */
    InterfazDeUsuario();

    /**
     * @brief atajosDeTeclado Método que muestra los atajos de teclado.
     */
    void atajosDeTeclado();

    void guardarImagen(string &pTipoArchivo, string &pNombre, string &pTipoImagen);

    void imagenGuardada(string &pCarpeta, string &pNombre, string &pTipo);

    /**
     * @brief menuInicial Método que muestra el menú de inicio.
     * @return Devuelve true si se ha elegido iniciar el procesamiento y false en caso de que se decida cerrar el programa.
     */
    bool menuInicial();

    /**
     * @brief opcionesDirectorio Método que muestra las opciones de directorio.
     * @return Devuelve un entero correspondiente a la opción de directorio elegida.
     */
    int opcionesDirectorio();

    int aumentoBrillo();

    int disminucionBrillo();

    int  getUmbralBinarizacion();

    void opcionAtajo(string opcion);

    void mostrarEstadisticos(Pixel pMaximo, Pixel pMinimo, Pixel pMedia, Pixel pDesvioEstandar, Pixel pModa);

    void errorTipoImagen(string tipoImagen);

    void comunicarArea(int pArea);

    /**
     * @brief alertaDeError Método que permite al sistema comunicar al usuario un error.
     */
    void alertaDeError();

};

#endif // INTERFAZDEUSUARIO_H
