setlocal enabledelayedexpansion
set n=0
for /f "tokens=* usebackq delims=." %%A in (`dir ..\ /o:d /b`) do (
	if not "%%A"=="zzzbat r" (
	if  "%%A.%%B"=="%%A." (
		if !n! lss 10 (
			ren "../%%A" "0!n!"
		) else (
			ren "../%%A" "!n!"
		)
	)
	)
)

rem �ӳٱ���n,�ұ�����"!"����,������ӳ�,��n��Զ��0;


