#include "mainwindow.h"
#include "login_dialog.h"
#include <QApplication>

/******************************************************************************
 *
 * @file       main.cpp
 * @brief      主程序
 *
 * @author     纯真丁一郎
 * @date       2024/09/02
 * @Blog       https://www.relxdingyilang.cn/
 * @history
 *****************************************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
