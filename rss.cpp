#include "rss.h"

Rss::Rss(QWidget *parent) :
    QWidget(parent)
{
    /* Set up the network manager. */
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    openRssFeed();
}

QStringList Rss::showFeeds()
{
    qDebug()<<"Feeds-:"<<feeds;
    return feeds;
}

void Rss::getFeedDatas(QStringList list)
{
    feeds<<list;
    //qDebug()<<"FeedsGetFeed-:"<<feeds;
}

void Rss::openRssFeed()
{
    /* Set the RSS URL */
    reply = manager->get(QNetworkRequest(QUrl("http://localhost/feed.xml")));
}

void Rss::replyFinished(QNetworkReply * netReply)
{
   QString str(netReply->readAll());

    if (!doc.setContent(str, false, &error))
    {
        qDebug()<<"Error, Something terribly went wrong";
    }
    else
    {
        docElem = doc.documentElement();
        nodeList = docElem.elementsByTagName("item");

        for (uint i = 0; i < nodeList.length(); i++)
        {
            node = nodeList.item(i);
            e = node.toElement();
            strTitle =  e.elementsByTagName("title").item(0).firstChild().nodeValue();
            strLink = e.elementsByTagName("link").item(0).firstChild().nodeValue();
            strDescription = e.elementsByTagName("description").item(0).firstChild().nodeValue();
            feedDatas << strTitle << ":" << strLink << ":" << strDescription;
        }
        getFeedDatas(feedDatas);
    }
    //qDebug()<<"RSS -:" << feedDatas;
}

