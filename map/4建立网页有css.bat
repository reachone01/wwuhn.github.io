echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"  >more.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>more.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>more.html
echo ^<base target="_blank" /^> >>more.html

echo ^<head^> >>more.html
echo ^<title^>contents^</title^> >>more.html
echo ^<link  href="../../more.css" rel="stylesheet" type="text/css" /^> >>more.html
echo ^<style type=text/css^> >>more.html
echo div{width:74.125^%%;} >>more.html
echo div{margin^:auto^;font-size^:18px^;} >>more.html

echo li{width^:32^%%^; display^:block^;float^:left^;height^:28px^;line-height^:28px^;overflow^:hidden^;} >>more.html
echo a^:link,a^:visited{color^:black^;text-decoration^:none^;} >>more.html
echo ^</style^>^</head^> >>more.html

echo ^<body^>^<div^> >>more.html
echo ^<li^>^<a href="http://api.map.baidu.com/lbsapi/getpoint/index.html"^>百度地图坐标^</a^>^</li^> >>more.html
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (

	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="more.html" (
	if not "%%b"=="bat" (

		echo ^<li^>^<a href="%%a.%%b"^>%%a.%%b^</a^>^</li^> >>more.html
	)
	)
	)

)
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="world矢量SVG." (	
		echo ^<li^>^<a href="%%a/index.html"^>%%a^</a^>^</li^> >>more.html
	))
	if "%%a.%%b"=="world矢量SVG." (	
		echo ^<li^>^<a href="%%a/tests/index.html"^>%%a^</a^>^</li^> >>more.html
	)
)
echo ^</div^> >>more.html
echo ^</body^> >>more.html
echo ^</html^> >>more.html
