#include "scrollwidget.h"
#include <QDesktopWidget>


ScrollWidget::ScrollWidget(QWidget *parent) :   QWidget(parent)
{
    desktopWidget = new QDesktopWidget();
    start = new QPoint(0, 10);
    end = new QPoint(0, 50);
    gradient = new QLinearGradient(*start, *end);
    ticker = new Ticker(this);
    screenRect = desktopWidget->availableGeometry();

    setAutoFillBackground(true);
    startPos = (( screenRect.width() * 5 ) / 100);
    setGeometry(startPos, screenRect.height()-50, screenRect.width(), screenRect.height()/14);
    qDebug()<<screenRect.width();
    setMask(roundedRect(rect(), 20));


    ticker->setText(" This document introduces Qt Assistant, a tool for presenting on-line documentation. The document is divided into the following sections:  ");
    ticker->show();

    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ticker);


}


QRegion ScrollWidget::roundedRect(const QRect& rect, int r)
{
    QRegion region;
    // middle and borders
    region += rect.adjusted(r, 0, -r, 0);
    region += rect.adjusted(0, r, 0, -r);
    // top left
    QRect corner(rect.topLeft(), QSize(r*2, r*2));
    region += QRegion(corner, QRegion::Ellipse);
    // top right
    corner.moveTopRight(rect.topRight());
    region += QRegion(corner, QRegion::Rectangle);
    // bottom left
    corner.moveBottomLeft(rect.bottomLeft());
    region += QRegion(corner, QRegion::Rectangle);
    // bottom right
    corner.moveBottomRight(rect.bottomRight());
    region += QRegion(corner, QRegion::Rectangle);
    return region;

}

void ScrollWidget::paintEvent(QPaintEvent *)
{
    /* Set the Gradient, To Look like 3D Toolbar */
    QPainter painter(this);
    gradient->setColorAt(0, Qt::lightGray);
    gradient->setColorAt(1, Qt::darkGray);
    painter.setBrush(*gradient);

    painter.drawRect(rect());
}

ScrollWidget::~ScrollWidget()
{
    //delete ticker;
}
