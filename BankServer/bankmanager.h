#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <QObject>
#include <mainwindow.h>
#include <QMainWindow>

class BankManager : public QObject
{
    Q_OBJECT
public:
    explicit BankManager(QObject *parent = nullptr);

signals:

};

#endif // BANKMANAGER_H
