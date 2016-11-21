#ifndef MYSHOPPING_H
#define MYSHOPPING_H

#include <QtGui/QWidget>
#include "ui_myshopping.h"
#include "common.h"
#include "myshopping.h"


class QNetworkReply;
class QNetworkAccessManager;
class QStandardItemModel;
class QStringListModel;

class MyShopping : public QWidget
{
	Q_OBJECT

public:
	MyShopping(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyShopping();
   
	Ui::MyShoppingClass ui;
    
	//保存当前的订单号
	QString tmpOrderId;

	//记录配送中是第几哥
	int tmpSenderNum;


	//横竖滚动位置记录
	int horposion;
	int verposion;

	QString sipTel;

	//来电闪动定时器
	QTimer *callTimer;
	//用户订单字典
	QMap<QString,GuestOrder>  m_guestmap;
    //以电话号码为主键
	QMap<QString,GuestOrder>  m_guestmapTel;
	
	
	//用户订单状态字典（以编号为主键）
	QMap<QString,GoodsDics>   map_PsstatesNo;
	//用户订单状态字典（以键值为主键）
	QMap<QString,GoodsDics>   map_PsstatesMsg;




	//用户历史订单列表
	QMap<QString,GuestOrder>   m_historymap;

	//遍历订单,初始化订单列表
	void iterGuestMap();

	//遍历历史订单
	void iterHistoryMap();

	//请求订单列表
	void loadXML();

	//请求订单列表
	void historyXML();
	
	//请求订单状态字典
	void loadDicXML();

	//设置配送状态
	void setSendCombox();

public  slots:
	void linponeIterate();

    //定时更新订单列表
	void updateGuest();

	//历史订单
	void updateHistory();

	//保留函数，用户呼叫时订单颜色闪动变化
	void updateColor();

	//坐左边四个按钮
	void on_homeBtn_clicked();
	void on_addGoodsBtn_clicked();
	void on_AppointBtn_clicked();
	void on_sendBtn_clicked();

	void on_HistoryBtn_clicked();
	void on_pushButton_clicked();

	void on_productQueryBtn_clicked();
	
	//请求用户订单xml完成处理函数
	void replyFinished(QNetworkReply *reply);

    //请求用户历史订单xml完成处理函数
	void replyHisFinished(QNetworkReply *reply);

	//修改订单状态处理函数
	void replyGoodState(QNetworkReply *reply);
	void replyGoodDics(QNetworkReply *reply);

    //单击列表
	void changeCurrent(const QModelIndex &current,const QModelIndex &previous);
	void dealCall(const QString &str);

	//接听挂断
	void on_sipcallBtn_clicked();
	void on_siphungupBtn_clicked();

	//条件查询comboBox处理函数
	void conditionProcess(int index);


	//
	void verMove(int);
	void horMove(int);

private:
	//Ui::MyShoppingClass ui;
	//下载订单xml
	QNetworkAccessManager *manager;

	//下载历史订单xml
	QNetworkAccessManager *managerHistory;
	//提交订单状态
	QNetworkAccessManager *googstate;
    //下载订单状态自动xml
	QNetworkAccessManager *goodsdic;

	QStandardItemModel* initModel;
	QStandardItemModel* historyModel;
	          
	QStringListModel* listModel;
	
	int currentRow; //当前选中的行
	int currentQueryCombo;
};

#endif // MYSHOPPING_H
