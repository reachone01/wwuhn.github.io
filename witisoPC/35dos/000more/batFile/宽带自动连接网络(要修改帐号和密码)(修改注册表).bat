@echo off
echo windows registry editor version 5.00 >temp.reg
echo ��������ϵͳ����ʱ�Զ�������������...
echo.
echo [hkey_local_machine\software\microsoft\windows\currentversion\run] >>temp.reg
echo "autodial"=rasdial pppoe accountname password >>temp.reg
echo �ɹ�����ϵͳ�����󣬿���Զ��������磡
regedit /s temp.reg
del /q /f temp.reg
