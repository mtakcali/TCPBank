#include "secdialog.h"
#include "ui_secdialog.h"
#include <QDebug>
#include "mainwindow.h"
#include <QPixmap>



SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    QDir dir;
    QString pic_direc;
    pic_direc = dir.currentPath()+ "/resources/sec.jpg";


    QPixmap pix(pic_direc);
    pix.width();

    pix = pix.scaled(this->size(), Qt::KeepAspectRatio,Qt::SmoothTransformation);
//    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QPalette palette;
    palette.setBrush(QPalette::Window, pix);
    this->setPalette(palette);

    socket = new QTcpSocket(this);

    socket->connectToHost(QHostAddress::LocalHost,8080);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->open(QIODevice::ReadWrite);

    if(socket->waitForConnected())
       ui->label_serverStatus->setText("Connected to server!");
    else{
        ui->label_serverStatus->setText("Not connected to server!");
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }



//    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE","MyConnect2");
//    myDatabase.setDatabaseName("C:/Users/talha/Documents/QtDocuments/BankDatabase/BankDatabase.db");




//    QSqlQuery query(QSqlDatabase::database("MyConnect2"));
//    query.exec(QString("SELECT balance FROM ClientInfos"));

//    balance1 = query.value(0).toDouble();

    double balance1= 1250.55;

    ui->label_realDeposit->setNum(balance1);








}

SecDialog::~SecDialog()
{

    if(socket->isOpen())
        socket->close();
    delete ui;
}



void SecDialog::on_pushButton_Send_clicked()
{
    // para gönderme
    if(socket)
    {
        if(socket->isOpen())
        {
            QString amountOfMoney = ui->lineEdit_amountOfMoney->text();
            QString accountNumber = ui->lineEdit_accountNumber->text();
            QString recieverName = ui->lineEdit_recieverName->text();

            socket->write(amountOfMoney.toStdString().c_str());
            socket->write("-");
            socket->write(accountNumber.toStdString().c_str());
            socket->write("-");
            socket->write(recieverName.toStdString().c_str());



            ui->lineEdit_amountOfMoney->clear();
            ui->lineEdit_accountNumber->clear();
            ui->lineEdit_recieverName->clear();
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}


void SecDialog::on_pushButton_Deposit_clicked()
{
    // para yatırma
    if(socket)
    {
        if(socket->isOpen())
        {
            QString amountOfMoney_2 = ui->lineEdit_amountOfMoney_2->text();

            socket->write("deposited amount: ");
            socket->write(amountOfMoney_2.toStdString().c_str());

        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket couldn't open");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}



void SecDialog::on_pushButton_Withdraw_clicked()
{
    // para çekme
    if(socket)
    {
        if(socket->isOpen())
        {
            QString amountOfMoney_2 = ui->lineEdit_amountOfMoney_2->text();

            socket->write("withdrawed amount: ");
            socket->write(amountOfMoney_2.toStdString().c_str());
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket couldn't open");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}

void SecDialog::readyRead()
{
    QByteArray myByte;
    myByte = socket->readAll();


}

void SecDialog::whoAmI()
{

}

