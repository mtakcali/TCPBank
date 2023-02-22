#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir;
    QString pic_direc;
    pic_direc = dir.currentPath()+ "/resources/bank.jpg";


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


    ui->lineEdit_Username->setPlaceholderText("Enter your username");
    ui->lineEdit_Password->setPlaceholderText("Enter your password");



}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_Login_clicked()
{

    QDir dir;
    QString direc;
    direc = dir.currentPath();

    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE","MyConnect");
    myDatabase.setDatabaseName(direc + "/database/BankDatabase.db");



    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();



    if(myDatabase.open())
    {
        //QMessageBox::information(this,"Connected","Database is connected!");
        QSqlQuery query(QSqlDatabase::database("MyConnect"));
        query.prepare(QString("SELECT * FROM ClientInfos WHERE username = :username AND password = :password"));

        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if(!query.exec())
        {
             QMessageBox::information(this,"Failed","Query is not executed!");
        }
        else
        {

                QString usernameFromDatabase = query.value(1).toString();
                QString passwordFromDatabase = query.value(2).toString();

                if(socket)
                {
                    if(socket->isOpen())
                    {
                        QString sender = ui->lineEdit_Username->text();

                        socket->write("Welcome: ");
                        socket->write(sender.toStdString().c_str());

                    }
                    else
                        QMessageBox::critical(this,"QTCPClient","Socket couldn't open");
                }
                else
                    QMessageBox::critical(this,"QTCPClient","Not connected");

                if(query.next())
                {
                    QMessageBox::information(this,"Success","Login Success!");



                    hide();
                    secDialog = new SecDialog(this);
                    secDialog->show();


                }
                else
                {
                    QMessageBox::information(this,"Failed","Login Failed!");

                }

        }

    }
    else
    {
        QMessageBox::information(this,"Not connected","Database is not connected!");
    }
}

//QString getUsername()
//{
//    QString username = setUsername(u_name);

//    return username;
//}

//QString setUsername(QString u_name)
//{
//    return u_name;
//}
