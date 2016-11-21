#include "distributedlg.h"

#include <QtNetwork>
#include <QMap>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QMessageBox>


#include "Markup.h"
#include "myshopping.h"

#include< iostream>
using namespace std;


extern Order2Sender os;
extern SipInfo  usrAuth; //用户信息


DistributeDlg::DistributeDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	senderlist = new QNetworkAccessManager(this);
    connect(senderlist, SIGNAL(finished(QNetworkReply*)),this, SLOT(getCourierList(QNetworkReply*)));
	

	QString ipStr(usrAuth.serverip);
	QString tmpStr(tr("/OAapp/WebObjects/OAapp.woa?cjApply=serviceUersList_ps"));
	
	senderlist->get(QNetworkRequest(QUrl(ipStr+tmpStr)));
	qDebug()<<"快递员"<<ipStr+tmpStr;

	changestate= new QNetworkAccessManager(this);
	connect(changestate, SIGNAL(finished(QNetworkReply*)),this, SLOT(changeSenderState(QNetworkReply*)));
	
	//初始化list模型
	listModel = new QStringListModel;

		//用户订单表初始化
	senderModel=new QStandardItemModel(50, 5, this);
	senderModel->setHeaderData(0, Qt::Horizontal, tr("配送员ID"));
	senderModel->setHeaderData(1, Qt::Horizontal, tr("配送员电话"));
    senderModel->setHeaderData(2, Qt::Horizontal, tr("配送员姓名"));
	senderModel->setHeaderData(3, Qt::Horizontal, tr("配送员位置"));
	senderModel->setHeaderData(4, Qt::Horizontal, tr("配送员任务数"));

	 ui.tableView->setEditTriggers ( QAbstractItemView::NoEditTriggers );
	 ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	 ui.tableView->setModel(senderModel);
	 for(int i=0;i<11;i++)
		ui.tableView->setColumnWidth(i,120);

	loadXML();
	iterGuestMap();
	
	// 获取视图的项目选择模型
    QItemSelectionModel *selectionModel = ui.tableView->selectionModel();
    connect(selectionModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)),this, SLOT(changeCurrent(QModelIndex,QModelIndex)));
	
}

DistributeDlg::~DistributeDlg()
{
	delete senderlist;
	delete changestate;
	delete listModel;
	delete senderModel;
}


void DistributeDlg::getCourierList(QNetworkReply *reply)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString all = codec->toUnicode(reply->readAll());

    QFile file("senderlist.xml");  
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))  
    {  
        qDebug()<< "Open failed." ;  
        return;  
    }  
      
    QTextStream txtOutput(&file);   
    txtOutput << all << endl;  
    file.close(); 
}

//配送返回结果
void DistributeDlg::changeSenderState(QNetworkReply *reply)
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString all = codec->toUnicode(reply->readAll());

    QString codeStr,msgStr;
	QXmlStreamReader resxml(all);
	while(!resxml.atEnd())  
    {  
        resxml.readNext();  
        if(resxml.isStartElement())  
        {  
            if(resxml.name() == "Code")  
            {
				codeStr=resxml.readElementText();
				if(codeStr==tr("-1"))
					QMessageBox::warning(this,"提示！",msgStr);
            }
			if(resxml.name() =="msg")
			{
				msgStr=resxml.readElementText();
			}
        }  
    }
	//QMessageBox::warning(this,"提示！",msgStr);
}


void DistributeDlg::loadXML()
{
    CMarkup xml;
	string str="senderlist.xml";
	SenderInfo si;

    bool xx=xml.Load(str);
    xml.ResetMainPos();   

	while (xml.FindChildElem("user"))
	{
		GuestOrder m_guestorder;
		xml.IntoElem();

		xml.FindChildElem("id");	
		string idStr= xml.GetChildData();
		strcpy(si.senderId,idStr.c_str());

		xml.FindChildElem("phone");	
		string phoneStr= xml.GetChildData();
		strcpy(si.senderPhone,phoneStr.c_str());

		xml.FindChildElem("name");	
		string nameStr= xml.GetChildData();
		strcpy(si.senderName,nameStr.c_str());

		xml.OutOfElem();

		QString strTmp(si.senderId);
		map_sendinfo.insert(strTmp,si);//orderIdStr
	}
}


//遍历map
void DistributeDlg::iterGuestMap()
{
	QMap<QString,SenderInfo>::const_iterator go_iter;
    int i=0;
    for( go_iter=map_sendinfo.constBegin(); go_iter!=map_sendinfo.constEnd(); go_iter++,i++)
	{
		senderModel->setData(senderModel->index(i,0),go_iter.value().senderId);		
		senderModel->setData(senderModel->index(i,1),go_iter.value().senderPhone);	
		senderModel->setData(senderModel->index(i,2),go_iter.value().senderName);	
		//senderModel->item(i,5)->setForeground(QBrush(QColor(255, 0, 0)));  
	}
}


// 改变当前项目
void DistributeDlg::changeCurrent(const QModelIndex &current,const QModelIndex &previous)
{
	QString index=ui.tableView->model()->index(current.row(),0).data().toString();
	QMap<QString,SenderInfo>::const_iterator go_iter;
	go_iter=map_sendinfo.find(index);
	
	//ui.ddInfoEdit->clear();
	listModel->removeRows(0,listModel->rowCount());

	//获取订单配送员对应信息
	strcpy(os.senderName,go_iter.value().senderName);

	QStringList liststr;
	liststr <<tr("订单号：")+os.orderID <<tr("配送员：")+os.senderName;

	listModel->setStringList(liststr);
	ui.listView->setModel(listModel);
}

void DistributeDlg::on_pushButton_clicked()
{
	QString ipStr(usrAuth.serverip);
	QString tmpStr1("/OAapp/WebObjects/OAapp.woa?cjApply=orderSta&orderId=");
	QString tmpStr2(os.orderID);
	QString tmpStr3("&dispatch=");
	QString tmpStr4(os.senderName);
	QString tmpURL=ipStr+tmpStr1+tmpStr2+tmpStr3+tmpStr4;
	qDebug()<<"配送员"<<tmpURL;
	changestate->get(QNetworkRequest(QUrl(tmpURL)));

	MyShopping *father=getShop();
	father->setSendCombox();

	this->close();


}

MyShopping *DistributeDlg::getShop()
{
	return myshop; 
}

void  DistributeDlg::setShop(MyShopping* _myshop)
{
	myshop=_myshop;
}