/*
��дC++���򣬶�comments.txt��ȥ���������е�ע�ͣ������浽�ļ�nocomments.txt�С�
  �ļ���
 ask patches [set pcolor green ]
; check��GRASS? switch.
; if it istrue, then grass grows and the sheep eat it. if it false, then the sheep don'tneed to eat
  if grass? [
    ask patches[
      setcountdown random grass-regrowth-time ; initialize grass grow clocks randomly
      set pcolorone-of [green brown]
    ]
  ]
*/
#if 0

//������������Ҫ��ĳ���ȥ��ע�ͣ����ע�͵���ռһ�У��������У�
#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	ifstream sourceFile;
	ofstream targetFile;
	char ch[100];
	int i;
	sourceFile.open("comments.txt", ios::in);
	targetFile.open("nocomments.txt", ios::out);
	while (!sourceFile.eof())
	{	
		sourceFile.getline(ch,100,'\n');
		i=0;
		while(ch[i]!='\0' && ch[i]!=';')
		{
			targetFile.put(ch[i]);
			++i;
		}
		targetFile.put('\n');
	}
	sourceFile.close();
	targetFile.close();
	cout << "Finish!" << endl;
	system("pause");
	return 0;
}

#else

//��������Ľϸ�Ҫ��ĳ��򣺵�ע�͵���ռһ��ʱ��ȥ��ע�ͺ󣬿��н����ٱ�����
#include <iostream>
#include <fstream>
using namespace std;
bool isCommentLine(char[]);
int main() 
{
	ifstream sourceFile;
	ofstream targetFile;
	char ch[100];
	int i;
	sourceFile.open("WolfSheep.nls", ios::in);
	targetFile.open("WS_nocomment.nls", ios::out);
	while (!sourceFile.eof())
	{	
		sourceFile.getline(ch,100,'\n');
		if(!isCommentLine(ch))   //����Ƕ�����ע���У����н�����д��Ŀ���ļ�
		{
			i=0;
			while(ch[i]!='\0' && ch[i]!=';')
			{
				targetFile.put(ch[i]);
				++i;
			}
			targetFile.put('\n');
		}
	}
	sourceFile.close();
	targetFile.close();
	cout << "Finish!" << endl;
	system("pause");
	return 0;
}
 
bool isCommentLine(char line[]) //�ж��Ƿ�Ϊ������ע����
{
	int i=0;
	bool is = false;
	char c=line[i];
	while(c!='\0' && c!=';' && (c==' ' || c=='\t'))
	{
		c=line[++i];
	}
	if (c==';') is=true;
	return is;
}


#endif
/*

*/