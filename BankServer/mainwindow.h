#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QList>
#include <QStringList>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    float balance;
    float deposited_amount;
    QString username[10];

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readSocket();
    void SplitMessage(QString message_to_splitted, QStringList list, QTcpSocket *socket1);

    QString userInfo(QString message_to_info, QStringList list);

    float getUserBalance(QString username);
    float depositInfo(QString message_to_info, QStringList list);
signals:
    void newMessage(QString);

private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket* socket);
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString& str);

private:
    Ui::MainWindow *ui;

    QTcpServer* m_server;
    QSet<QTcpSocket*> connection_set;
    QList<QTcpSocket*> connection_list;

};

#endif // MAINWINDOW_H
