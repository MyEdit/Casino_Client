#include "workingistableview.h"

WorkingIsTableView::WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn) :
    _tableView(table),
    _boxsNameColumn(boxsNameColumn)
{

}

void WorkingIsTableView::settingVisualTableView()
{
    _tableView->setStyleSheet("selection-background-color: rgb(42, 117, 255);");
    _tableView->setWordWrap(false);

    //Устанавливка жирного шрифта для заголовков столбцов
    QFont font = _tableView->horizontalHeader()->font();
    font.setBold(true);
    _tableView->horizontalHeader()->setFont(font);

    //Скрыть номер строк в tableView
    _tableView->verticalHeader()->setVisible(false);

    _tableView->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 14pt; }");

    //Устанавка растягивания для заголовков строк и столбцов на по размеру содержимого
    _tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Устанавка растягивания для строк и столбцов на всю высоту
    _tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Запрет редактирования данных в ячейке
    _tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Для выделения всей строки
    _tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void WorkingIsTableView::setModel(QStandardItemModel* model)
{
    if(model->rowCount() == 0)
    {
        Message::logWarn("Данных нет");
        return;
    }

    _tableView->setModel(model);

    _tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    for (int col = 1; col < model->columnCount(); ++col)
    {
        QString originalHeaderText = model->headerData(col, Qt::Horizontal).toString();
        QString wrappedHeaderText = originalHeaderText.replace(" ", "\n");
        model->setHeaderData(col, Qt::Horizontal, wrappedHeaderText);
    }

    if(_headers.isEmpty())
        setValueNameColumn();
}

void WorkingIsTableView::setValueNameColumn()
{
    _headers = getColumnHeaders();

    for(QComboBox* boxNameColumn : *_boxsNameColumn)
    {
        for(QString nameColumn : _headers)
        {
            boxNameColumn->blockSignals(true);
            boxNameColumn->addItem(nameColumn);
            boxNameColumn->blockSignals(false);
        }
    }
}

QVector<QString> WorkingIsTableView::getColumnHeaders()
{
    QVector<QString> headers;
    QAbstractItemModel* model =_tableView->model();
    int columnCount = model->columnCount();

    for (int column = 0; column < columnCount; ++column)
    {
        QString header = model->headerData(column, Qt::Horizontal).toString();
        header = header.replace("\n", " ");
        headers.push_back(header);
    }

    return headers;
}
