#ifndef WINDOW_ADMIN_H
#define WINDOW_ADMIN_H

#include <QMainWindow>

namespace Ui {
class Window_Admin;
}

class Window_Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Admin(QWidget *parent = nullptr);
    ~Window_Admin();

private:
    Ui::Window_Admin *ui;
};

#endif // WINDOW_ADMIN_H
