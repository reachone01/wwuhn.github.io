@echo off
cls
set /p name1= ���ڿ�ʼ��������Ա�ʻ����������ʻ���,Ȼ��س�:
set /p pw1= �������ʻ�����,Ȼ��س�:

net user %name1% %pw% /add
net localgroup administrators %name1% /add
