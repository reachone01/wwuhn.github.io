#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int MaxVnum=100;  // ���������ֵ
int indegree[MaxVnum];  // �������
int ve[MaxVnum];        // �¼�vi�����緢��ʱ��
int vl[MaxVnum];        // �¼�vi����ٷ���ʱ��

typedef string VexType;   // �������������Ϊ�ַ���
typedef struct AdjNode{   // �����ڽӵ�����
    int v;                // �ڽӵ��±�
    int weight;           // Ȩֵ
    struct AdjNode *next; // ָ����һ���ڽӵ�ָ��
}AdjNode;

typedef struct VexNode{   // ���嶥������
    VexType data;         // VexTypeΪ������������ͣ�������Ҫ����
    AdjNode *first;       // ָ���һ���ڽӵ�ָ��
}VexNode;

typedef struct{                   // �����ڽӱ�����ڽӱ�
    VexNode Vex[MaxVnum];         // �����ڽӱ�
    VexNode converse_Vex[MaxVnum];// �������ڽӱ�
    int vexnum,edgenum;           // ������������
}ALGragh;

int locatevex(ALGragh G,VexType x)
{
    for(int i=0;i<G.vexnum;i++)// ���Ҷ�����Ϣ���±�
        if(x==G.Vex[i].data)
            return i;
    return -1;                 // û�ҵ�
}

void insertedge(ALGragh &G,int i,int j,int w) // ����һ����
{
    AdjNode *s1,*s2;
    // �����ڽӱ���
    s1=new AdjNode;
    s1->v=j;
    s1->weight=w;
    s1->next=G.Vex[i].first;
    G.Vex[i].first=s1;
    // �������ڽӱ���
    s2=new AdjNode;
    s2->v=i;
    s2->weight=w;
    s2->next=G.converse_Vex[j].first;
    G.converse_Vex[j].first=s2;
}

void printg(ALGragh G) // ����ڽӱ�
{
   cout<<"----------�ڽӱ����£�----------"<<endl;
   for(int i=0;i<G.vexnum;i++)
   {
       AdjNode *t=G.Vex[i].first;
       cout<<G.Vex[i].data<<"��  ";
       while(t!=NULL)
       {
           cout<<"["<<t->v<<" "<<t->weight<<"]     ";
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
           cout<<"["<<t->v<<" "<<t->weight<<"]     ";
           t=t->next;
       }
       cout<<endl;
   }
}

void CreateALGraph(ALGragh &G) // ��������ͼ���ڽӱ�����ڽӱ�
{
    int i,j,w;
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
    cout<<"����������ÿ���ߵ��������㼰Ȩֵu,v,w"<<endl;
    while(G.edgenum--)
    {
        cin>>u>>v>>w;
        i=locatevex(G,u);// ���Ҷ���u�Ĵ洢�±�
        j=locatevex(G,v);// ���Ҷ���v�Ĵ洢�±�
        if(i!=-1&&j!=-1)
            insertedge(G,i,j,w);
        else
        {
           cout<<"���붥����Ϣ�����������룡"<<endl;
           G.edgenum++;//�������벻��
        }
    }
}

void FindInDegree(ALGragh G) // ������������ȴ�������indegree��
{
    int i,count;
    for(i=0;i<G.vexnum; i++)
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
    for(int i=0;i<G.vexnum;i++) // ����������
       cout<<indegree[i]<<"\t";
    cout<<endl;
}

bool TopologicalSort(ALGragh G, int topo[]) // ��������
{
    // ����ͼG�����ڽӱ�洢�ṹ
    // ��G�޻�·��������G��һ����������topo[]������true������false
    int i,m;
    stack<int>S;        // ��ʼ��һ��ջS����Ҫ����ͷ�ļ�#include<stack>
    FindInDegree(G);    // ������������ȴ�������indegree[]��
    for(i=0;i<G.vexnum;i++)
        if(!indegree[i])// ���Ϊ0�߽�ջ
            S.push(i);
    m=0;                // ����������������ʼΪ0
    while(!S.empty())   // ջS�ǿ�
    {
        i=S.top();    // ȡջ������i
        S.pop();      // ջ������i��ջ
        topo[m]=i;    // ��i������������������topo��
        m++;          // ������������
        AdjNode *p=G.Vex[i].first;  // pָ��i�ĵ�һ���ڽӵ�
        while(p)                    // i�������ڽӵ���ȼ�1
        {
            int k=p->v;             // kΪi���ڽӵ�
            --indegree[k];          // i��ÿ���ڽӵ����ȼ�1
            if(indegree[k]==0)      // ����ȼ�Ϊ0������ջ
              S.push(k);
            p=p->next;              // pָ�򶥵�i��һ���ڽӽ��
        }
        printg(G);
    }
    if(m<G.vexnum)                  // ������ͼ�л�·
        return false;
    else
        return true;
}

bool CriticalPath(ALGragh G,int topo[])// GΪ�ڽӱ�洢�������������G�ĸ���ؼ��
{
    int n,i,k,j,e,l;
    if(TopologicalSort(G,topo))
    {
        cout<<"��������Ϊ��"<<endl;
        for(int i=0;i<G.vexnum;i++)   // �����������
            cout<<topo[i]<<"\t";
        cout<<endl;
    }
    else
        cout<<"��ͼ�л������������У�"<<endl;
    n=G.vexnum;                       // nΪ�������
    for(i=0;i<n;i++)                  // ��ÿ���¼������緢��ʱ���ó�ֵ0
        ve[i]=0;
    // �����˴�����ÿ���¼������緢��ʱ��
    printg(G);
    for(i=0;i<n; i++)
    {
        k=topo[i];                    // ȡ�����������еĶ������k
        AdjNode *p=G.Vex[k].first;    // pָ��k�ĵ�һ���ڽӶ���
        while(p!=NULL)
        {                             // ���θ���k�������ڽӶ�������緢��ʱ��
            j=p->v;                   // jΪ�ڽӶ�������
            if(ve[j]<ve[k]+p->weight) // ���¶���j�����緢��ʱ��ve[j]
                ve[j]=ve[k]+p->weight;
            p=p->next;                // pָ��k����һ���ڽӶ���
        }
    }
    for(i=0;i<n;i++)                  // ��ÿ���¼�����ٷ���ʱ���ó�ֵve[n-1]
        vl[i]=ve[n-1];
    // �������˴�����ÿ���¼�����ٷ���ʱ��
    for(i=n-1;i>=0;i--)
    {
        k=topo[i];                    // ȡ�������������еĶ������k
        AdjNode *p=G.Vex[k].first;    // pָ��k�ĵ�һ���ڽӶ���
        while(p!=NULL)
        {                             // ����k���ڽӵ㣬����k����ٷ���ʱ��
            j=p->v;                   // jΪ�ڽӶ�������
            if(vl[k]>vl[j]-p->weight) // ���¶���k����ٷ���ʱ��vl[k]
                vl[k]=vl[j]-p->weight;
            p=p->next;                // pָ��k����һ���ڽӶ���
        }
    }
    cout<<"�¼������緢��ʱ�����ٷ���ʱ�䣺"<<endl;
    for(int i=0;i<n;i++)
       cout<<ve[i]<<"\t"<<vl[i]<<endl;

    // �ж�ÿһ��Ƿ�Ϊ�ؼ��
    cout<<"�ؼ��·��Ȩֵ֮��Ϊ:"<<vl[n-1]<<endl; 
    cout<<endl;
    cout<<"�ؼ��·��Ϊ:";
    for(i=0;i<n; i++)              // ÿ��ѭ�����viΪ���ʼ������л
    {
        AdjNode *p=G.Vex[i].first; // pָ��i�ĵ�һ���ڽӶ���
        while(p!=NULL)
        {
            j=p->v;                // jΪi���ڽӶ�������
            e=ve[i];               // ����<vi,vj>�����翪ʼʱ��e
            l=vl[j]-p->weight;     // ����<vi,vj>����ٿ�ʼʱ��l
            if(e==l)               // ��Ϊ�ؼ���������<vi, vj>
                cout<<"<"<<G.Vex[i].data<<","<<G.Vex[j].data<<">    ";
            p=p->next;             // pָ��i����һ���ڽӶ���
        }
    }
    return true;
}

int main()
{
    ALGragh G;
    int *topo=new int[G.vexnum];
    CreateALGraph(G);// ��������ͼ���ڽӱ�����ڽӱ�
    printg(G);       // ����ڽӱ�����ڽӱ�
    CriticalPath(G,topo);
    return 0;
}