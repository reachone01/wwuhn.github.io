/*
����ͨͼ�ı���
*/
#if 1


#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];     //�����Žڵ�ķ��ʱ�־��ȫ������
void DFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w;
    visited[v]=1;
    printf("%d ", v);
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        w=p->adjvex;
        if (visited[w]==0)
            DFS(G,w);
        p=p->nextarc;
    }
}

//�����������������������ͨ����ͼ
void DFS1(ALGraph *G)
{
    int i;
    for (i=0; i<G->n; i++)
        if (visited[i]==0)
            DFS(G,i);
}

int main()
{
    int i;
    ALGraph *G;
    int A[8][8]=
    {
        {0,1,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,0},
        {0,1,0,1,1,0,0,0},
        {1,0,1,0,1,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0},
    };
    /*
        1
     /     \
    2 - 3 - 0
     \  |
       4

       5
      / \
     6 - 7
    */
    ArrayToList(A[0], 8, G);
    for (i=0; i<G->n; i++)
        visited[i]=0; //���ʱ�־�����ʼ��
    printf(" ����ͨͼ�Ĺ�����ȱ���:\n");
    DFS1(G);
    printf("\nend\n");
    while(1);
    return 0;
}




#endif

#if 0

#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];     //�����Žڵ�ķ��ʱ�־��ȫ������
void BFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w;
    int queue[MAXV],front=0,rear=0; //����ѭ������
    printf("%2d",v);                //��������ʶ���ı��
    visited[v]=1;                   //���ѷ��ʱ��
    rear=(rear+1)%MAXV;
    queue[rear]=v;                  //v����
    while (front!=rear)             //�����в���ʱѭ��
    {
        front=(front+1)%MAXV;
        w=queue[front];             //���Ӳ�����w
        p=G->adjlist[w].firstarc;   //��w�ĵ�һ�����ڽӵ�
        while (p!=NULL)
        {
            if (visited[p->adjvex]==0)
            {
                printf("%2d",p->adjvex); //����֮
                visited[p->adjvex]=1;
                rear=(rear+1)%MAXV;     //�ö������
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;               //����һ���ڽӶ���
        }
    }
    printf("\n");
}

//���ù������������������ͨ����ͼ
void BFS1(ALGraph *G)
{
   int i;
   for (i=0;i<G->n;i++)
      if (visited[i]==0)
           BFS(G,i);
}

int main()
{
    int i;
    ALGraph *G;
    int A[8][8]=
    {
        {0,1,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,0},
        {0,1,0,1,1,0,0,0},
        {1,0,1,0,1,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0},
    };
    ArrayToList(A[0], 8, G);
    for (i=0; i<G->n; i++)
        visited[i]=0; //���ʱ�־�����ʼ��
    printf(" ����ͨͼ�Ĺ�����ȱ���:\n");
    BFS1(G);
    printf("\nend\n");
    while(1)
    return 0;
}
#endif

#if 0
// �жϷ���ͨͼ
#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];     //�����Žڵ�ķ��ʱ�־��ȫ������
void DFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w;
    visited[v]=1;  //�˴����˱�Ǽ�����˷��ʣ������¾�����
    //printf("%d ", v);
    p=G->adjlist[v].firstarc;
    while (p!=NULL)
    {
        w=p->adjvex;
        if (visited[w]==0)
            DFS(G,w);
        p=p->nextarc;
    }
}

//����ͨͼ����true�����򷵻�false
bool Connect(ALGraph *G)
{
    int i;
    bool flag=true;
    for (i=0; i<G->n; i++)
        visited[i]=0;
    DFS(G,0);
    for (i=0; i<G->n; i++)
        if (visited[i]==0)
        {
            flag=false;
            break;
        }
    return flag;
}

int main()
{
    int i;
    ALGraph *G;
    int A[8][8]=
    {
        {0,1,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,0},
        {0,1,0,1,1,0,0,0},
        {1,0,1,0,1,0,0,0},
        {0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0},
    };
    ArrayToList(A[0], 8, G);
    for (i=0; i<G->n; i++)
        visited[i]=0; //���ʱ�־�����ʼ��
    if(Connect(G))
        printf(" G����ͨͼ\n");
    else
        printf(" G������ͨͼ\n");
    printf("\nend\n");
    while(1)
    return 0;
}
#endif
/*

*/