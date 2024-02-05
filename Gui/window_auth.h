#ifndef WINDOW_AUTH_H
#define WINDOW_AUTH_H

#include <QMainWindow>
#include <Network/networkclient.h>
#include <Network/PacketsActions/p_authorization.h>
#include <GUI/window_admin.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Window_Auth; }
QT_END_NAMESPACE

class Window_Auth : public QMainWindow
{
    Q_OBJECT

public:
    Window_Auth(QWidget *parent = nullptr);
    ~Window_Auth();

private slots:
    void on_Button_Auth_clicked();

private:
    Ui::Window_Auth *ui;
};
#endif // WINDOW_AUTH_H
