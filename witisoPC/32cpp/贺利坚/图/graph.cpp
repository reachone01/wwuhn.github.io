#include <stdio.h>
#include <malloc.h>
#include "graph.h"

//���ܣ���һ����ӳͼ�ж����ڽӹ�ϵ�Ķ�ά���飬��������ڽӾ���洢��ͼ
//������Arr - ��������������ʽ����Ϊ��ά����ʱ�������ÿ�е�Ԫ�ظ������ڴ˽�����Arr����Ϊһά��������ָ��int��ָ�룩
//      n - ����Ľ���
//      g - Ҫ����������ڽӾ������ݽṹ
void ArrayToMat(int *Arr, int n, MGraph &g) //����ͨ���鹹��ͼ���ڽӾ���Matrix
{
    int i,j,count=0;  //count����ͳ�Ʊ������������з�0Ԫ�ظ���
    g.n=n;
    for (i=0; i<g.n; i++)
        for (j=0; j<g.n; j++)
        {
            g.edges[i][j]=Arr[i*n+j]; //��Arr����n��n�Ķ�ά���飬Arr[i*n+j]����Arr[i][j]������洢λ�õĹ����ڴ�Ӧ��
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
                count++;
        }
    g.e=count;
}

void ArrayToList(int *Arr, int n, ALGraph *&G)//����ͨ���鹹��ͼ���ڽӱ�adjacent list
{
    int i,j,count=0;                    //count����ͳ�Ʊ������������з�0Ԫ�ظ���
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    G->n=n;
    for (i=0; i<n; i++)                 //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
        G->adjlist[i].firstarc=NULL;
    for (i=0; i<n; i++)                 //����ڽӾ�����ÿ��Ԫ��
        for (j=n-1; j>=0; j--)
            if (Arr[i*n+j]!=0)          //����һ���ߣ���Arr����n��n�Ķ�ά���飬Arr[i*n+j]����Arr[i][j]
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));   //����һ���ڵ�*p
                p->adjvex=j;
                p->info=Arr[i*n+j];
                p->nextarc=G->adjlist[i].firstarc;      //����ͷ�巨����*p
                G->adjlist[i].firstarc=p;
            }
    G->e=count;
}

void MatToList(MGraph g, ALGraph *&G)       //���ڽӾ���gת�����ڽӱ�G
{
    int i,j;
    ArcNode *p;
    G=(ALGraph *)malloc(sizeof(ALGraph));
    for (i=0; i<g.n; i++)                   //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
        G->adjlist[i].firstarc=NULL;
    for (i=0; i<g.n; i++)                   //����ڽӾ�����ÿ��Ԫ��
        for (j=g.n-1; j>=0; j--)
            if (g.edges[i][j]!=0)           //����һ����
            {
                p=(ArcNode *)malloc(sizeof(ArcNode));   //����һ���ڵ�*p
                p->adjvex=j;
                p->info=g.edges[i][j];
                p->nextarc=G->adjlist[i].firstarc;      //����ͷ�巨����*p
                G->adjlist[i].firstarc=p;
            }
    G->n=g.n;
    G->e=g.e;
}

void ListToMat(ALGraph *G,MGraph &g) //���ڽӱ�Gת�����ڽӾ���g
{
    int i,j;
    ArcNode *p;
    g.n=G->n;               //����һ¥ͬѧ���ٱ����ĵġ�g.nδ��ֵ������ĳ�ʼ����������
    g.e=G->e;
    for (i=0; i<g.n; i++)   //�ȳ�ʼ���ڽӾ���
        for (j=0; j<g.n; j++)
            g.edges[i][j]=0;
    for (i=0; i<G->n; i++)  //�����ڽӱ�Ϊ�ڽӾ���ֵ
    {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            g.edges[i][p->adjvex]=p->info;
            p=p->nextarc;
        }
    }
}

void DispMat(MGraph g)//����ڽӾ���g
{
    int i,j;
    for (i=0; i<g.n; i++)
    {
        for (j=0; j<g.n; j++)
            if (g.edges[i][j]==INF)
                printf("%3s","��");
            else
                printf("%3d",g.edges[i][j]);
        printf("\n");
    }
}

void DispAdj(ALGraph *G) //����ڽӱ�G
{
    int i;
    ArcNode *p;
    for (i=0; i<G->n; i++)
    {
        p=G->adjlist[i].firstarc;
        printf("%3d: ",i);
        while (p!=NULL)
        {
            printf("-->%d/%d ",p->adjvex,p->info);
            p=p->nextarc;
        }
        printf("\n");
    }
}