::�����������ļ������ڣ�e:\website�£�echo %~dp0����ʾ��E:\Website\ 
::�����������ļ������ڣ�e:\website�£�md %~dp0new222�Ὠ���ļ���E:\Website\new222
::Ҳ�����ں����"\",�½��ļ��к͸����ļ�ʱ���޴�ֻ����echo %~dp0\aaanew >a.txt,������E:\Website\\aaanew
::set path1 = %~dp0 ����Ч�ģ���Ϊ"="���ұ�ֻ����string

md %userprofile%\desktop\witiso
copy  %~dp0\witiso\* %userprofile%\desktop\witiso

for /f "tokens=1,2 usebackq delims=." %%a in (`dir %~dp0\witiso /o:d /b`) do (
	if "%%a.%%b"=="%%a." (
		md %userprofile%\desktop\witiso\%%a
	)
)
for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witiso /o:d /b`) do (
	if "%%j.%%k"=="%%j." (
		copy  %~dp0witiso\%%j\*.html %userprofile%\desktop\witiso\%%j
	)
)

for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witiso /o:d /b`) do (
	if "%%j"=="zfirst" (
		xcopy /s %~dp0witiso\zfirst %userprofile%\desktop\witiso\zfirst
	)
	if "%%j"=="css" (
		copy  %~dp0witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
	if "%%j"=="js" (
		copy  %~dp0witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
)

cd %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\witiso.rar %userprofile%\desktop\witiso\*

rem python F:\Website\witiso.py

rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......