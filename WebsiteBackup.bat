md %userprofile%\desktop\website
md %userprofile%\desktop\website\pctips
md %userprofile%\desktop\website\zfirst

xcopy /s %~dp0\pctips %userprofile%\desktop\website\pctips
xcopy /s %~dp0\zfirst %userprofile%\desktop\website\zfirst
copy %~dp0\*.* %userprofile%\desktop\website

cd /d %ProgramFiles%\winrar

rar a -r %userprofile%\desktop\website.rar %userprofile%\desktop\website\*

python F:\Website\website.py



rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......