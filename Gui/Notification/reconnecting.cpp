#include "reconnecting.h"

Reconnecting::Reconnecting()
{
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground); //для скругления

    setupUI();
    setupConnections();
}

void Reconnecting::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(palette().window());
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(contentsRect(), 10, 10); //радиус скругления
}

void Reconnecting::setAlertProperties(QWidget* parentForm)
{
    _parentForm = parentForm;

    QString title = "Пропало соединение с сервером";
    QString message = "Идет переподключение";
    QString backgroundColor;
    QString progressBarColor;
    QIcon icon(":/icons/resources/update.png");

    backgroundColor = "#ff8585";
    progressBarColor = "#f00";

    titleLabel->setText(title);
    textLabel->setText(message);
    setStyleSheet(QString("background-color: %1;").arg(backgroundColor));
    progressBar->setStyleSheet(QString("QProgressBar::chunk { background-color: %1; }").arg(progressBarColor));
    iconLabel->setPixmap(icon.pixmap(iconLabel->size()));

    adjustSize(); //Автоматическая настройка размера

    showReconnecting();
}

void Reconnecting::showReconnecting()
{
    positionAlertBox();
    show();
    timer.start(1);
}

void Reconnecting::updateProgressBar()
{
    progressBar->setValue(progressBar->value() + 1);
    if (progressBar->value() == progressBar->maximum())
    {
        progressBar->setValue(progressBar->minimum());
        updateProgressBar();
    }
}

void Reconnecting::setupUI()
{
    QFont titleFont;
    titleFont.setFamily("Segoe UI");
    titleFont.setPointSize(12);
    titleFont.setBold(true);

    QFont textFont;
    textFont.setFamily("Segoe UI");
    textFont.setPointSize(10);

    QGridLayout* mainLayout = new QGridLayout(this);

    iconLabel = new QLabel(this);
    iconLabel->setFixedSize(32, 32);

    titleLabel = new QLabel(this);
    titleLabel->setFont(titleFont);

    textLabel = new QLabel(this);
    textLabel->setWordWrap(true);
    textLabel->setFont(textFont);

    int time = 5000;
    progressBar = new QProgressBar(this);
    progressBar->setTextVisible(false);
    progressBar->setRange(0, time);

    mainLayout->addWidget(iconLabel, 1, 0, 2, 1);
    mainLayout->addWidget(titleLabel, 1, 1);
    mainLayout->addWidget(textLabel, 2, 1);
    mainLayout->addWidget(progressBar, 3, 0, 1, 2);
}

void Reconnecting::setupConnections()
{
    connect(&timer, &QTimer::timeout, this, &Reconnecting::updateProgressBar);
}

void Reconnecting::positionAlertBox()
{
    if (_parentForm)
    {
        QPoint parentCenter = _parentForm->mapToGlobal(_parentForm->rect().center());
        int x = parentCenter.x() - width() / 2;
        int y = parentCenter.y() - height() / 2;
        move(x, y);
    }
    else
    {
        QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
        int x = (screenGeometry.width() - width()) / 2;
        int y = (screenGeometry.height() - height()) / 2;
        move(x, y);
    }
}
