@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell")>>runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs&&exit
:findvbs
del runhide.vbs

##########���������Ŀ�ʼ##########
##########�������д����##########
explorer %userprofile%\AppData\Local\Microsoft\Windows\Temporary Internet Files
##########���������Ľ���##########
