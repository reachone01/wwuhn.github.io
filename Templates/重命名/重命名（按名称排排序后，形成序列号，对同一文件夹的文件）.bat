setlocal enabledelayedexpansion
set n=0
for /f "tokens=1,2 usebackq delims=." %%A in (`dir /o:d /b`) do (
	if not "%%B"=="bat" (  rem ������bat�ļ������ƣ�
	if not "%%B"=="html" ( rem ������html�ļ������ƣ�
	if not "%%A.%%B"=="%%A" ( rem �������ļ��е����ƣ�
		set /a n=n+1
		if n leq 9 (
		ren "%%A.%%B" " "0!n!.%%B"
		)
	)
	)
	)
)