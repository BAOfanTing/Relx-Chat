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

// 当点击获取验证码按钮时触发的方法
void Register_Dialog::on_btn_get_code_clicked()
{
    // 获取用户在邮件输入框中输入的内容
    auto email = ui->le_mailbox->text();

    // 定义一个正则表达式来验证邮箱地址格式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    // 使用正则表达式检查邮箱地址是否匹配
    bool match = regex.match(email).hasMatch();

    if (match) {
        // 如果邮箱地址格式正确，则发送 HTTP 请求以获取验证码
        // 这里应当实现发送 HTTP 请求的逻辑，但此处仅做注释说明
        // 发送http请求验真码
    } else {
        // 如果邮箱地址格式不正确，则提示用户
        showTip("邮箱地址不正确", false);
    }
}

// 显示提示信息的方法
void Register_Dialog::showTip(QString str, bool b_ok)
{
    // 设置错误提示标签的状态属性
    if (b_ok) {
        // 如果 b_ok 为 true，设置状态为正常
        ui->err_tip->setProperty("state", "normal");
    } else {
        // 如果 b_ok 为 false，设置状态为错误
        ui->err_tip->setProperty("state", "err");
    }
    // 设置错误提示标签的文本为传入的字符串
    ui->err_tip->setText(str);
    // 调用全局函数 repolish 刷新错误提示标签的样式
    repolish(ui->err_tip);
}

