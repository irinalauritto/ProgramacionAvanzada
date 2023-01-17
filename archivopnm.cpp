#include "archivopnm.h"

void ArchivoPNM::setNombreArchivo(const string &newNombreArchivo)
{
    nombreArchivo = newNombreArchivo;
}

ArchivoPNM::ArchivoPNM()
{

}

string ArchivoPNM::getTipoArchivo()
{
    return tipoArchivo;
}


void ArchivoPNM::setTipoArchivo(const string pTipoArchivo)
{
    tipoArchivo = pTipoArchivo;
}

void ArchivoPNM::leerArchivoImagen(string ruta, Imagen &i)
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
            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Leo los pixeles y los cargo

            int valor; //Representa el valor de la imagen monocromática, solo puede ser 1 o 0.

            for(int fila = 0; fila<i.getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información

                    archivoPNM>>valor;
                    i.modificarPixel(columna, fila, valor, valor, valor);
                }
            }
        }

        if(tipoArchivo=="P2") //Escala de grises
        {
            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i.setMaximoValor(pMaximoValor);

            //Leo los pixeles y los cargo
            int intensidad;

            for(int fila = 0; fila<i.getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información

                    archivoPNM>>intensidad;
                    i.modificarPixel(columna, fila, intensidad, intensidad, intensidad);
                }

            }
        }
        if(tipoArchivo=="P3") //RGB
        {
            float red, green, blue;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i.setMaximoValor(pMaximoValor);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');


            for(int fila = 0; fila<i.getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información

                    archivoPNM>>red>>green>>blue;

                    i.modificarPixel(columna, fila, red, green, blue);
                }
            }
        }

        if(tipoArchivo=="P4") //Monocromática
        {
            unsigned char pValor;
            float valor;
            char posicionPunteroArchivo;


            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i.setMaximoValor(pMaximoValor);

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
            for(int fila = 0; fila<i.getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pValor, sizeof(pValor));

                    valor = (float)pValor;

                    i.modificarPixel(columna, fila, valor,  valor,  valor);
                }
            }
        }

        if(tipoArchivo=="P5") //Escala de grises
        {
            unsigned char pIntensidad;
            float intensidad;

            char posicionPunteroArchivo;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Muevo el puntero hasta la siguiente linea
            getline(archivoPNM, auxiliarPosicion,'\n');

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i.setMaximoValor(pMaximoValor);

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
            for(int fila = 0; fila < i.getCantidadFilas() ; ++fila)
            {
                for(int columna = 0; columna < i.getCantidadColumnas() ; ++columna)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pIntensidad, sizeof(pIntensidad));

                    intensidad = (float)pIntensidad;

                    i.modificarPixel(columna, fila, intensidad, intensidad, intensidad);

                }
            }
        }

        if(tipoArchivo=="P6") //RGB
        {
            unsigned char pRed, pGreen, pBlue;
            float red, green, blue;
            char posicionPunteroArchivo;

            //Leo los comentarios hasta el fin de linea
            getline(archivoPNM, comentarios,'\n');

            //Guardo los comentarios extraídos
            i.setComentarios(comentarios);

            //Leo el número de columnas
            archivoPNM>>pColumnas>>pFilas;

            //Cargo el número de columnas y filas de la imagen
            i.setTamanio(pColumnas, pFilas);

            //Leo el valor máximo del rango dinámico
            archivoPNM>>pMaximoValor;

            //Guardo el valor máximo del rango dinámico
            i.setMaximoValor(pMaximoValor);

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
            for(int fila = 0; fila<i.getCantidadFilas();fila++)
            {
                for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
                {
                    //Leo y guardo la información
                    archivoPNM.read((char*)&pRed, sizeof(pRed));
                    archivoPNM.read((char*)&pGreen, sizeof(pGreen));
                    archivoPNM.read((char*)&pBlue, sizeof(pBlue));

                    red = (float)pRed;
                    blue = (float)pBlue;
                    green = (float)pGreen;

                    i.modificarPixel(columna, fila, red, green, blue);
                }
            }
        }

    }
}

void ArchivoPNM::guardarImagen(Imagen &i)
{
    ofstream archivoPNM;

    if(tipoArchivo == "P1") //Monocromática
    {
        //Abro el archivo
        archivoPNM.open("./ImagenesModificadas/" + nombreArchivo+ ".pbm");

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Cargamos la informacion de los pixeles

        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                archivoPNM<<i.getPrimerComponente(columna, fila)<<" ";
            }
        }
    }

    if(tipoArchivo == "P2") //Escala de grises
    {
        //Abro el archivo
        archivoPNM.open("./ImagenesModificadas/" + nombreArchivo + ".pgm");

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Se carga el valor máximo del rango dinámico
        archivoPNM<<i.getMaximoValor()<<endl;


        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                archivoPNM<<i.getPrimerComponente(columna,fila)<<" ";
            }

        }
    }
    if(tipoArchivo == "P3") //RGB
    {
        //Abro el archivo
        archivoPNM.open("./ImagenesModificadas/" + nombreArchivo + ".ppm");

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Se carga el valor máximo del rango dinámico
        archivoPNM<<i.getMaximoValor()<<endl;

        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                archivoPNM<<i.getPrimerComponente(columna,fila)<<" "<<i.getSegundaComponente(columna, fila)<<" "<<i.getTercerComponente(columna, fila)<<" ";
            }
        }
    }

    if(tipoArchivo=="P4") //Monocromática
    {
        string ruta = "./ImagenesModificadas/" + nombreArchivo+ ".pbm";

        //Abro el archivo
        archivoPNM.open(ruta);

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

        //Recorro todo el archivo restante (la imagen) para extraer la información
        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                float valor = i.getPrimerComponente(columna, fila);
                archivoPNM.write((char*)&valor, sizeof(valor));
            }
        }
    }

    if(tipoArchivo=="P5") //Escala de grises
    {
        string ruta = "./ImagenesModificadas/" + nombreArchivo+ ".pgm";

        //Abro el archivo
        archivoPNM.open(ruta);

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Se carga el máximo valor del rango dinámico
        archivoPNM<<i.getMaximoValor()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

        //Recorro todo el archivo restante (la imagen) para extraer la información
        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                float intensidad = i.getPrimerComponente(columna, fila);
                archivoPNM.write((char*)&intensidad, sizeof(intensidad));
            }
        }
    }

    if(tipoArchivo=="P6") //RGB
    {
        string ruta = "./ImagenesModificadas/" + nombreArchivo+ ".ppm";

        //Abro el archivo
        archivoPNM.open(ruta);

        //Se escribe el tipo de formato
        archivoPNM<<tipoArchivo<<endl;

        //Se escriben los comentarios
        archivoPNM<<i.getComentarios()<<endl;

        //Se cargan el numero de  columnas y de filas
        archivoPNM<<i.getCantidadColumnas()<<" "<<i.getCantidadFilas()<<endl;

        //Se carga el máximo valor del rango dinámico
        archivoPNM<<i.getMaximoValor()<<endl;

        //Cierro el archivo
        archivoPNM.close();

        //Abro el archivo como binario
        fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

        //Recorro todo el archivo restante (la imagen) para extraer la información
        for(int fila = 0; fila<i.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<i.getCantidadColumnas(); columna++)
            {
                //Leo y guardo la información
                float red = i.getPrimerComponente(columna, fila);
                archivoPNM.write((char*)&red, sizeof(red));
                float green = i.getSegundaComponente(columna, fila);
                archivoPNM.write((char*)&green, sizeof(green));
                float blue = i.getTercerComponente(columna, fila);
                archivoPNM.write((char*)&blue, sizeof(blue));
            }
        }
    }

}



