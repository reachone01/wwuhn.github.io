echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >..\listAll������.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\listAll������.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\listAll������.html
echo ^<base target="_blank" /^> >>..\listAll������.html

echo ^<head^> >>..\listAll������.html
echo ^<title^>total pic list^</title^> >>..\listAll������.html
echo ^<style type=text/css^> >>..\listAll������.html
echo div{width:94.125^%;} >>..\listAll������.html
echo div{margin^:auto^;} >>..\listAll������.html
echo img{display^:block^;margin^:auto;} >>..\listAll������.html
echo img{padding^:4px 4px; height^:200px; float^:left;} >>..\listAll������.html
echo img{border^:0 red solid;} >>..\listAll������.html
echo a:link{text-decoration: none; color:#fff;} >>..\listAll������.html

echo ^</style^>^</head^> >>..\listAll������.html

echo ^<body^>^<div^> >>..\listAll������.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:d /b`) do (
	if not "%%a"=="zzzbat r" (
	if not "%%b"=="html" (
		for /f "tokens=* usebackq" %%n in (`dir ..\%%a /o:d /b`) do (
			if not "%%n"=="picList.html" (
				echo ^<a href="%%a\%%n"^>^<img src="%%a/%%n" /^>^</a^> >>..\listAll������.html
			)
		)
	)
	)
)
echo ^</div^> >>..\listAll������.html
echo ^</body^> >>..\listAll������.html
echo ^</html^> >>..\listAll������.html
