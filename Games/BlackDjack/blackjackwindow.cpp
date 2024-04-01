#include "blackjackwindow.h"
#include "ui_blackjackwindow.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QMessageBox>
#include "Games/BlackDjack/urlcard.h"

BlackjackWindows::BlackjackWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BlackjackWindows)
{
    ui->setupUi(this);

    UrlCard::initializeUrlCard();

    ui->label_6->setText("");
    _nameGame = "Блэкджек";
    ui->label_5->setText("0");
    ui->label_4->setText("0");
    _numMovePlayer = 0;
    _numMoveBot = 0;

    _deck = new Deck;
    _bot = new Player;
    _player = new Player;

    _cardOnTablePlayer[0] = ui ->label;
    _cardOnTablePlayer[1] = ui ->label_10;
    _cardOnTablePlayer[2] = ui ->label_11;
    _cardOnTablePlayer[3] = ui ->label_12;
    _cardOnTablePlayer[4] = ui ->label_13;
    _cardOnTablePlayer[5] = ui ->label_14;
    _cardOnTablePlayer[6] = ui ->label_7;
    _cardOnTablePlayer[7] = ui ->label_8;

    _cardOnTableDiller[0] = ui ->label_19;
    _cardOnTableDiller[1] = ui ->label_21;
    _cardOnTableDiller[2] = ui ->label_23;
    _cardOnTableDiller[3] = ui ->label_25;
    _cardOnTableDiller[4] = ui ->label_20;
    _cardOnTableDiller[5] = ui ->label_22;
    _cardOnTableDiller[6] = ui ->label_24;
    _cardOnTableDiller[7] = ui ->label_26;

    connect(ui->pushButton, &QPushButton::clicked, this, &BlackjackWindows::takeKard);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &BlackjackWindows::enough);
}

BlackjackWindows::~BlackjackWindows()
{
    delete _deck;
    delete _bot;
    delete _player;
    delete ui;
}

void BlackjackWindows::botTurn()
{
    while (_bot->score() < minimumDealerScore)
    {
        QString filePatch = _bot->urlCard(*_deck);
        QLabel* label = BlackjackWindows::_cardOnTableDiller[_numMoveBot++];

        QRect startPosition = ui->label_27->geometry();
        QRect finishPosition = label->geometry();

        QLabel* tempLabel = new QLabel(ui->centralwidget);
        tempLabel->setStyleSheet("image: url(" + filePatch + ");");
        tempLabel->setGeometry(startPosition);
        tempLabel->show();
        tempLabel->raise();

        QPropertyAnimation* animation = new QPropertyAnimation(tempLabel, "geometry");
        animation->setDuration(1000);
        animation->setStartValue(startPosition);
        animation->setEndValue(finishPosition);

        animation->start();

        QTimer::singleShot(1000, [label, filePatch, tempLabel]()
        {
            tempLabel->deleteLater();
            label->setStyleSheet("image: url(" + filePatch + ");");
        });
    }
}

void BlackjackWindows::takeKard()
{
    QString filePatch = _player->urlCard(*_deck);
    ui->label_4->setText(QString::number(_player->score()));

    QLabel* label = BlackjackWindows::_cardOnTablePlayer[_numMovePlayer++];

    QRect startPosition = ui->label_27->geometry();
    QRect finishPosition = label->geometry();

    QLabel* tempLabel = new QLabel(ui->centralwidget);
    tempLabel->setStyleSheet("image: url(" + filePatch + ");");
    tempLabel->setGeometry(startPosition);
    tempLabel->show();
    tempLabel->raise();

    QPropertyAnimation* animation = new QPropertyAnimation(tempLabel, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(startPosition);
    animation->setEndValue(finishPosition);

    animation->start();

    QTimer::singleShot(1000, [label, filePatch, tempLabel]()
    {
        tempLabel->deleteLater();
        label->setStyleSheet("image: url(" + filePatch + ");");
    });

    if(_player->isBust())
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        enough();
    }
}

void BlackjackWindows::enough()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);;
    botTurn();

    ui->label_5->setText(QString::number(_bot->score()));
    if (_player->isBust() and _bot->isBust())
    {
        ui->label_6->setText("Ничья");
    }
    else if(!_player->isBust() and _bot->isBust() )
    {
        ui->label_6->setText("Вы выйграли! У диллера перебор");
    }
    else if(!_player->isBust() and _player->score() > _bot->score())
    {
        ui->label_6->setText("Вы выйграли! У диллера: " + QString::number(_bot->score()));
    }
    else if(_player->score() == _bot->score())
    {
        ui->label_6->setText("Ничья");
    }
    else
    {
        ui->label_6->setText("Вы проиграли! У диллера: " + QString::number(_bot->score()));
    }
}

void BlackjackWindows::on_action_2_triggered()
{
    delete _deck;
    delete _bot;
    delete _player;

    _deck = new Deck;
    _bot = new Player;
    _player = new Player;

    ui->label_5->setText("0");
    ui->label_4->setText("0");
    _numMovePlayer = 0;
    _numMoveBot = 0;

    ui->label_6->setText("");
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);

    for(int i = 0; i < _cardOnTablePlayer.size(); i++)
        _cardOnTablePlayer[i]->setStyleSheet("");

    for(int i = 0; i < _cardOnTableDiller.size(); i++)
        _cardOnTableDiller[i]->setStyleSheet("");
}

void BlackjackWindows::on_action_triggered()
{
    if (_fullScreen)
    {
        showNormal();
        _fullScreen = false;
        ui->action->setText("Полноэкранный режим");
    }
    else
    {
        showFullScreen();
        _fullScreen = true;
        ui->action->setText("Оконный режим");
    }
}

void BlackjackWindows::on_action_4_triggered()
{
    QMessageBox messageBox;
     messageBox.setWindowTitle("Правила игры");
     messageBox.setText("Цель игры: набрать комбинацию карт, близкую к 21 очку, но не превышающую это значение.\n"
                        "Правила:\n"
                        "• Каждая карта имеет свой балловый номинал: от 2 до 10 - по номиналу, валет, дама, король - 10, туз - 1 или 11 (в зависимости от ситуации);\n"
                        "• Игроки получают по две карты из колоды;\n"
                        "• Игроки решают, берут ли дополнительные карты (хит) или остаются с текущей суммой (стой);\n"
                        "• Цель - набрать комбинацию, близкую к 21, но не превышающую эту сумму. Если у игрока 21, это называется 'блэкджек';\n"
                        "• Если у игрока больше 21, он проигрывает (перебор);\n"
                        "• Выигрывает тот, кто ближе всех к 21, но не превышает эту сумму.");

     messageBox.setIcon(QMessageBox::Information);
     messageBox.setFont(QFont("Segoe UI", 12));
     messageBox.exec();
}

void BlackjackWindows::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    WindowTracker::activeWindow = this;
}
