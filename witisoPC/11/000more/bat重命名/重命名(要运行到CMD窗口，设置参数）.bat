@echo off
if not exist %1 (
echo �����÷����£�
echo %0 filename
echo filename :��ʾ��Ҫ�޸ĵ��ļ���
echo.
echo.
goto end
)
set extension=%~x1
for /f "tokens=1-3 delims=/-" %%A in ('date /T') do set date=%%A%%B%%C
ren %1 %date%%extension%
echo.
echo �ļ�%1�Ѿ����ɹ�����Ϊ%date%%extension%
set extension=
set date=
:end