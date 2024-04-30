#include "workingistableview.h"

WorkingIsTableView::WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn) :
    tableView(table),
    boxsNameColumn(boxsNameColumn) {}

void WorkingIsTableView::settingVisualTableView()
{
    tableView->setStyleSheet("selection-background-color: rgb(42, 117, 255);");
    tableView->setWordWrap(false);

    //Устанавливка жирного шрифта для заголовков столбцов
    QFont font = tableView->horizontalHeader()->font();
    font.setBold(true);
    tableView->horizontalHeader()->setFont(font);

    //Скрыть номер строк в tableView
    tableView->verticalHeader()->setVisible(false);

    tableView->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 14pt; }");

    //Устанавка растягивания для заголовков строк и столбцов по размеру содержимого
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Устанавка растягивания для строк и столбцов на всю высоту
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Запрет редактирования данных в ячейке
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Для выделения всей строки
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void WorkingIsTableView::setModel(QSharedPointer<QStandardItemModel> model)
{
    if(model->rowCount() == 0)
    {
        QStandardItemModel* emptyModel = new QStandardItemModel;
        emptyModel->setHorizontalHeaderItem(0, new QStandardItem(""));
        QStandardItem* item = new QStandardItem("Данных нет");
        item->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        emptyModel->setItem(0, 0, item);
        tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tableView->setModel(emptyModel);
        emit unlockInterface(true);
        return;
    }

    tableView->setModel(model.data());

    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    for (int col = 1; col < model->columnCount(); ++col)
    {
        QString originalHeaderText = model->headerData(col, Qt::Horizontal).toString();
        QString wrappedHeaderText = originalHeaderText.replace(" ", "\n");
        model->setHeaderData(col, Qt::Horizontal, wrappedHeaderText);
    }

    if(headers.isEmpty())
        setValueNameColumn();

    emit unlockInterface(true);
}

void WorkingIsTableView::setValueNameColumn()
{
    headers = getColumnHeaders();

    for(QComboBox* boxNameColumn : *boxsNameColumn)
    {
        for(QString nameColumn : headers)
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
    QAbstractItemModel* model =tableView->model();
    int columnCount = model->columnCount();

    for (int column = 1; column < columnCount; ++column)
    {
        QString header = model->headerData(column, Qt::Horizontal).toString();
        header = header.replace("\n", " ");
        headers.push_back(header);
    }

    return headers;
}

void WorkingIsTableView::setCurrentIndex(QModelIndex index)
{
    tableView->setCurrentIndex(index);
}

bool WorkingIsTableView::checkDataInTable()
{
    return tableView->isModal();
}
