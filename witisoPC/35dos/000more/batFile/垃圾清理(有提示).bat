@echo off


echo.
echo   ʹ������del /f ...  >nul
echo   %userprofile%\cookies\*.*
echo   %userprofile%\recent\*.* >nul

echo   %userprofile%\local settings\temp\*.*
echo   %userprofile%\local settings\temporary internet files\*.*
set /p cho="��ȷ���Ƿ�Ҫ���������ļ���(y/n):"
if "%cho%"=="y" goto y
if "%cho%"=="n" goto n

:y
echo ���������ڽ��У����Ե�...
echo.
del /f /q %windir%\temp\*.* >nul
echo �ɹ����ϵͳ��ʱ�ļ����е������ļ���
echo.
del /f /q %userprofile%\cookies\*.* >nul
echo �ɹ������ǰ�û����е�cookies��¼��
echo.
del /f /q %userprofile%\recent\*.* >nul
echo �ɹ������ǰ�û����ʹ���ļ���¼��
echo.
del /f /q /s %userprofile%\local settings\temp\*.* >nul
echo �ɹ������ǰ�û���ʱ�ļ����е������ļ���
echo.
del /f /q /s %userprofile%\local settings\temporary internet files\*.* >nul
echo �ɹ������ǰ�û�internet��ʱ�ļ����е������ļ���
echo.
echo �����ļ��Ѿ�������ϣ�

:n
cls
cho=
