echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >more.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>more.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>more.html
echo ^<base target="_blank" /^> >>more.html

echo ^<head^> >>more.html
echo ^<title^>contents^</title^> >>more.html
:: echo ^<link  href="../../more.css" rel="stylesheet" type="text/css" /^> >>more.html
echo ^<style type=text/css^> >>more.html


		echo div{width:74.125^%%;} >>more.html
		echo div{margin^:auto^;} >>more.html
		echo li{width^:33%%^;float^:left;} >>more.html
		echo li{overflow^:hidden;} >>more.html
		echo li{text-overflow^:ellipsis^;white-space^:nowrap^;} >>more.html
		echo a:link{text-decoration: none; color:#000;} >>more.html
echo ^</style^>^</head^> >>more.html

echo ^<body^>^<div^> >>more.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (

	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="more.html" (
	if not "%%b"=="bat" (
		if "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a^</a^>^</li^> >>more.html 
		) else (
			echo ^<li^>^<a href="%%a.%%b"^>%%a.^<span style="color:red; "^>%%b^</span^>^</a^>^</li^> >>more.html
		)
	)
	)
	)
)
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
		echo ^<li^>^<a href="%%a/more.html"^>^<span style="color:#930; "^>%%a^</span^>^</a^>^</li^> >>more.html
	)

)
echo ^</div^> >>more.html
echo ^</body^> >>more.html
echo ^</html^> >>more.html
