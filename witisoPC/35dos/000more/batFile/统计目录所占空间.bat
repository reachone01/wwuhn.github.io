@echo off
echo.
echo ����ͳ��Ŀ¼��ռ�ռ䣬���Ժ�
echo ----------------------
for /f "tokens=*" %%a in ('dir') do (
echo "%%a" | find "���ļ�" >nul && for /f "tokens=3*" %%b in ("%%a") do (
echo ��ǰĿ¼��С:%%b%%c
)
)
echo ---
echo ��Ŀ¼��ռ�ռ��С�ֱ����£�
for /f %%a in ('dir /ad /s /b') do (
for /f "tokens=*" %%b in ('"dir %%a\"') do (
echo "%%b"|find "���ļ� ">nul && for /f "tokens=3*" %%c in ("%%b") do (
echo %%a:%%c%%d
)
)
)