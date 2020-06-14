#ifndef GRAFICO_H
#define GRAFICO_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

class grafico{
public:
    grafico(QString nombre_);
    QString generarGrafico(QString contenido);

private:
    QString ruta,nombre,dot;
    void generarDot(QString rutaDot,QString rutaPng);
};

#endif // GRAFICO_H
