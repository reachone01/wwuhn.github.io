setlocal enabledelayedexpansion
set n=0
rem ȡ��·�����������һ��б��\
set tempPath=%~dp0

rem ��·���е����һ��б��ȥ��
set tempPath=!tempPath:~,-1!
echo %tempPath%
for %%a in ("!tempPath!") do (

set dirName=%%~na

)

for /f "tokens=1,2 usebackq delims=." %%A in (`dir /o:n /b`) do (
	if not "%%~nA"=="%~n0"  (  rem ������bat�ļ������ƣ�
	if not "%%B"=="html" ( rem ������html�ļ������ƣ�
	if not "%%A.%%B"=="%%A." ( rem �������ļ��е����ƣ�

		set /a n=n+1

		if !n! lss 10 (
			ren "%%A.%%B" "!dirName!0!n!.%%B"
		) else (
			ren "%%A.%%B" "!dirName!!n!.%%B"
		)

	)
	)
	)
)


::ͼƬ������������ʱ�򣬿��ܻ��뵽��acdsee7.0���ϵİ汾��ʵ�֡�
::���ļ��У�ȫѡͼƬ�ļ���Ȼ����ctrl�����ţ��ڵ�һ��ͼƬ���ҽ��������������������ĳ���list(1).jpg��list(2).jpg��list(3).jpg������

::set /p name=""		"="ǰ�����пո�
::) else (		"else"ǰ������пո�
:: if !n! lss 10 ( �˴����ű�����"!"��������"%";





