#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>

#include "pixel.h"

using namespace std;

class Imagen
{
private:
    vector<vector<Pixel> > pixeles;
    unsigned int ancho;
    unsigned int alto;
    int maximoValor; //Rango dinámico
    string comentarios; //Comentarios extraídos del archivo de la imagen

public:
    Imagen();
    Imagen(int pAncho, int pAlto);

    int getAncho();
    int getAlto();

    float getRed(int columna, int fila);
    float getGreen(int columna, int fila);
    float getBlue(int columna, int fila);

    void setTamanio(int pAncho, int pAlto);
    void modificarPixel(int columna, int fila, int red, int green, int blue);

    //Ajustes
    void aumentarBrillo();
    void disminuirBrillo();
    void ajustarContraste();
    void setMaximoValor(int newMaximoValor);
    void setComentarios(string newComentarios);
    int getMaximoValor() const;
    const string &getComentarios() const;
};

#endif // IMAGEN_H
