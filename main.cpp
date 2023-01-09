#include <QApplication>

#include "spdi.h"

#include "pixel.h"
#include <vector>
#include <iostream>;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("chcp 65001");
//    SPDI sistemaDeProcesamiento;
//    sistemaDeProcesamiento.procesarImagenes();

    Pixel pixel1;
    Pixel pixel2;

    vector<float> componentesPixel2;
    componentesPixel2.resize(3);
    componentesPixel2[0] = 0.1;
    componentesPixel2[1] = 0.1;
    componentesPixel2[2] = 0.1;
    pixel2.setComponentes(componentesPixel2);
    pixel1.setR(1);
    pixel1.setG(1);
    pixel1.setB(1);

    if(pixel1 == pixel2)
        cout<<"Los pixeles son iguales"<<endl;
    else
        cout<<"Los pixeles son distintos"<<endl;

    Pixel suma =  (pixel1 + pixel2);
    cout<<"suma: "<<suma.getR()<<" "<< suma.getG()<<" "<<suma.getB()<<endl;

    cout<<pixel1.getR()<<" "<<pixel1.getG()<<" "<<pixel1.getB()<<endl;
    cout<<pixel2.getR()<<" "<<pixel2.getG()<<" "<<pixel2.getB()<<endl;

    Pixel resta = (pixel1 - pixel2);
    cout<<"resta: "<<resta.getR()<<" "<<resta.getG()<<" "<<resta.getB()<<endl;

    cout<<pixel1.getR()<<" "<<pixel1.getG()<<" "<<pixel1.getB()<<endl;
    cout<<pixel2.getR()<<" "<<pixel2.getG()<<" "<<pixel2.getB()<<endl;


    Pixel producto = (pixel1 * pixel2);

    cout<<"producto: "<<producto.getR()<<" "<<producto.getG()<<" "<<producto.getB()<<endl;

    cout<<pixel1.getR()<<" "<<pixel1.getG()<<" "<<pixel1.getB()<<endl;
    cout<<pixel2.getR()<<" "<<pixel2.getG()<<" "<<pixel2.getB()<<endl;






//    return a.exec();
    return 10;
}
