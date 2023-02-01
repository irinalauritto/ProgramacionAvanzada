#ifndef PSEUDOCOLOREADOR_H
#define PSEUDOCOLOREADOR_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "pixel.h"
#include "imagen.h"

using namespace std;

class Pseudocoloreador
{
private:
   vector <Pixel> tablaLUT;
public:
    Pseudocoloreador();
    void colorearImagen(Imagen *iIntensidad);
    void leerArchivoLUT(string rutaLUT); //recibir intensidad y devolver un pixel rgb
};

#endif // PSEUDOCOLOREADOR_H
