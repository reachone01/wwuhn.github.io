@echo off
echo windows registry editor version 5.00 >temp.reg
echo ��������ϵͳ����ʱ�Զ�������������...
echo.
echo [hkey_local_machine\software\microsoft\windows\currentversion\run] >>temp.reg
echo "autodial"=rasdial pppoe 404 4048016 >>temp.reg
echo �ɹ�����ϵͳ�����󣬿���Զ��������磡
regedit /s temp.reg
del /q /f temp.reg
<p>�û����Ƿ�Ҫ�����ţ�"
rem C:\windows\system32\rasphone.exe -d �������
::1 ��ϵͳ�����˿�����ӵ��û���������
::�������������Internet���鿴����״̬������������µ����ӻ���������ӵ�Internet����������ӣ���ѡ�����������û��������롢����������ƣ�������ӣ���ѡ����ס���롣

::�鿴���������ӣ�������������� Internet����͹������ġ��������������ã����ɲ鿴�������ӿ�������������ӡ�

::2 ���á�������ӡ�����
::״̬�����½ǵ����н��������ӵ�ͼ����һ����������"�����ԡ���ѡ�ѡ���ȥ����ѡ����ʾ���ơ������֤�飻

::����win+r��rasphone��ݼ���

::3 ����Internet����
::win+R��inetcpl.cpl���򿪡�Internet���ԡ��Ի���������ӡ�ѡ���ѡ����ʼ�ղ���Ĭ�����ӡ���

::4 �����������ų���
::4.1 ʹ��������ű�����ע��������������
::�½�һ���������ļ��������������ݣ�
::reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run" /v autodial /t REG_SZ /d "%SystemRoot%\system32 \rasphone.exe -d �������" /f

::c:windowssystem32 asphone.exe�ǲ��ų����·����

::-d��ָ���п�����ӣ����ġ�������ӡ���Ҫ�Զ����ŵĿ����������

::�ű����к�ע��HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run�����һ��ֵ�

::4.2 ʹ�üƻ�����

::c:\Windows\System32\rasphone.exe -d �������
