#ifndef DISTRIBUTEDLG_H
#define DISTRIBUTEDLG_H

#include <QWidget>
#include "ui_distributedlg.h"
#include "common.h"



class QNetworkReply;
class QNetworkAccessManager;
class QStandardItemModel;
class QStringListModel;
class MyShopping;

class DistributeDlg : public QWidget
{
	Q_OBJECT

public:
	DistributeDlg(QWidget *parent = 0);
	~DistributeDlg();
   
	QMap<QString,SenderInfo>  map_sendinfo;


	//请求配送员列表xml，同时初始化数据字典
	void loadXML();

	//遍历map，显示配送员列表
	void iterGuestMap();
	MyShopping *getShop();
	void setShop(MyShopping* _myshop);

public slots:
	//修改订单状态处理函数
	void getCourierList(QNetworkReply *reply);
	void changeSenderState(QNetworkReply *reply);
	void changeCurrent(const QModelIndex &current,const QModelIndex &previous);
	void on_pushButton_clicked();

private:
	Ui::DistributeDlg ui;
	QNetworkAccessManager *senderlist;
	QNetworkAccessManager *changestate;



	QStandardItemModel* senderModel;
	QStringListModel* listModel;

	
	MyShopping* myshop;

};

#endif // DISTRIBUTEDLG_H
