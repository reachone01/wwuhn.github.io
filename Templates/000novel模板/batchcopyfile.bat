@echo off
@cd c:\user\wwu\desktop\
@cd c:
echo ���ڴ���file0.txt~file9.txt��10���ļ�...
echo.
echo.
for /l %%n in (2,1,21) do (  copy n.html %%n.html )
rem:in��Ӧ�пո�, (��Ҫ����
echo �ļ�������ϣ�