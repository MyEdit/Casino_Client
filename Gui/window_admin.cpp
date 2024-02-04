#include "window_admin.h"
#include "ui_window_admin.h"

Window_Admin::Window_Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window_Admin)
{
    ui->setupUi(this);
}

Window_Admin::~Window_Admin()
{
    delete ui;
}
