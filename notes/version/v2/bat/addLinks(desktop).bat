@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell") >runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs
:findvbs

@rem ��������ݣ�����ȷ������ҳ����ʾ�����л򱣴桱����������ʾ��


@echo.
echo.

@set /p address="��������ַ:"
@set /p linkName="������������:"

echo ^<li^>^<a href="%address%"^>%linkName%^</a^>^</li^>  >> F:/Website/notes/noteshtml.html

start F:/Website/notes/noteshtml.html
del %~dp0%\runhide.vbs


::�������и�������a.bat��D:/qq�ļ�����  
::a.bat����Ϊcd /d %~dp0 
::������cd /d %~dp0����˼����cd /d d:/qq 
::%0������������ d:/qq/a.bat
::~dp�Ǳ�������
::d�������䵽������ d:
::p�������䵽·�� /qq 
::dp�������䵽������·�� d:/qq 