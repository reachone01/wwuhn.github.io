setlocal=enabledelayedexpansion


set /p n2= �������5���ı��ĵ���ʼ��������

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "6//" ( 
		echo %%a >>5.txt 
		) else  exit	
	)		

)