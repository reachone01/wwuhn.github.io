@echo off
echo.
setlocal enabledelayedexpansion   rem���������������ʱ���书�ܡ�����������ʹ�øù��ܺ󣬿���ʹ��"!"������ִ��ʱ�������
cd. >a_new.txt
echo �����滻�ļ��е��ַ��������Ժ�...
echo.
for /f %%a in (a.txt) do (
set str=%%a
set str=!str:����=����! ::����"!"֮���"str"ʹ���˱�����ʱ���ܣ�
echo !str! >>a_new.txt ::����"!"֮���"str"ʹ���˱�����ʱ���ܣ�
)
ren a.txt a_old.txt
ren a_new.txt a.txt
echo �ɹ��滻�ļ���ָ�����ַ�����profit_old.txt�ļ�Ϊδ�޸�ǰ��profit.txt�ļ���
set str=