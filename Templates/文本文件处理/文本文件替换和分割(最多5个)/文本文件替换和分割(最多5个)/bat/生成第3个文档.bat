setlocal=enabledelayedexpansion


set /p n2= �������3���ı���ʼ��������

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "4//" ( 
		echo %%a >>3.txt 
		) else  call bat\���ɵ�4���ĵ�.bat	
	)		

)