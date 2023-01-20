#include <QApplication>

#include "spdi.h"
#include "espaciodetrabajo.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("chcp 65001");
    SPDI sistemaDeProcesamiento;
    sistemaDeProcesamiento.procesarImagenes();

    return a.exec();
    return 10;
}
