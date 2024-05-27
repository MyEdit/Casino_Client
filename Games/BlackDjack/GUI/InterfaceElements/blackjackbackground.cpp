#include "blackjackbackground.h"
#include "ui_blackjackbackground.h"

BlackJackBackground::BlackJackBackground(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackJackBackground)
{
    ui->setupUi(this);
    assigningValues();
}

BlackJackBackground::~BlackJackBackground()
{
    delete ui;
}

void BlackJackBackground::movingCard(QSharedPointer<Card> card)
{
    QString filePatch = Card::getCardTexture(*card);

    if(placeCardOnTable.size() == numMovePlayer)
    {
        Notification::showNotification(TypeMessage::Warning, "Места под карты больше нет");
        return;
    }

    QLabel* label = placeCardOnTable[numMovePlayer++];

    QRect startPosition = ui->labelDeck->geometry();
    QRect finishPosition = label->geometry();

    QLabel* tempLabel = new QLabel(this);
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
    });;
}

void BlackJackBackground::movingFaceCard(const QRect &playerPosition)
{
    QString filePatch = "://Games/BlackDjack/assets/Standart/shirt.png";

    QRect startPosition = ui->labelDeck->geometry();

    QLabel* tempLabel = new QLabel(this);
    tempLabel->setStyleSheet("image: url(" + filePatch + ");");
    tempLabel->setFixedSize(startPosition.size());
    tempLabel->setGeometry(startPosition);
    tempLabel->show();
    tempLabel->raise();

    QPropertyAnimation* animation = new QPropertyAnimation(tempLabel, "geometry");
    int timeAnimaton = 1000;
    animation->setDuration(timeAnimaton);
    animation->setStartValue(startPosition);
    animation->setEndValue(playerPosition);

    animation->start();

    connect(animation, &QPropertyAnimation::finished, this, [tempLabel]()
    {
        tempLabel->deleteLater();
    });
}

void BlackJackBackground::clearTable()
{
    for(int i = 0; i < placeCardOnTable.size(); i++)
        placeCardOnTable[i]->setStyleSheet("QLabel {border: 2px solid  rgb(255, 255, 255); border-radius: 10px;}");

    numMovePlayer = 0;
}

void BlackJackBackground::assigningValues()
{
    numMovePlayer = 0;

    placeCardOnTable[0] = ui ->labelCard_1;
    placeCardOnTable[1] = ui ->labelCard_2;
    placeCardOnTable[2] = ui ->labelCard_3;
    placeCardOnTable[3] = ui ->labelCard_4;
    placeCardOnTable[4] = ui ->labelCard_5;
    placeCardOnTable[5] = ui ->labelCard_6;
}

void BlackJackBackground::updateCardSize(int width, int height)
{
    QList<QLabel*> labels = findChildren<QLabel*>();
    for (QLabel* label : labels)
        label->setFixedSize(width, height);
}
