/*

*/
#if 1

#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[MAXV];
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

int main()
{
    int i;
    ALGraph *G;
    int A[5][5]=
    {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0}
    };
    /*
        1
     /     \
    2 - 3 - 0
     \  |
       4
    */
    ArrayToList(A[0], 5, G);

    for(i=0; i<MAXV; i++) visited[i]=0;
    printf(" ��2��ʼ��ȱ���:");
    DFS(G, 2);
    printf("\n");

    for(i=0; i<MAXV; i++) visited[i]=0;
    printf(" ��0��ʼ��ȱ���:");
    DFS(G, 0);
    printf("\nend\n");
    while(1);
    return 0;
}
/*
 ��2��ʼ��ȱ���:2 1 0 3 4
 ��0��ʼ��ȱ���:0 1 2 3 4
end

*/
#else

#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void BFS(ALGraph *G, int v)
{
    ArcNode *p;
    int w,i;
    int queue[MAXV],front=0,rear=0;     //����ѭ������
    int visited[MAXV];                  //�����Žڵ�ķ��ʱ�־������
    for (i=0; i<G->n; i++) visited[i]=0;//���ʱ�־�����ʼ��
    printf("%2d",v);                    //��������ʶ���ı��
    visited[v]=1;                       //���ѷ��ʱ��
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


int main()
{
    ALGraph *G;
    int A[5][5]=
    {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,0,1,1,0}
    };
    ArrayToList(A[0], 5, G);

    printf(" ��2��ʼ��ȱ���:");
    BFS(G, 2);

    printf(" ��0��ʼ��ȱ���:");
    BFS(G, 0);
    printf("\nend\n");
    while(1);
    return 0;
}


#endif

#if 0


#endif
/*

*/