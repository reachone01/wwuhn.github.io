@echo off
color 5F
mode con cols=100 lines=35
:0
echo.                               ������������������������������������������
echo.                  �q����r     ��                                      ����     �q����r
echo.                  {/ ��� \}     ��                                      ����     {/ ��� \}
echo.                   ( (oo) )      ��             ��������:�Уã£գ�          ��      ( (oo) ) 
echo.                    ����       ��                                        ��       ����
echo.                               ��                                        ��
echo.                               ������������������������������������������
echo.
echo.                                              �q����r ��
echo.                                              {/ ��� \}�� 
echo.                                               ( (oo) ) �� 
echo.                                                ���� 
echo. 
echo    [1] ��ʾ�ļ���չ��
echo.
echo    [2] �����ļ���չ��
echo.
echo    ***************************************************** 
echo    [3] ���ش��������Ե��ļ���
echo.  
echo    [4] ǿ�Ƴ����������д��������Ե��ļ���
echo.
echo.       ��4��˵��:���к���"�ļ���ѡ��"������ʾ�����ļ�����Ч������������3��5��6����һ��ȡ��ǿ������
echo    *****************************************************
echo.
echo    [5] ��ʾ���������Ե��ļ��У�����ʾϵͳ�����ļ�
echo.
echo    [6] ��ʾ�����ļ��и�ϵͳ�����ļ�
echo.
echo. [7] �˳� 
echo. 
echo.    ���ϲ�����ɺ���ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч
echo. 
SET Choice=Ĭ��1
SET /P Choice=ѡ��[1],[2],[3],[4],[5],[6],[7]������ֱ�ӻس�Ĭ��ѡ�� 1��
IF /I '%Choice%'=='1' goto 01
IF /I '%Choice%'=='2' goto 02
IF /I '%Choice%'=='3' goto 03
IF /I '%Choice%'=='4' goto 04
IF /I '%Choice%'=='5' goto 05
IF /I '%Choice%'=='6' goto 06
IF /I '%Choice%'=='7' goto �˳�
if /i '%choice%'=='Ĭ��1' goto 01

rem echo %choice%
echo.
echo ��Чѡ��������ѡ��
echo.
goto 0

:01
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v HideFileExt /t REG_DWORD /d "0" /f
echo.                              �Ѷ�ϵͳ������ʾ�ļ���չ��
echo.                    ������ɺ���ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч��
echo.                              �������Զ��ع������˵�
echo. & pause
SET Choice=Ĭ��0
if /i '%choice%'=='Ĭ��0' goto 0

:02
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v HideFileExt /t REG_DWORD /d "1" /f
echo.                              �Ѷ�ϵͳ���������ļ���չ��
echo.                    ������ɺ���ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч��
echo.                              �������Զ��ع������˵�
echo. & pause
SET Choice=Ĭ��0
if /i '%choice%'=='Ĭ��0' goto 0

:03
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "0" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                  ���ش��������Ե��ļ�������� ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч                             
echo.
echo [1] �˳�
echo.
echo [2] �������˵���������ѡ�����
echo.
:A
SET Choice=Ĭ��1
SET /P Choice=ѡ��[1],[2]������ֱ�ӻس�Ĭ��ѡ�񣱣�
IF /I '%Choice%'=='1' goto �˳�
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='Ĭ��1' goto 1

rem echo %choice%
echo.
echo ��Чѡ��������ѡ��
echo.
goto A
exit

:04
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "0" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "0" /f
echo.                           �ѳɹ�ǿ���������д��������Ե��ļ����ļ���
echo.     �����к���"�ļ���ѡ��"������ʾ�����ļ�����Ч������������3��5��6����һ��ȡ��ǿ�����أ�
echo.                              ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч
echo.                               
echo.
echo [1] �˳�
echo.
echo [2] �������˵���������ѡ�����
echo.
:B
SET Choice=Ĭ��1
SET /P Choice=ѡ��[1],[2]������ֱ�ӻس�Ĭ��ѡ�񣱣�
IF /I '%Choice%'=='1' goto �˳�
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='Ĭ��1' goto 1

rem echo %choice%
echo.
echo ��Чѡ��������ѡ��
echo.
goto B
exit

:05
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "1" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                 ��ʾ���������Ե��ļ��У�����ʾϵͳ�����ļ��������
echo.                        ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч
echo.
echo [1] �˳�
echo.
echo [2] �������˵���������ѡ�����
echo.
:C
SET Choice=Ĭ��1
SET /P Choice=ѡ��[1],[2]������ֱ�ӻس�Ĭ��ѡ�񣱣�
IF /I '%Choice%'=='1' goto �˳�
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='Ĭ��1' goto 1

rem echo %choice%
echo.
echo ��Чѡ��������ѡ��
echo.
goto C
exit

:06
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "1" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "1" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                    ��ʾ�����ļ��и�ϵͳ�����ļ�������� ˢ���Ѵ򿪵��̷����ļ��д��ڼ�ʱ��Ч
echo.
echo.
echo [1] �˳�
echo.
echo [2] �������˵���������ѡ�����
echo.
:D
SET Choice=Ĭ��1
SET /P Choice=ѡ��[1],[2]������ֱ�ӻس�Ĭ��ѡ�񣱣�
IF /I '%Choice%'=='1' goto �˳�
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='Ĭ��1' goto 1

rem echo %choice%
echo.
echo ��Чѡ��������ѡ��
echo.
goto D
exit

:�˳�
exit 