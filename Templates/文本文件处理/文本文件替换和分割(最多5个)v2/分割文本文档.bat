setlocal=enabledelayedexpansion
for /l %%n in ( 1,1,10) do if exist %%n.txt del %%n.txt
	for /f "tokens=* delims= " %%a in (all.txt) do (
		if NOT "%%a" == "2//" ( 
		echo %%a >>1.txt 
		) else goto second	
	)

:second
set /p n2= �������2���ı���ʼ��������
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "3//" ( 
		echo %%a >>2.txt 
		) else goto third	
	)
)

:third
set /p n2= �������3���ı���ʼ��������
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "4//" ( 
		echo %%a >>3.txt 
		) else  goto four
	)
)

:four
set /p n2= �������4���ı��ĵ���ʼ��������
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "5//" ( 
		echo %%a >>4.txt 
		) else   goto five
	)
)

:five
set /p n2= �������5���ı��ĵ���ʼ��������
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "6//" ( 
		echo %%a >>5.txt 
		) else  exit	
	)
)