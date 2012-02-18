#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //türkçe karakterler için

    QTextCodec::setCodecForLocale( QTextCodec::codecForName("ISO-8859-9") );
    QTextCodec::setCodecForTr( QTextCodec::codecForName("ISO-8859-9") );



    MainWindow w;
    w.show();


    return a.exec();
}
