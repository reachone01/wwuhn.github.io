@echo off
echo.
title ip setingup
set ip=
set mask=
set gate=
set dns1=
set ip2=
set mask2=
set gate2=
set dns2=
set dns11=
set wins1=
set ip3=
set mask3=
set gateway3=
set dns3=
cls

:menu
echo.

echo    IP��ַ����
echo   ___________________________________
echo.
echo      1 ����IP��ַΪ:�칫����
echo.
echo      2 ����IP��ַΪ:С���ڲ�����
echo.
echo      3 ����IP��ַΪ:DHCP�Զ���ȡ
echo.
echo      4 �ֶ�����IP��ַ
echo.
echo      5 ��"��������"���ô���
echo.
echo      6 �鿴 IP and DNS
echo.
echo   _____________________________________
echo.
set /p input= please choice,then press enter: 

if "%input%"=="1" goto 1
if "%input%"=="2" goto 2
if "%input%"=="3" goto 3
if "%input%"=="4" goto 4
if "%input%"=="5" goto 5
if "%input%"=="6" goto 6
echo.
goto end

:1
cls
set ip=192.168.1.18
set mask=255.255.255.0
set gate=192.168.1.8
set dns1=202.100.100.128
set dns11=202.100.100.128
set wins1=02.100.100.122
netsh interface ip set address �������� static "%ip%" "%mask%" "%gate%" >nul
netsh interface ip set dns �������� static "%dns1%" >nul
netsh interface ip add dnsservers �������� static "%dns11%" >nul
netsh interface ip set winsservers �������� static "%wins1%" >nul
echo.
echo ���õİ칫�����ַ:
echo    IP adress:   %ip%
echo    subnet mask: %mask%
echo    gatewary:    %gate%
echo    first dns:   %dns1%
set ip=
set mask=
set gate=
set dns1=
set dns11=
set wins1=
echo.
echo.
pause
goto menu

:2
cls
set ip2=192.168.0.25
set mask2=255.255.255.0
set gate2=192.168.0.5
set dns2=202.100.100.235
netsh interface ip set address �������� static "%ip2%" "%mask2%" "%gate2%" >nul
netsh interface ip set dns �������� static "%dns2%" >nul
echo.
echo ���õ�С�������ַ:
echo    IP adress:   %ip2%
echo    subnet mask: %mask2%
echo    gatewary:    %gate2%
echo    first dns:   %dns2%
set ip2=
set mask2=
set gate2=
set dns2=
echo.
echo.
pause
goto menu

:3
cls
netsh interface ip set address �������� source=dhcp >nul
netsh interface ip set dns �������� source=dhcp >nul
echo.
echo IP����Ϊ�Զ���ȡ��ص�ַ;
echo.
pause
goto menu

:4
cls
set /p ip3= please input ip:  
set mask3=255.255.255.0
set /p gateway3= please input gateway:  
set /p dns3= please input dns 1: 
netsh interface ip set address �������� static "%ip3%" "%mask3%" "%gateway3%" >nul
netsh interface ip set dns �������� static "%dns3%" >nul
echo.
echo ���õİ칫�����ַ:
echo    IP adress:   %ip3%
echo    subnet mask: %mask3%
echo    gatewary:    %gateway3%
echo    first dns:   %dns3%
set ip3=
set mask3=
set gateway3=
set dns3=
echo.
echo.
pause
goto menu

:5
cls
echo.
ncpa.cpl -tcp/ipv4
goto menu
echo.

:6
cls
ipconfig /all
echo.
echo ______________________________________________________________________
echo.
netsh interface ip show config
pause
cls
goto menu

:225
cls
netsh interface ip set address name=�������� source=static addr=192.158.3.3 mask= 255.255.255.0 gateway=192.158.3.3 gatewaymetric=1 >nul
goto menu
:end
cls
rem:"��������"����������������,Ĭ�ϵ�����,����"�������"-"����͹�������"-��������������--�ɲ鿴