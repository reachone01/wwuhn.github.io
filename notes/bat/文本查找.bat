@echo off
echo. >c:\virus.txt
color 3a
echo.
echo  ���ߣ����������ϡ� 2013.3.7 windowsXP
:fh
echo.
echo  ���������Ϊ��ȫ�̲��Һ����ض����ݵ��ļ���λ��
echo.
@echo  �X�����������������������������������������������[
@echo  ��                                              ��
@echo  ��  1. �Ķ������ļ�                             ��
@echo  ��                                              ��
@echo  ��  2. �����ļ�����                             ��
@echo  ��                                              ��
@echo  ��  3. �˳�                                     ��
@echo  ��                                              ��
@echo  �^�����������������������������������������������a
echo.
echo  ѡ���Ӧ��1��2��3��ֱ�ӻس�����ڶ�����в�ѯ!
echo.
:Choice2
set choice2=
set /p choice2= ��ѡ��:
IF NOT "%Choice2%"=="" SET Choice2=%Choice2:~0,1%
if /i "%choice2%"=="1" goto help
if /i "%choice2%"=="2" goto run
if /i "%choice2%"=="3" goto end

:run
echo.
echo.
set /p a=������Ҫ���ҵ�����:
if /i "%a%"=="" cls && goto fh

echo.
set /p b=��������ļ���չ��:
if /i "%b%"=="" cls && goto fh

echo.
echo.
echo.
echo.
echo                       ϵͳ���ڲ����ļ��������ĵȺ�......
echo.
echo.
for %%a in (C D E F) do (
  cd /d %%a:\
::for %%a in (F:\website) do (
::cd /d %%a\
  for /r . %%b in (*.%b%) do ( rem ��һ��.���ʾ����cdת���ĵ�ǰĿ¼,\r��ѡ���ݹ������Ŀ¼
      if exist "%%b" (
	type "%%b" | find /i "%a%" && echo %%b>>c:\virus.txt rem ������Ǿ���·�����򱣴浽cdת����Ŀ¼��
      )
  )
)
type c:\virus.txt | find /i "\"  && goto no

echo.
echo �ļ�����û�ҵ�!
del c:\virus.txt>nul 2>nul
echo.
pause
exit

:no
cls
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo                       �ļ�������ϲ���¼��c:\virus.txt�� !
echo.
echo.
echo.
echo �Ƿ���ı��鿴��¼ ?
echo.
echo ѡ��" Y "�鿴��   ѡ��" N "�˳���
echo.
set /p Choice=Y/N: 
IF /I '%Choice:~0,1%'=='y' goto A
IF /I '%Choice:~0,1%'=='n' goto B
pause
exit

:A
start c:\virus.txt
exit
pause
:b
exit

:help
cls
echo.
echo                               ��  ��  ��  ��
echo.
echo        1. ������Ҫ���ҵ�����: ������Ҫ���ҵ��ַ��������ִ������ִ��顣
echo           �������س���������ʾ����ڶ���ļ���չ��.
echo.
echo        2. ��������ļ���չ��:  ��չ���������κ��ı������ļ����磺txt��
echo           log��ini��inf��vbs��bat �ȣ�Ҳ����ʹ�� * ���������������ļ���
echo           ���Ƽ��� * ���ң�����ϵͳ����ʹ�õ��ļ�����ļ�ʱ����ҳ�����
echo           �����س�������ʼ�����ļ�.
echo.
echo        3. Ȼ��ȴ�ϵͳΪ����ѯ���ҵ���ϵͳ������һ���ı��ļ�����¼�˺���
echo           �����������ļ���ŵ�λ�ã�δ�ҵ�ϵͳ����ʾ�ļ�����û�ҵ�!
echo.
echo        3. ע�����
echo           Ĭ����ȫ��C D E F����ĳ�����͵��ļ����ٶȻ�ǳ�����������嵽
echo           ĳһ·�����ң��ٶȻ��һЩ������Ǿ���·���������cd���:Ҫȥ��
echo.
echo        4. findstr����ʹ��ͨ�������.���������ַ���
echo	       type "%%b" | findstr /i "charset.gb2312" && echo %%b>>D:\content.txt
echo           findҪ���ҵ����ݷ���""�ڣ����Ҫ����""������ʹ��""""
echo.
echo        �밴���������ѡ�����!
echo.
pause
cls
goto fh


:end
exit
 
