@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo ���ļ��л��������һ��˵�����Ӳ˵�����...
echo [-hkey_local_machine\software\classes\directory\shell\��ʾ�������ļ�] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\��ʾ�������ļ�] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\��ʾ�������ļ�\commamnd] >>temp.reg
echo [hkey_local_machine\software\classes\directory\shell\��ʾ�������ļ�\commamnd] >>temp.reg
echo @="cmd.exe /c F:\\Website\\notes\\bat\\��ʾ�������ļ�.bat %1" >>temp.reg


echo.
regedit /s temp.reg
::del /q /f temp.reg >nul