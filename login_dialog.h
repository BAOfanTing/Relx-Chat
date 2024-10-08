#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>

namespace Ui {
class Login_Dialog;
}

class Login_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Login_Dialog(QWidget *parent = nullptr);
    ~Login_Dialog();

private:
    Ui::Login_Dialog *ui;

signals:
    void switchRegister();

};

#endif // LOGIN_DIALOG_H
