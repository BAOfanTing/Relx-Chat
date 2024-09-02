#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login_dialog.h"
#include <QMainWindow>
#include "register_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Login_Dialog *_login_dlg;
    Register_Dialog * _register_dlg;

public slots:
    void slots_switch_register();
};
#endif // MAINWINDOW_H
