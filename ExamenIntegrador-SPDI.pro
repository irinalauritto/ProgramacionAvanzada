QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = 2DCircularOrbitals
TEMPLATE = app
LIBS = -lOpengl32
CONFIG += c++11 console
CONFIG -= app_bundle


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        archivo.cpp \
        archivoaic.cpp \
        archivopnm.cpp \
        binarizador.cpp \
        espaciodetrabajo.cpp \
        filtro.cpp \
        filtromediana.cpp \
        filtropasaaltos.cpp \
        filtropasabajos.cpp \
        imagen.cpp \
        interfazdeusuario.cpp \
        main.cpp \
        pintor.cpp \
        pixel.cpp \
        procesadorestadistico.cpp \
        pseudocoloreador.cpp \
        spdi.cpp \
        visualizador.cpp \
        visualizadorhistograma.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    archivo.h \
    archivoaic.h \
    archivopnm.h \
    binarizador.h \
    espaciodetrabajo.h \
    filtro.h \
    filtromediana.h \
    filtropasaaltos.h \
    filtropasabajos.h \
    imagen.h \
    interfazdeusuario.h \
    pintor.h \
    pixel.h \
    procesadorestadistico.h \
    pseudocoloreador.h \
    spdi.h \
    visualizador.h \
    visualizadorhistograma.h