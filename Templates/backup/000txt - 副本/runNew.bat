@echo off
echo.
:menu
cls
echo ѡ��˵���
echo.

echo   1  û�п��е������ı�����cn(�ϲ����ַ�),����������
echo   2  �п��е������ı�����cn(�ϲ����ַ�),���������䣬���ǿ��еĶ���ϲ���
echo   3  û�п��е�Ӣ���ı�����en(���ϲ����ַ�),����������
echo   4  �п��е�Ӣ���ı�����en(���ϲ����ַ�),���������䣬���ǿ��еĶ���ϲ���
echo   0  exit �˳���������
echo.     __________________________________________________________________________
echo.    
set /p cho=  ����ѡ������֣�Ȼ��س�:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4

if "%cho%"=="0" goto 0

goto 0
:1
echo.
python F:\Website\Templates\000txt\new.py
pause
goto menu

:2
echo.
python F:\Website\Templates\000txt\newnn.py
pause
goto menu

:3
echo.
python F:\Website\Templates\000txt\newen.py
pause
goto menu

:4
echo.
python F:\Website\Templates\000txt\newnnen.py
pause
goto menu

:0
set time=
set cho=
cls