#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QMainWindow>
#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>



namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();
    void whoAmI();
signals:
    void newMessage(QString);
private slots:
    void readyRead();

    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString& str);

    void on_pushButton_Send_clicked();

    void on_pushButton_Deposit_clicked();

    void on_pushButton_Withdraw_clicked();


    void on_label_realDeposit_linkActivated(const QString &link);

private:
    Ui::SecDialog *ui;
    QTcpSocket* socket;
};

#endif // SECDIALOG_H
