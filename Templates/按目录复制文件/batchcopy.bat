@echo off
@cd c:\user\wwu\desktop\
@cd c:
echo 正在创建file0.txt~file9.txt共10个文件...
echo.
echo.
for /f "eol=; tokens=* delims=, " %%i in (contents.txt) do copy module.html %%i.html
rem:in后应有空格, (不要换行
echo 文件创建完毕！