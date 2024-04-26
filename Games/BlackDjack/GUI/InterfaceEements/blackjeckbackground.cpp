#include "blackjeckbackground.h"
#include "ui_blackjecktablewidget.h"

BlackJeckBackground::BlackJeckBackground(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackJeckBackground)
{
    ui->setupUi(this);
    assigningValues();
}

BlackJeckBackground::~BlackJeckBackground()
{
    delete ui;
}

void BlackJeckBackground::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int labelWidth = width() / 10;
    int labelHeight = height() / 4;

    QList<QLabel*> labels = findChildren<QLabel*>();
    for (QLabel* label : labels)
        label->setFixedSize(labelWidth, labelHeight);
}

void BlackJeckBackground::paintEvent(QPaintEvent* event)
{
    QPainter painter( this );
    painter.drawPixmap( 0, 0, QPixmap(":/InterfaceEements/resources/Table.png").scaled(size()));

    QWidget::paintEvent(event);
}

void BlackJeckBackground::movingCard(QSharedPointer<Card> card)
{
    QString filePatch = Card::getCardTexture(*card);

    if(placeCardOnTable.size() == numMovePlayer)
    {
        Notification* message = new Notification();
        message->setAlertProperties(TypeMessage::Warning, "Места под карты больше нет", WindowTracker::activeWindow);
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
    });
}

void BlackJeckBackground::movingFaceCard(const QRect &playerPosition)
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

void BlackJeckBackground::assigningValues()
{
    numMovePlayer = 0;

    placeCardOnTable[0] = ui ->labelCard_1;
    placeCardOnTable[1] = ui ->labelCard_2;
    placeCardOnTable[2] = ui ->labelCard_3;
    placeCardOnTable[3] = ui ->labelCard_4;
    placeCardOnTable[4] = ui ->labelCard_5;
    placeCardOnTable[5] = ui ->labelCard_6;
}
