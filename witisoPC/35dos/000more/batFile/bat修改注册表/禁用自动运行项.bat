@echo off
echo windows registry editor version 5.00 >temp.reg
echo ���ڽ���ע�������Ӧ���Զ���������Ժ�...
echo [hkey_current_user\software\microsoft\windows\currentversion\policies\explorer] >>temp.reg
echo "disableLocalMachinRun"=dword:00000001 >>temp.reg
echo "disableLocalMachinRunonce"=dword:00000001 >>temp.reg
echo "disableCurrentUserRun"=dword:00000001 >>temp.reg
echo "disableCurrentUserRunonce"=dword:00000001 >>temp.reg
echo �ɹ���Ҫ�������ע�������Ӧ��������
echo.
regedit /s temp.reg
del /q /f temp.reg >nul
