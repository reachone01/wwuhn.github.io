md %userprofile%\desktop\website
md %userprofile%\desktop\website\pctips
md %userprofile%\desktop\website\zfirst

xcopy /s F:\Website\pctips %userprofile%\desktop\website\pctips
xcopy /s F:\Website\zfirst %userprofile%\desktop\website\zfirst
copy F:\Website\*.* %userprofile%\desktop\website

cd /d %ProgramFiles%\winrar

rar a -r %userprofile%\desktop\website.rar %userprofile%\desktop\website\*
python F:\Website\notes\tools\websiteBackup\smtp.py



rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......