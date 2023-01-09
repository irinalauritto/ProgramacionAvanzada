#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include <sstream>

using namespace std;


class EspacioDeTrabajo
{
private:

    vector<string> listadoDeArchivos;

    string directorio1 = "./grupo_imagenes_1";
    string directorio2 = "./grupo_imagenes_2";
    string directorio3 = "./grupo_imagenes_3_corruptas";

public:
    EspacioDeTrabajo();
    //    void mostrarDirectorio(string pDirectorio);

    //Método que obtiene la lista de archivos del directorio escogido
    void extraerListadoDeArchivos(string pDirectorio);

    //Métodos que devuelven los directorios que maneja la clase
    string &getDirectorio1();
    string &getDirectorio2();
    string &getDirectorio3();

    //Método que devuelve el contenido que se halla en listadoDeArchivos
    const vector<string> &getListadoDeArchivos() const;
};
#endif // ESPACIODETRABAJO_H
