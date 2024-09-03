#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include "QStyle"
#include <QRegularExpression>
/**
 * @brief repolish 用于刷新样式
 */
extern std::function<void(QWidget *)> repolish;

#endif // GLOBAL_H


