#include "mainwindow.h"

#include <QApplication>
/******************************************************************************
 *
 * @file       main.cpp
 * @brief      XXXX Function
 *
 * @author     纯真丁一郎
 * @date       2024/09/02
 * @history
 *****************************************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
