echo �������F:\*.opt����
del /f /s /q F:\*.opt
echo �ɹ����IDE��Option�ļ������̹��ڿ��������Ĳ����ļ����繤����λ�õ���Ϣ�����湤���ռ������ ��F:\*.opt��

echo �������F:\*.ncb����
del /f /s /q F:\*.ncb
echo �ɹ����.ncb�ļ���¼�������ʾ��Ϣ�������ĳ�Ա�����ͱ�������ʾ�����ˣ��������ɸ��ļ�����F:\*.ncb��

echo �������F:\*.plg����
del /f /s /q F:\*.plg
echo �ɹ����������־�ļ����Ǳ�����Ϣ�ļ�������ʱ��error��warning��Ϣ�ļ�F:\*.plg��

echo �������F:\*.pch����
del /f /s /q F:\*.pch
echo �ɹ����Ԥ����ͷ�ļ�F:\*.pch��

echo �������F:\*.res����
del /f /s /q F:\*.res
echo �ɹ����VC++�б���õ���Դ�ļ�(������) F:\*.res��

echo �������F:\*.ilk����
del /f /s /q F:\*.ilk
echo �ɹ����ILK�����ӹ��������ɵ�һ���м��ļ���ֻ��LINK����ʹ��F:\*.ilk��
echo.

echo �������F:\*.pdb����
del /f /s /q F:\*.pdb
echo �ɹ����Program Database����¼�˳����йص�һЩ���ݺ͵�����Ϣ���ڵ��Ե�ʱ��������á�F:\*.pdb��

echo �������F:\*.obj����
del /f /s /q F:\*.obj
echo �ɹ����obj��F:\*.obj��

echo �������F:\*.idb����
del /f /s /q F:\*.idb
echo �ɹ����.idb��¼����Щ�ļ����޸Ĺ��ģ���Ҫ���±���ġ���F:\*.idb��

echo �������F:\*.tlh����
del /f /s /q F:\*.tlh
echo �ɹ����tlh��tli�ļ���������VC++���������� tlb �ļ����ɵı�׼ C++ �ļ���F:\*.tlh��

echo �������F:\*.tli����
del /f /s /q F:\*.tli
echo �ɹ����tlh��tli�ļ���������VC++���������� tlb �ļ����ɵı�׼ C++ �ļ���F:\*.tli��
del /f /s /q F:\*.sdf

echo.
echo �����ļ��Ѿ�������ϣ�

pause

rem DEL /F /A /Q //?/%1
rem RD /S /Q //?/%1