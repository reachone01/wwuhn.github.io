@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo ���ļ��л��������һ��˵�����Ӳ˵�����...
echo [+hkey_local_machine\software\classes\directory\shell\���������] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\���������\commamnd] >>temp.reg
echo [hkey_local_machine\software\classes\directory\shell\���������\command] >>temp.reg
echo @="c:\windows\rundll.exe user.exe,exit windows exec" >>temp.reg
echo �����������ļ����һ��˵�����Ӳ˵�����...
echo [+hkey_classes_root\*\shell] >>temp.reg
echo [+hkey_classes_root\*\shell\���±�] >>temp.reg
echo [+hkey_classes_root\*\shell\���±�\command] >>temp.reg
echo [hkey_classes_root\*\shell\���±�\command] >>temp.reg
echo @="notepad %1" >>temp.reg
echo.
regedit /s temp.reg
del /q /f temp.reg >nul