#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    desktopWidget = new QDesktopWidget();
    screenRect = desktopWidget->availableGeometry();

    startPosx = (( screenRect.width() * 25 ) / 100);
    startPosy = (( screenRect.height() * 15.6 ) / 100);
    height = (( screenRect.height() * 79.5 ) / 100);
    width = (( screenRect.width() * 75) / 100);
    setGeometry(startPosx, startPosy, width, height);
    setPalette(QColor(Qt::lightGray));
    setMask(roundedRect(rect(), 30));

    rss = new Rss(this);

    tableWidget = new QTableWidget(3, 3, this);
    QStringList labels;
        labels << tr("ITEM1") << tr("ITEM2") << tr("ITEM3");
        tableWidget->setHorizontalHeaderLabels(labels);

    tableWidget->setHorizontalHeaderLabels(labels);
    tableWidget->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);

    tableWidget->verticalHeader()->setResizeMode(0, QHeaderView::Stretch);
    tableWidget->verticalHeader()->setResizeMode(1, QHeaderView::Stretch);
    tableWidget->verticalHeader()->setResizeMode(2, QHeaderView::Stretch);

    tableWidget->setFrameStyle(QFrame::NoFrame);
    tableWidget->setShowGrid(false);
    tableWidget->setAutoFillBackground(true);

    item0 = new QTableWidgetItem(tr("test string"));
    item1 = new QTableWidgetItem(tr("Normal"));
    item2 = new QTableWidgetItem(tr("Off"));

    font = item0->font();
    font = item1->font();
    font = item2->font();
    font.setPointSize(23);

    item0->setFont(font);
    item1->setFont(font);
    item2->setFont(font);

    tableWidget->setItem(0, 0, item0);
    tableWidget->setItem(0, 1, item1);
    tableWidget->setItem(0, 2, item2);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tableWidget);

    QStringList list = rss->showFeeds();
    qDebug()<<"My List" <<list;


}

void TableWidget::paintEvent(QPaintEvent *pe)
{
        Q_UNUSED(pe);
}

QRegion TableWidget::roundedRect(const QRect& rect, int r)
{
    QRegion region;
    // middle and borders
    region += rect.adjusted(r, 0, -r, 0);
    region += rect.adjusted(0, r, 0, -r);
    // top left
    QRect corner(rect.topLeft(), QSize(r*2, r*2));
    region += QRegion(corner, QRegion::Rectangle);
    // top right
    corner.moveTopRight(rect.topRight());
    region += QRegion(corner, QRegion::Rectangle);
    // bottom left
    corner.moveBottomLeft(rect.bottomLeft());
    region += QRegion(corner, QRegion::Ellipse);
    // bottom right
    corner.moveBottomRight(rect.bottomRight());
    region += QRegion(corner, QRegion::Rectangle);
    return region;
}
