/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_amountOfMoney_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Deposit;
    QPushButton *pushButton_Withdraw;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_amountOfMoney;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_accountNumber;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_recieverName;
    QPushButton *pushButton_Send;
    QSpacerItem *verticalSpacer;
    QLabel *label_blink;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_serverStatus;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_yourDeposit;
    QLabel *label_realDeposit;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(810, 552);
        gridLayout = new QGridLayout(SecDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(10, 12, 10, 20);
        lineEdit_amountOfMoney_2 = new QLineEdit(SecDialog);
        lineEdit_amountOfMoney_2->setObjectName(QString::fromUtf8("lineEdit_amountOfMoney_2"));

        verticalLayout_4->addWidget(lineEdit_amountOfMoney_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_Deposit = new QPushButton(SecDialog);
        pushButton_Deposit->setObjectName(QString::fromUtf8("pushButton_Deposit"));
        pushButton_Deposit->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(pushButton_Deposit);

        pushButton_Withdraw = new QPushButton(SecDialog);
        pushButton_Withdraw->setObjectName(QString::fromUtf8("pushButton_Withdraw"));
        pushButton_Withdraw->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(pushButton_Withdraw);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(100, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SecDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_amountOfMoney = new QLineEdit(SecDialog);
        lineEdit_amountOfMoney->setObjectName(QString::fromUtf8("lineEdit_amountOfMoney"));

        horizontalLayout->addWidget(lineEdit_amountOfMoney);

        label_2 = new QLabel(SecDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(SecDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_accountNumber = new QLineEdit(SecDialog);
        lineEdit_accountNumber->setObjectName(QString::fromUtf8("lineEdit_accountNumber"));

        horizontalLayout_2->addWidget(lineEdit_accountNumber);

        label_4 = new QLabel(SecDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(SecDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        lineEdit_recieverName = new QLineEdit(SecDialog);
        lineEdit_recieverName->setObjectName(QString::fromUtf8("lineEdit_recieverName"));

        verticalLayout->addWidget(lineEdit_recieverName);

        pushButton_Send = new QPushButton(SecDialog);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(pushButton_Send);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);

        label_blink = new QLabel(SecDialog);
        label_blink->setObjectName(QString::fromUtf8("label_blink"));

        gridLayout->addWidget(label_blink, 3, 2, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_serverStatus = new QLabel(SecDialog);
        label_serverStatus->setObjectName(QString::fromUtf8("label_serverStatus"));

        verticalLayout_5->addWidget(label_serverStatus);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_yourDeposit = new QLabel(SecDialog);
        label_yourDeposit->setObjectName(QString::fromUtf8("label_yourDeposit"));
        label_yourDeposit->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(label_yourDeposit);

        label_realDeposit = new QLabel(SecDialog);
        label_realDeposit->setObjectName(QString::fromUtf8("label_realDeposit"));
        QFont font;
        font.setPointSize(12);
        label_realDeposit->setFont(font);

        horizontalLayout_5->addWidget(label_realDeposit);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);


        retranslateUi(SecDialog);
        QObject::connect(pushButton_Send, SIGNAL(clicked()), lineEdit_amountOfMoney, SLOT(copy()));
        QObject::connect(pushButton_Send, SIGNAL(clicked()), lineEdit_accountNumber, SLOT(copy()));
        QObject::connect(pushButton_Send, SIGNAL(clicked()), lineEdit_recieverName, SLOT(copy()));

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        pushButton_Deposit->setText(QCoreApplication::translate("SecDialog", "Deposit", nullptr));
        pushButton_Withdraw->setText(QCoreApplication::translate("SecDialog", "Withdraw", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Transfer</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Lira</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">to</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">account number</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Name of the reciever is:</span></p></body></html>", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("SecDialog", "Send", nullptr));
        label_blink->setText(QString());
        label_serverStatus->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">TextLabel</span></p></body></html>", nullptr));
        label_yourDeposit->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p align=\"center\">Your balance   =</p></body></html>", nullptr));
        label_realDeposit->setText(QCoreApplication::translate("SecDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
