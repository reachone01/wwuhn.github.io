@echo off
cls
mode con: lines=420
:menu
echo 1 �򿪷�������������������������
echo 2 ͣ�����·���net stop��
echo		2.1 Offline Files(���OF���ѻ��ļ�����) �������ϵĹ��������ڱ��ػ��棬
echo			ʹ�û��������ѻ�״̬�·��ʹ����ļ�;
echo		2.2 HomeGroup Listener ά����ͥ��pc֮��Ĺ������ã���Ϊ֮�ṩ���շ���
echo		2.3 HomeGroup Provider ִ�����ͥ������ú�ά����ص�����
echo		2.4 Computer Browser������������ϵ�����pc�����Զ����¾������е�pc�б�
echo		2.5 workstation ʹ��SMBЭ�鴴����ά���ͻ���������Զ�̷�����֮�������
echo		2.6 Power ��Դ�������,�����ĵ�����̨ʽ�����߲�û�����õ�Դ�������
echo		2.7 Tablet PC Input Service �ṩ��д��֧�ֺͱʴ���Ӧ����;
echo			������ò�����д���ֲ���ƽ����ԣ���ô���Խ��÷���
echo		2.8 BITS,Background Intelligent Transfer Service
echo			ʹ�ÿ��е���������ں�̨����ͻ��˺ͷ�����֮������ݣ�
echo			��Ҫ���Ƕ�ϵͳ��WindowsUpdate�����ṩ֧�֡�
echo		2.9 WMPNetworkSvc �ṩ��Windows Media Playerý������繲����
echo		2.10 Diagnostic Policy Service(��ϲ��Է��񣬼��DPS)����
echo		2.11 TrkWks Distributed Link Tracking Client�ͻ��˷ֲ�ʽ���Ӹ��ٷ���
echo		2.12 WerSvc��Windows Error Reporting Service
echo		2.13 ShellHWDetection��Shell Hardware Detection��Ӳ��������	
echo			Ϊ�Զ����ŵ��豸��Ӳ���ṩ֪ͨ����
echo		2.14 WSearch����������
echo		2.15 Windows Update
echo		2.16 DNS Client DNS��������,��ĵ��Բ���DNS�������Ļ�����ͣ��
echo		2.17 Print Spooler ���ļ����ص��ڴ����Թ��Ժ��ӡ;
echo		2.18 Portable Device Enumerator Service 
echo			�ܹ�ʹ�ÿ��ƶ��������洢�豸�����ͬ�����ݡ�
echo    	2.19 StiSvc��windows Image Acquisition(Windowsͼ��ɼ�����)
echo			Ϊɨ���Ǻ�������ṩͼ��ɼ�����ġ�(һ��û������)
echo		2.20 server ��������ͨ�����繲���ļ���
echo 3 �������ȫ����Ϊ����
echo 4 �������ȫ����Ϊ�ֶ�
echo 5 �������ȫ����Ϊ�Զ�
echo 6 ��������ķ���net start��
echo 7 �鿴���ŵĶ˿�
echo 0 exit
set /p cho=   ������ѡ�������[1,2,3,4,5,0]��Ȼ��س�������ִ����Ӧ����:  
if "%cho%"=="0" goto 0
if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="6" goto 6
if "%cho%"=="7" goto 7
goto 0

:1
echo.
cls
@echo off
services.msc
pause
cls
goto menu

:2
echo.
cls
echo ______________________________________________________________________
echo.
:: ���·�����������ϵ������˳��ͬʱִ��Ч����������
net stop "Offline Files"
net stop "HomeGroup Listener"
net stop "HomeGroup Provider"
net stop "Computer Browser"
net stop Workstation
net stop Power
net stop "Tablet PC Input Service"
net stop BITS
net stop WMPNetworkSvc
net stop DPS
net stop TrkWks
net stop WerSvc
net stop ShellHWDetection
net stop WSearch
net stop "Windows Update"
net stop "DNS Client"
net stop "Print Spooler"
net stop "Portable Device Enumerator Service"
net stop StiSvc
net stop Server
echo ______________________________________________________________________
echo.
pause
cls
goto menu

:3
echo.
cls
@echo off
::�����������ʹ�÷�����(��������������=ǰ��û�ո񣬺�����Ҫ�ո�
sc config CscService start= disabled
sc config HomeGroupListener start= disabled
sc config HomeGroupProvider start= disabled
sc config Browser start= disabled
sc config LanmanWorkstation start= disabled
sc config Power start= disabled
sc config TabletInputService start= disabled
sc config BITS start= disabled
sc config WMPNetworkSvc start= disabled
sc config DPS start= disabled
sc config TrkWks start= disabled
sc config WerSvc start= disabled
sc config ShellHWDetection start= disabled
sc config WSearch start= disabled
sc config wuauserv start= disabled
sc config Dnscache start= disabled
sc config Spooler start= demand
sc config WPDBusEnum start= disabled
sc config StiSvc start= disabled
sc config LanmanServer start= disabled
:: ���Ҫ����Ϊ�Զ��������Ϊ��auto
pause
cls
goto menu

:4
echo.
cls
@echo off
sc config CscService start= demand
sc config HomeGroupListener start= demand
sc config HomeGroupProvider start= demand
sc config Browser start= demand
sc config LanmanWorkstation start= demand
sc config Power start= demand
sc config TabletInputService start= demand
sc config BITS start= demand
sc config WMPNetworkSvc start= demand
sc config DPS start= demand
sc config TrkWks start= demand
sc config WerSvc start= demand
sc config ShellHWDetection start= demand
sc config WSearch start= demand
sc config wuauserv start= demand
sc config Dnscache start= demand
sc config Spooler start= demand
sc config WPDBusEnum start= demand
sc config StiSvc start= demand
sc config LanmanServer start= demand
pause
goto menu



:5
echo.
cls
@echo off
sc config CscService start= auto
sc config HomeGroupListener start= auto
sc config HomeGroupProvider start= auto
sc config Browser start= auto
sc config LanmanWorkstation start= auto
sc config Power start= auto
sc config TabletInputService start= auto
sc config BITS start= auto
sc config WMPNetworkSvc start= auto
sc config DPS start= auto
sc config TrkWks start= auto
sc config WerSvc start= auto
sc config ShellHWDetection start= auto
sc config WSearch start= auto
sc config wuauserv start= auto
sc config Dnscache start= auto
sc config Spooler start= auto
sc config WPDBusEnum start= auto
sc config StiSvc start= auto
sc config LanmanServer start= auto
pause
goto menu

:6
echo.
cls
@echo off
net start "Offline Files"
net start "HomeGroup Listener"
net start "HomeGroup Provider"
net start "Computer Browser"
net start Workstation
net start Power
net start "Tablet PC Input Service"
net start BITS
net start WMPNetworkSvc
net start DPS
net start TrkWks
net start WerSvc
net start ShellHWDetection
net start WSearch
net start "Windows Update"
net start "DNS Client"
net start "Print Spooler"
net start "Portable Device Enumerator Service"
net start StiSvc
net start Server
pause
goto menu


:7
echo.
cls
@echo off
netstat -ano
pause
goto menu

:0
set cho=
cls
