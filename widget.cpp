#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setAutoFillBackground(true);
    screenRect = QApplication::desktop()->availableGeometry();

    pal = palette();
    pix.load(":/images/container-back.png");
    pal.setBrush( QPalette::Background, pix.scaled(QSize(screenRect.width(), screenRect.height()), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    setPalette( pal );

    tbl = new TableWidget(this);
    scr = new ScrollWidget(this);
    //rss = new Rss(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
