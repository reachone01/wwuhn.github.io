@echo off
cls
rem taskkill /f /t /im ������ 
rem ntsd -c q -pn ������ 
rem ntsd -c q -p ���̵�PID 

taskkill /f /t /im regedit.exe


set /p cho1= �븴�ƻ�������Ҫ��λ��ע����֧��·��,Ȼ��س�:

cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe