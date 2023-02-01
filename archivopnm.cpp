#include "archivopnm.h"

void ArchivoPNM::setNombreArchivo(const string &newNombreArchivo)
{
    nombreArchivo = newNombreArchivo;
}

const string &ArchivoPNM::getNombreArchivo() const
{
    return nombreArchivo;
}

ArchivoPNM::ArchivoPNM()
{

}

string ArchivoPNM::devolverTipo()
{
    return tipoArchivo;
}


void ArchivoPNM::setTipoArchivo(const string pTipoArchivo)
{
    tipoArchivo = pTipoArchivo;
}

void ArchivoPNM::leerArchivoImagen(string ruta, Imagen *i)
{
    fstream archivoPNM;
    int pColumnas, pFilas, pMaximoValor;
    string comentarios;

    // Este auxiliar se utilizará para manipular la posición dentro del archivo
    string auxiliarPosicion;

    //Abro el archivo
    archivoPNM.open(ruta);

    if(!archivoPNM.is_open())
    {
        cout<<"No se pudo abrir el archivo"<<endl;;
        cout<<ruta<<endl;
    }

    if (archivoPNM.is_open())
    {
        //Leo la primer linea y obtengo el tipo de formato
        getline(archivoPNM,tipoArchivo,'\n');

        if(tipoArchivo=="P1") //Monocromática
        {
            i->setTipoImagen("Monocromatica");

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);

            //Se setea 1 como Maximo valor del rango dinamico
            i->setMaximoValor(1);

            //Leo los pixeles y los cargo

            unsigned int valor = 0; //Representa el valor de la imagen monocromática, solo puede ser 1 o 0.

            for(int fila = 0; fila < i->getCantidadFilas(); ++fila)
            {
                for(int columna = 0; columna < i->getCantidadColumnas(); ++columna)
                {
                    //Leo y guardo la información
                    archivoPNM>>valor;
                    i->modificarPixel(columna, fila, valor, valor, valor);
                }
            }
        }

        if(tipoArchivo=="P2") //Escala de grises
        {
            i->setTipoImagen("Intensidades");

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i->setMaximoValor(pMaximoValor);

            //Leo los pixeles y los cargo
            float intensidad;

            for(int fila = 0; fila<i->getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información

                    archivoPNM>>intensidad;
                    i->modificarPixel(columna, fila, intensidad, intensidad, intensidad);
                }

            }
        }
        if(tipoArchivo=="P3") //RGB
        {
            i->setTipoImagen("RGB");

            float red, green, blue;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i->setMaximoValor(pMaximoValor);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');


            for(int fila = 0; fila<i->getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información

                    archivoPNM>>red>>green>>blue;

                    i->modificarPixel(columna, fila, red, green, blue);
                }
            }
        }

        if(tipoArchivo=="P4") //Monocromática
        {
            i->setTipoImagen("Monocromatica");

            unsigned char pValor;
            char posicionPunteroArchivo;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);            

            //Se setea 1 como Maximo valor del rango dinamico
            i->setMaximoValor(1);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');

            //Guardo la posicion del puntero en el archivo
            posicionPunteroArchivo = archivoPNM.tellg();

            //Cierro el archivo
            archivoPNM.close();

            //Abro el archivo como binario
            fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

            //Posiciono el puntero del archivo en la ubicación en la que estaba antes de cerrarse
            archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

            //Recorro todo el archivo restante (la imagen) para extraer la información
            for(int fila = 0; fila < i->getCantidadFilas();fila++)
            {
                for(int columna = 0; columna < i->getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pValor, sizeof(char));

                   // valor = (float)pValor;

                    i->modificarPixel(columna, fila, pValor,  pValor, pValor);
                }
            }
        }

        if(tipoArchivo=="P5") //Escala de grises
        {
            i->setTipoImagen("Intensidades");

            unsigned char pIntensidad;
            float intensidad;

            char posicionPunteroArchivo;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i->setMaximoValor(pMaximoValor);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');

            //Guardo la posicion del puntero en el archivo
            posicionPunteroArchivo = archivoPNM.tellg();

            //Cierro el archivo
            archivoPNM.close();

            //Abro el archivo como binario
            fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

            //Posiciono el puntero del archivo en ubicacion en la que estaba antes de cerrarse
            archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

            //Recorro todo el archivo restante (la imagen) para extraer la información
            for(int fila = 0; fila < i->getCantidadFilas() ; ++fila)
            {
                for(int columna = 0; columna < i->getCantidadColumnas() ; ++columna)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pIntensidad, sizeof(pIntensidad));

                    intensidad = (float)pIntensidad;

                    i->modificarPixel(columna, fila, intensidad, intensidad, intensidad);

                }
            }
        }

        if(tipoArchivo=="P6") //RGB
        {
            i->setTipoImagen("RGB");

            unsigned char pRed, pGreen, pBlue;
            float red, green, blue;
            char posicionPunteroArchivo;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i->setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i->setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i->setMaximoValor(pMaximoValor);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');

            //Guardo la posicion del puntero en el archivo
            posicionPunteroArchivo = archivoPNM.tellg();

            //Cierro el archivo
            archivoPNM.close();

            //Abro el archivo como binario
            fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

            //Posiciono el puntero del archivo en ubicacion en la que estaba antes de cerrarse
            archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

            //Recorro todo el archivo restante (la imagen) para extraer la información
            for(int fila = 0; fila<i->getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pRed, sizeof(pRed));
                    archivoPNM.read((char*)&pGreen, sizeof(pGreen));
                    archivoPNM.read((char*)&pBlue, sizeof(pBlue));

                    red = (float)pRed;
                    blue = (float)pBlue;
                    green = (float)pGreen;

                    i->modificarPixel(columna, fila, red, green, blue);
                }
            }
        }

    }
}

void ArchivoPNM::guardarImagen(Imagen *i, string pTipoArchivo, string pNombreArchivo)
{
    ofstream archivoPNM;

    if(pTipoArchivo == "P1") //Monocromática
    {
        string nombre = pNombreArchivo+ ".pbm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Cargamos la informacion de los pixeles

        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                archivoPNM<<i->getPrimerComponente(columna, fila)<<" ";

            }
        }
    }

    if(pTipoArchivo == "P2") //Escala de grises
    {
        string nombre = pNombreArchivo+ ".pgm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Se carga el valor máximo del rango dinámico
        archivoPNM<<i->getMaximoValor()<<endl;


        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                float intensidad = (i->getPrimerComponente(columna,fila) + i->getSegundaComponente(columna,fila) + i->getTercerComponente(columna,fila) ) / 3.0;
                archivoPNM<<intensidad<<" ";
            }

        }
    }
    if(pTipoArchivo == "P3") //RGB
    {
        string nombre = pNombreArchivo+ ".ppm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Se carga el valor máximo del rango dinámico
        archivoPNM<<i->getMaximoValor()<<endl;

        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                archivoPNM<<i->getPrimerComponente(columna,fila)<<" "<<i->getSegundaComponente(columna, fila)<<" "<<i->getTercerComponente(columna, fila)<<" ";
            }
        }
    }

    if(pTipoArchivo=="P4") //Monocromática
    {
        string nombre = pNombreArchivo+ ".pbm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(nombre.c_str(), ios::binary|ios::in|ios::app);

        //Recorro todo el archivo restante (la imagen) para extraer la información
        unsigned char valor;
        Pixel auxiliar;

        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                auxiliar = i->devolverPixel(columna, fila);
                valor = auxiliar.getPrimerComponente();
                archivoPNM.write((char*)&valor, sizeof(char));
            }
        }
    }

    if(pTipoArchivo=="P5") //Escala de grises
    {
        string nombre = pNombreArchivo+ ".pgm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Se carga el máximo valor del rango dinámico
        archivoPNM<<i->getMaximoValor()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(nombre.c_str(), ios::binary|ios::app);

        unsigned char intensidad;
        Pixel auxiliar;

        //Recorro todo el archivo restante (la imagen) para extraer la información
        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                auxiliar = i->devolverPixel(columna, fila);
                intensidad = (auxiliar.getPrimerComponente() + auxiliar.getSegundaComponente() + auxiliar.getTercerComponente())/3.0;
                archivoPNM.write((const char*)&intensidad, sizeof(char));
            }
        }
    }

    if(pTipoArchivo=="P6") //RGB
    {
        string nombre = pNombreArchivo+ ".ppm";

        //Abro el archivo
        archivoPNM.open(nombre.c_str());

        //Se escribe el tipo de formato
        archivoPNM<<pTipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i->getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i->getCantidadColumnas()<<" "<<i->getCantidadFilas()<<endl;

        //Se carga el máximo valor del rango dinámico
        archivoPNM<<i->getMaximoValor()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(nombre.c_str(), ios::binary|ios::in|ios::app);

        unsigned char red, green, blue;

        //Recorro todo el archivo restante (la imagen) para extraer la información
        for(int fila = 0; fila<i->getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i->getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                red = i->getPrimerComponente(columna, fila);
                archivoPNM.write((const char*)&red, sizeof(red));

                green = i->getSegundaComponente(columna, fila);
                archivoPNM.write((const char*)&green, sizeof(green));

                blue = i->getTercerComponente(columna, fila);
                archivoPNM.write((const char*)&blue, sizeof(blue));
            }
        }
    }

}



