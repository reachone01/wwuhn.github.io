@echo off
cls
echo.
echo.
echo -----------------��ѡ��Ҫִ�еĲ���------------------------
echo ----1 ��������1�����س���,����Telnet����----
echo ----2 ��������1�����س���,ֹͣTelnet����----
echo ----3 ��������1�����س���,��ͣTelnet����----
echo ----4 ��������1�����س���,�ָ�Telnet����----
echo ----5 ���������ַ�,ֱ���˳�������----
echo.
echo.
set /p num=��ѡ��Ҫִ�еĲ���:
if "%num%"=="1"(
echo.
echo.
net start telephony
echo �ɹ�����Telnet����......
goto exit
)

if "%num%"=="2"(
echo.
echo.
net stop task schedule
echo �ɹ�ֹͣTelnet����......
goto exit
)

if "%num%"=="3"(
echo.
echo.
task schedule  pause
echo �ɹ���ͣTelnet����......
goto exit
)

if "%num%"=="4"(
echo.
echo.
task schedule  continue
echo �ɹ��ָ�����ͣTelnet����......
goto exit
)
echo.
echo.
echo ��������%num%�ַ�,�������Զ��˳�......
:exit
