#include "grafico.h"
#include "iostream"

#include <QCoreApplication>

grafico::grafico(QString nombre_){
    nombre=nombre_;
    ruta=QCoreApplication::applicationDirPath()+"\\Graficos";
    if(!QDir(ruta).exists()){
        QDir().mkdir(ruta);
    }
}
QString grafico::generarGrafico(QString contenido){
    dot=contenido;
    QString rutaDot=ruta+"\\"+nombre+".dot";
    QString rutaPng=ruta+"\\"+nombre+".png";
    this->generarDot(rutaDot,rutaPng);
    return rutaPng;
}
void grafico::generarDot(QString rutaDot, QString rutaPng){
    QFile archivo(rutaDot);
    if(archivo.open(QIODevice::WriteOnly)){
        QTextStream stream(&archivo);
        stream<<dot<<endl;
    }
    archivo.close();
    std::string crearPNG="dot.exe -Tpng \""+rutaDot.toStdString()+"\" -o +\""+rutaPng.toStdString()+"\" ";
    std::string abrirPNG="start Graficos\\"+nombre.toStdString()+".png";

    const char *comandoCrear=crearPNG.c_str();
    const char *comandoAbrir=abrirPNG.c_str();

    system(comandoCrear);
    system(comandoAbrir);
}
