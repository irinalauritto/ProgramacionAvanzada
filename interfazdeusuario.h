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
     * @brief menuInicial Método que muestra el menú de inicio.
     * @return Devuelve 1 si se ha elegido iniciar el procesamiento y 0 en caso de que se decida cerrar el programa.
     */
    int menuInicial();

    /**
     * @brief opcionesDirectorio Método que muestra las opciones de directorio.
     * @return Devuelve un entero correspondiente a la opción de directorio elegida.
     */
    int opcionesDirectorio();

    /**
     * @brief atajosDeTeclado Método que muestra los atajos de teclado.
     */
    void atajosDeTeclado();

    /**
     * @brief guardarImagen Método que se comunica con el usuario para realizar el guardado de imágenes.
     * @param pTipoArchivo
     * @param pNombre
     * @param pTipoImagen
     */
    void guardarImagen(string &pTipoArchivo, string &pNombre, string &pTipoImagen);

    /**
     * @brief imagenGuardada Método que comunica al usuario la información de la magen guardada.
     * @param pCarpeta
     * @param pNombre
     * @param pTipo
     */
    void imagenGuardada(string &pCarpeta, string &pNombre, string &pTipo);

    /**
     * @brief aumentoBrillo Método que solicita al usuario ingresar las unidades en las que desea aumentar el brillo.
     * @return unidadesAumento
     */
    int aumentoBrillo();

    /**
     * @brief disminucionBrillo Método que solicita al usuario ingresar las unidades en las que desea disminuir el brillo.
     * @return unidadesDisminucion
     */
    int disminucionBrillo();

    /**
     * @brief getUmbralBinarizacion Método que solicita al usuario ingresar el umbral de binarización.
     * @return umbral
     */
    int  getUmbralBinarizacion();

    /**
     * @brief opcionAtajo Método que comunica al usuario la opcion de atajo elegida.
     * @param opcion
     */
    void opcionAtajo(string opcion);

    /**
     * @brief mostrarEstadisticos Método que muestra los datos estadístico de la imagen.
     * @param pMaximo Pixel con los valores máximos.
     * @param pMinimo Pixel con los valores mínimos.
     * @param pMedia Pixel con los valores promedio.
     * @param pDesvioEstandar Pixel con los valores de  desvío estándar.
     * @param pModa Pixel con los valores de moda.
     */
    void mostrarEstadisticos(Pixel pMaximo, Pixel pMinimo, Pixel pMedia, Pixel pDesvioEstandar, Pixel pModa);

    /**
     * @brief errorTipoImagen Método que permite comunicar al usuario un error ante un tipo erróneo de imagen.
     * @param tipoImagen
     */
    void errorTipoImagen(string tipoImagen);

    /**
     * @brief comunicarArea Método que permite comunicar el area detectada por el detector de area.
     * @param pArea Valor de area a mostrar.
     */
    void comunicarArea(int pArea);

    /**
     * @brief errorImagenAlterada Método que permite comunicar al usuario un error ante una imagen alterada.
     */
    void errorImagenAlterada();

    /**
     * @brief alertaDeError Método que permite al sistema comunicar al usuario un error ante una carpeta vacía.
     */
    void alertaDeError();

};

#endif // INTERFAZDEUSUARIO_H
