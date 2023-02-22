#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server = new QTcpServer();



    if(m_server->listen(QHostAddress::Any, 8080))
    {

       connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
       connect(m_server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
       ui->statusbar->showMessage("Server is listening...");
    }
    else
    {
        QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(m_server->errorString()));
        exit(EXIT_FAILURE);
    }
}

MainWindow::~MainWindow()
{
    foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }

    m_server->close();
    m_server->deleteLater();

    delete ui;
}

void MainWindow::newConnection()
{
    while (m_server->hasPendingConnections())
        appendToSocketList(m_server->nextPendingConnection());

}

void MainWindow::appendToSocketList(QTcpSocket* socket)
{

    connection_list.append(socket);

    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &MainWindow::displayError);

    displayMessage(QString("(Server)INFO :: Client with sockd:%1 has just entered the room. username is: ").arg(socket->socketDescriptor()));
}

QString username[10];

void MainWindow::readSocket()
{

    QStringList list_transfer;

    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    QByteArray messageFromServer = socket->readAll();

    QString messageForInfo = QString::fromStdString(messageFromServer.toStdString());

    int i =0;

    if(username[i]=="")
    {
    username[i] = userInfo(messageForInfo, list_transfer);

    }
    balance = getUserBalance(username[i]);

    QString balanceAsString = "Your balance: " + QString::number(balance);
    displayMessage(balanceAsString);

    SplitMessage(messageForInfo, list_transfer, socket);



    QString message= "Client : " + username[i] + " :: " + QString::fromStdString(messageFromServer.toStdString());
    displayMessage(message);
    i++;
}


void MainWindow::SplitMessage(QString message_to_splitted, QStringList list,  QTcpSocket* socket1)
{
    if(message_to_splitted.contains('-'))
    {
        list =message_to_splitted.split('-');

        displayMessage("Client : " + QString::number(socket1->socketDescriptor()));

        for(int i = 0; i<3; i++)
        {
            displayMessage(list[i]);

        }
    }
}

QString MainWindow::userInfo(QString message_to_info, QStringList list)
{
    if(message_to_info.startsWith("W"))
    {
        list =message_to_info.split(' ');

        QString username = list[1].toUtf8();

        return username;
    }
    return 0;
}

float MainWindow::depositInfo(QString message_to_info, QStringList list)
{
    if(message_to_info.startsWith("d"))
    {
        list =message_to_info.split(' ');

        deposited_amount = list[2].toFloat();

        return deposited_amount;
    }
    return 0;
}


float MainWindow::getUserBalance(QString username)
{
    QDir dir;
    QString direc;
    direc = dir.currentPath();

    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE","MyConnectFromServer");
    myDatabase.setDatabaseName(direc + "/database/BankDatabase.db");

    QString USER = username;
    ////////////

    if(myDatabase.open())
    {
        ////////////////////////////////////////
        ///
        if(USER=="mtakcali")
        {
            QSqlQuery query(QSqlDatabase::database("MyConnectFromServer"));
            query.prepare("SELECT balance FROM ClientInfos WHERE username = 'mtakcali'");

            if(!query.exec())
            {
                 QMessageBox::information(this,"Failed(Server)","Query is not executed!");
            }
            else
            {
                    while(query.next())
                    {
                        float balanceFromDatabase = query.value(0).toFloat();

                        return balanceFromDatabase;
                    }
            }
        }
        else if(USER=="ttuna")
        {
            QSqlQuery query(QSqlDatabase::database("MyConnectFromServer"));
            query.prepare("SELECT balance FROM ClientInfos WHERE username = 'ttuna'");

            if(!query.exec())
            {
                 QMessageBox::information(this,"Failed(Server)","Query is not executed!");
            }
            else
            {
                    while(query.next())
                    {
                        float balanceFromDatabase = query.value(0).toFloat();

                        return balanceFromDatabase;
                    }
            }
        }
        else if(USER=="rdvan")
        {
            QSqlQuery query(QSqlDatabase::database("MyConnectFromServer"));
            query.prepare("SELECT balance FROM ClientInfos WHERE username = 'rdvan'");

            if(!query.exec())
            {
                 QMessageBox::information(this,"Failed(Server)","Query is not executed!");
            }
            else
            {
                    while(query.next())
                    {
                        float balanceFromDatabase = query.value(0).toFloat();

                        return balanceFromDatabase;
                    }
            }
        }

        ///
        /// //////////////////////////////////
        //QMessageBox::information(this,"Connected","Database is connected!");



//        if(!query.exec())
//        {
//             QMessageBox::information(this,"Failed(Server)","Query is not executed!");
//        }
//        else
//        {
//                while(query.next())
//                {
//                    float balanceFromDatabase = query.value(0).toFloat();

//                    return balanceFromDatabase;
//                }
//        }

    }
    else
    {
        QMessageBox::information(this,"Not connected(Server)","Database is not connected!");
    }
    return 496.496;
}


void MainWindow::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = connection_set.find(socket);
    if (it != connection_set.end()){
        displayMessage(QString("(Server)INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        connection_set.remove(*it);
    }


    socket->deleteLater();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPServer", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPServer", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
            QMessageBox::information(this, "QTCPServer", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}

void MainWindow::displayMessage(const QString& str)
{
    ui->textBrowser->append(str);
}



















