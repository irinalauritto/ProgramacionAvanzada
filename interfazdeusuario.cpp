#include "interfazdeusuario.h"


InterfazDeUsuario::InterfazDeUsuario()
{

}

void InterfazDeUsuario::atajosDeTeclado()
{
    system("CLS");

    cout<<"Lista de atajos de teclado:"<<endl;
    cout<<"Ctrl + flecha izquierda para desplazarse a la imagen anterior. "<<endl;
    cout<<"Ctrl + flecha derecha para desplazarse a la imagen siguiente. "<<endl;
    cout<<"Ctrl + H para obtener el histograma. "<<endl;
    cout<<"Ctrl + click izquierdo, arrastrando sin soltar, para activar el zoom."<<endl;
    cout<<"Ctrl + click derecho para volver la imagen con zoom a su tamaño original. "<<endl;
    cout<<"Ctrl + click izquierdo para aplicar deteción de área con el color o intensidad del píxel sobre el cual se hizo click."<<endl;
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

bool InterfazDeUsuario::menuInicial()
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
        return true;
    else
        return false;

}

int InterfazDeUsuario::opcionesDirectorio()
{
    //Se consulta al usuario el directorio que desería abrir
    system("CLS");

    int auxOpcion;

    cout<<"Elija un directorio, por favor:"<<endl;
    cout<<"1) Carpeta de imágenes 1"<<endl;
    cout<<"2) Carpeta de imágenes 2"<<endl;
    cout<<"3) Carpeta de imágenes 3 (corruptas)"<<endl;
    cout<<"4) Carpeta de imágenes 4 (modificadas)"<<endl;
    cout<<"Ingrese 0 para cerrar el programa."<<endl;
    cin>>auxOpcion;


    //Las siguientes líneas corrsponden a un control para evitar ingresos de opciones inválidas.
    while(auxOpcion != 1 and auxOpcion != 2 and auxOpcion != 3 and auxOpcion != 4 and auxOpcion!=0)
    {
        cout<< "La opción ingresada es incorrecta. Vuelva a intentarlo, por favor. \a"<<endl;
        cin>>auxOpcion;
        cout<<endl;
    }

    //Se comunica al SPDI la opcion escogida o se cierra el programa
    switch(auxOpcion)
    {
    case 1:
        return 1;

    case 2:
        return 2;

    case 3:
        return 3;
    case 4:
        return 4;
    }
    if (auxOpcion == 0)
        exit(0);
}

void InterfazDeUsuario::alertaDeError()
{
    cout<<"\a";
    cout<<"Disculpe, la opción elegida no se encuentra disponible. "<<endl;
    cout<<"Intente nuevamente, por favor."<<endl;
}




