// �������ڽӱ�洢��ͼ

#include <stdio.h>
#include <malloc.h>
#include "graph.h"

//����ͼG�б��Ϊv�Ķ���ĳ���
int OutDegree(ALGraph *G,int v)
{
    ArcNode *p;
    int n=0;
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        n++;
        p=p->nextarc;
    }
    return n;
}

//���ͼG��ÿ������ĳ���
void OutDs(ALGraph *G)
{
    int i;
    for (i=0; i<G->n; i++)
        printf("  ����%d:%d\n",i,OutDegree(G,i));
}

//���ͼG�г�������һ������
void OutMaxDs(ALGraph *G)
{
    int maxv=0,maxds=0,i,x;
    for (i=0; i<G->n; i++)
    {
        x=OutDegree(G,i);
        if (x>maxds)
        {
            maxds=x;
            maxv=i;
        }
    }
    printf("����%d������=%d\n",maxv,maxds);
}
//���ͼG�г���Ϊ0�Ķ�����
void ZeroDs(ALGraph *G)
{
    int i,x;
    for (i=0; i<G->n; i++)
    {
        x=OutDegree(G,i);
        if (x==0)
            printf("%2d",i);
    }
    printf("\n");
}

//����ͼG���Ƿ���ڱ�<i,j>
bool Arc(ALGraph *G, int i,int j)
{
    ArcNode *p;
    bool found = false;
    p=G->adjlist[i].firstarc;
    while (p!=NULL)
    {
        if(p->adjvex==j)
        {
            found = true;
            break;
        }
        p=p->nextarc;
    }
    return found;
}

int main()
{
    ALGraph *G;
    int A[7][7]=
    {
        {0,1,1,1,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0},
        {0,0,0,1,1,0,1},
        {0,1,0,0,0,0,0}
    };
    ArrayToList(A[0], 7, G);
    printf("(1)���������:\n");
    OutDs(G);
    printf("(2)�����ȵĶ�����Ϣ:");
    OutMaxDs(G);
    printf("(3)����Ϊ0�Ķ���:");
    ZeroDs(G);
    printf("(4)��<2,6>������");
    if(Arc(G,2,6))
        printf("��\n");
    else
        printf("��\n");
    printf("\n");
    return 0;
}

// https://helijian.blog.csdn.net/article/details/49717317