/*   ���ļ�������̬����
����Ĺؼ������������ƶ���������ӣ�ͨ��headָ�뱣�ֲ�������ʱָ�벻�ϵ��������£��������ƶ�
β�壺  ��Ҫ����ָ��ڵ��ָ�룺head, pNew, pMove��ָ������ֵ����ʾָ����ƶ�����
        head = pNew; pMove = pNew;
        ָ��ڵ��ָ��ĳ�Աָ��next����ֵʱ��ʾ���ӣ���
        pMove->next = pNew;
������  ��Ҫ����ָ�룺head, pMove
        �ƶ���pMove = pMove->next;
ɾ����  ��Ҫ4��ָ�룺head, pRear, pFront, pPend
        pPend = pFront; // ��ɾ��ָ����ݴ�
        pFront = pFront->next; // ��
        pRear->next = pFront;  // ��
        û��ɾ��ʱ������ָ�붼�ƶ�
        pRear = pFront; // pRear = pRear->next  //���ƶ�β��ָ��
        pFront = pFront->next;
        


*/
#if 0

#include  <iostream>
#include  <fstream>
#include <cstdlib>  //��codeblocks�£�exit(1)��Ҫ���ͷ�ļ�
using namespace std;
struct Student
{
    char num[13]; //���ܶ��������ֹ��ɣ�������Ϊ�ַ������ʡ�
    char name[10]; //ÿ������ռ�����ֽڣ��й��˵����֣�5�����ֹ���
    int cpp;
    int math;
    int english;
    int grade;
    struct Student *next;   //ָ����һ�ڵ��ָ��
};

int main( )
{
    Student *head=NULL,*newNode,*pMove;
    int stuNum=0,i;
    int sum=0,ave;   //������ƽ��
    ifstream infile("score.txt",ios::in); 	//������ķ�ʽ���ļ�
    if(!infile)   				//�����Ƿ�ɹ���
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    //������ļ��ж�ȡ���ݣ�ͬʱ������̬������Ϊ���ܷ�֮��
    stuNum=0;
    while(!infile.eof())
    {
        newNode = new Student;
        infile>>newNode->num>>newNode->name>>newNode->cpp>>newNode->math>>newNode->english;
        newNode->grade = newNode->cpp + newNode->math + newNode->english;
        sum+=newNode->grade;
        newNode->next=NULL;
        if (stuNum==0)
            head=newNode;   //�ǵ�һ���ڵ�
        else
            pMove->next=newNode;   //��q��¼�ող����Ľ�㣬�������һ������Ҫq��֮������
        ++stuNum;
        pMove=newNode;
    }
    infile.close();
    
    //��ƽ���ɼ�
    ave=sum/stuNum;
    cout<<"�ܷ�ƽ��Ϊ��"<<ave<<endl;
    
    //������������ָܷ���ƽ���ܷ���û�йҿƵ�ͬѧ��ѧ�š��������ܷ֡�
    cout<<"�ָܷ���ƽ���ܷ���û�йҿƵ�ͬѧ�У�"<<endl;
    pMove=head;
    i=1;
    while(pMove!=NULL)
    {
        if(pMove->grade>=ave&&pMove->cpp>=60&&pMove->math>=60&&pMove->english>=60)
        {
            cout<<i<<" "<<pMove->num<<" "<<pMove->name<<" "<<pMove->grade<<endl;
            i++;
        }
        pMove=pMove->next;
    }
    cout<<i<<endl;
    while(1);
    return 0;
}

#else

//���������һλ���Ķ����ṩ�Ĵ�������������޸ġ�
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
struct node
{
    char num[15];
    char name[10];
    int cpp;
    int math;
    int english;
    int score;
    node* pnext;
};
int main()
{
    node *head=NULL, *p,*q, *k;
    int num=0;
    float sum=0,ave;
    ifstream readfile("score.txt",ios::in);
    if(!readfile)
    {
        cerr<<"the score.txt can't be read!"<<endl;
        exit(1);
    }
    while(!readfile.eof())
    {
        p=new node;
        readfile>>p->num>>p->name>>p->cpp>>p->math>>p->english;
        p->score=p->cpp+p->english+p->math;
        sum+=p->score;
        p->pnext=NULL;
        if(num==0)
            head=p;
        else
            q->pnext=p;
        num++;
        q=p;
    }
    readfile.close();
    ave=sum/num;
    cout<<"����ƽ�����ǣ�   "<<ave<<endl<<endl;
    //���ֵܷ����ܾ��ֵܷĽڵ�ɾ��
    while(head!=NULL&&head->score<ave)//���ȣ���ͷ����ɾ����ɾ����
    {
        q=head;
        head=head->pnext;
        delete(q);
    }
    //ͨ������q��pһ��һǰ����ָ�룬ɾ������Ҫɾ���Ľڵ�
    q=head;
    p=head->pnext;
    while(p!=NULL)
    {
        if(p->score < ave )    //ɾ��p
        {
            k=p;            //p��ɾ������k���ס
            p=p->pnext;     //��һ��Ҫ����ģ���pnextָ���
            q->pnext=p;     //����ܹؼ���Ҫ��ɾ����k������������������
            delete(k);      //�ͷſռ�
        }
        else  //������p��q��������
        {
            //q=p;
            q = q->pnext;
            p = p->pnext;
        }
    }
    //���ʣ��Ľ�㣬���ڹ۲���
    p=head;
    cout<<"�ָܷ���ƽ���ֵܷ�ͬѧ�У� "<<endl<<endl;
    while(p!=NULL)
    {
        cout<<setw(10)<<p->num<<setw(10)<<p->name<<setw(10)<<p->score<<endl;
        p=p->pnext;
    }
    
    while(1);
    return 0;
}


#endif

#if 0


#endif
/*

*/