@echo off
cls
color 3a
:menu
echo.
echo    ѡ��˵���
echo.
@echo  �X�������������������������������������������������������������������[
@echo  ��                                                                  ��
@echo  ��  1. ��ʱ�ػ�,����ʱ��(��24:12),��������������ʱ���һ���ӹر�  ��
@echo  ��                                                                  ��
@echo  ��  2. ��ʱ�ػ�,��������(��3600),��������������������ر�         ��
@echo  ��                                                                  ��
@echo  ��  3. �鿴�ƻ�����(��Դ��������������)                             ��
@echo  ��                                                                  ��
@echo  ��  4. �鿴�ƻ�����(at�������õ�����,CMD����,Ҳ���Ǳ����ڲ鿴)      ��
@echo  ��                                                                  ��
@echo  ��  5. ȡ���ƻ�����Ͷ�ʱ�ػ�����                                   ��
@echo  ��                                                                  ��
@echo  ��  0. exit                                                         ��
@echo  ��                                                                  ��
@echo  �^�������������������������������������������������������������������a

echo.
set /p choice="    ѡ����Ŀ(����ǰ�������)��Ȼ��س�:"  
if "%choice%"=="1" goto 1
if "%choice%"=="2" goto 2
if "%choice%"=="3" goto 3
if "%choice%"=="4" goto 4
if "%choice%"=="5" goto 5
if "%choice%"=="0" goto 0
echo.

goto 0
:1
cls
echo.
set /p time= as "24:12" ,input time:
at %time% shutdown -s -t 30
goto menu

:2
cls
echo.
set /p time= as "3600" ,input seconds:
shutdown -s -t %time%
goto menu

:3
cls
echo.
taskschd.msc
goto menu


:4
cls
echo.
at
goto menu

:5
cls
echo.
shutdown -a
at /del
goto menu

:0
set time=
cls
echo.