@echo off
cls
:menu

echo [1] ��ʱ�ػ�,����ʱ��,��������������ʱ���һ���ӹر�
echo [2] ȡ���ػ�
echo [3] ȡ���ƻ�����
echo [0] exit
echo.
set /p choice=  please choice and press enter:  
if "%choice%"=="1" goto 1
if "%choice%"=="2" goto 2
if "%choice%"=="3" goto 3
if "%choice%"=="0" goto 0
echo.

goto 0
:1
cls
echo.
set /p time= as "24:12" ,input time:
at %time% shutdown -s -t 30
goto menu

:2
cls
echo.
shutdown -a
goto menu


:3
cls
echo.
at /del
goto menu

:0
set time=
cls
echo.