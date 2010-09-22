#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListView>
#include <QComboBox>
#include <QStandardItemModel>
#include <QProgressBar>
#include <QtGui/QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtWebKit/QWebView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openRssFeed();
    void replyFinished(QNetworkReply*);
    void listViewDoubleClicked (const QModelIndex & index );
    void downloadProgress(qint64 bytes, qint64 bytesTotal);

private:
    QListView * tv;
    QWebView * wv;
    QComboBox * combo;
    QNetworkAccessManager *manager;
    QNetworkReply * reply;
    QStandardItemModel * model;
    QProgressBar * progress;
};

class ListView : public QListView
{
    Q_OBJECT

protected:
    void keyPressEvent ( QKeyEvent * event );
};

#endif // MAINWINDOW_H
