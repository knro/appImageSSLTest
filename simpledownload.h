#ifndef SIMPLEDOWNLOAD_H
#define SIMPLEDOWNLOAD_H

#include <QObject>
#include <QNetworkAccessManager>

class SimpleDownload : public QObject
{
    Q_OBJECT
public:
    SimpleDownload();

    void getHTTPS();

private slots:
    void dataFinished(QNetworkReply * pReply);
    void dataReady();
    void slotError();

private:
    QNetworkAccessManager manager;
    // Network reply
    QNetworkReply * m_Reply = NULL;

    QString content;
    int totalSize=0;

};

#endif // SIMPLEDOWNLOAD_H
