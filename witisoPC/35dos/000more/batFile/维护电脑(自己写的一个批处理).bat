@echo off
echo.
:menu
cls
echo.    _______________________________________________________________
echo.
echo       [00] exit �˳���������
echo.    
echo       [  ] regedit /s fname.reg ����ע���
echo       [  ] scanreg /restore �ָ�ע���
echo       [  ] regsvr32 /u fname.dll �ֶ�ע��DLL�ļ�
echo       [  ] ��ϵͳ��װ�̽���ϵͳ�ָ�����̨
echo       [  ] ctrl+c �ɽ����������
echo.
echo       [01] msinfo32 ϵͳ��Ϣ(windows������ʾ)
echo       [02] systeminfo ϵͳ��Ϣ(��������ʾ)
echo       [03] net start �����ķ���\���еĽ���(����������ʾ)
echo       [04] services.msc �����ķ���(��windows������ʾ)
echo       [05] ipconfig �鿴��������
echo.
echo       [06] net config ��ʾϵͳ��������
echo       [07] set ��ʾ��ǰ���л�������    
echo       [08] rstrui ϵͳ��ԭ
echo       [09] �����Ż���ʦ������Ƭ����
echo       [10] chkdsk ���̼��
echo.
echo       [11] sfc ϵͳ�ļ����   
echo       [12] display driver setup �Կ�������װ
echo       [13] powerword �򿪽�ɽ�ʰ�
echo       [14] shutdown һ���Ӻ�ػ�
echo       [15] shutdown ��ʱ�ػ�,����ʱ��,��������������ʱ���һ���ӹػ�
echo.
echo       [16] shutdown -a ȡ���ػ�
echo       [17] at 1 delȡ���ƻ�����
echo       [18] event�鿴eventvwr
echo       [19] ���ܼ�����perfmon.msc
echo       [20] ������ѯdriverquery
echo.
echo       [21] msconfig �鿴�Զ����ó���serivces(can hide all windows serivces);
echo       [22] services.msc ���÷���������ʽ;
echo       [23] taskmgr �鿴CPU���ڴ�ռ�á�ÿһ���̵�CPUռ�ã�
echo       [24] ��internet��ʱ�ļ���
echo       [25] ��ϵͳ��ʱ�ļ���
echo.    _______________________________________________________________
echo.
set /p cho=  please input number,then enter:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="6" goto 6
if "%cho%"=="7" goto 7
if "%cho%"=="8" goto 8
if "%cho%"=="9" goto 9
if "%cho%"=="10" goto 10
if "%cho%"=="11" goto 11
if "%cho%"=="12" goto 12
if "%cho%"=="13" goto 13
if "%cho%"=="14" goto 14
if "%cho%"=="15" goto 15
if "%cho%"=="16" goto 16
if "%cho%"=="17" goto 17
if "%cho%"=="18" goto 18
if "%cho%"=="19" goto 19
if "%cho%"=="20" goto 20

if "%cho%"=="21" goto 21
if "%cho%"=="22" goto 22
if "%cho%"=="23" goto 23
if "%cho%"=="24" goto 24
if "%cho%"=="25" goto 25

if "%cho%"=="0" goto 0

goto 0
:1
echo.
cls
msinfo32
goto menu

:2
echo.
cls
systeminfo
pause
goto menu

:3
echo.
cls
net start
echo ------------------------------------------------------------------------
tasklist
echo ------------------------------------------------------------------------
tasklist /svc
pause
goto menu

:4
echo.
cls
services.msc
goto menu

:5
echo.
cls
ipconfig /all
pause
goto menu

:6
echo.
cls
net config
pause
goto menu

:7
echo.
cls
set
pause
goto menu

:8
echo.
cls
rstrui
goto menu


:9
echo.
cls
F:\�Ż���ʦ\WoptiUtilities_CN.exe
goto menu

:10
echo.
cls
echo.
echo ���ڲ��c��..............................................................................
echo.
chkdsk /f c:
echo.
echo ���ڲ��d��....................................................................................
echo.
chkdsk /f d:
echo.
echo ���ڲ��e��....................................................................................
echo.
chkdsk /f e:
echo.
echo ���ڲ��f��....................................................................................
echo.
chkdsk /f g:
echo.
echo ���ڲ��g��....................................................................................
echo.
chkdsk /f f:
echo.
echo ���ڲ��h��....................................................................................
echo.
chkdsk /f h:
echo.
echo ���ڲ��i��....................................................................................
echo.
chkdsk /f i:
echo.
echo ���ڲ��j��....................................................................................
echo.
chkdsk /f j:
pause
goto menu


:11
echo.
cls
sfc /scannow
goto menu

:12
echo.
cls
echo 1 �س�;
echo 2 upper,then�س�;
echo 3 �س�;
echo 4 e;yes to all
echo 5 �س�
e:
cd\
cd software
cd drivers
sp36729
goto menu

:13
echo.
cls
f:
cd\
cd win7\Powerword 2003
XDICT.EXE
goto menu


:14
cls
echo.
shutdown -s -t 5
goto menu

:15
cls
echo.
set /p time= as "24:12" ,input time:
at %time% shutdown -s -t 30
goto menu

:16
cls
echo.
shutdown -a
goto menu


:17
cls
echo.
at /del
goto menu


:18
cls
echo.
eventvwr
goto menu


:19
cls
echo.
%windir%\system32\perfmon.msc
goto menu

:20
cls
echo.
driverquery
pause
goto menu

:21
cls
echo.
msconfig
goto menu

:22
cls
echo.
services.msc
goto menu

:23
cls
echo.
taskmgr
goto menu

:24
cls
echo.
explorer %userprofile%\AppData\Local\Microsoft\Windows\Temporary Internet Files
goto menu

:25
cls
echo.
explorer %temp%
goto menu

:0
set time=
set cho=
cls
