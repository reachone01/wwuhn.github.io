@echo off
cls
echo.
:menu
echo    ***********************************************
echo.
echo      [1] net share �鿴����������Դ�б�
echo      [2] ÿһ�γ���ɾ������
echo      [3] ÿ���γ���ɾ������
echo      [4] �ֶ�ɾ������
echo      [5] ��������
echo      [z] exit
echo    ***********************************************
echo.
set /p cho=  please input number,then enter:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="z" goto z

goto z
:1
echo.
cls
net share
goto menu

:2
echo.
cls
FOR /F "usebackq delims=c" %%i IN (`net share`) DO net share %%i /del
goto menu

:3
echo.
cls
FOR /F "usebackq delims=" %%i IN (`net share`) DO net share "%%i" /del
goto menu

:4
echo.
cls
set /p n= �����빲����: 
net share "%n%" /del
goto menu

:5
echo.
cls
net share "wwu top"=c:\users\wwu\desktop
net share wwu=c:\users\wwu
goto menu

:z
set n=
set cho=
cls

