#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>

namespace Ui {
class Register_Dialog;
}

class Register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Register_Dialog(QWidget *parent = nullptr);
    ~Register_Dialog();

private slots:
    void on_btn_get_code_clicked();

private:
    Ui::Register_Dialog *ui;

    void showTip(QString str, bool b_ok);
};

#endif // REGISTER_DIALOG_H
