@echo off
@cd c:\user\wwu\desktop\
@cd c:
echo ���ڴ���file0.txt~file9.txt��10���ļ�...
echo.
echo.
for /f "eol=; tokens=* delims=, " %%i in (contents.txt) do copy module.html %%i.html
rem:in��Ӧ�пո�, (��Ҫ����
echo �ļ�������ϣ�