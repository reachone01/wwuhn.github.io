@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo �����������ļ��п�ݲ˵�...
echo [hkey_classes_root\directory\shell\cmd] >>temp.reg
echo @="��&cmd���ڴ��ļ���" >>temp.reg
echo [hkey_classes_root\directory\shell\cmd\command] >>temp.reg
echo @="cmd /k cd "%~dp1"" >>temp.reg
echo �ɹ���������д��ڴ��ļ������
echo.
regedit /s temp.reg
del /q /f temp.reg >nul