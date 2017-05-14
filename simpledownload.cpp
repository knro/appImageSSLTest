#include "simpledownload.h"

#include <QNetworkReply>
#include <QFile>

SimpleDownload::SimpleDownload()
{
    connect(&manager, SIGNAL (finished(QNetworkReply *)), this, SLOT (dataFinished(QNetworkReply *)));
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
    manager.setRedirectPolicy(QNetworkRequest::SameOriginRedirectPolicy);
#endif
}

void SimpleDownload::getHTTPS()
{
    QString cycle       = QDate::currentDate().addDays(7).toString("yyMM");
    QString airportID= "KSAN";
    QUrl    url         = QUrl(QString("https://www.faa.gov/air_traffic/flight_info/aeronav/digital_products/dtpp/search/results/?cycle=%1&ident=%2").arg(cycle,airportID));

    QNetworkRequest request(url);
    m_Reply = manager.get(request);

    qDebug() << "Expected size is 42382 bytes. URL:" << url.toString();

    connect(m_Reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError()));
    connect(m_Reply, SIGNAL(readyRead()), this, SLOT(dataReady()));
}

void SimpleDownload::dataReady()
{
    totalSize += m_Reply->size();
    qCritical() << "Data Ready Size: " << m_Reply->size() << "Total Size Progress:" << totalSize;

    content += m_Reply->readAll();
}

void SimpleDownload::dataFinished(QNetworkReply * pReply)
{
    qCritical() << "Data Finished. Size is " << pReply->size();
    if (totalSize != 42382)
        qCritical() << "Total size does not match expected size, SSL download error!";
    else
        qCritical() << "Total size equals expeted size, SSL download success";

    QFile out("result.html");
    out.open(QFile::WriteOnly);
    out.write(content.toLatin1());
    out.close();

    qCritical() << "Fileout output is result.html";

    pReply->deleteLater();
}

void SimpleDownload::slotError()
{
    qCritical() << "Data Error: " << m_Reply->errorString();

    m_Reply->deleteLater();
}
