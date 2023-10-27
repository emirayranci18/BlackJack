#include "Qt21Deneme.h"

Qt21Deneme::Qt21Deneme(QWidget* parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	ui.setupUi(this);

	connect(ui.btnTake, SIGNAL(clicked()), this, SLOT(BtnTakeFunc()));
	connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(BtnStartFunc()));
	connect(ui.btnFinish, SIGNAL(clicked()), this, SLOT(BtnFinishFunc()));

	srand(time(0));
	ui.btnTake->setVisible(false);
	ui.btnFinish->setVisible(false);

	ui.playerName->setStyleSheet("QLabel { color : white; }");
	ui.curpName->setStyleSheet("QLabel { color : white; }");
	ui.playerPoint->setStyleSheet("QLabel { color : white; }");
	ui.curpPoint->setStyleSheet("QLabel { color : white; }");
	ui.moneyCount->setStyleSheet("QLabel { color : white; }");
	ui.betLabel->setStyleSheet("QLabel { color : white; }");

	ui.moneyCount->setText(QString::number(money));

	infoBox.setIcon(QMessageBox::Information);

	bool ok;
	QString userName = QInputDialog::getText(nullptr, "Isim", "Isminizi Girin:", QLineEdit::Normal, "", &ok);

	if (ok) {
		ui.playerName->setText(userName);
	}

}

Qt21Deneme::~Qt21Deneme()
{



}

void Qt21Deneme::PlayerTake()
{
	QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
	timer.start(waitTime);
	loop.exec();

	string value = RandomNumber();
	
	QPixmap pixmap("cards/" + QString::fromStdString(permFileName));
	pCard[playerCardCount] = new QLabel(this);
	pCard[playerCardCount]->show();
	pCard[playerCardCount]->setGeometry(200 + (playerCardCount * 30), 230, width, height);
	pCard[playerCardCount]->setPixmap(pixmap.scaled(82, 82, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	
	if (value == "1" && playerCardCount==1) {
		asCheck = true;
		pPoint += stoi(value);
		pPoint += 10;
		ui.playerPoint->setText(QString::number(pPoint) +"/"+QString::number(pPoint+10));
	}
	else if (value != "1"){
		asCheck = false;
		pPoint += stoi(value);
		ui.playerPoint->setText(QString::number(pPoint));
	}
	
	playerCardCount++;

	if (pPoint > 21) {
		MainCalculate("bitir");
	}
	else if (pPoint == 21) {
		MainCalculate("bitir");
	}
}

void Qt21Deneme::CurpTake()
{
	QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
	timer.start(waitTime);
	loop.exec();

	string value = RandomNumber();
	QPixmap pixmap("cards/" + QString::fromStdString(permFileName));
	cCard[curpCardCount] = new QLabel(this);
	cCard[curpCardCount]->show();
	cCard[curpCardCount]->setGeometry(200 + (curpCardCount * 30), 50, width, height);
	cCard[curpCardCount]->setPixmap(pixmap.scaled(82, 82, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	cPoint += stoi(value);
	ui.curpPoint->setText(QString::number(cPoint));
	curpCardCount++;
}

void Qt21Deneme::BtnTakeFunc()
{
	string value = RandomNumber();

	if (value != "error")
		MainCalculate("cek");

}

void Qt21Deneme::BtnStartFunc()
{
	inputMoney = ui.moneyField->text().toInt();

	if (money >= inputMoney) {
		money -= inputMoney;
	}
	else {
		infoBox.setText("Yeterli Paraniz Yok.");
		infoBox.setWindowTitle("Hata");
		infoBox.exec();
		return;
	}

	ui.moneyField->setVisible(false);
	ui.betLabel->setVisible(false);
	ui.btnStart->setVisible(false);
	ui.btnTake->setVisible(true);
	ui.btnFinish->setVisible(true);

	ui.moneyCount->setText(QString::number(money));

	for (int a = 0; a < curpCardCount; a++) {
		delete cCard[a];

	}
	for (int a = 0; a < playerCardCount; a++) {
		delete pCard[a];

	}

	cPoint = 0;
	pPoint = 0;
	curpCardCount = 0;
	playerCardCount = 0;
	dosya_sira = 0;
	cards.clear();

	string value = RandomNumber();

	if (value != "error")
		MainCalculate("basla");

	else
		BtnStartFunc();
}

void Qt21Deneme::BtnFinishFunc()
{
	MainCalculate("bitir");
}

void Qt21Deneme::FinishCheck()
{	
	if (playerCardCount==2 && pPoint==21){
		infoBox.setText("Kazandiniz! Tebrikler.");
		infoBox.setWindowTitle("Son");
		infoBox.exec();
		money += (2 * inputMoney);
	}
	else if (cPoint < 17) {
		CurpTake();
		FinishCheck();
	}
	else if (cPoint < 22 && cPoint > 16){
		qDebug() << " Girdi";
		if (pPoint < 22 && pPoint > cPoint){
			infoBox.setText("Kazandiniz! Tebrikler.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
			money += (2 * inputMoney);
		}
		else if (pPoint < 22 && pPoint < cPoint){
			infoBox.setText("Kaybettiniz! Yeniden Deneyin.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
		}
		else if (pPoint > 21) {
			infoBox.setText("Kaybettiniz! Yeniden Deneyin.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
		}
		else if (pPoint == cPoint) {
			infoBox.setText("Berabere Kaldiniz! Yeniden Deneyin.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
			money += (inputMoney);
		}
	}
	else if (cPoint > 21) {
		if (pPoint < 22) {
			infoBox.setText("Kazandiniz! Tebrikler.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
			money += (2 * inputMoney);
		}
		else {
			infoBox.setText("Kaybettiniz! Yeniden Deneyin.");
			infoBox.setWindowTitle("Son");
			infoBox.exec();
		}
	}

	ui.moneyCount->setText(QString::number(money));
	ui.curpPoint->setText("0");
	ui.playerPoint->setText("0");
	ui.btnStart->setVisible(true);
	ui.btnTake->setVisible(false);
	ui.btnFinish->setVisible(false);
	ui.moneyField->setVisible(true);
	ui.betLabel->setVisible(true);
}

string Qt21Deneme::RandomNumber()
{
	dosya_sira = 0;
	randS = (rand() % 53) + 1;

	for (const int& eleman : cards) {
		if (eleman == randS) {
			return RandomNumber();
		}
	}

	for (const auto& entry : fs::directory_iterator(path)) {
		dosya_sira++;
		string fileName = entry.path().filename().string();
		permFileName = fileName;
		fileName.erase(fileName.length() - 4);

		size_t underscore_position = permFileName.find('_');

		if (underscore_position != string::npos) {
			if (randS == dosya_sira) {
				string cardValue = fileName.substr(0, underscore_position);
				if (cardValue == "jack" || cardValue == "queen" || cardValue == "king") {
					cardValue = "10";
					if (asCheck == true) {
						pPoint -= 10;
					}
					asCheck = false;
				}
				else if (cardValue == "ace") {
					cardValue = "11";
				}
				else if (cardValue.length()>2) {
					return RandomNumber();
				}
				
				cards.push_back(randS);
				return cardValue;
			}
		}
	}

}

void Qt21Deneme::MainCalculate(string komut)
{

	if (komut == "basla") {

		CurpTake();

		QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
		timer.start(waitTime);
		loop.exec();

		string value2 = RandomNumber();
		reverseCardName = permFileName;
		reverseCardValue = value2;
		QPixmap pixmap("reverseCard/reverse_of_card.jpg");
		cCard[curpCardCount] = new QLabel(this);
		cCard[curpCardCount]->show();
		cCard[curpCardCount]->setGeometry(200 + (curpCardCount * 30), 50, width, height);
		cCard[curpCardCount]->setPixmap(pixmap.scaled(82, 82, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		curpCardCount++;	

		PlayerTake();
		PlayerTake();

		if (playerCardCount == 2 && pPoint == 21) {
			FinishCheck();
		}

	}
	else if (komut == "cek") {
		PlayerTake();
	}
	else if (komut == "bitir") {

		QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
		timer.start(waitTime);
		loop.exec();

		QPixmap pixmap3("cards/" + QString::fromStdString(reverseCardName));
		cCard[curpCardCount - 1]->setPixmap(pixmap3.scaled(82, 82, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		cPoint += stoi(reverseCardValue);
		ui.curpPoint->setText(QString::number(cPoint));
		FinishCheck();
	}

	return;
}