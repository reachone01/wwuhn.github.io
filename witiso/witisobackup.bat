md %userprofile%\desktop\witiso

set path1 = R:\wwuhn\website\witiso
copy  R:\wwuhn\website\witiso\* %userprofile%\desktop\witiso


for /f "tokens=1,2 usebackq delims=." %%a in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%a.%%b"=="%%a." (
		md %userprofile%\desktop\witiso\%%a
	)

)
for /f "tokens=1,2 usebackq delims=." %%j in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%j.%%k"=="%%j." (
		copy  R:\wwuhn\website\witiso\%%j\*.html %userprofile%\desktop\witiso\%%j
	)

)

for /f "tokens=1,2 usebackq delims=." %%j in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%j"=="img" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
	if "%%j"=="css" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
	if "%%j"=="js" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)


)



cd %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\witiso.rar %userprofile%\desktop\witiso\*


rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......