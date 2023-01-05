#include "interfazdeusuario.h"


InterfazDeUsuario::InterfazDeUsuario()
{

}

void InterfazDeUsuario::mostrarAtajosDeTeclado()
{

    cout<<"Lista de atajos de teclado:"<<endl;
    cout<<"Ctrl + flecha izquierda para desplazarse a la imagen anterior. "<<endl;
    cout<<"Ctrl + flecha derecha para desplazarse a la imagen siguiente. "<<endl;
    cout<<"Ctrl + H para obtener el histograma. "<<endl;
    cout<<"Ctrl + click izquierdo, arrastrando sin soltar, para activar el zoom."<<endl;
    cout<<"Ctrl + click derecho para volver la imagen con zoom a su tamaño original. "<<endl;
    cout<<"Ctrl + click izquierdo para aplicar deteción de área con el color o intensidad del píxel sobre el cual se hizo clik."<<endl;
    cout<<"Ctrl + G para guardar la imagen. "<<endl;
    cout<<"Ctrl + 1 para pseudocolorear una imagen de intensidades (mediante Tabla 1)."<<endl;
    cout<<"Ctrl + 2 para pseudocolorear una imagen de intensidades (mediante Tabla 2)."<<endl;
    cout<<"Ctrl + S para aplicar filtro de suavizado. "<<endl;
    cout<<"Ctrl + M para aplicar filtro de mediana. "<<endl;
    cout<<"Ctrl + '+' para aumentar el brillo."<<endl;
    cout<<"Ctrl + '-' para disminuir el brillo."<<endl;
    cout<<"Ctrl + C para ajustar el contraste."<<endl<<endl;

    //Cambiamos el color del texto para resaltar el mensaje
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"Para salir del programa ingrese 0."<<endl<<endl;

    //Cambiamos nuevamente el color del texto para que se mantenga el original
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

int InterfazDeUsuario::mostrarMenu()
{
    //Este método permite al usuario relacionarse con el programa.
    //A través de este mismo método la interfaz provee al SPDI la información que el usuario ingresa.

    system("chcp 65001");

    system("CLS");

    SetConsoleTitleA("Sistema de Procesamiento Digital de Imágenes");


    int auxOpcion;
    cout<<"¡Bienvenido al programa de procesamiento digital de imágenes!"<<endl<<endl;
    cout<< "¿Desea inciar el procesamiento de imágenes? "<<endl<<"Ingrese 1 por sí o 0 por no."<<endl;
    cin>>auxOpcion;
    cout<<endl;


    //Las siguientes líneas corrsponden a un control para evitar ingresos de opciones inválidas.
    while(auxOpcion != 1 and auxOpcion !=0)
    {
        cout<< "La opción ingresada es incorrecta. Vuelva a intentarlo, por favor. /a"<<endl;
        cin>>auxOpcion;
        cout<<endl;
    }

    //Se da inicio o no al procesamiento de imágenes
    if(auxOpcion==1)
        sistemaDeProcesamiento->procesarImagenes();
    else
        return 1;

    //Se consulta al usuario el directorio que desería abrir
    system("CLS");

    cout<<"Elija un directorio, por favor:"<<endl;
    cout<<"1) Carpeta de imágenes 1"<<endl;
    cout<<"2) Carpeta de imágenes 2"<<endl;
    cout<<"3) Carpeta de imágenes 3 (corruptas)"<<endl;
    cout<<"Ingrese 0 para cerrar el programa."<<endl;
    cin>>auxOpcion;


    //Las siguientes líneas corrsponden a un control para evitar ingresos de opciones inválidas.
    while(auxOpcion != 1 and auxOpcion !=2 and auxOpcion !=3 and auxOpcion !=0)
    {
        cout<< "La opción ingresada es incorrecta. Vuelva a intentarlo, por favor. \a"<<endl;
        cin>>auxOpcion;
        cout<<endl;
    }

    //Se comunica al SPDI la opcion escogida o se cierra el programa
    switch(auxOpcion)
    {
    case 1:
        sistemaDeProcesamiento->setOpcionDirectorio(1);

    case 2:
        sistemaDeProcesamiento->setOpcionDirectorio(2);

    case 3:
        sistemaDeProcesamiento->setOpcionDirectorio(3);

    }
    if (auxOpcion==0)
        return 0;

    //Una vez iniciado el procesamiento, se muestra la lista de atajos de teclado.
    system("CLS");

    this->mostrarAtajosDeTeclado();

    //Leemos la opcion por si el usuario desea salir del programa
    cin>>auxOpcion;
    cout<<endl;

    while(auxOpcion != 0)
    {
        system("CLS");
        this->mostrarAtajosDeTeclado();

        cout<< "La opción ingresada es incorrecta. Vuelva a intentarlo, por favor. \a"<<endl;
        cin>>auxOpcion;
        cout<<endl<<endl;
    }

    if(auxOpcion == 0)
    {
        //Limpiamos la consola y cambiamos el color del texto
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        cout<<"Usted ha cerrado el programa."<<endl<<endl;

        //Retornamos el texto al color original
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        return 0;
    }

}

void InterfazDeUsuario::setSPDI(SPDI *pSistema)
{
    sistemaDeProcesamiento = pSistema;
}


