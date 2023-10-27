#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt21Deneme.h"
#include <filesystem>
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>
#include <windows.h>
#include <mmsystem.h>
#include <QInputDialog>



namespace fs = std::filesystem;
using namespace std;

class Qt21Deneme : public QMainWindow
{
    Q_OBJECT

public:
    Qt21Deneme(QWidget *parent = nullptr);
    ~Qt21Deneme();
    Ui::Qt21DenemeClass ui;

    

private slots:
   
    void MainCalculate(string komut);
    void PlayerTake();
    void CurpTake();
    void BtnTakeFunc();
    void BtnStartFunc();  
    void BtnFinishFunc();
    void FinishCheck();
    string RandomNumber();
    
    
public:

    int width = 61;
    int height = 81;

    int konum; // curp 30 oyuncu 230
    bool asCheck=false;

    int money=500;
    int inputMoney;

    int waitTime = 1000;
    QEventLoop loop;
    QTimer timer;
    QMessageBox infoBox;
    QPixmap pixmap;
    string path = "cards";
    string permFileName;
    string reverseCardName, reverseCardValue;
    string delimiter = "_";
    int dosya_sira = 0;
    list<int> cards;

    int randS = 0;
    int cPoint = 0, pPoint = 0;
    int curpCardCount = 0, playerCardCount = 0;

    QLabel* cCard[10];
    QLabel* curpPoint;
    QLabel* pCard[10];
    QPushButton* btnStart;
    QPushButton* btnTake;
    QPushButton* btnFinish;

};