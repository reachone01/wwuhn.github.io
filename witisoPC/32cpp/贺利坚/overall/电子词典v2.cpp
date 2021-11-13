#include <fstream>
#include<iostream> // ���Ӵʵ�v2
#include<string>
#include<cstdlib>
using namespace std;

//
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
    cout<<'\n'<<english<<'\t'<<word_class<<'\t'<<chinese<<endl<<endl;
}

int Word::compare(string k)
{
    return english.compare(k);
}

int BinSeareh(int low, int high, Word *w, string k);

int main( )
{
    Word words[800]; //���ڱ���ʿ�
    string e,c,wc;
    string key;      //��ѯ�ؼ���
    int wordsNum=0;  //�ʿ��д���
    
    //���ļ��е����ݶ��뵽����������
    ifstream infile("dict.txt",ios::in);  //������ķ�ʽ���ļ�
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
    for(int i=0;i<wordsNum;i++)
    {
        words[i].display();
    }
    //�������ؼ��ʲ��ö��ֲ��ҷ����в�ѯ
    do
    {
        cout<<"��ʾ���ļ���Ҫ����һ�������ַ������Կո�ָ���������Excel����һ�¡�\n"<<endl;
        cout<<"���������ѯ�Ĺؼ��ʣ�Ӣ�ģ�,0000������"<<endl;
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