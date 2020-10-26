#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int MaxVnum=100;// ���������ֵ
int indegree[MaxVnum];// �������

typedef string VexType;   // �������������Ϊ�ַ���
typedef struct AdjNode{   // �����ڽӵ�����
    int v;                // �ڽӵ��±�
    struct AdjNode *next; // ָ����һ���ڽӵ�
}AdjNode;

typedef struct VexNode{ // ���嶥������
    VexType data;       // VexTypeΪ������������ͣ�������Ҫ����
    AdjNode *first;     // ָ���һ���ڽӵ�
}VexNode;

typedef struct{           // �����ڽӱ�����ڽӱ�
    VexNode Vex[MaxVnum]; // �����ڽӱ�
    VexNode converse_Vex[MaxVnum]; // �������ڽӱ�
    int vexnum,edgenum;   // ������������
}ALGragh;

int locatevex(ALGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)// ���Ҷ�����Ϣ���±�
        if(x==G.Vex[i].data)
            return i;
    return -1;                 // û�ҵ�
}

void insertedge(ALGragh &G,int i,int j)// ����һ����
{
    AdjNode *s1,*s2;
    s1=new AdjNode;    // �����ڽӱ���
    s1->v=j;
    s1->next=G.Vex[i].first;
    G.Vex[i].first=s1;
    s2=new AdjNode;    // �������ڽӱ���
    s2->v=i;
    s2->next=G.converse_Vex[j].first;
    G.converse_Vex[j].first=s2;
}

void printg(ALGragh G)  // ����ڽӱ�
{
   cout<<"----------�ڽӱ����£�----------"<<endl;
   for(int i=0;i<G.vexnum;i++)
   {
       AdjNode *t=G.Vex[i].first;
       cout<<G.Vex[i].data<<"��  ";
       while(t!=NULL)
       {
           cout<<"["<<t->v<<"]  ";
           t=t->next;
       }
       cout<<endl;
   }
   cout<<"----------���ڽӱ����£�----------"<<endl;
   for(int i=0;i<G.vexnum;i++)
   {
       AdjNode *t=G.converse_Vex[i].first;
       cout<<G.converse_Vex[i].data<<"��  ";
       while(t!=NULL)
       {
           cout<<"["<<t->v<<"]  ";
           t=t->next;
       }
       cout<<endl;
   }
}

void CreateALGraph(ALGragh &G)//��������ͼ���ڽӱ�����ڽӱ�
{
    int i,j;
    VexType u,v;
    cout<<"�����붥�����ͱ���:"<<endl;
    cin>>G.vexnum>>G.edgenum;
    cout<<"�����붥����Ϣ:"<<endl;
    for(i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
    {
        cin>>G.Vex[i].data;
        G.converse_Vex[i].data=G.Vex[i].data;
        G.Vex[i].first=NULL;
        G.converse_Vex[i].first=NULL;
    }
    cout<<"����������ÿ���ߵ���������u,v"<<endl;
    while(G.edgenum--)
    {
        cin>>u>>v;
        i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
        j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
        if(i!=-1&&j!=-1)
            insertedge(G,i,j);
        else
        {
           cout<<"���붥����Ϣ�����������룡"<<endl;
           G.edgenum++;//�������벻��
        }
    }
}

void FindInDegree(ALGragh G)//������������ȴ�������indegree��
{
    int i,count;
    for(i=0;i<G.vexnum;i++)
    {
        count=0;
        AdjNode *p=G.converse_Vex[i].first;
        if(p)
        {
            while(p)
            {
                p=p->next;
                count++;
            }
        }
        indegree[i]=count;
    }
    cout<<"�������Ϊ��"<<endl;
    for(int i=0;i<G.vexnum;i++)//����������
       cout<<indegree[i]<<"\t";
    cout<<endl;
}

bool TopologicalSort(ALGragh G, int topo[])//��������
{
    // ����ͼG�����ڽӱ�洢�ṹ
    // ��G�޻�·��������G��һ����������topo[]������true������false
    int i,m;
    stack<int>S;        // ��ʼ��һ��ջS����Ҫ����ͷ�ļ�#include<stack>
    FindInDegree(G);    // ������������ȴ�������indegree[]��
    for(i=0;i<G.vexnum;i++)
        if(!indegree[i])// ���Ϊ0�߽�ջ
            S.push(i);
    m=0;              // ����������������ʼΪ0
    while(!S.empty()) // ջS�ǿ�
    {
        i=S.top();    // ȡջ������i
        S.pop();      // ջ������i��ջ
        topo[m]=i;    // ��i������������������topo��
        m++;          // ������������
        AdjNode *p=G.Vex[i].first;  // pָ��i�ĵ�һ���ڽӵ�
        while(p)               // i�������ڽӵ���ȼ�1
        {
            int k=p->v;        // kΪi���ڽӵ�
            --indegree[k];     //i��ÿ���ڽӵ����ȼ�1
            if(indegree[k]==0) //����ȼ�Ϊ0������ջ
                S.push(k);
            p=p->next;         // pָ�򶥵�i��һ���ڽӽ��
        }
    }
    if(m<G.vexnum)             // ������ͼ�л�·
        return false;
    else
        return true;
}

int main()
{
    ALGragh G;
    int *topo=new int[G.vexnum];
    CreateALGraph(G); // ��������ͼ���ڽӱ�����ڽӱ�
    printg(G);        // ����ڽӱ�����ڽӱ�
    if(TopologicalSort(G,topo))
    {
        cout<<"��������Ϊ��"<<endl;
        for(int i=0;i<G.vexnum;i++)// �����������
            cout<<topo[i]<<"\t";
    }
    else
        cout<<"��ͼ�л������������У�"<<endl;
    return 0;
}