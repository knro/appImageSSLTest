#include <QCoreApplication>
#include "simpledownload.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting SSL Test...";
    SimpleDownload *httpsDownload = new SimpleDownload();
    httpsDownload->getHTTPS();


    return a.exec();
}
