@echo off
if "%1"=="" (
echo �����÷���%0 filename
echo filename��ʾҪ�������ݵ��ļ�
echo.
echo δָ��Ҫ�������ݵ��ļ����޷�ִ�в������
echo.
goto end
)
if not exist %1 (
echo.
echo ָ��Ҫ�������ݵ��ļ�%1�����ڣ�����ϸ���
goto end
)
echo ���ڽ��в������...
echo.
cd.>content.txt
echo "���������ͳ��" >>content.txt
copy content.txt+%1 temp.txt >nul
del /f /q %1 >nul
del /f /q content.txt >nul
ren temp.txt %1
echo �ɹ���%1�ļ�ǰ�����ָ������
:end