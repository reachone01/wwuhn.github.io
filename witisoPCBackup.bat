::�����������ļ������ڣ�e:\website�£�echo %~dp0����ʾ��E:\Website\ 
::�����������ļ������ڣ�e:\website�£�md %~dp0new222�Ὠ���ļ���E:\Website\new222
::Ҳ�����ں����"\",�½��ļ��к͸����ļ�ʱ���޴�ֻ����echo %~dp0\aaanew >a.txt,������E:\Website\\aaanew
::set path1 = %~dp0 ����Ч�ģ���Ϊ"="���ұ�ֻ����string

md %userprofile%\desktop\witisoPC
copy  %~dp0\witisoPC\* %userprofile%\desktop\witisoPC

for /f "tokens=1,2 usebackq delims=." %%a in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%a.%%b"=="%%a." (
		md %userprofile%\desktop\witisoPC\%%a
	)
)
for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%j.%%k"=="%%j." (
		copy  %~dp0witisoPC\%%j\*.html %userprofile%\desktop\witisoPC\%%j
	)
)

for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%j"=="zfirst" (
		xcopy /s %~dp0witisoPC\zfirst %userprofile%\desktop\witisoPC\zfirst
	)
	if "%%j"=="css" (
		copy  %~dp0witisoPC\%%j\* %userprofile%\desktop\witisoPC\%%j
	)
	if "%%j"=="js" (
		copy  %~dp0witisoPC\%%j\* %userprofile%\desktop\witisoPC\%%j
	)
)

cd %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\witisoPC.rar %userprofile%\desktop\witisoPC\*

rem python F:\Website\witisoPC.py

rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......