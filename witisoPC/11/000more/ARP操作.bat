@echo off
cls
echo.
:menu
echo    ***********************************************
echo.
echo      [1] ��ʾ����arp����
echo.
echo      [2] ɾ��arp����/��Ӿ�̬arp������(��������,��IP��ַ�����������ַ)
echo.
echo      [3] �ֶ����Լ���IP(��IP����̬����ʱ)
echo.
echo      [0] exit

echo    ***********************************************
echo.
set /p cho=   please input number,then press enter:  

if "%cho%"=="0" goto 0
if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3


goto 0
:1
echo.
cls
echo ______________________________________________________________________
echo.
ipconfig /all
echo ______________________________________________________________________
echo.
arp -a
echo ______________________________________________________________________
echo.
netsh interface ip show config
echo ______________________________________________________________________
echo.
pause
goto menu

:2
echo.
cls
@echo off
arp -d
set yourip=192.168.1.100
set yourmac=00-1f-16-68-ea-b7
set gateip=192.168.1.1
set gatemac=00-21-27-b2-eb-96
netsh -c "i i" add neighbors 10 "%yourip%" "%yourmac%"
netsh -c "i i" add neighbors 10 "%gateip%" "%gatemac%"
set yourip=
set yourmac=
set gateip=
set gatemac=
pause
goto menu

:3
echo.
cls
@echo off
arp -d
set /p yourip1=   please input yourip,then press enter: 
set yourmac=00-1f-16-68-ea-b7
set gateip=192.168.1.1
set gatemac=00-21-27-b2-eb-96
netsh -c "i i" add neighbors 10 "%yourip1%" "%yourmac%"
netsh -c "i i" add neighbors 10 "%gateip%" "%gatemac%"
set yourip1=
set yourmac=
set gateip=
set gatemac=
pause
goto menu


:0
set cho=
cls
