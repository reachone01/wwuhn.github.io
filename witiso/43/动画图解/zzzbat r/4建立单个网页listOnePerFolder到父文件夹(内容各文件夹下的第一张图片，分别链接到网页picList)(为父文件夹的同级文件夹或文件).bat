echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >..\listOnePerFolder.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\listOnePerFolder.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\listOnePerFolder.html
echo ^<base target="_blank" /^> >>..\listOnePerFolder.html

echo ^<head^> >>..\listOnePerFolder.html
echo ^<title^>list^</title^> >>..\listOnePerFolder.html
echo ^<style type=text/css^> >>..\listOnePerFolder.html
echo div{width:34.125^%%;} >>..\listOnePerFolder.html
echo div{margin^:auto^;} >>..\listOnePerFolder.html
echo img{display^:block^;margin^:auto;} >>..\listOnePerFolder.html
echo img{padding^:2px 22px; height^:200px;} >>..\listOnePerFolder.html
echo img{border^:0 red solid;} >>..\listOnePerFolder.html
echo a:link{text-decoration: none; color:#fff;} >>..\listOnePerFolder.html

echo ^</style^>^</head^> >>..\listOnePerFolder.html

echo ^<body^>^<div^> >>..\listOnePerFolder.html

for /f "skip=3 tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:D /b`) do (
	if not "%%a"=="zzzbat r" (
	if not "%%b"=="html" (
	if not "%%n"=="listOnePerFolder.html" (
		
			if not  "%%b" == "bat" ( 
			echo ^<p^>%%a^</p^> >>..\listOnePerFolder.html
			echo ^<a href="%%a\picList.html"^>^<img src="%%a/1.gif" /^>^</a^> >>..\listOnePerFolder.html
			
			)
							
		

	
	)
	)
	)
	
)
echo ^</div^> >>..\listOnePerFolder.html
echo ^</body^> >>..\listOnePerFolder.html
echo ^</html^> >>..\listOnePerFolder.html
