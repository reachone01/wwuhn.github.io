setlocal=enabledelayedexpansion


set /p n2= �������4���ı��ĵ���ʼ��������

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "5//" ( 
		echo %%a >>4.txt 
		) else  call bat\���ɵ�5���ĵ�.bat
	)		

)