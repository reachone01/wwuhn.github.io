@echo off
if "%1"=="" (
echo ���������ļ�����ȷ�÷����£�
echo %0 filename
echo ����filename��ʾҪ������ݷ�ʽ���ļ�
echo.
echo �������޷�������ݷ�ʽ����Ϊû��ָ���ļ�
goto end
)
echo ����Ϊָ�����ļ�������ݷ�ʽ...
set shortcutname=%~n1.url
echo [InternetShortcut] >%shortcutname%
echo URL=%~f1 >>%shortcutname%
echo IconIndex=1 >>%shortcutname%
echo IconFile=%windir%\system32\shell32.dll >>%shortcutname%
copy %shortcutname% "%userprofile%\desktop" >nul
echo.
echo �ɹ�����%1�Ŀ�ݷ�ʽ%shortcutname%,�ÿ�ݷ�ʽ�Ѿ����͵����棡
set shortcutname=
:end