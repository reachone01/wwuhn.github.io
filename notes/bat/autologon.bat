@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo ���������Զ���¼��ǰϵͳ���ʻ�...
echo [hkey_local_machin\software\microsoft\windows nt\currentversion\winlogon] >>temp.reg
echo "autoadminlogon"="1" >>temp.reg
echo "defaultusername"="normalaccount" >>temp.reg
echo "defaultpassword"="noprivilege" >>temp.reg
echo.
echo �ɹ���"normalaccount"�ʻ�����Ϊ��ǰ�Զ���¼���ʻ���
pause
regedit /s temp.reg
del /q /f temp.reg >nul