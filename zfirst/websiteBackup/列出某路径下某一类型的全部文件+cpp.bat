@echo off
setlocal enabledelayedexpansion
echo.>D:\websiteBackup\fileList.txt
color 3a
echo.
echo ϵͳ���ڲ����ļ��������ĵȺ�......
echo.

::for %%a in (C D E F) do (
for %%a in (F:\Website) do (
cd /d %%a\
	for /r %%b in (*.htm) do ( ::����*.html 
		if exist "%%b" (
			echo %%b
			echo %%b>>D:\websiteBackup\fileList.txt
		)
	)
	for /r %%b in (*.css *.js) do (
		if exist "%%b" (
			echo %%b
			echo %%b>>D:\websiteBackup\fileList.txt
		)
	)
	for /r %%b in (*.doc *.xls) do (
		if exist "%%b" (
			echo %%b
			echo %%b>>D:\websiteBackup\fileList.txt
		)
	)
	for /r %%b in (*.c) do (
		if exist "%%b" (
			echo %%b
			echo %%b>>D:\websiteBackup\fileList.txt
		)
	)
)

for /r F:\website\witiso\zfirst %%b in (*) do (
	if exist "%%b" (
		echo %%b
		echo %%b>>D:\websiteBackup\fileList.txt
	)
)
for /r F:\website\witisoPC\zfirst %%b in (*) do (
	if exist "%%b" (
		echo %%b
		echo %%b>>D:\websiteBackup\fileList.txt
	)
)
for /r F:\Website\zfirst %%b in (*) do (
	if exist "%%b" (
		echo %%b
		echo %%b>>D:\websiteBackup\fileList.txt
	)
)

type D:\websiteBackup\fileList.txt | find /i "\" && goto no
echo.
echo �ļ�����û�ҵ�!
del D:\websiteBackup\fileList.txt>nul 2>nul
echo.
pause
exit
:no
::cls
echo.
echo �ļ�������ϲ���¼��D:\websiteBackup\fileList.txt�� !
echo �ֲ鵽%b%�ļ��ܵĸ�����!n!
echo.
echo �Ƿ���ı��鿴��¼ ?
echo.
echo ѡ��" Y "�鿴�� ѡ��" N "�˳���
echo.
set /p Choice=Y/N: 
IF /I '%Choice:~0,1%'=='y' goto A
IF /I '%Choice:~0,1%'=='n' goto B
pause
exit
:A
start D:\websiteBackup\fileList.txt
exit
pause
:b
exit