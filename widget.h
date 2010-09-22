#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDesktopWidget>
#include <QPixmap>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QDebug>
#include <QtNetwork/QNetworkReply>

#include "scrollwidget.h"
#include "tablewidget.h"
#include "rss.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;
    QRect screenRect;
    QPalette pal;
    QPixmap pix;

    ScrollWidget *scr;
    TableWidget *tbl;
    Rss *rss;
};

#endif // WIDGET_H
