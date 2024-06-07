#ifndef BASECLASFILTER_H
#define BASECLASFILTER_H

#include <QDialog>
#include <QMap>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <functional>
#include <QValidator>
#include <QDebug>

class BaseClasFilter : public QDialog
{
    Q_OBJECT

protected:
    QPushButton* applyFilterButton;
    QPushButton* resetButton;
    QMap<QCheckBox*, std::function<const QString()>> functionsSetFilters;
    QMap<QPushButton*, std::function<void()>> functionButton;
    QList<QWidget*> filterwidgets;

public:
    BaseClasFilter(QWidget *parent);

    void reset();

protected:
    void setButton(QPushButton* applyFilterButton, QPushButton* resetButton);
    void setFilterWidgets();
    void startSetting();
    void resetCategory(QWidget* parent);
    virtual void connects();
    virtual void applyFilter();
    virtual void initFunSetFilters() = 0;
    virtual void initFunButton() = 0;
    virtual void visibleCategory();
    virtual void hideCategory() = 0;
    virtual void customizationLiteEdit() = 0;
    virtual void setBoldButtonCategoty(QPushButton* button, const bool bold);
    void textChange(QCheckBox* checkBox, QLineEdit* lineEdit);

signals:
    void setFilter(const QString&);
};

#endif // BASECLASFILTER_H
