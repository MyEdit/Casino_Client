#ifndef FLOATINGMESSAGE_H
#define FLOATINGMESSAGE_H

#include <QTimer>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QScreen>
#include <QPainter>
#include <QStyle>

enum class TypeMessage
{
    Information,
    Warning,
    Error
};

class Notification : public QWidget
{
    Q_OBJECT

    QLabel* titleLabel;
    QLabel* textLabel;
    QLabel* iconLabel;
    QProgressBar* progressBar;
    QTimer timer;
    QWidget* parentForm;

public:
    Notification();
    void setAlertProperties(const TypeMessage typeMessage, const QString& text, QWidget* parentForm);
    static void showNotification(const TypeMessage typeMessage, const QString& text, QWidget* parentForm);

private:
    void setupUI();
    void setupConnections();
    void positionAlertBox();
    void showNotification();
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateProgressBar();
};


#endif // FLOATINGMESSAGE_H
