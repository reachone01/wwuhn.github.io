setlocal enabledelayedexpansion

for /f "tokens=1 usebackq delims=." %%C in (`dir ..\  /o:d /b`) do (
  set n=0
  if not "%%C"=="zzzbat r" (
  if  "%%A.%%B"=="%%A." (
     for /f "tokens=1,2 usebackq delims=." %%A in (`dir ..\%%C /o:d /b`) do (
     set /a n=n+1
		if !n! lss 10 (
			ren "..\%%C\%%A.%%B" "0!n!.%%B"
		) else (
			ren "..\%%C\%%A.%%B" "!n!.%%B"
		)
     )
   )
   )
)



rem delims==."��."�м��޿ո�,��Ȼ���������пյ��ļ����ļ��д�����;
rem �ӳٱ���n,�ұ�����"!"����,������ӳ�,��n��Զ��0;