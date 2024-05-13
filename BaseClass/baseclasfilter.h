#ifndef BASECLASFILTER_H
#define BASECLASFILTER_H

#include <QDialog>
#include <QMap>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <functional>
#include <QValidator>

class BaseClasFilter : public QDialog
{
    Q_OBJECT

protected:
    QPushButton* applyFilterButton;
    QPushButton* resetButton;
    QMap<QRadioButton*, std::function<const QString()>> functionsSetFilters;
    QMap<QPushButton*, std::function<void()>> functionsVisibleFilters;

public:
    BaseClasFilter(QWidget *parent);

    void reset();

protected:
    void setButton(QPushButton* applyFilterButton, QPushButton* resetButton);
    void startSetting();
    virtual void connects();
    virtual void applyFilter();
    virtual void initFunSetFilters() = 0;
    virtual void initFunVisibletFilters() = 0;
    virtual void visibleCategory();
    virtual void hideCategory() = 0;
    virtual void customizationLiteEdit() = 0;
    virtual void selectCategory(QPushButton *button);
    virtual void setBoldButtonCategoty(QPushButton* button, const bool bold);

signals:
    void setFilter(const QString&);
};

#endif // BASECLASFILTER_H
