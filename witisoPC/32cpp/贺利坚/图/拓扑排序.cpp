#include <stdio.h>
#include <malloc.h>
#include "graph.h"

void TopSort(ALGraph *G)
{
    int i,j;
    int St[MAXV],top=-1;            //ջSt��ָ��Ϊtop
    ArcNode *p;
    for (i=0; i<G->n; i++)          //����ó�ֵ0
        G->adjlist[i].count=0;
    for (i=0; i<G->n; i++)          //�����ж�������
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            G->adjlist[p->adjvex].count++;
            p=p->nextarc;
        }
    }
    for (i=0; i<G->n; i++)
        if (G->adjlist[i].count==0)  //���Ϊ0�Ķ����ջ
        {
            top++;
            St[top]=i;
        }
    while (top>-1)                  //ջ��Ϊ��ʱѭ��
    {
        i=St[top];
        top--;              //��ջ
        printf("%d ",i);            //�������
        p=G->adjlist[i].firstarc;   //�ҵ�һ�����ڶ���
        while (p!=NULL)
        {
            j=p->adjvex;
            G->adjlist[j].count--;
            if (G->adjlist[j].count==0)//���Ϊ0�����ڶ����ջ
            {
                top++;
                St[top]=j;
            }
            p=p->nextarc;       //����һ�����ڶ���
        }
    }
}

int main()
{
    ALGraph *G;
    int A[7][7]=
    {
        {0,0,1,0,0,0,0},
        {0,0,0,1,1,0,1},
        {0,0,0,1,0,0,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0}
    };
    ArrayToList(A[0], 7, G);
    DispAdj(G);
    printf("\n");
    printf("��������:");
    TopSort(G);
    printf("\n");
    return 0;
}

// https://helijian.blog.csdn.net/article/details/49847159