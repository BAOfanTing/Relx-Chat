#include "register_dialog.h"
#include "ui_register_dialog.h"
#include "global.h"
// Register_Dialog 类的构造函数
Register_Dialog::Register_Dialog(QWidget *parent)  // 接受父窗口指针作为参数
    : QDialog(parent),  // 调用基类 QDialog 的构造函数
    ui(new Ui::Register_Dialog)  // 分配 Ui::Register_Dialog 对象的空间
{
    ui->setupUi(this);  // 设置 UI，使用 Qt Designer 生成的 setupUi 方法初始化对话框界面

    // 设置两个密码输入框的显示模式为密码模式，即用户输入时不显示实际字符
    ui->le_password1->setEchoMode(QLineEdit::Password);
    ui->le_password2->setEchoMode(QLineEdit::Password);

    // 设置错误提示标签的状态属性为 "normal"，这可能会影响其样式或行为
    ui->err_tip->setProperty("state", "normal");

    // 调用全局函数 repolish，刷新错误提示标签的样式
    repolish(ui->err_tip);
}

Register_Dialog::~Register_Dialog()
{
    delete ui;
}
