QT -= gui

QT += widgets       # se añade
LIBS += -lopengl32  # se añade

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        archivo.cpp \
        archivoaic.cpp \
        archivopnm.cpp \
        detectorarea.cpp \
        editorimagen.cpp \
        espaciodetrabajo.cpp \
        filtro.cpp \
        filtromediana.cpp \
        filtropasabajos.cpp \
        imagen.cpp \
        interfazdeusuario.cpp \
        main.cpp \
        manejodeexcepciones.cpp \
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
    detectorarea.h \
    editorimagen.h \
    espaciodetrabajo.h \
    filtro.h \
    filtromediana.h \
    filtropasabajos.h \
    imagen.h \
    interfazdeusuario.h \
    manejodeexcepciones.h \
    pixel.h \
    procesadorestadistico.h \
    pseudocoloreador.h \
    spdi.h \
    visualizador.h \
    visualizadorhistograma.h
