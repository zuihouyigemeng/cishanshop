#include "myshopping.h"
#include <QtGui/QApplication>
#include <QTextCodec>

#include "common.h"

SipInfo  usrAuth; //用户信息


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName(QTextCodec::codecForLocale()->name())); 
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));

	ReadUserConfig();
	MyShopping w;

	w.show();

	//WriteUserConfig();

	RegisterSip();
	
	return a.exec();
}



