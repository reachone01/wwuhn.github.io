#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define MAXV 100                //��󶥵����
#define INF 32767               //INF��ʾ��
typedef int InfoType;

//���¶����ڽӾ�������
typedef struct
{
    int no;                     //������
    InfoType info;              //����������Ϣ���ڴ˴�Ŵ�ȨͼȨֵ
} VertexType;                   //��������

typedef struct                  //ͼ�Ķ���
{
    int edges[MAXV][MAXV];      //�ڽӾ���
    int n,e;                    //������������
    VertexType vexs[MAXV];      //��Ŷ�����Ϣ
} MGraph;                       //ͼ���ڽӾ�������Matrix

//���¶����ڽӱ�����
typedef struct ANode            //���Ľ��ṹ����
{
    int adjvex;                 //�û����յ�λ��
    struct ANode *nextarc;      //ָ����һ������ָ��
    InfoType info;              //�û��������Ϣ,�������ڴ��Ȩֵ
} ArcNode;

typedef int Vertex;

typedef struct Vnode            //�ڽӱ�ͷ��������
{
    Vertex data;                //������Ϣ
    int count;                  //��Ŷ������,ֻ��������������
    ArcNode *firstarc;          //ָ���һ����
} VNode;

typedef VNode AdjList[MAXV];    //AdjList���ڽӱ�����adjacent list

typedef struct
{
    AdjList adjlist;            //�ڽӱ�
    int n,e;                    //ͼ�ж�����n�ͱ���e
} ALGraph;                      //ͼ���ڽӱ�����adjacent list

//���ܣ���һ����ӳͼ�ж����ڽӹ�ϵ�Ķ�ά���飬��������ڽӾ���洢��ͼ
//������Arr - ��������������ʽ����Ϊ��ά����ʱ�������ÿ�е�Ԫ�ظ�����
     // �ڴ˽�����Arr����Ϊһά��������ָ��int��ָ�룩
//      n - ����Ľ���
//      g - Ҫ����������ڽӾ������ݽṹ
void ArrayToMat(int *Arr, int n, MGraph &g);    //����ͨ���鹹��ͼ���ڽӾ���Matrix
void ArrayToList(int *Arr, int n, ALGraph *&);  //����ͨ���鹹��ͼ���ڽӱ�adjacent list
void MatToList(MGraph g,ALGraph *&G);   //���ڽӾ���gת�����ڽӱ�G
void ListToMat(ALGraph *G,MGraph &g);   //���ڽӱ�Gת�����ڽӾ���g
void DispMat(MGraph g);     //����ڽӾ���g
void DispAdj(ALGraph *G);   //����ڽӱ�G

#endif // GRAPH_H_INCLUDED