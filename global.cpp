#include "global.h"

std::function<void(QWidget *)> repolish = [](QWidget *widget) {
    // 使用 widget 的样式（style）对象进行 unpolish 操作
    // unpolish 通常用于取消对 widget 的样式优化
    widget->style()->unpolish(widget);

    // 使用 widget 的样式（style）对象进行 polish 操作
    // polish 通常用于重新应用样式优化
    widget->style()->polish(widget);
};
