@echo off
cd /d %userprofile%\desktop\

echo ���ڴ���1.txt~3.txt��3���ļ�...
echo.
echo.

for /L %%n in (1,1,3) do (  echo. >%%n.txt 
)
rem:in��Ӧ�пո�
echo �ļ�������ϣ�