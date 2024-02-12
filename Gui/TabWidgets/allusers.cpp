#include "allusers.h"
#include "ui_allusers.h"

AllUsers::AllUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllUsers)
{
    ui->setupUi(this);
    workingWithTableView();
}

AllUsers::~AllUsers()
{
    delete ui;
}

void AllUsers::setModel(QStandardItemModel* model)
{
    if(model->rowCount() == 0)
    {
        Message::logWarn("Данных нет");
        return;
    }

    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    for (int col = 1; col < model->columnCount(); ++col)
    {
        QString originalHeaderText = model->headerData(col, Qt::Horizontal).toString();
        QString wrappedHeaderText = originalHeaderText.replace(" ", "\n");
        model->setHeaderData(col, Qt::Horizontal, wrappedHeaderText);
    }
}

void AllUsers::workingWithTableView()
{
    ui->tableView->setStyleSheet("selection-background-color: rgb(42, 117, 255);");
    ui->tableView->setWordWrap(false);

    //Устанавливка жирного шрифта для заголовков столбцов
    QFont font = ui->tableView->horizontalHeader()->font();
    font.setBold(true);
    ui->tableView->horizontalHeader()->setFont(font);

    //Скрыть номер строк в tableView
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 14pt; }");

    //Устанавка растягивания для заголовков строк и столбцов на по размеру содержимого
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Устанавка растягивания для строк и столбцов на всю высоту
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Запрет редактирования данных в ячейке
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Для выделения всей строки
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
