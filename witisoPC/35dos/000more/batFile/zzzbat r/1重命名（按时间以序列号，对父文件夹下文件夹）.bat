setlocal enabledelayedexpansion
set n=0
for /f "tokens=* usebackq delims=." %%A in (`dir ..\ /o:d /b`) do (
	if not "%%A"=="zzzbat r" (
		set /a n=n+1
		ren "..\%%A" "!n!"
	)
)

rem �ӳٱ���n,�ұ�����"!"����,������ӳ�,��n��Զ��0;