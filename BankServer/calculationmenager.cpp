#include "calculationmenager.h"

CalculationMenager::CalculationMenager()
{
    float Current_Balance = currentBalance();

}

float CalculationMenager::currentBalance()
{
    MainWindow::balance = MainWindow::balance + MainWindow::deposited_amount;


    return balance;
}
