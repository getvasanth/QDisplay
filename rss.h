#ifndef RSS_H
#define RSS_H

#include <QWidget>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QDebug>
#include <QtNetwork/QNetworkReply>


class Rss : public QWidget
{

public:
    explicit Rss(QWidget *parent = 0);
    QStringList showFeeds();

signals:

private slots:
    void replyFinished(QNetworkReply*);
    void openRssFeed();

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QDomNode node;
    QDomElement e;
    QString strTitle;
    QString strLink;
    QString strDescription;
    QDomElement docElem;
    QDomNodeList nodeList;
    QDomDocument doc;
    QString error;
    QStringList feeds;
    QStringList feedDatas;
    void getFeedDatas(QStringList);



    Q_OBJECT
};

#endif // RSS_H
