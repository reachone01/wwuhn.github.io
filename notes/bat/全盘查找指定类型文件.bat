@echo off
setlocal enabledelayedexpansion
echo. >c:\virus.txt
color 3a
echo.
set /a n = 0
set /p b=��������ļ���չ��:
if /i "%b%"=="" cls && goto fh

echo ϵͳ���ڲ����ļ��������ĵȺ�......
echo.

::for %%a in (F E D C) do (
for %%a in (E) do (
cd /d %%a:\
	for /r %%b in (*.%b%) do (
		if exist "%%b" (
			echo %%b
			echo %%b>>c:\virus.txt
			set /a n+=1
			echo �ֲ鵽%b%�ļ�������!n!
		)
	)
)
type c:\virus.txt | find /i "\"  && goto no
echo.
echo �ļ�����û�ҵ�!
del c:\virus.txt>nul 2>nul
echo.
pause
exit

:no
::cls
echo.
echo �ļ�������ϲ���¼��c:\virus.txt�� !
echo �ֲ鵽%b%�ļ��ܵĸ�����!n!
echo.
echo �Ƿ���ı��鿴��¼ ?
echo.
echo ѡ��" Y "�鿴��   ѡ��" N "�˳���
echo.
set /p Choice=Y/N: 
IF /I '%Choice:~0,1%'=='y' goto A
IF /I '%Choice:~0,1%'=='n' goto B
pause
exit

:A
start c:\virus.txt
exit
pause
:b
exit

 
