#include <QApplication>

#include "spdi.h"
#include "interfazdeusuario.h"

#include "espaciodetrabajo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    system("chcp 65001");
    SPDI sistemaDeProcesamiento;
    InterfazDeUsuario interfaz;
    interfaz.setSPDI(&sistemaDeProcesamiento);
    interfaz.mostrarMenu();


//    return a.exec();
    return 10;
}
