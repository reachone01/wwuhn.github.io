setlocal=enabledelayedexpansion


set /p n2= �������2���ı���ʼ��������

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "3//" ( 
		echo %%a >>2.txt 
		) else  call bat\���ɵ�3���ĵ�.bat	
	)		

)