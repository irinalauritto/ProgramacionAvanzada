#include "archivopnm.h"

ArchivoPNM::ArchivoPNM()
{

}

void ArchivoPNM::setNombreArchivo(const string &newNombreArchivo)
{
    nombreArchivo = newNombreArchivo;
}

const string &ArchivoPNM::getNombreArchivo() const
{
    return nombreArchivo;
}


string ArchivoPNM::devolverTipo()
{
    return tipoArchivo;
}


void ArchivoPNM::setTipoArchivo(const string pTipoArchivo)
{
    tipoArchivo = pTipoArchivo;
}

void ArchivoPNM::leerArchivoImagen(string ruta, Imagen &imagen)
{
    fstream archivoPNM;
    int pColumnas, pFilas, pMaximoValor;
    string comentarios;
    string auxiliarPosicion;

    archivoPNM.open(ruta);

    if(!archivoPNM.is_open())
    {
        cout<<"No se pudo abrir el archivo"<<endl;;
        cout<<ruta<<endl;
    }

    if (archivoPNM.is_open())
    {
        try
        {
            getline(archivoPNM,tipoArchivo,'\n');

            if(tipoArchivo != "P1" and tipoArchivo != "P2" and tipoArchivo != "P3" and tipoArchivo != "P4" and  tipoArchivo != "P5" and tipoArchivo != "P6")
            {
                imagen.setEstaAlterada(true);
                throw(err);
            }

            if(tipoArchivo=="P1") //Monocromática
            {
                imagen.setTipoImagen("Monocromatica");

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                imagen.setMaximoValor(1);

                unsigned int valor = 0;

                for(int fila = 0; fila < imagen.getCantidadFilas(); ++fila)
                {
                    for(int columna = 0; columna < imagen.getCantidadColumnas(); ++columna)
                    {
                        archivoPNM>>valor;
                        imagen.modificarPixel(columna, fila, valor, valor, valor);
                    }
                }
            }
        }
        catch(runtime_error &e)
        {
            puts(e.what());
        }

        try
        {


            if(tipoArchivo=="P2") //Escala de grises
            {
                imagen.setTipoImagen("Intensidades");

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                archivoPNM>>pMaximoValor;

                imagen.setMaximoValor(pMaximoValor);

                float intensidad;

                for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
                {
                    for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
                    {
                        archivoPNM>>intensidad;
                        imagen.modificarPixel(columna, fila, intensidad, intensidad, intensidad);
                    }

                }
            }
        }
        catch(runtime_error &e)
        {
            puts(e.what());
        }

        try
        {
            if(tipoArchivo=="P3") //RGB
            {
                imagen.setTipoImagen("RGB");

                float red, green, blue;

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                archivoPNM>>pMaximoValor;

                imagen.setMaximoValor(pMaximoValor);

                getline(archivoPNM, auxiliarPosicion,'\n');


                for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
                {
                    for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
                    {
                        archivoPNM>>red>>green>>blue;
                        imagen.modificarPixel(columna, fila, red, green, blue);
                    }
                }
            }
        }
        catch(runtime_error &e)
        {
            puts(e.what());
        }

        try
        {
            if(tipoArchivo=="P4") //Monocromática
            {
                imagen.setTipoImagen("Monocromatica");

                unsigned char pValor;
                char posicionPunteroArchivo;

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                imagen.setMaximoValor(1);

                getline(archivoPNM, auxiliarPosicion,'\n');

                posicionPunteroArchivo = archivoPNM.tellg();

                archivoPNM.close();

                fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

                archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

                for(int fila = 0; fila < imagen.getCantidadFilas();fila++)
                {
                    for(int columna = 0; columna < imagen.getCantidadColumnas(); columna++)
                    {
                        archivoPNM.read((char*)&pValor, sizeof(char));
                        imagen.modificarPixel(columna, fila, pValor,  pValor, pValor);
                    }
                }
            }
        }
        catch(runtime_error &e)
        {
            puts(e.what());
        }

        try
        {
            if(tipoArchivo=="P5") //Escala de grises
            {
                imagen.setTipoImagen("Intensidades");
                unsigned char pIntensidad;
                int intensidad;

                char posicionPunteroArchivo;

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                getline(archivoPNM, auxiliarPosicion,'\n');

                archivoPNM>>pMaximoValor;

                imagen.setMaximoValor(pMaximoValor);

                getline(archivoPNM, auxiliarPosicion,'\n');

                posicionPunteroArchivo = archivoPNM.tellg();

                archivoPNM.close();

                fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

                archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

                for(int fila = 0; fila < imagen.getCantidadFilas() ; ++fila)
                {
                    for(int columna = 0; columna < imagen.getCantidadColumnas() ; ++columna)
                    {
                        archivoPNM.read((char*)&pIntensidad, sizeof(pIntensidad));
                        intensidad = (float)pIntensidad;
                        imagen.modificarPixel(columna, fila, intensidad, intensidad, intensidad);

                    }
                }
            }
        }
        catch(const runtime_error &e)
        {
            puts(e.what());
        }

        try
        {
            if(tipoArchivo=="P6") //RGB
            {
                imagen.setTipoImagen("RGB");

                unsigned char pRed, pGreen, pBlue;
                float red, green, blue;
                char posicionPunteroArchivo;

                getline(archivoPNM, comentarios,'\n');

                imagen.setComentarios(comentarios);

                archivoPNM>>pColumnas>>pFilas;

                imagen.setTamanio(pColumnas, pFilas);

                if(pColumnas == 0 or pFilas == 0)
                {
                    imagen.setEstaAlterada(true);
                    throw (err);
                }

                archivoPNM>>pMaximoValor;

                imagen.setMaximoValor(pMaximoValor);

                getline(archivoPNM, auxiliarPosicion,'\n');

                posicionPunteroArchivo = archivoPNM.tellg();

                archivoPNM.close();

                fstream archivoPNM(ruta.c_str(), ios::binary|ios::in|ios::app);

                archivoPNM.seekg(posicionPunteroArchivo,ios_base::beg);

                for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
                {
                    for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
                    {
                        archivoPNM.read((char*)&pRed, sizeof(pRed));
                        archivoPNM.read((char*)&pGreen, sizeof(pGreen));
                        archivoPNM.read((char*)&pBlue, sizeof(pBlue));

                        red = (float)pRed;
                        blue = (float)pBlue;
                        green = (float)pGreen;

                        imagen.modificarPixel(columna, fila, red, green, blue);
                    }
                }
            }
        }
        catch(runtime_error &e)
        {
            puts(e.what());
        }
    }
}

void ArchivoPNM::guardarImagen(Imagen &imagen, string pTipoArchivo, string pNombreArchivo)
{
    ofstream archivoPNM;

    if(pTipoArchivo == "P1") //Monocromática
    {
        string nombre = pNombreArchivo+ ".pbm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                archivoPNM<<imagen.getPrimerComponente(columna, fila)/imagen.getMaximoValor()<<" ";
            }
        }
    }

    if(pTipoArchivo == "P2") //Escala de grises
    {
        string nombre = pNombreArchivo+ ".pgm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoPNM<<imagen.getMaximoValor()<<endl;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                float intensidad = (imagen.getPrimerComponente(columna,fila) + imagen.getSegundaComponente(columna,fila) + imagen.getTercerComponente(columna,fila) ) / 3.0f;
                archivoPNM<<(float)intensidad<<" ";
            }
        }
    }

    if(pTipoArchivo == "P3") //RGB
    {
        string nombre = pNombreArchivo+ ".ppm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoPNM<<imagen.getMaximoValor()<<endl;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                archivoPNM<<imagen.getPrimerComponente(columna,fila)<<" "<<imagen.getSegundaComponente(columna, fila)<<" "<<imagen.getTercerComponente(columna, fila)<<" ";
            }
        }
    }

    if(pTipoArchivo=="P4") //Monocromática
    {
        string nombre = pNombreArchivo+ ".pbm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoPNM.close();

        fstream archivoPNM(nombre.c_str(), ios::binary|ios::in|ios::app);

        unsigned char valor;
        Pixel auxiliar;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                auxiliar = imagen.devolverPixel(columna, fila);
                valor = auxiliar.getPrimerComponente()/imagen.getMaximoValor();
                archivoPNM.write((char*)&valor, sizeof(char));
            }
        }
    }

    if(pTipoArchivo=="P5") //Escala de grises
    {
        string nombre = pNombreArchivo+ ".pgm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoPNM<<imagen.getMaximoValor()<<endl;

        archivoPNM.close();

        fstream archivoPNM(nombre.c_str(), ios::binary|ios::app);

        unsigned char intensidad;
        Pixel auxiliar;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                auxiliar = imagen.devolverPixel(columna, fila);
                intensidad = (auxiliar.getPrimerComponente() + auxiliar.getSegundaComponente() + auxiliar.getTercerComponente())/3.0f;
                archivoPNM.write((const char*)&intensidad, sizeof(char));
            }
        }
    }

    if(pTipoArchivo=="P6") //RGB
    {
        string nombre = pNombreArchivo+ ".ppm";

        archivoPNM.open(nombre.c_str());

        archivoPNM<<pTipoArchivo<<endl;

        archivoPNM<<imagen.getComentarios()<<endl;

        archivoPNM<<imagen.getCantidadColumnas()<<" "<<imagen.getCantidadFilas()<<endl;

        archivoPNM<<imagen.getMaximoValor()<<endl;

        archivoPNM.close();

        fstream archivoPNM(nombre.c_str(), ios::binary|ios::in|ios::app);

        unsigned char red, green, blue;

        for(int fila = 0; fila<imagen.getCantidadFilas();fila++)
        {
            for(int columna = 0; columna<imagen.getCantidadColumnas(); columna++)
            {
                red = imagen.getPrimerComponente(columna, fila);
                archivoPNM.write((const char*)&red, sizeof(red));

                green = imagen.getSegundaComponente(columna, fila);
                archivoPNM.write((const char*)&green, sizeof(green));

                blue = imagen.getTercerComponente(columna, fila);
                archivoPNM.write((const char*)&blue, sizeof(blue));
            }
        }
    }
}

ArchivoPNM::~ArchivoPNM()
{

}



