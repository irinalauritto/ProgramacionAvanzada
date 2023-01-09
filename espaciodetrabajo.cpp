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


const vector<string> &EspacioDeTrabajo::getListadoDeArchivos() const
{
    return listadoDeArchivos;
}

void EspacioDeTrabajo::extraerListadoDeArchivos(string pDirectorio)
{
    //Declaro una variable auxiliar
    vector<string> auxListadoDeArchivos;

    DIR *dir = opendir(pDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
            if( entry->d_name != pto and entry->d_name != ptopto )
                auxListadoDeArchivos.push_back(entry->d_name);
        closedir(dir);
    }

    //Asigno al atributo de la clase lo guardado en la variable auxiliar
    listadoDeArchivos = auxListadoDeArchivos;
}

//void EspacioDeTrabajo::mostrarDirectorio(string pDirectorio)
//{
//    auto lista = listadoDeArchivos;
//    cout<<"Directorio: "<<pDirectorio<<endl;
//    cout<<"Entradas:"<< endl;
//    for(string& entrada : lista)
//        cout<<"\t"<<entrada<<endl;
//}
