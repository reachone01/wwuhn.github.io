//���·��

#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                  //��󶥵���
#define Maxint 32767
typedef char VertexType; 
typedef int Adjmatrix; 

typedef enum {FALSE,TRUE} boolean; //���岼����

typedef struct {
    VertexType vexs[MVNum];        //�������飬���ͼٶ�Ϊchar��
    Adjmatrix  arcs[MVNum][MVNum]; //�ڽӾ��󣬼ٶ�Ϊint��
}MGraph;
//ȫ������
int D1[MVNum],P1[MVNum];
int D[MVNum][MVNum],P[MVNum][MVNum];
//��������ԭ��
void CreateMGraph(MGraph *,int ,int );
void Dijkstra(MGraph,int,int );
void Floyd(MGraph ,int);
void displayNode(MGraph *,int);
//������

void main( )
{   MGraph G;
    int n,e,v,w,k;
	int xz=1;
    printf("����ͼ�ж�������ͱ���n,e(�ո�ָ�)��");
	scanf("%d %d",&n,&e);

	CreateMGraph(&G,n,e);//����ͼ�Ĵ洢�ṹ

	displayNode(&G,n);

    while (xz!=0) {
       printf("******�����֮������·��******\n");
       printf("================================\n");
       printf("1.��һ�����е����г��е����·��\n");
       printf("2.���������������֮������·��\n");
	   printf("================================\n");
	   printf("  ��ѡ��1 �� 2��ѡ�� 0 �˳� ��");
	   
       scanf("%d",&xz);
	   
	    if(xz==2) {
           Floyd(G,n); //���÷��������㷨
	        printf(" ����Դ��(������)���յ㣺v,w ��");
           scanf("%d %d",&v,&w);
           k=P[v][w];  //kΪ���v�ĺ�̶���
           if(k==0)
              printf("���� %d �� %d ��·����\n",v,w);
           else 
		     {
               printf("�Ӷ���%d��%d�����·���ǣ�%d",v,w,v);
               while(k!=w) {
                   printf("��%d",k); //�����̶��� 
                   k=P[k][w];        //��������һ����̶���
			     }
               printf("��%d\n",w);    //����յ�w
               printf("  ·�����ȣ�%d\n",D[v][w]);
		      }
        }
	     else
		   if(xz==1) {
		       printf("��Դ·��������Դ�� v ��");
              scanf("%d",&v);
              Dijkstra(G,v,n);  //���õϽ�˹�����㷨
		    }
			
	//   xz=0;
	  }
	  
   printf("���������·�����ټ���\n");

   system("pause");
}
void displayNode(MGraph *G,int m)
{
	int i,j;
	printf("ͼ���ڽӾ���Ϊ��\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
			printf("%10d",G->arcs[i][j]);
		printf("\n");
	}
}

void CreateMGraph(MGraph* G,int n,int e)
{//�����ڽӾ����ʾ������������G, n��e��ʾͼ�ĵ�ǰ�������ͱ���
   int i,j,k,w;
   for(i=1;i<=n;i++)//���붥����Ϣ 
      G->vexs[i]=(char)i;
   for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
         G->arcs[i][j]=Maxint;//��ʼ���ڽӾ���

   printf("����%d���ߵ�i��j��w��\n",e);

   for(k=1;k<=e;k++){     //����e���ߣ������ڽӾ���
      scanf("%d %d %d",&i,&j,&w);
      G->arcs[i][j]=w;
   }              
   printf("����ͼ�Ĵ洢�ṹ������ϣ�\n");
}


//�Ͻ�˹�����㷨
void Dijkstra(MGraph G,int v1,int n)
{ //��Dijkstra�㷨������ͼG��v1���㵽��������v�����·��P[v]����ȨD[v]
  //��G�����������ڽӾ�������<i,j>�����ڣ���G[i][j]=Maxint
  //S[v]Ϊ�浱�ҽ���v��S,������ô�v1��v�����·��
  int D2[MVNum],P2[MVNum];
  int v,i,w,min;
  boolean S[MVNum];
  for(v=1;v<=n;v++){//��ʼ��S��D
     S[v]=FALSE;          //�ÿ����·���յ㼯
     D2[v]=G.arcs[v1][v]; //�ó�ʼ�����·��ֵ
	 if(D2[v]<Maxint)
        P2[v]=v1;          //v1��v��ǰ��(˫��)
     else
        P2[v]=0;           //v��ǰ��
  }//end_for
  D2[v1]=0;S[v1]=TRUE;     //S����ʼʱֻ��Դ�㣬Դ�㵽Դ��ľ���Ϊ0
  //��ʼѭ����ÿ�����v1��ĳ��v��������·��������v��S����
  for(i=2;i<n;i++)
  {//����n-1������
     min=Maxint;
     for(w=1;w<=n;w++)
       if(!S[w] && D2[w]<min) 
	   {  
		   v=w;
		   min=D2[w];
	   }//w������v1�������
       S[v]=TRUE;   
       for(w=1;w<=n;w++)//���µ�ǰ���·��������
           if(!S[w]&&(D2[v]+G.arcs[v][w]<D2[w]))
		   { //�޸�D2[w]��P2[w],w��V-S
                  D2[w]=D2[v]+G.arcs[v][w];
                  P2[w]=v; 
	       }//End_if  
		}//End_for
       printf("·������    ·��\n");
      for(i=1;i<=n;i++) 
	  {
         printf("%5d",D2[i]);
	     printf("%5d",i);v=P2[i];
	     while(v!=0) {
	        printf("<-%d",v);
	        v=P2[v];
	  }
      printf("\n");
	}
}
//���������㷨
void Floyd(MGraph G,int n)
{
   int i,j,k; 
   for(i=1;i<=n;i++) //����·������D��·��path��ֵ
      for(j=1;j<=n;j++)
      {
         if(G.arcs[i][j]!=Maxint)
            P[i][j]=j;  //j��i�ĺ��
         else
            P[i][j]=0;
         D[i][j]=G.arcs[i][j];
     }
   for(k=1;k<=n;k++)
   {//��k�ε���,ÿ�ξ���ͼ������k���䵽��ǰ��õĴ�i��j�����·��Pij��
      for(i=1;i<=n;i++) 
         for(j=1;j<=n;j++)
         {  
			 if(D[i][k]+D[k][j]<D[i][j]) 
			 {
               D[i][j]= D[i][k]+D[k][j]; //�޸ĳ���
               P[i][j]=P[i][k];
		      }
		 }
     }
 }