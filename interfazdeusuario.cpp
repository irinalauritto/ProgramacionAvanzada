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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"Para volver al menú inicial presione Ctrl + Q."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"Para salir presione escape."<<endl<<endl;
    //Cambiamos nuevamente el color del texto para que se mantenga el original
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void InterfazDeUsuario::guardarImagen(string &pTipoArchivo, string &pNombre, string &pTipoImagen)
{
    string opcionTipo;
    cout<<"Elija el formato de archivo: "<<endl;
    cout<<"P1: imagen monocromática escrita en archivo de texto."<<endl;
    cout<<"P2: imagen en escala de grises escrita en archivo de texto."<<endl;
    cout<<"P3: imagen RGB escrita en archivo de texto."<<endl;
    cout<<"P4: imagen monocromática escrita en archivo binario."<<endl;
    cout<<"P5: imagen en escala de grises escrita en archivo binario."<<endl;
    cout<<"P6: imagen RGB escrita en archivo binario."<<endl;
    cout<<"P2C: imagen en escala de grises escrita en archivo de texto comprimido."<<endl<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"La imagen actual es de tipo "<<pTipoImagen<<"."<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cin>>opcionTipo;

    while(opcionTipo != "P1" and opcionTipo != "P2" and opcionTipo != "P2C" and opcionTipo != "P3" and opcionTipo != "P4" and opcionTipo != "P5" and opcionTipo != "P6")
    {
        cout<<endl<<"La opción ingresada es incorrecta. Reintente."<<endl;
        cin>>opcionTipo;
    }

    while(pTipoImagen == "Monocoromatica" and (opcionTipo != "P1" and opcionTipo != "P4"))
    {
        cout<<endl<<"La opción ingresada es incorrecta. Reintente. Su elección debe ser un tipo de imagen monocromatica."<<endl;
        cin>>opcionTipo;
    }

    while((pTipoImagen == "Intensidades" or pTipoImagen == "IntensidadesC") and (opcionTipo != "P2" and opcionTipo != "P2C" and opcionTipo != "P5"))
    {
        cout<<endl<<"La opción ingresada es incorrecta. Reintente. Su elección debe ser un tipo de imagen en esacala de grises."<<endl;
        cin>>opcionTipo;
    }

    while((pTipoImagen == "RGB") and (opcionTipo != "P2" and opcionTipo != "P3" and opcionTipo != "P5" and  opcionTipo != "P6"))
    {
        cout<<endl<<"La opción ingresada es incorrecta. Reintente. Su elección debe ser un tipo de imagen RGB o en escala de grises."<<endl;
        cin>>opcionTipo;
    }

    pTipoArchivo = opcionTipo;

    string opcionNombre;

    cout<<endl;
    cout<<"Ingrese el nombre de su archivo. Recuerde que no son válidos caracteres extraños, puntos, espacios, guiones medios."<<endl;
    cin>>opcionNombre;
    pNombre = opcionNombre;
}

void InterfazDeUsuario::imagenGuardada(string &pCarpeta, string &pNombre, string &pTipo)
{
    atajosDeTeclado();
    cout<<"La imagen se guardó con éxito."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"La ubicacion de la misma es "<<pCarpeta<<"."<<endl;
    cout<<"El archivo se llama "<<pNombre<<" y es de tipo "<<pTipo<<endl<<endl;
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
    {
        system("CLS");
        return true;
    }
    else
    {
        return false;
    }


}

int InterfazDeUsuario::opcionesDirectorio()
{
    //Se consulta al usuario el directorio que desería abrir
    int auxOpcion;

    cout<<"Elija un directorio, por favor:"<<endl;
    cout<<"1) Carpeta de imágenes 1"<<endl;
    cout<<"2) Carpeta de imágenes 2"<<endl;
    cout<<"3) Carpeta de imágenes 3 (corruptas)"<<endl;
    cout<<"4) Carpeta de imágenes 4 (modificadas)"<<endl;
    cout<<"5) Ultima imagen visualizada"<<endl;
    cout<<"Ingrese 0 para cerrar el programa."<<endl;
    cin>>auxOpcion;


    //Las siguientes líneas corrsponden a un control para evitar ingresos de opciones inválidas.
    while(auxOpcion != 1 and auxOpcion != 2 and auxOpcion != 3 and auxOpcion != 4 and auxOpcion!= 5 and auxOpcion != 0)
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
    case 5:
        return 5;
    }
    if (auxOpcion == 0)
        exit(0);
}

int InterfazDeUsuario::aumentoBrillo()
{
    int unidadesAumento;
    cout<<"¿En cuántas unidades desea aumentar el brillo de la imagen?"<<endl;

    cin>>unidadesAumento;

    return unidadesAumento;
}

int InterfazDeUsuario::disminucionBrillo()
{
    int unidadesDisminucion;
    cout<<"¿En cuántas unidades desea disminuir el brillo de la imagen?"<<endl;

    cin>>unidadesDisminucion;

    return unidadesDisminucion;
}

int InterfazDeUsuario::getUmbralBinarizacion()
{
    int umbral;
    cout<<"¿A partir de qué valor desea binarizar la imagen? El mismo debe hallarse entre 0 y 255"<<endl;

    cin>>umbral;

    while(umbral<0 or umbral>256)
    {
        cout<<"El valor ingresado es incorrecto. Reintente, por favor."<<endl;
        cin>>umbral;
    }

    return umbral;

}

void InterfazDeUsuario::opcionAtajo(string opcion)
{
    if(opcion == "H")
    {
        cout<<"Usted ha solicitado obtener el histograma de la imagen y los datos estadísticos de la misma."<<endl;
    }

    if(opcion == "click izquierdo")
    {
        cout<<"Usted ha solicitado que se detecten los píxeles que son iguales al seleccionado."<<endl;
    }

    if(opcion == "G")
    {
        cout<<"Usted ha solicitado que se guarde la imagen."<<endl;
    }

    if(opcion == "1")
    {
        cout<<"Usted ha solicitado pseudocolorear la imagen con la tabla LUT 1."<<endl;
    }

    if(opcion == "2")
    {
        cout<<"Usted ha solicitado pseudocolorear la imagen con la tabla LUT 2."<<endl;
    }

    if(opcion == "S")
    {
        cout<<"Usted ha solicitado aplicar el filtro de suavizado."<<endl;
    }

    if(opcion == "M")
    {
        cout<<"Usted ha solicitado aplicar el filtro de mediana."<<endl;
    }

    if(opcion == "N")
    {
        cout<<"Usted ha solicitado negativizar la imagen."<<endl;
    }

    if(opcion == "B")
    {
        cout<<"Usted ha solicitado binarizar la imagen."<<endl;
    }

    if(opcion == "+")
    {
        cout<<"Usted ha solicitado aumentar el brillo de la imagen."<<endl;
    }

    if(opcion == "-")
    {
        cout<<"Usted ha solicitado bajar el brillo de la imagen."<<endl;
    }

    if(opcion == "C")
    {
        cout<<"Usted ha solicitado ajustar el contraste de la imagen."<<endl;
    }

    if(opcion == "Q")
    {
        cout<<"Usted ha solicitado volver al menú inicial."<<endl;
    }

    if(opcion == "escape")
    {
        cout<<"Usted ha solicitado salir del programa."<<endl;
    }
}

void InterfazDeUsuario::mostrarEstadisticos(Pixel pMaximo, Pixel pMinimo, Pixel pMedia, Pixel pDesvioEstandar, Pixel pModa)
{
    cout<<"Datos estadísticos: "<<"\t\t\t"<<"R\t"<<"G\t"<<"B\t"<<endl;
    cout<<"Máximo: "<<"\t\t\t\t"<<pMaximo.getPrimerComponente()<<"\t"<<pMaximo.getSegundaComponente()<<"\t"<<pMaximo.getTercerComponente()<<"\t"<<endl;
    cout<<"Mínimo: "<<"\t\t\t\t"<<pMinimo.getPrimerComponente()<<"\t"<<pMinimo.getSegundaComponente()<<"\t"<<pMinimo.getTercerComponente()<<"\t"<<endl;
    cout<<"Media:  "<<"\t\t\t\t"<<pMedia.getPrimerComponente()<<"\t"<<pMedia.getSegundaComponente()<<"\t"<<pMedia.getTercerComponente()<<"\t"<<endl;
    cout<<"Desvio Estándar: "<<"\t\t\t"<<pDesvioEstandar.getPrimerComponente()<<"\t"<<pDesvioEstandar.getSegundaComponente()<<"\t"<<pDesvioEstandar.getTercerComponente()<<"\t"<<endl;
    cout<<"Moda: "<<"\t\t\t\t\t"<<pModa.getPrimerComponente()<<"\t"<<pModa.getSegundaComponente()<<"\t"<<pModa.getTercerComponente()<<"\t"<<endl;

}

void InterfazDeUsuario::errorTipoImagen(string tipoImagen)
{
    cout<<"Tipo de imagen no compatible. La imagen actual es de tipo "<<tipoImagen<<"."<<endl;
}

void InterfazDeUsuario::comunicarArea(int pArea)
{
    cout<<"El área detectada es de "<<pArea<<" píxeles."<<endl;

}

void InterfazDeUsuario::alertaDeError()
{
    system("CLS");

    cout<<"\a";
    cout<<"Disculpe, la opción elegida no se encuentra disponible. La carpeta se encuentra actualmente vacía."<<endl;
    cout<<"Probablemente es la primer ejecuación del programa."<<endl;
    cout<<"Intente nuevamente, por favor."<<endl<<endl;
}




