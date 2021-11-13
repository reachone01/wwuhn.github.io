/*

һ���򵥵ĵ��Ӵʵ䡣

�������ļ�dictionary.txt�У��������Ӣ�����յ�һ���ʵ䣬�ʻ�����8000����
Ӣ�ġ�������������Լ��á�\t����������һ����ʾ��������Words��Words���һ�������������һ���ʣ�
�����������Դ洢�ʿ⡣���ļ��е����ݶ������������У����û�����Ӣ�Ĵʣ���ʾ�������塣

������ʾ���ļ��еĴʻ��Ѿ����򣬹��ڲ���ʱ���ö��ֲ��ҷ����Ч�ʡ�

������չ1�������û����г���������ز�ʵ䣬ֱ�����롱0000��������

������չ2��������һ�����ڰ�ĵ��Ӵʵ䡣

������չ3��ʹ����ʵ䣬����һƪ���£�������е��������ʣ��򶯴ʣ���ȫ��ʵ�ʣ��������������������ƵĹ��ܣ����������дʶ�ֵ��������

  */


#if 0

#include <fstream>
#include<iostream>
#include<string>
using namespace std;

//�������
class Word
{
public:
    void set(string e, string c, string wc);
    int compare(string);  //Ӣ�ﲿ��������ַ����Ƚϣ����ڷ��أ����ڷ��أ�С�ڷ���-1
    void display();
private:
    string english;
    string chinese;
    string word_class;
};

void Word::set(string e, string c, string wc)
{
    english=e;
    chinese=c;
    word_class=wc;
}

void Word::display()
{
    cout<<english<<'\t'<<word_class<<'\t'<<chinese<<endl<<endl;
}

int Word::compare(string k)
{
    return english.compare(k);
}

int BinSeareh(int low, int high, Word *w, string k);

int main( )
{
    Word words[8000]; //���ڱ���ʿ�
    string e,c,wc;    
    string key;      //��ѯ�ؼ���
    int wordsNum=0;  //�ʿ��д���
    
    //���ļ��е����ݶ��뵽����������
    ifstream infile("dictionary.txt",ios::in);  //������ķ�ʽ���ļ�
    if(!infile)       //�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile>>e>>c>>wc;
        words[wordsNum].set(e, c, wc);
        ++wordsNum;
    }
    
    //�������ؼ��ʲ��ö��ֲ��ҷ����в�ѯ
    do
    {
        cout<<"���������ѯ�Ĺؼ��ʣ�Ӣ�ģ���"<<endl;
        cin>>key;
        if (key!="0000")
        {
            int low=0,high=wordsNum-1;  //�õ�ǰ���������ϡ��½�ĳ�ֵ
            int index=BinSeareh(low, high, words, key);
            if (index == -1)
                cout<<"���޴˴ʣ�"<<endl<<endl;
            else
                words[index].display();
        }
    }
    while(key!="0000");
    cout<<"��ӭ�ٴ�ʹ�ã�"<<endl<<endl;
    system("pause");
    return 0;
}

int BinSeareh(int low, int high, Word *w, string k)
{
    int mid;
    while(low<=high)
    { 
        mid=(low + high) / 2;
        if(w[mid].compare(k)==0)
        {
            return mid; //���ҳɹ�����
        }
        if(w[mid].compare(k)>0)
            high=mid-1; //������w[low..mid-1]�в���
        else
            low=mid+1; //������w[mid+1..high]�в���
    }
    return -1; //��low>highʱ��ʾ��������Ϊ�գ�����ʧ��
}

#else

#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Word
{
public:
	void get_cixing(string cixing);
	void get_chinese(string english);
	void get_english(string chinese);
	friend void find_word(Word *t,string word);
	friend void input_word(Word *t);
	friend void output_word(Word *t);
 
private:
	string cixing;
	string english;
	string chinese;
};
void Word::get_cixing(string cixing)
{
	this->cixing = cixing;
}
void Word::get_chinese(string english)
{
	this->english = english;
}
void Word::get_english(string chinese)
{
	this->chinese = chinese;
}
void input_word(Word *t)
{
	string cixing;
	string english;
	string chinese;
	int i;
	ifstream inFile("dictionary.txt",ios::in);
	if(!inFile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<8000;++i)
	{
		inFile>>chinese;
		t[i].get_chinese(chinese);
 
		inFile>>cixing;
		t[i].get_cixing(cixing);
 
		inFile>>english;
		t[i].get_english(english);
	}	
 
	inFile.close();
 
}
void output_word(Word *t)
{
	string cixing;
	string english;
	string chinese;
	ofstream outFile("dic.txt",ios::out);
	if(!outFile)
	{
		cerr<<"open dic.txt error!"<<endl;
		exit(1);
	}
	for(int i=0;i<8000;++i)
	{
		outFile<<t[i].chinese;
 
		outFile<<t[i].english;
 
		outFile<<t[i].cixing;
	}		
	outFile.close();
 
}
 
void find_word(Word *t,string word)
{	
	int  f=0;
	int  s=7999;
	int mid=(f+s)/2;
 
 
	while(f<s&&t[mid].english!=word)
	{
		if(t[mid].english<word) f=mid+1;
		if(t[mid].english>word) s=mid-1;
		mid=f+(s-f)/2;
		if(t[mid].english==word)
		{
			cout<<t[mid].chinese<<endl;
			cout<<t[mid].cixing<<endl;
		}	
 
	}
	if(t[mid].english!=word)
		cout<<"û�в鵽"<<endl;
}
int main()
{
	Word t[8000];
	input_word(t);
	string word;
	do{
		cin>>word;
		find_word(t,word);
	}while(word!="0000");
	output_word(t);
	system("pause");
	return 0;
}


#endif