@echo off
mode con lines=25
title time shutdown
color if
cls

echo.
echo.
echo.
echo.
echo    ʹ��ʱ��ʹ��24Сʱ�ƣ�����������ʱ��㣬
echo        ���ʱ����ÿո�ֿ�
echo.
echo.
echo------------------------------------------------
echo.
set times=
set /p times=             ������ػ�ʱ�䣺
if not "%times%"=="" for %%i in (%times%) do ( at %%i /every:M,t,w,th,f,s,su shutdown -s)
