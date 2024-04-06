﻿#include "window_player.h"
#include "ui_window_player.h"

#include "Gui/form.h"

Window_Player::Window_Player(QWidget *parent) : BaseClassMainMenu(parent), ui(new Ui::Window_Player)
{
    ui->setupUi(this);
    fullName = P_Authorization::getActualUser()->getName();

    prepareStyleSheets();
    assigningValues();
    completionTabWidget();
    settingUserInformation();
    settingWindowPosition();
    connects();
    settingVisual();

    ui->tabWidget->setCurrentWidget(welcomeTab.get());
}

Window_Player::~Window_Player()
{
    delete ui;
}

void Window_Player::assigningValues()
{
    buttonSwitchingTab.push_back(ui->gameTables);
    buttonSwitchingTab.push_back(ui->replenish);
    buttonSwitchingTab.push_back(ui->credits);

    selectedButton =
    {
        {ui->gameTables, ui->label},
        {ui->replenish, ui->label_2},
        {ui->credits, ui->label_3}
    };
}

void Window_Player::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    rendering_WelcomeTab();
    rendering_GameTablesTab();
}

void Window_Player::rendering_WelcomeTab()
{
    welcomeTab = QSharedPointer<Welcome>::create(fullName);
    ui->tabWidget->addTab(welcomeTab.data(), "");
}

void Window_Player::uploadingPhotoPlaer()
{
    QPixmap photo = uploadingUserPhoto(":/photos/resources/TestStuffPhoto.jpg");

    ui->photo->setScaledContents(true);
    ui->photo->setPixmap(photo);
}

void Window_Player::settingUserInformation()
{
    ui->fullNamePlayer->setText(fullName);
    uploadingPhotoPlaer();
}

void Window_Player::connects()
{
    connect(ui->gameTables, &QPushButton::clicked, this, &Window_Player::on_gameTables_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &Window_Player::on_buttonExit_clicked);
    connect(ui->credits, &QPushButton::clicked, this, &Window_Player::on_credits_clicked);
    connect(ui->replenish, &QPushButton::clicked, this, &Window_Player::on_replenish_clicked);
}

void Window_Player::on_gameTables_clicked()
{
    ui->tabWidget->setCurrentWidget(gameTabels.get());
    onNavigationsButton_clicked();
}

void Window_Player::on_credits_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Player::on_replenish_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Player::setTabels()
{
    gameTabels->updateTables();
}

void Window_Player::rendering_GameTablesTab()
{
    gameTabels = QSharedPointer<GameTable>::create();
    ui->tabWidget->addTab(gameTabels.data(), "");
}
