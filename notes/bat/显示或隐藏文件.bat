@ECHO off
setlocal ENABLEDELAYEDEXPANSION
set uu="HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"
for /f "skip=2 tokens=3" %%i in ('reg query %uu% /v Hidden') do (if "%%i"=="0x0" (goto show) else (goto noshow))
:show
echo ��ʾ�����ļ�����չ��
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v Hidden /t reg_dword /d 1 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v HideFileExt /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSuperHidden /t reg_dword /d 1 /f
rem ��������ǲ���ʾ "�ļ���ѡ��"�˵�
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer" /v NoFolderOptions /t REG_DWORD /d 1 /f
taskkill /im Explorer.exe /f && start Explorer.exe >nul 2>nul
exit
:noshow
echo ����ʾ�����ļ�����չ��
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v Hidden /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSuperHidden /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v HideFileExt /t reg_dword /d 1 /f
rem ��������ǻָ� "�ļ���ѡ��"�˵�
reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer" /v NoFolderOptions /f
taskkill /im Explorer.exe /f && start Explorer.exe >nul 2>nul
exit