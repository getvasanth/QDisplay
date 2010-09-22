#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QDebug>
#include <QPainter>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QHeaderView>
#include "rss.h"

class TableWidget : public QWidget
{
Q_OBJECT
    QDesktopWidget *desktopWidget;
    QRect screenRect;
    int space, startPosx, startPosy, width, height;
public:
    explicit TableWidget(QWidget *parent = 0);
    static QRegion roundedRect(const QRect& rect, int r);
    Rss *rss;
protected:
   void paintEvent(QPaintEvent*);
signals:

public slots:

private:
   QTableWidget *tableWidget;
   QTableWidgetItem *item0, *item1, *item2;
   QFont font;
   QVBoxLayout *mainLayout;
   QGroupBox *formGroupBox;
   QFormLayout *layout;

};

#endif // TABLEWIDGET_H
