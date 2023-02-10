#include "espaciodetrabajo.h"


EspacioDeTrabajo::EspacioDeTrabajo()
{

}

string &EspacioDeTrabajo::getDirectorio1()
{
    return directorio1;
}

string &EspacioDeTrabajo::getDirectorio2()
{
    return directorio2;
}

string &EspacioDeTrabajo::getDirectorio3()
{
    return directorio3;
}

string &EspacioDeTrabajo::getDirectorio4()
{
    return directorio4;
}

string &EspacioDeTrabajo::getDirectorio5()
{
    return directorio5;
}

string &EspacioDeTrabajo::getDirectorio6()
{
    return directorio6;
}

const string &EspacioDeTrabajo::getDirectorio7() const
{
    return directorio7;
}

const vector<string> &EspacioDeTrabajo::getListadoDeArchivos() const
{
    return listadoDeArchivos;
}

void EspacioDeTrabajo::extraerListadoDeArchivos(string pDirectorio)
{
    vector<string> auxListadoDeArchivos;

    DIR *dir = opendir(pDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                auxListadoDeArchivos.push_back(entry->d_name);
            }
        }

        closedir(dir);
    }

    else
    {
        listadoDeArchivos.resize(0);
    }

    listadoDeArchivos = auxListadoDeArchivos;
}


