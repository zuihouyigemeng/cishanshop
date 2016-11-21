#include "linphonecore.h"
#include "private.h"

#include "common.h"
#include <string>

extern SipInfo  usrAuth; //用户信息
extern LinphoneCore *the_core;


//
bool WriteUserConfig()
{

   //程序启动的时候，检测配置文件是否存在，存在则读，不存在则写空文件
   //但这里有个问题要谨记，查出原因，为什么在dialoginit里面使用下面的代码就不行呢，，，******

   //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省   
   QSettings *configIniWrite = new QSettings("userinfo.ini", QSettings::IniFormat);  
   //向ini文件中写入内容,setValue函数的两个参数是键值对   
   //向ini文件的第一个节写入内容,ip节下的第一个参数   
   configIniWrite->setValue("/sipuser/usr", "192.168.0.1");  
   //向ini文件的第一个节写入内容,ip节下的第二个参数   
   configIniWrite->setValue("sipuser/pwd", "127.0.0.1");  
   //向ini文件的第二个节写入内容,port节下的第一个参数   
   configIniWrite->setValue("sipuser/sipIP", "2222");  

   configIniWrite->setValue("sipuser/serverIP", "2222");  
   //写入完成后删除指针   
   delete configIniWrite;  
   return true;
}

bool ReadUserConfig()
{

   QSettings *configIniRead = new QSettings("userinfo.ini", QSettings::IniFormat);  
   //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型   
   QString usrStr = configIniRead->value("/sipuser/usr").toString();  
   strcpy(usrAuth.usrname,usrStr.toStdString().c_str());
  
   QString pwdStr = configIniRead->value("/sipuser/pwd").toString(); 
   strcpy(usrAuth.password,pwdStr.toStdString().c_str());
   
   QString sipIPStr = configIniRead->value("/sipuser/sipIP").toString(); 
   strcpy(usrAuth.sipip,sipIPStr.toStdString().c_str());

   QString serverIPStr = configIniRead->value("/sipuser/serverIP").toString(); 
   strcpy(usrAuth.serverip,serverIPStr.toStdString().c_str());

   //打印得到的结果   
   qDebug()<<"sipIPStr" << usrAuth.usrname;  
   qDebug() <<"serverIPStr"<< serverIPStr;  
   //读入入完成后删除指针   
   delete configIniRead;  

   return true;
}

bool RegisterSip()
{
	char identity[128];
	ReadUserConfig();
	
	//先退出当前注册
	linphone_core_clear_proxy_config(the_core);
	
	//获取注册信息
	//QString username,password,server,szidentity;

	//username.Format(_T("%s"),usrAuth.usrname);
	//password.Format(_T("%s"),usrAuth.password);
	//server.Format(_T("%s"),usrAuth.sipip);
	//if (username.IsEmpty() || password.IsEmpty() || server.IsEmpty())
	//{
	//	return -1;
	//}
	if((strlen(usrAuth.usrname)==0)||(strlen(usrAuth.password)==0)||(strlen(usrAuth.sipip)==0))
		return false;

	//构建注册格式
	//strcpy(szidentity,"sip:%s@%s");
	//strcat(szidentity,usrAuth.usrname);
	//strcat(szidentity,usrAuth.);
	sprintf(identity,"sip:%s@%s",usrAuth.usrname,usrAuth.sipip);

	//szidentity.Format(_T("sip:%s@%s"),username.GetString(),server.GetString());
	//AfxMessageBox(szidentity);

    //这里宽字符转char型，麻烦死了，
    //USES_CONVERSION;
	//const char *identity = (LPSTR)(LPCTSTR)szidentity;
	//const char *secret = (LPSTR)(LPCTSTR)password;
	//const char *host = (LPSTR)(LPCTSTR)server;



	//检查是否已经注册，如果没有注册则注册
	LinphoneProxyConfig* proxyCfg=NULL;	

	//LinphoneProxyConfig* proxyCfg=new LinphoneProxyConfig;	
	linphone_core_get_default_proxy(the_core,&proxyCfg);
	if (proxyCfg!=NULL)
	{
		if (linphone_proxy_config_is_registered(proxyCfg))
		{
			return false;
		}else
		{
			linphone_core_clear_proxy_config(the_core);
		}
		
	}
	//应该是写配置信息
	proxyCfg = linphone_proxy_config_new();

	// add username password
	LinphoneAddress *from = linphone_address_new(identity);
	LinphoneAuthInfo *info;
	if (from !=0){
		info=linphone_auth_info_new(linphone_address_get_username(from),NULL,usrAuth.password,NULL,NULL);
		linphone_core_add_auth_info(the_core,info);
	}
	linphone_address_destroy(from);

	// configure proxy entries
	linphone_proxy_config_set_identity(proxyCfg,identity);
	linphone_proxy_config_set_server_addr(proxyCfg,usrAuth.sipip);
	linphone_proxy_config_enable_register(proxyCfg,true);
	linphone_proxy_config_set_dial_escape_plus(proxyCfg,TRUE);
	linphone_core_add_proxy_config(the_core,proxyCfg);

	//set to default proxy
	linphone_core_set_default_proxy(the_core,proxyCfg);
	return true;
}


//将单字节char*转化为宽字节wchar_t*  
wchar_t* AnsiToUnicode( const char* szStr )  
{  
    int nLen = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0 );  
    if (nLen == 0)  
    {  
        return NULL;  
    }  
    wchar_t* pResult = new wchar_t[nLen];  
    MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen );  
    return pResult;  
}  

//将宽字节wchar_t*转化为单字节char*  
char* UnicodeToAnsi( const wchar_t* szStr )  
{  
    int nLen = WideCharToMultiByte( CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL );  
    if (nLen == 0)  
    {  
        return NULL;  
    }  
    char* pResult = new char[nLen];  
    WideCharToMultiByte( CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL );  
    return pResult;  
}  



std::string ws2s(const std::wstring& ws)
{
    std::string curLocale = setlocale(LC_ALL, NULL);        // curLocale = "C";
    setlocale(LC_ALL, "chs");
    const wchar_t* _Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest,0,_Dsize);
    wcstombs(_Dest,_Source,_Dsize);
    std::string result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, curLocale.c_str());
    return result;
}

  std::string WStringToString(const std::wstring &wstr)
  {
      std::string str(wstr.length(), ' ');
      std::copy(wstr.begin(), wstr.end(), str.begin());
      return str; 
  }

/*
std::wstring s2ws(const std::string& s)
{
    setlocale(LC_ALL, "chs"); 
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest,_Source,_Dsize);
    std::wstring result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, "C");
    return result;
}
*/

std::string EncodeUtf8(std::wstring in)  
{  
    std::string s(in.length() * 3, ' ');  
    size_t len = ::WideCharToMultiByte(CP_UTF8, 0,  
                  in.c_str(), in.length(),  
                  &s[0], s.length(),  
                  NULL, NULL);  
    s.resize(len);  
    return s;  
}  

wchar_t* MulityByteToWideChar(int CodePage, char *str)
{
 DWORD dwNum = MultiByteToWideChar(CodePage, 0, str, -1, 0, 0);
 wchar_t *pwText = new wchar_t[dwNum];
 MultiByteToWideChar(CodePage, 0, str, -1, pwText, dwNum); 
 return pwText;
}


char* WideCharToMulityByte(int CodePage, wchar_t *str)
{
 int len = WideCharToMultiByte(CodePage, 0, str, -1, 0, 0, 0, 0); 
 char* output = new char[len + 2];
 WideCharToMultiByte(CodePage, 0, str, -1, output, len + 1, 0, 0); 
 return output;
}


/****
*para src fileinfo include path and filename,input
*para filename oubput
*para dirname output
*****/
bool GetFileInfo(char *src,char *filename,char *dirname)
{
    int total_len=0;
    int sub_len=0;
    char *p=NULL;
    total_len=strlen(src);
    p=strrchr(src,'/')+1;
    strcpy(filename,p);
    printf("file name is :%s\n",filename);
    sub_len=strlen(p);
    src[total_len-sub_len]='\0';
    strcpy(dirname,src);
    return true;
}
