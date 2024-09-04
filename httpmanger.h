#ifndef HTTPMANGER_H
#define HTTPMANGER_H
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include "Singleton.h"
#include <QJsonDocument>
#include <QJsonObject>

//CRTP
class HttpManager: public QObject ,public Singleton<HttpManager>,
                   public std::enable_shared_from_this<HttpManager>
{
    Q_OBJECT
public:
    ~HttpManager();

private:
    // 友元类声明，允许 Singleton 模板类访问私有构造函数
    friend class Singleton<HttpManager>;
    // 私有构造函数，防止外部实例化
    HttpManager();

    // 网络访问管理器
    QNetworkAccessManager _manager;

    // 发送 HTTP POST 请求
    void PostHttpReq(QUrl url, QJsonObject json, ReqID req_id, Modules mod);

private slots:
    void slot_http_finish(ReqID id, QString res, ErrorCodes err, Modules mod);
signals:
    void sig_http_finish(ReqID id, QString res, ErrorCodes err, Modules mod);
    void sig_register_mod_finish(ReqID id, QString res, ErrorCodes err);
};

#endif // HTTPMANGER_H
