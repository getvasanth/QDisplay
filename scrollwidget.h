#ifndef SCROLLWIDGET_H
#define SCROLLWIDGET_H

#include <QWidget>
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
#include <QDebug>
#include <QTimerEvent>
#include <QLabel>
#include <QObject>
#include <QFont>
#include <QPoint>
#include <QLinearGradient>
#include "ticker.h"
#include <QHBoxLayout>
#include <QLineEdit>

class ScrollWidget : public QWidget
{
    Q_OBJECT
private:
    int space, startPos, x;
    QLabel *lbl;
    Ticker *ticker;
    QRect screenRect;
    QDesktopWidget *desktopWidget;
    QPoint *start, *end;
    QLinearGradient *gradient;
    QString myText;
    int offset;
    int myTimerId;

    QHBoxLayout *mainLayout;

public:
    ScrollWidget(QWidget *parent = 0);
    ~ScrollWidget();
    QPixmap bg;
    QPainter* pPainter;
    static QRegion roundedRect(const QRect& rect, int r);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SCROLLWIDGET_H
