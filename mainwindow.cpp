#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************
 *
 * @file       mainwindow.cpp
 * @brief      主窗口
 *
 * @author     纯真丁一郎
 * @date       2024/09/02
 * @history
 *****************************************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _login_dlg = new Login_Dialog();
    setCentralWidget(_login_dlg);
    _login_dlg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
