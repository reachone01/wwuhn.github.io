@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo ���ļ��л��������һ��˵�����Ӳ˵�����...
echo [HKEY_CLASSES_ROOT\*\shell\runas] >>temp.reg
echo @="��ʾ�������ļ�" >>temp.reg
echo "NoWorkingDirectory"="" >>temp.reg
echo [HKEY_CLASSES_ROOT\*\shell\runas\command] >>temp.reg
echo @="cmd.exe /c F:\Website\notes\bat\��ʾ�������ļ�.bat %1" >>temp.reg

echo.
regedit /s temp.reg
del /q /f temp.reg >nul





