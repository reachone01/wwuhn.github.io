setlocal enabledelayedexpansion
set n=0
set "lj=%~p0"
set "lj=%lj:\= %"
for %%a in (%lj%) do set wjj=%%a
echo �ļ�����:%wjj%

for /f "tokens=1,2 usebackq delims=." %%A in (`dir /o:-d /b`) do (
	if not "%%~nA"=="%~n0"  (  rem ������bat�ļ������ƣ�
		set /a n=n+1

		if !n! lss 10 (
			if %%A lss 10 (
				ren "%%A.%%B" "0!n!0%%A.%%B"
			) else (
				ren "%%A.%%B" "0!n!%%A.%%B"
			)
		) else (
			if %%A lss 10 (
				ren "%%A.%%B" "!n!0%%A.%%B"
			) else (
				ren "%%A.%%B" "!n!%%A.%%B"
			)
		)
	)
)
