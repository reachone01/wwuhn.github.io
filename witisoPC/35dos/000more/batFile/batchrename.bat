@echo off
echo ��ʼ�����ļ���...
set ext=.rar
set /a sum=0
for %%m in (*)do (
if not "%%m"=="batchrename.bat"(
ren %%m %%m%ext%
set /a sum=sum+1
)
)
echo �ļ�������ɣ�һ����%sum%���ļ���������
set sum=
set ext=