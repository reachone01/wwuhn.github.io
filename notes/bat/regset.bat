@echo off
cls
rem taskkill /f /t /im ������ 
rem ntsd -c q -pn ������ 
rem ntsd -c q -p ���̵�PID 

tasklist >list.txt      
find /i "regedit.exe" list.txt      
if "%errorlevel%"=="1" (goto f) else (goto e)                                                                                                             


:e                    
taskkill /f /t /im regedit.exe    
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run >list.txt
clip < list.txt
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run�Ѹ��Ƶ����а�
del /q list.txt
echo.
set /p cho1= �븴�ƻ�������Ҫ��λ��ע����֧��·��,Ȼ��س�:
pause
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe

:f
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run >list.txt
clip < list.txt
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run�Ѹ��Ƶ����а�
del /q list.txt
echo.
set /p cho1= �븴�ƻ�������Ҫ��λ��ע����֧��·��,Ȼ��س�:
pause
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe