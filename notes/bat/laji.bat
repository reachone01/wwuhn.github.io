@echo off
echo ׼�����������ļ�������������ɿ�ʼ��
echo.
echo 1  ���ϵͳ��ʱ�ļ����е��ļ���           2  �����ǰ�û���ʱ�ļ����е��ļ���
echo 3  �����ǰ�û����е�cookies��¼��        4  �����ǰ�û����ʹ���ļ���¼��
echo 5  ��ǰ�û�IE��ʱ�ļ����е��ļ���         6  ���ϵͳ�������ļ����е�tmp�ļ���
echo 7  ���ϵͳ���е�.old�ļ���               8  ����������е��ļ���
echo.
echo 9  ���ϵͳ���е�gid�ļ���
echo   ��.gid����׺���ļ���ȫ�����ļ���Windows��ʱҪ�����������ļ�������Щ�ļ�������
echo    �����ļ�����Ϣ�����ҽ������������ļ�����ʽ�Ͱ����ļ��洢��ͬһ��Ŀ¼�¡�
echo.
echo 10  ���ϵͳ���е�CHK�ļ���
echo     ���û���ʹ�á�������Ƭ�����������Ӳ�̺��������ġ���ʧ�صĻָ��ļ�����
echo     �ƶ��洢�豸�ڶ�ȡ���ݵ�ʱ�������ϵ��ǿ�аγ�,Ҳ�����������CHK�ļ���
 
echo.
echo 11  �����ϵͳ��windowsĿ¼�µ�.bak�ļ���
echo     bak�Ǳ����ļ��������޸�ǰ������Ϊbak�ı����ļ�(ǰ���������˱��ݹ���)��
echo.

pause
echo.
echo ���������ʼ�������



del /f /q %windir%\temp\*.* >nul
echo �ɹ����ϵͳ��ʱ�ļ����е������ļ���
echo.
del /f /s /q %userprofile%\cookies\*.* >nul
echo �ɹ������ǰ�û����е�cookies��¼��
echo.
del /f /s /q %userprofile%\recent\*.* >nul
echo �ɹ������ǰ�û����ʹ���ļ���¼��
echo.
del /f /s /q %userprofile%\local settings\temp\*.* >nul
echo �ɹ������ǰ�û���ʱ�ļ����е������ļ���
echo.
del /f /s /q %userprofile%\local settings\temporary internet files\*.* >nul
echo �ɹ������ǰ�û�internet��ʱ�ļ����е������ļ���
echo.

del /f /s /q %systemdrive%\*.tmp
del /f /s /q %systemdrive%\*._mp
rd /s /q %windir%\temp & md %windir%\temp
echo �ɹ����ϵͳ�������ļ����е�tmp�ļ���
echo.
del /f /s /q %systemdrive%\*.gid
echo. 
echo �ɹ������ϵͳ���е�gid�ļ���
echo ��.gid����׺���ļ���ȫ�����ļ���
echo Windows��ʱҪ�����������ļ�������Щ�ļ�����������ļ�����Ϣ��
echo ���ҽ������������ļ�����ʽ�Ͱ����ļ��洢��ͬһ��Ŀ¼�¡�
echo.

del /f /s /q %systemdrive%\*.chk
echo �ɹ������ϵͳ���е�gid�ļ���
echo CHK���ļ����û���ʹ�á�������Ƭ�����������Ӳ�̺��������ġ���ʧ�صĻָ��ļ�����
echo �ƶ��洢�豸�ڶ�ȡ���ݵ�ʱ�������ϵ��ǿ�аγ�,Ҳ�����������CHK�ļ���
echo.

del /f /s /q %systemdrive%\*.old
echo �ɹ������ϵͳ���е�.old�ļ���
echo.

del /f /s /q %systemdrive%\recycled\*.*
echo �ɹ�������������е��ļ���
echo.
del /f /s /q %windir%\*.bak
echo �ɹ������ϵͳ��windowsĿ¼�µ�.bak�ļ���
echo bak�Ǳ����ļ��������޸�ǰ������Ϊbak�ı����ļ�(ǰ���������˱��ݹ���)��
echo.
del /f /s /q %windir%\prefetch\*.*
echo �ɹ������ǰ�û�internet��ʱ�ļ����е������ļ���
echo.

echo �����ļ��Ѿ�������ϣ�