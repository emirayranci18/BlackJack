/********************************************************************************
** Form generated from reading UI file 'Qt21Deneme.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT21DENEME_H
#define UI_QT21DENEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt21DenemeClass
{
public:
    QWidget *centralWidget;
    QPushButton *btnTake;
    QLabel *playerCard1;
    QLabel *curpPoint;
    QLabel *playerPoint;
    QPushButton *btnStart;
    QLabel *playerCard1_2;
    QLabel *curpName;
    QLabel *playerName;
    QPushButton *btnFinish;
    QLabel *background;
    QLineEdit *moneyField;
    QLabel *moneyCount;
    QLabel *betLabel;

    void setupUi(QMainWindow *Qt21DenemeClass)
    {
        if (Qt21DenemeClass->objectName().isEmpty())
            Qt21DenemeClass->setObjectName("Qt21DenemeClass");
        Qt21DenemeClass->resize(599, 381);
        centralWidget = new QWidget(Qt21DenemeClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setEnabled(true);
        btnTake = new QPushButton(centralWidget);
        btnTake->setObjectName("btnTake");
        btnTake->setGeometry(QRect(510, 140, 61, 24));
        playerCard1 = new QLabel(centralWidget);
        playerCard1->setObjectName("playerCard1");
        playerCard1->setGeometry(QRect(200, 230, 61, 81));
        curpPoint = new QLabel(centralWidget);
        curpPoint->setObjectName("curpPoint");
        curpPoint->setGeometry(QRect(278, 150, 51, 20));
        curpPoint->setAutoFillBackground(false);
        curpPoint->setAlignment(Qt::AlignCenter);
        playerPoint = new QLabel(centralWidget);
        playerPoint->setObjectName("playerPoint");
        playerPoint->setGeometry(QRect(280, 330, 49, 16));
        playerPoint->setAutoFillBackground(false);
        playerPoint->setAlignment(Qt::AlignCenter);
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(500, 110, 81, 24));
        playerCard1_2 = new QLabel(centralWidget);
        playerCard1_2->setObjectName("playerCard1_2");
        playerCard1_2->setGeometry(QRect(200, 50, 61, 81));
        curpName = new QLabel(centralWidget);
        curpName->setObjectName("curpName");
        curpName->setGeometry(QRect(270, 20, 61, 20));
        curpName->setAutoFillBackground(false);
        curpName->setAlignment(Qt::AlignCenter);
        playerName = new QLabel(centralWidget);
        playerName->setObjectName("playerName");
        playerName->setGeometry(QRect(270, 200, 61, 20));
        playerName->setAutoFillBackground(false);
        playerName->setAlignment(Qt::AlignCenter);
        btnFinish = new QPushButton(centralWidget);
        btnFinish->setObjectName("btnFinish");
        btnFinish->setGeometry(QRect(510, 170, 61, 24));
        background = new QLabel(centralWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, -20, 601, 401));
        background->setPixmap(QPixmap(QString::fromUtf8("table.jpg")));
        background->setScaledContents(true);
        moneyField = new QLineEdit(centralWidget);
        moneyField->setObjectName("moneyField");
        moneyField->setGeometry(QRect(502, 80, 81, 22));
        moneyCount = new QLabel(centralWidget);
        moneyCount->setObjectName("moneyCount");
        moneyCount->setGeometry(QRect(500, 60, 81, 16));
        moneyCount->setAlignment(Qt::AlignCenter);
        betLabel = new QLabel(centralWidget);
        betLabel->setObjectName("betLabel");
        betLabel->setGeometry(QRect(410, 80, 81, 21));
        betLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Qt21DenemeClass->setCentralWidget(centralWidget);
        background->raise();
        btnStart->raise();
        btnTake->raise();
        playerCard1->raise();
        curpPoint->raise();
        playerPoint->raise();
        playerCard1_2->raise();
        curpName->raise();
        playerName->raise();
        btnFinish->raise();
        moneyField->raise();
        moneyCount->raise();
        betLabel->raise();

        retranslateUi(Qt21DenemeClass);

        QMetaObject::connectSlotsByName(Qt21DenemeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt21DenemeClass)
    {
        Qt21DenemeClass->setWindowTitle(QCoreApplication::translate("Qt21DenemeClass", "BlackJack", nullptr));
        btnTake->setText(QCoreApplication::translate("Qt21DenemeClass", "\303\207ek", nullptr));
        playerCard1->setText(QString());
        curpPoint->setText(QString());
        playerPoint->setText(QString());
        btnStart->setText(QCoreApplication::translate("Qt21DenemeClass", "Ba\305\237la", nullptr));
        playerCard1_2->setText(QString());
        curpName->setText(QCoreApplication::translate("Qt21DenemeClass", "Kurpiyer", nullptr));
        playerName->setText(QCoreApplication::translate("Qt21DenemeClass", "Sen", nullptr));
        btnFinish->setText(QCoreApplication::translate("Qt21DenemeClass", "Bitir", nullptr));
        background->setText(QString());
        moneyCount->setText(QString());
        betLabel->setText(QCoreApplication::translate("Qt21DenemeClass", "Betinizi Giriniz:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt21DenemeClass: public Ui_Qt21DenemeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT21DENEME_H
