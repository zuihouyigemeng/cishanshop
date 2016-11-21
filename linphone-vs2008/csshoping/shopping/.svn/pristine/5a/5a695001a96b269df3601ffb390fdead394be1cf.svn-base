#include "httpdeal.h"

#include "common.h"
#include <QTextCodec>
#include <QMessageBox>

extern SipInfo  usrAuth; //用户信息

HttpDeal::HttpDeal(QObject *parent)
	: QObject(parent)

{
	serverIP=tr(usrAuth.serverip);
	manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply* )));

}

HttpDeal::~HttpDeal()
{
	delete manager;
	manager=NULL;
}

void HttpDeal::sendRequire(QString url)
{
	setUrl(url);
    manager->get(QNetworkRequest(QUrl(downXmlUrl)));//url
	//QMessageBox::warning(this,tr("ccccccc"),downXmlUrl);
	//qDebug()<<"+++++++++++++++++++"<<downXmlUrl;

}

void HttpDeal::replyFinished(QNetworkReply *reply)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString all = codec->toUnicode(reply->readAll());

   QFile file(xmlfilename);  
  
   if(!file.open(QIODevice::WriteOnly | QIODevice::Text))  
    {  
        qDebug()<< "Open failed." <<file.error(); 
        return;  
    }  
      
    QTextStream txtOutput(&file);  
    txtOutput << all << endl;  
      
    file.close(); 
}
void HttpDeal::setUrl(QString url)
{
	downXmlUrl=serverIP+url;
}

void HttpDeal::setXmlFile(QString filename)
{
	xmlfilename=filename;
}