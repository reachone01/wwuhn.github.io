@echo off
echo windows registry editor version 5.00 >temp.reg
echo ���ڽ���windows����ʷ��¼����...
echo [hkey_local_machinge\software\microsoft\windows nt\currentversion\policies\explorer] >>temp.reg
echo "noRecentDocsNetHood"=dword:00000001
echo "noRecentDocsHistory"=dword:00000001
echo "noInstrumentation"=dword:00000001
echo "noStartMenuMfuprogramsList"=dword:00000001
echo.
echo �ɹ�����windows����ʷ��¼���ܣ�
regedit /s temp.reg
del /f /f temp.reg >nul
