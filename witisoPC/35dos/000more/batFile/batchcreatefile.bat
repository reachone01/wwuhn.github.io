@echo off
cd c:\user\wwu\desktop\
cd c:
echo ���ڴ���file0.txt~file9.txt��10���ļ�...
echo.
echo.
for /l %%n in (1,1,3) do ( rem:in��Ӧ�пո� echo >>%%n.txt
)
echo �ļ�������ϣ�