#include "login_dialog.h"
#include "ui_login_dialog.h"

Login_Dialog::Login_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login_Dialog)
{
    ui->setupUi(this);

    //绑定点击切换注册页面的信号
    connect(ui->btn_register,&QPushButton::clicked,this,&Login_Dialog::switchRegister);
}

Login_Dialog::~Login_Dialog()
{
    delete ui;
}
