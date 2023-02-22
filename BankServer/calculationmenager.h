#ifndef CALCULATIONMENAGER_H
#define CALCULATIONMENAGER_H

#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class CalculationMenager : public MainWindow
{
public:
    CalculationMenager();
    float currentBalance();
};

#endif // CALCULATIONMENAGER_H
