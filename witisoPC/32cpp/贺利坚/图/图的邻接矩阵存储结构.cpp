// ͼ���ڽӾ���洢�ṹ
#include <stdio.h>
#include <malloc.h>
#define MAXV 100 /*��󶥵�����Ϊ100*/
#define LIMITLESS 9999

typedef struct
{
    int no;         //������
    char info[20];  //����������Ϣ,������Ӧ�ö���
} VertexType;       //��������

typedef struct                  //ͼ�Ķ���
{
    int edges[MAXV][MAXV];      //�ڽӾ���
    int n, e;                   //������������
    VertexType vexs[MAXV];      //��Ŷ�����Ϣ
} MGraph;

                                //����һ��ͼ���ڽӾ���洢
void CreateMGraph(MGraph *G)
{                               /*��������ͼG ���ڽӾ���洢*/
    int i,j,k,w;
    printf("�����붥�����ͱ���(�����ʽΪ:������ ����):");
    scanf("%d %d",&(G->n),&(G->e));                         /*���붥�����ͱ���*/
    printf("�����붥����Ϣ(�����ʽΪ:����� ��������):\n");
    for (i=0; i<G->n; i++)
        scanf("%d %s",&(G->vexs[i].no),G->vexs[i].info);    /*���붥����Ϣ�����������*/
    for (i=0; i<G->n; i++)                                  /*��ʼ���ڽӾ���*/
        for (j=0; j<G->n; j++)
        {
            if(i==j)
                G->edges[i][j]=0;
            else
                G->edges[i][j]=LIMITLESS;
        }
    printf("������ÿ���߶�Ӧ�������������ż�Ȩֵ(�����ʽΪ:i j w):\n");
    for (k=0; k<G->e; k++)
    {
        scanf("%d %d %d",&i,&j,&w);     /*����e ���ߣ������ڽӾ���*/
        G->edges[i][j]=w;               /*��Ϊ��Ȩͼ��ֱ��G->edges[j][i]=1;����������w*/
    }
}/*CreateMGraph*/


void DispMGraph(MGraph *G)   //��ʾһ�����ڽӾ���洢��ͼ
{
    int i,j;
    printf("������: %d������: %d\n", G->n, G->e);
    printf("%d ���������Ϣ��:\n", G->n);
    for (i=0; i<G->n; i++)                                          /*���������Ϣ*/
        printf("%5d %5d %s\n", i, G->vexs[i].no, G->vexs[i].info);
    printf("���������������:\n");
    printf("\t");
    for (j=0; j<G->n; j++)
        printf("[%d]\t", j);
    printf("\n");
    for (i=0; i<G->n; i++)
    {
        printf("[%d]\t", i);
        for (j=0; j<G->n; j++)
        {
            if(G->edges[i][j]==LIMITLESS)
                printf("��\t");
            else
                printf("%d\t", G->edges[i][j]);
        }
        printf("\n");
    }
}/*DispMGraph*/

int main()
{
    MGraph *g;
    g = (MGraph *)malloc(sizeof(MGraph));
    CreateMGraph(g);
    DispMGraph(g);
    printf("end");
    while(1);
    return 0;
}