@echo off
echo.
:menu
cls
echo ѡ��˵���
echo.

echo   1  û�п��е��ı�����
echo   2  �п��е��ı�����
echo   0  exit �˳���������
echo.     __________________________________________________________________________
echo.    
set /p cho=  ����ѡ������֣�Ȼ��س�:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2


if "%cho%"=="0" goto 0

goto 0
:1
echo.
python F:\Website\Templates\000txt\new.py
goto menu

:2
echo.
python F:\Website\Templates\000txt\newnn.py
pause
goto menu

:0
set time=
set cho=
cls