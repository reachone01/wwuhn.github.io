@echo off
echo Windows Registry Editor Version 5.00 >temp.reg

echo �����������ļ����һ��˵�����Ӳ˵�����...
echo [-hkey_classes_root\*\shell\��ʾ�������ļ�] >>temp.reg
echo [+hkey_classes_root\*\shell\��ʾ�������ļ�] >>temp.reg
echo [+hkey_classes_root\*\shell\��ʾ�������ļ�\command] >>temp.reg
echo [hkey_classes_root\*\shell\��ʾ�������ļ�\command] >>temp.reg
echo @="cmd.exe /c F:\\Website\\notes\\bat\\��ʾ�������ļ�.bat %1" >>temp.reg
echo.
regedit /s temp.reg
del /q /f temp.reg >nul