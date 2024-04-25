#ifndef RECONNECTING_H
#define RECONNECTING_H

#include <QTimer>
#include <QDialog>
#include <QLabel>
#include <QProgressBar>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QScreen>
#include <QPainter>
#include <QStyle>

class Reconnecting : public QDialog
{
    Q_OBJECT

    QLabel *titleLabel;
    QLabel *textLabel;
    QLabel *iconLabel;
    QProgressBar *progressBar;
    QTimer timer;
    QWidget* parentForm;

public:
    Reconnecting();

    void setAlertProperties(QWidget* parentForm);

private:
    void setupUI();
    void setupConnections();
    void positionAlertBox();
    void showReconnecting();
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateProgressBar();
};

#endif // RECONNECTING_H
