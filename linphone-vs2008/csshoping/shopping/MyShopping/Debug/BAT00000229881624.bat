@echo off
"d:\Qt\4.7.0\bin\moc.exe"   -DUNICODE -DWIN32 -DQT_LARGEFILE_SUPPORT -DQT_CORE_LIB -DQT_GUI_LIB -DIN_LINPHONE -DQT_XML_LIB -D_AFXDLL -D_WINDOWS  "-I.\GeneratedFiles" "-Id:\Qt\4.7.0\include" "-I.\GeneratedFiles\Debug\." "-Id:\Qt\4.7.0\include\qtmain" "-Id:\Qt\4.7.0\include\QtCore" "-Id:\Qt\4.7.0\include\QtGui" "-Id:\Qt\4.7.0\include\QtXml" "-I." "-I.\..\..\oRTP\include" "-I.\..\..\linphone\coreapi" "-I.\..\..\mediastreamer2\include" "-Id:\Qt\4.7.0\include\QtNetwork" ".\shopsubmit.h" -o ".\GeneratedFiles\Debug\moc_shopsubmit.cpp"

if errorlevel 1 goto VCReportError
goto VCEnd
:VCReportError
echo Project : error PRJ0019: 某个工具从以下位置返回了错误代码: "Moc'ing shopsubmit.h..."
exit 1
:VCEnd