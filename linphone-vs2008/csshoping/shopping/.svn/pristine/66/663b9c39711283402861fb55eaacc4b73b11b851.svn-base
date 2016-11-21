#ifndef HTTPDEAL_H
#define HTTPDEAL_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QtNetwork>
class QNetworkReply;


class HttpDeal : public QObject
{
	Q_OBJECT

public:
	HttpDeal(QObject *parent);
	~HttpDeal();

	//下载用户订单列表
	QString serverIP;
   void setXmlFile(QString filename);
	void sendRequire(QString url);


private:
	QString downXmlUrl;//订单列表下载地址
	QNetworkAccessManager *manager;
	QString xmlfilename;
	
	void setUrl(QString url);

public slots:
	//请求用户订单xml完成处理函数
	void  replyFinished(QNetworkReply *reply);
	
};

#endif // HTTPDEAL_H
