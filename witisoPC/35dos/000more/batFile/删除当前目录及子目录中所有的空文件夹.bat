@echo off
echo.
echo ����ɾ����ǰĿ¼����Ŀ¼�����еĿ��ļ��У����Ժ�...
echo ----
cd. >listnull.txt
for /f "delims=" %%i in ('dir /ad /b /s') do (
	dir /b "%%i" | findstr .>nul || echo %%i >>listnull.txt
)
set /a sum=0
for /f %%i in (listnull.txt) do (
	echo �ɹ�ɾ����Ŀ¼��%%i
	rd /q %%i
	set /a sum=sum+1
)
echo ------
echo ��ɾ��%cd%Ŀ¼������Ŀ¼��%sum%�����ļ��У�
echo.
set sum=
del /q listnull.txt >nul