@echo off
:repeate
cls
echo.
echo.
echo ------��ѡ��Ҫִ�еĲ���---
echo ---1 ��������1�����س�������ʾ��ǰ����---
echo ---2 ��������2�����س�������ʾ��ǰʱ��---
echo ---3 ��������3�����س�������ʾ�ļ��б�---
echo ---4 ��������4�����س�������ֹ������---
echo.
echo.
echo ��ѡ��Ҫִ�еĲ�����
set /p num=
if "%num%"=="1" (
cls
echo.
echo.
echo ��ǰ����Ϊ��
date /t
pause
goto repeate
)
if "%num%"=="2" (
cls
echo.
echo.
echo ��ǰʱ��Ϊ��
time /t
pause
goto repeate
)
if "%num%"=="3" (
cls
echo.
echo.
echo ��ǰĿ¼�µ�����Ϊ��
dir /w
pause
goto repeate
)
echo.
echo.
echo ��������%num%�ַ����������Զ��˳���
