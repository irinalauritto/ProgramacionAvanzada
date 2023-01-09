#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

using namespace std;



//Probar clase
class Pixel
{
private:
    vector<float> componentes;
public:
    Pixel();
    void setComponentes(vector<float> &newComponentes);
    void setR(float pR);
    void setG(float pG);
    void setB(float pB);
    float getR();
    float getG();
    float getB();

    //revisar como debo pasar como referencia
    bool operator==(Pixel pPixel);
    Pixel operator- (Pixel pPixel);
    Pixel operator+ (Pixel pPixel);
    Pixel operator* (Pixel pPixel);
};

#endif // PIXEL_H
