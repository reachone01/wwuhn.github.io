@echo off
echo windows registry editor version 5.00 >temp.reg
echo ���ڵ����������磬�Ա��û������Ի���ʹ�øù���...
echo.
echo [hkey_current_user\software\microsoft\windows\currentversion\internetsettings]>>temp.reg

echo "noNetAutodial"=hex:00,00,00,00 >>temp.reg
rem:��ʾ��δ����internet������£����г������internetʱ�����ų�����Զ�����
��
echo [hkey_local_machine\software\microsoft\windows\currentversion\network\realModeNet]>>temp.reg
echo "autologo"=dword:00000001 >>temp.reg
echo [hkey_current_user\software\policies\microsoft\windows\networkConnections]>>temp.reg
echo "nc_dialupPrefs"=dword:00000001 >>temp.reg
echo [hkey_classes_root\interface\{0000010c-0000-0000-c000-000000000046}] >>temp.reg
echo @="iPersist" >>temp.reg
echo [hkey_classes_root\interface\{0000010c-0000-0000-c000-000000000046}\numMethods] >>temp.reg
echo @="4" >>temp.reg
echo [hkey_classes_root\interface\{0000010c-0000-0000-c0000-000000000046}\proxyStubclsid32] >>temp.reg
echo @="00000320-0000-0000-c000-00000000046" >>temp.reg
echo �ɹ������������磬����ʹ�ò������罫�����㣡
regedit /s temp.reg
del /q /f temp.reg
