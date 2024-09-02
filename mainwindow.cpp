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

    _login_dlg = new Login_Dialog(this);
    setCentralWidget(_login_dlg);
    _register_dlg = new Register_Dialog(this);

    _login_dlg->show();

    connect(_login_dlg,&Login_Dialog::switchRegister,this,&MainWindow::slots_switch_register);

    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _register_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//切换为注册页面的槽函数
void MainWindow::slots_switch_register()
{
    setCentralWidget(_register_dlg);  // 设置主窗口的中心部件为注册对话框
    _login_dlg->hide();  // 隐藏登录对话框
    _register_dlg->show();  // 显示注册对话框
}
