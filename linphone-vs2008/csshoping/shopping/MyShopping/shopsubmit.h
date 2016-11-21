#ifndef SHOPSUBMIT_H
#define SHOPSUBMIT_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QFileDialog>
#include "ui_shopsubmit.h"
#include "httpdeal.h"
#include "common.h"
#include <QTimer>

#include <string>



class shopsubmit : public QWidget
{
	Q_OBJECT

public:
	shopsubmit(QWidget *parent = 0);
	~shopsubmit();

	int isDigitStr(QString src);
	void uploadfile(QString filename);
	bool uploadImage(std::string localPath);

	QTimer *tuanGouTimer;

	//团购倒计时用
	QString strBuffer1;
    QDateTime time1;
    QString strBuffer2;
    QDateTime time2;

    uint subSecs;
	uint currentShIndex;
	QString shKeyIndex;
	QString shProductIndex;

private:
	Ui::shopsubmit ui;
	HttpDeal *httpconn;

	QMap<QString,GoogsClass>  map_classinfo;//
	
	
	//QMap<QString,ProductInfo>  map_productinfo,map_shproductinfo;//默认总是排序byliu
	//QHash<QString,ProductInfo>  map_productinfo,map_shproductinfo;//默认总是排序QHash
	QVector<ProductInfo>  vector_productinfo,vector_shproductinfo;//默认总是排序QHash

	//下载分类信息xml
	QNetworkAccessManager *classConn;

	QNetworkAccessManager *classDelConn; //connect(classDelConn, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyClassDelConn(QNetworkReply* )));
	//下载产品信息xml
	QNetworkAccessManager *productConn;

	//下载产品信息xml
	QNetworkAccessManager *shProductConn;

	//http://222.73.197.174:88/OAapp/WebObjects/OAapp.woa?cjApply=productAudit&id=&pwd=
	//请求产品审核
	QNetworkAccessManager *requireShConn;

	//上传图片
	QNetworkAccessManager *uploadConn;

	//修改产品属性
	QNetworkAccessManager *productMode;

	//删除修改产品
	QNetworkAccessManager *productDelConn;
	QNetworkAccessManager *_uploadManager;
    QNetworkReply *_reply;
   
	//文件对话框
	QFileDialog* fileDlg;

	void loadXmlClass();
	void initClassTable();

	void loadXmlProduct();
	void loadShXmlProduct();
	void initProductTable();
	void initProductShTable();

	//从网络下载图片
	void setNetworkPic(QString szUrl);


	QString selectFile();

	//md5加密字符串生成
	QString getMd5Check( QString md5key );



private slots:
	void on_manageBtn_clicked();
	void on_addProductBtn_clicked();
	void on_xgProductBtn_clicked();//商品管理
	void on_classOkBtn_clicked();
	void on_goodsInfoOkBtn_clicked();
	void on_bigpicBtn_clicked();
	void on_smallpicBtn_clicked();
	void on_productModeBtn_clicked();
	void on_goodsDelBtn_clicked();
	void on_requireShBtn_clicked();
    void on_goodsBackBtn_clicked();
    void on_spUploadBtn_clicked();


	void on_bigpicBtn_2_clicked();
	void on_smallpicBtn_2_clicked();
	void setJiShi();

	void on_shProductBtn_clicked(); //xgProductBtn
	void on_xgClassBtn_clicked();
	void on_addClassOkBtn_clicked();
	void on_classDelBtn_clicked();

	void getClassItem(QTableWidgetItem* item);
	void getProductItem(QTableWidgetItem* item);
	void getShProductItem(QTableWidgetItem* item);
	void replyClassConn(QNetworkReply *reply);
	void replyClassDelConn(QNetworkReply *reply);

	void replyProductConn(QNetworkReply* reply );//已审核
	void replyshProductConn(QNetworkReply* reply );//待审核
	void replyRequireShConn(QNetworkReply* reply );//请求商品审核
	void replyUploadConn(QNetworkReply* reply );
	void replyProductMode(QNetworkReply* reply );
	void replyProductDelConn(QNetworkReply* reply);

	void uploadFinished( QNetworkReply* );

	void shBoxValueChanged(QString context);
	void initClassList();
	

};

#endif // SHOPSUBMIT_H
