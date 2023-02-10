#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief EspacioDeTrabajo clase concreta que posee información sobre los directorios y que permite el barrido de los mismos.
 * @author Irina Esmeralda Lauritto
 */
class EspacioDeTrabajo
{
private:

    vector<string> listadoDeArchivos; /**< atributo en el cual se cargan los nombres de los archivos. */

    string directorio1 = "./grupo_imagenes_1"; /**<  atributo que posee el nombre del primer directorio. */

    string directorio2 = "./grupo_imagenes_2"; /**< atributo que posee el nombre del segundo directorio. */

    string directorio3 = "./grupo_imagenes_3_corruptas"; /**< atributo que posee el nombre del tercer directorio. */

    string directorio4 = "./grupo_imagenes_modificadas"; /**<  atributo que posee el nombre del cuarto directorio. */

    string directorio5 = "./ultima_imagen_visualizada"; /**< atributo que posee el nombre del quinto directorio. */

    string directorio6 = "./ij_image_samples"; /**< atributo que posee el nombre del sexto directorio. */

    string directorio7 = "./grupo_luts"; /**< atributo que posee el nombre del septimo directorio. */


public:

    /**
     * @brief EspacioDeTrabajo Constructor de la clase EspacioDeTrabajo
     */
    EspacioDeTrabajo();

    /**
     * @brief extraerListadoDeArchivosMétodo que obtiene la lista de archivos del directorio escogido.
     * @param pDirectorio Elección de directorio.
     */
    void extraerListadoDeArchivos(string pDirectorio);

    /**
     * @brief getDirectorio1 método que devuelve el nombre del primer directorio.
     * @return Devuelve directorio1;
     */
    string &getDirectorio1();

    /**
     * @brief getDirectorio2 método que devuelve el nombre del segundo directorio.
     * @return Devuelve directorio2;
     */
    string &getDirectorio2();

    /**
     * @brief getDirectorio3 método que devuelve el nombre del tercer directorio.
     * @return Devuelve directorio3;
     */
    string &getDirectorio3();

    /**
     * @brief getDirectorio4 método que devuelve el nombre del cuarto directorio.
     * @return Devuelve directorio4;
     */
    string &getDirectorio4();

    /**
     * @brief getDirectorio5 método que devuelve el nombre del quinto directorio.
     * @return Devuelve directorio5
     */
    string &getDirectorio5();

    /**
     * @brief getDirectorio6 Método que devuelve el nombre del sexto directorio.
     * @return Devuelve directorio6.
     */
    string &getDirectorio6();

    /**
     * @brief getDirectorio7 Método que devuelve el nombre del septimo directorio.
     * @return directorio7
     */
    const string &getDirectorio7() const;

    /**
     * @brief getListadoDeArchivos Método que devuelve el contenido que se halla en listadoDeArchivos.
     * @return Devuelve el listadoDeArchivos.
     */
    const vector<string> &getListadoDeArchivos() const;
};
#endif // ESPACIODETRABAJO_H
