md %userprofile%\desktop\dataiso

xcopy /s %~dp0\dataiso %userprofile%\desktop\dataiso

cd /d %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\dataiso.rar %userprofile%\desktop\dataiso\*

rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......