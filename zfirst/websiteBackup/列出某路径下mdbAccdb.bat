@echo off
setlocal enabledelayedexpansion
echo.>D:\websiteBackup\fileList.txt
color 3a
echo.
echo 系统正在查找文件，请耐心等候......
echo.

::for %%a in (C D E F) do (
for %%a in (F:\Website) do (
cd /d %%a\
	for /r %%b in (*.mdb *.accdb) do ( ::包括*.html 
		if exist "%%b" (
			echo %%b
			echo %%b>>D:\websiteBackup\fileList.txt
		)
	)

)
type D:\websiteBackup\fileList.txt | find /i "\" && goto no
echo.
echo 文件内容没找到!
del D:\websiteBackup\fileList.txt>nul 2>nul
echo.
pause
exit
:no
::cls
echo.
echo 文件查找完毕并记录在D:\websiteBackup\fileList.txt中 !
echo 现查到%b%文件总的个数：!n!
echo.
echo 是否打开文本查看记录 ?
echo.
echo 选择" Y "查看。 选择" N "退出。
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