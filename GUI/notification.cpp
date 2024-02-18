#include "notification.h"

Notification::Notification()
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground); //для скругления

    setupUI();
    setupConnections();
}

void Notification::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(palette().window());
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(contentsRect(), 10, 10); //радиус скругления
}

void Notification::setAlertProperties(TypeMessage typeMessage, QString text, QWidget* parentForm)
{
    _parentForm = parentForm;

    QString title;
    QString backgroundColor;
    QString progressBarColor;
    QIcon icon;

    switch (typeMessage)
    {
    case TypeMessage::Information :
        title = "Информация";
        backgroundColor = "#9bf29e";
        progressBarColor = "#0d5901";
        icon = style()->standardIcon(QStyle::SP_MessageBoxInformation);
        break;
    case TypeMessage::Warning :
        title = "Внимание";
        backgroundColor = "#fcb786";
        progressBarColor = "#f80";
        icon = style()->standardIcon(QStyle::SP_MessageBoxWarning);
        break;
    case TypeMessage::Error :
        title = "Ошибка";
        backgroundColor = "#ff8585";
        progressBarColor = "#f00";
        icon = style()->standardIcon(QStyle::SP_MessageBoxCritical);
        break;
    }

    titleLabel->setText(title);
    textLabel->setText(text);
    setStyleSheet(QString("background-color: %1;").arg(backgroundColor));
    progressBar->setStyleSheet(QString("QProgressBar::chunk { background-color: %1; }").arg(progressBarColor));
    iconLabel->setPixmap(icon.pixmap(iconLabel->size()));

    adjustSize(); //Автоматическая настройка размера

    showNotification();
}

void Notification::showNotification()
{
    positionAlertBox();
    show();
    timer.start(1);
}

void Notification::updateProgressBar()
{
    progressBar->setValue(progressBar->value() + 1);
    if (progressBar->value() == progressBar->maximum())
    {
        close();
        delete this; //освободить память после окончания таймера
    }
}

void Notification::setupUI()
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

    int time = 1500;
    progressBar = new QProgressBar(this);
    progressBar->setTextVisible(false);
    progressBar->setRange(0, time);

    mainLayout->addWidget(iconLabel, 1, 0, 2, 1);
    mainLayout->addWidget(titleLabel, 1, 1);
    mainLayout->addWidget(textLabel, 2, 1);
    mainLayout->addWidget(progressBar, 3, 0, 1, 2);

    setFixedWidth(300);
}

void Notification::setupConnections()
{
    connect(&timer, &QTimer::timeout, this, &Notification::updateProgressBar);
}

void Notification::positionAlertBox()
{
    if (_parentForm) {
        QPoint parentPos = _parentForm->mapToGlobal(QPoint(0, 0));
        int x = parentPos.x() + _parentForm->width() - width() - 15;
        int y = parentPos.y() + _parentForm->height() - height() - 15;
        move(x, y);
    }
    else
    {
        QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
        int x = screenGeometry.width() - width() - 15;
        int y = screenGeometry.height() - height() - 15;
        move(x, y);
    }
}
