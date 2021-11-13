#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

//���������
class Word
{
public:
    void set(string e, string c, string wc);
    int compare(string);  //Ӣ�ﲿ��������ַ����Ƚϣ����ڷ��أ����ڷ��أ�С�ڷ���-1
    string getChinese();
    string getWord_class();
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

int Word::compare(string k)
{
    return english.compare(k);
}

string Word::getChinese()
{
    return chinese;
}

string Word::getWord_class()
{
    return word_class;
}

//�����ֵ���
class Dictionary
{
public:
    Dictionary();
    void searchWord(string k);
private:
    int BinSeareh(int low, int high, string k);
    int wordsNum;
    Word words[8000]; //���ڱ���ʿ�
};

Dictionary::Dictionary()
{
    string e,c,wc;
    wordsNum=0;
    //���ļ��е����ݶ��뵽����������
    ifstream infile("dictionary1.txt",ios::in);  //������ķ�ʽ���ļ�
    if(!infile)       //�����Ƿ�ɹ���
    {
        cerr<<"dictionary open error!"<<endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile>>e>>c>>wc;
        words[wordsNum].set(e, c, wc);
        ++wordsNum;
    }
    infile.close();
}

int Dictionary::BinSeareh(int low, int high, string key)
{
    int mid;
    while(low<=high)
    {
        mid=(low + high) / 2;
        if(words[mid].compare(key)==0)
        {
            return mid; //���ҳɹ�����
        }
        if(words[mid].compare(key)>0)
            high=mid-1; //������w[low..mid-1]�в���
        else
            low=mid+1; //������w[mid+1..high]�в���
    }
    return -1; //��low>highʱ��ʾ��������Ϊ�գ�����ʧ��
}

void Dictionary::searchWord(string key)
{
    int low=0,high=wordsNum-1;  //�õ�ǰ���������ϡ��½�ĳ�ֵ
    int index=BinSeareh(low, high, key);
    if(index>=0)
        cout<<key<<"--->"<<words[index].getWord_class()+"\t"<<words[index].getChinese();
    else
        cout<<"���޴˴�";
    cout<<endl<<endl;
}

int main( )
{
    Dictionary dict;
    string key;
    
    do
    {
        cout<<"���������ѯ�Ĺؼ��ʣ�Ӣ�ģ�,0000������"<<endl;
        cin>>key;
        if (key!="0000")
        {
            dict.searchWord(key);
        }
    }
    while(key!="0000");
    cout<<"��ӭ�ٴ�ʹ�ã�"<<endl<<endl;
    while(1);
    return 0;
}