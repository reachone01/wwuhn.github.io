if exist all.txt del all.txt
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if not "%%b"=="bat" (
	for /f "tokens=* usebackq" %%f in ("%%a.%%b") do (@echo  %%a ^| %%f >>all.txt)
	)
)
rem usebackq������ļ������пո�Ҫ��usebackq;
rem %%a.%%b�ļ�������ļ���%%a�пո�Ҫ��"";
rem tokens=*��ʾ���д����޷��в�����