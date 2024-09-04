#include "httpmanger.h"

HttpManager::HttpManager() {
    connect(this,&HttpManager::sig_http_finish,this,&HttpManager::slot_http_finish);
}
HttpManager::~HttpManager(){}

void HttpManager::PostHttpReq(QUrl url, QJsonObject json, ReqID req_id, Modules mod)
{
    QByteArray data = QJsonDocument(json).toJson();
    QNetworkRequest request(url);       // 创建网络请求对象
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json"); // 设置请求头 Content-Type 为 application/json
    request.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(data.length()));// 设置请求头 Content-Length 为数据长度
    auto self = shared_from_this(); // 获取当前对象的智能指针，确保在异步回调中对象仍然有效
    // 发送 POST 请求
    QNetworkReply * reply = _manager.post(request,data);

    //处理发送完成的情况
    connect(reply,&QNetworkReply::finished,[this,self,reply,req_id,mod](){
       //处理错误情况
        if (reply->error() != QNetworkReply::NoError){
           qDebug()<< reply->errorString();
            //发送信号通知完成
           emit sig_http_finish(req_id,"",ErrorCodes::ERR_NETWORK,mod);
           reply->deleteLater();
           return;
        }

        //无错误的情况
        QString res = reply->readAll();
        //发送信号通知完成
        emit sig_http_finish(req_id, res, ErrorCodes::SUCCESS,mod);
        reply->deleteLater();
        return;
    });
}

void HttpManager::slot_http_finish(ReqID id, QString res, ErrorCodes err, Modules mod)
{
    // 根据模块类型处理不同的槽函数
    if (mod == Modules::REGISTERMOD) {
        // 发送注册模块的信号
        sig_register_mod(id, res, err);
    }
}
