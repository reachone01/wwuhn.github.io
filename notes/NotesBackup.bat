md %userprofile%\desktop\notes
md %userprofile%\desktop\notes\Assistants
md %userprofile%\desktop\notes\Assistants\res
md %userprofile%\desktop\notes\consoleProgram
md %userprofile%\desktop\notes\VC\������������Ϣ����

copy %~dp0\Assistants\*.* %userprofile%\desktop\notes\Assistants
copy %~dp0\Assistants\res\*.* %userprofile%\desktop\notes\Assistants\res
copy %~dp0\consoleProgram\*.* %userprofile%\desktop\notes\consoleProgram
copy %~dp0\VC\������������Ϣ����\*.* %userprofile%\desktop\notes\VC\������������Ϣ����


cd /d %ProgramFiles%\winrar
rar a -r %userprofile%\desktop\notes.rar %userprofile%\desktop\notes\*
::python F:\notes\notes.py

rem �����ļ��������ļ����������ļ���
rem xcopy /s %~dp0\consoleProgram\*.* %userprofile%\desktop\notes\consoleProgram
rem a��ʾ����ѹ���ĵ������
rem -m5��ָ�����ѹ�����ʣ�
rem -s�ǲ��ù�ʵѹ����
rem -r�ǵݹ�ѹ���ļ����������ļ���
rem ����Ĵ�ѹ���������ļ��С�
rem ���winrar�İ�װĿ¼���ڻ�������PATH�У�����Ҫдȫ·�����磺"C:\Program Files\WinRar\rar" ......