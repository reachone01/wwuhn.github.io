
	/* 
	1 ͼ�����ݽṹ
	
	ͼ��ǰ������ִ��������У��������ĸ��ʾ�����Ӧ�����ݣ�

		  0A
		 /  \
		1C  2E
		/  / \
	  3B  4D  5F
		   \  /
			6G

	ͼ���ڽӱ��ʾ��
	A-->2-->1
	C-->3-->0
	E-->5-->4-->0
	B-->1
	D-->6-->2
	F-->6-->2
	G-->5-->4

		  0
		  A
		 / \
		1   2
		C   E
	   /   / \
	  3   4   5
	  B   D   F
		   \ /
			6
			G
	2 ��ȡ������������
	
	��������Ȼ��ǹ������������ͨ����һ�����Ա���д���ֻ�������ȴ���ͷ������β����������ˡ�
	����ͷ�����ȵ�ʱ��Ҳ�����ȼ������̽�������ǹ�������ˣ���Ϊ��ͷ���Ķ����ֵܽڵ㣻
	��β��������������ȣ���Ϊ����β���Ķ��Ǹո����������Ľڵ㣬
	��������̽������Ҳ������νһ��·�ߵ��ס� ͬ��������뵽����ʽ������
	����ʽ���������������Զ�������ȼ�����Ȼ�����Թ��Ϊ���ȼ����� 
	���ԣ������ף���ν������������һ�ֶ��������ȼ���ö�١�


	2.1 �������������ջ����
	
		  A
		 / \
		C   E
	   /   / \
	  B   D   F
		   \ /
			G

	ջ������ȳ���ջ������һ���ڵ㣬����ջ��ѹ��ýڵ���ڽӵ㣨��ȥ�أ�

			|F| |G|
		|E| |D| |D| |D|
	|A| |C| |C| |C| |C| |C| |B|

	ǰ����ѹ��ڵ㣬���ݾ͵����ڵ㡣
	��Ϊ�������������

	2.2 ������������Ķ��в���

		  A
		 / \
		C   E
	   /   / \
	  B   D   F
		   \ /
			G

  ���У���������ͷ������һ���ڵ㣬����β������ýڵ���ڽӵ㣨��ȥ�أ�
    ----------------
	A
	----------------
	  E C
	----------------
		C F D
	----------------
		  F D B
	----------------
			D B
	----------------
			  B G
	----------------
				G
	----------------

	��Ϊ�������������

	*/

#include<stdio.h>
#include<stdlib.h>

#define MaxVex 100
int visited[MaxVex];		// ȫ������,���ڼ�¼ͼ�нڵ����״̬

/*
��ν�ڽӱ���Ƕ�ͼG�е�ÿ������(Vi��vertex)����һ��������
�������еĽ���ʾ�����ڶ���Vi�ıߣ����������ͳ�ΪVi�ı߱�
�߱��ͷ�ڵ�Ͷ����������Ϣ����˳��洢����Ϊ�����
�������ڽӱ��д������ֽ�㣺�������ͱ߱�ڵ㡣
  */
typedef struct EdgeNode {	// �ڽӱ�ڵ�
    int adjvex;				// ���ڽӵ��ڶ��������е��±�
    struct EdgeNode *next;  // ָ����һ���ڽӵ�
}EdgeNode;
 
typedef struct VertexNode { // ͷ�ڵ㣨�����ͼ��㣩
    char data;				// ������Ϣ
    EdgeNode *firstedge;	// �ڽӱ�ͷָ��(ָ���һ�������ڸö���Ļ���ָ��)
}VertexNode,AdjList[MaxVex];// ��������(�ṹ������)
 
typedef struct Graph{			// ͼ���ڽӱ�
    AdjList adjList;			// �涥�������
    int numVertexes,numEdges;	// ͼ�е�ǰ�Ľ�����Լ�����
}Graph,*GraphAdjList;
 
// ��������ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList &G)
{
    if(G==NULL)
        G = (GraphAdjList)malloc(sizeof(Graph));
 
    printf("����ͼ�Ľ�����Լ��������ո�����: ");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    fflush(stdin);
 
    printf("===========================\n");
    printf("����������������:\n");
    for (int i=0; i<G->numVertexes; ++i)
	{
        printf("����%d: ",i);
        scanf("%c", &(G->adjList[i].data));	// ���������ݷ���������
        G->adjList[i].firstedge = NULL;		// �߱�ͷָ���ʼΪNULL
        fflush(stdin);
    }
 
    printf("===========================\n");
	int j;
    for (int k=0; k<G->numEdges; ++k)			    // ����ߵ���Ϣ���붥�㽨����ϵ
	{
        printf("����(vi,vj)�ϵĶ������: ");
        scanf("%d %d",&i,&j);
 
        EdgeNode *ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
        ptrEdgeNode->adjvex = j;			        // �߽ڵ�������涥���±�
        ptrEdgeNode->next = G->adjList[i].firstedge;// ��ͷ�������߽ڵ�
        G->adjList[i].firstedge = ptrEdgeNode;
 
        ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
        ptrEdgeNode->adjvex = i;			        // ����ͼ�ٽ���һ���෴����
        ptrEdgeNode->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = ptrEdgeNode;
    }
}
 
/** ��ջ���弰��ز���(������ȱ������õ���ջ) **/
int Stack[MaxVex];
int Stackcount=-1;			// ��ջָ��
 
int StackEmpty(){			// �ж�ջ��
    return Stackcount==-1;
}
 
int StackFull(){			// �ж�ջ��
    return Stackcount==MaxVex-1;
}
 
void Push(int e){			// ��ջ
    if(!StackFull())
        Stack[++Stackcount]=e;
    else
        printf("Full!");
}
 
void Pop(){					// ��ջ
    if(!StackEmpty())
        Stackcount--;
    else
        printf("Empty!");
}
/*************************************************/
 
void DFSTraverseStack(GraphAdjList &G){	// ������ȱ���(��ջʵ��)
    int i;
    for (i=0; i<G->numVertexes; ++i)
        visited[i]=0;					// ��ʼ������״̬
    i=0;								// ��i�Ŷ��㿪ʼ����
    visited[i] = 1;
    printf("%c ", G->adjList[i].data);
    Push(i);							// ����ʼ�ڵ��ջ���Ա㽫����ȷ����
    while(!StackEmpty())
    {
        EdgeNode *p=G->adjList[Stack[Stackcount]].firstedge;// ָ��ջ��Ԫ�ص��ڽӱ�ͷ
        while(p)
        {
            if(!visited[p->adjvex])	// ����ǰ�ڽӶ���û�б����ʹ�������з��ʲ���ջ
            {
                printf("%c ",G->adjList[p->adjvex].data);
                visited[p->adjvex]=1;
                Push(p->adjvex);	// ���ʶ����ջ
                break;	            // �ڽӱ��Ǻ���ģ�������̽������Ϊ����ջ��������ѭ���з�����һ��Ԫ��
            }
            else		            // ����ǰ�ڽӶ����Ѿ������ʹ������ر��ҵ���һ������
                p=p->next;
        }
        if(p==NULL)		            // ��ĳһ���򱻷����꣬�����Ѱ��δ�����ʵĶ���
            Pop();
    }
}

// �ݹ�������ȱ���(�ݹ�ʵ��)
void DFSRecursion(GraphAdjList &G, int i)// DFSTraverseRecursion()���Ӻ���
{
    visited[i] = 1;						 // �ı����״̬
    printf("%c ",G->adjList[i].data);	 // �������
 
    EdgeNode *p=G->adjList[i].firstedge;
    while(p){
        if(!visited[p->adjvex])			// ���ڵ���δ����
            DFSRecursion(G,p->adjvex);	// �ݹ���ȱ���
        p=p->next;                      // �߽ڵ�ָ�����
    }
} // �ɱ������Զ����ѹջ�뵯ջ
 
 void DFSTraverseRecursion(GraphAdjList &G)
 {
	 for (int i=0; i<G->numVertexes;++i)
		 visited[i] = 0;	        // ��ʼ����������visited��Ԫ��ֵΪ0
	 
	 for (i=0; i<G->numVertexes;++i)
		 if(!visited[i])	       // �ڵ���δ����
			 DFSRecursion(G,i);	   // ���ñ�������
 }

/** ���ж��弰��ز���(������ȱ������õ���ѭ������) **/
int Queue[MaxVex];
int front=0,rear=0;		// ��ͷ�Ͷ�βָ��
 
int QueueEmpty(){
    return front == rear;
}
 
int QueueFull(){
    return rear == MaxVex-1;
}
 
void EnQueue(int e){	// ��β����Ԫ��
    if(!QueueFull())
        Queue[rear++] = e;
}
 
void DeQueue(int *e){	// ��ͷɾ��Ԫ��
    if(!QueueEmpty())
        *e = Queue[front++];// ��������[front,rear]
}
/*************************************************/
 
void BFSTraverse(GraphAdjList &G){// ͼ�Ĺ�����ȱ���
    for(int i=0; i<G->numVertexes; ++i)
        visited[i] = 0;	// ��ʼ������״̬
    i=0;				// ��i�Ŷ��㿪ʼ����
    visited[i] = 1;
    printf("%c ", G->adjList[i].data);
    EnQueue(i);
 
    while (!QueueEmpty())
    {
        DeQueue(&i);
        EdgeNode *p = G->adjList[i].firstedge;//ָ���ͷԪ�ص��ڽӱ�ͷ
        while (p)
        {
            if (!visited[p->adjvex])		  //����ǰ�ڽӶ���û�б����ʹ�������з��ʲ����
            {
                visited[p->adjvex] = 1;
                printf("%c ", G->adjList[p->adjvex].data);
                EnQueue(p->adjvex);
            }
            p = p->next;					// ������һ�������Ķ���
        }
    }
}


// �ڽӱ����
void ShowVlist(GraphAdjList &G){
    int i;
    EdgeNode* curp;
 
    printf("===========================\n�ڽӱ����:\n");
    for(i=0;i<G->numVertexes;i++)
    {
        printf("\%c",G->adjList[i].data);
        curp=G->adjList[i].firstedge;	 // �߽ڵ�ָ��ָ���һ���߽ڵ�
        while(curp!=NULL)
        {
            printf("-->%d",curp->adjvex);
            curp=curp->next;			// �����������
        }
        printf("\n");
    }
}
 
int main()
{
    GraphAdjList G = NULL;
    CreateALGraph(G);	// �����ڽӱ�
    ShowVlist(G);		// ����ڽӱ�
 
    printf("\nͼ��������ȱ���(��ջʵ��)Ϊ:\t");
    DFSTraverseStack(G);
 
    printf("\nͼ��������ȱ���(�ݹ�ʵ��)Ϊ:\t");
    DFSTraverseRecursion(G);
 
    printf("\nͼ�Ĺ�����ȱ���Ϊ:\t\t");
    BFSTraverse(G);


    printf("\n\n");
	system("pause");
    return 0;
}


/*
��������
7 7
A
C
E
B
D
F
G
0 1
0 2
1 3
2 4
2 5
4 6
5 6


*/

/* ����Ч����
����ͼ�Ľ�����Լ�����: 7 7
===========================
����������������:
����0: A
����1: C
����2: E
����3: B
����4: D
����5: F
����6: G
===========================
����(vi,vj)�ϵĶ������: 0 1
����(vi,vj)�ϵĶ������: 0 2
����(vi,vj)�ϵĶ������: 1 3
����(vi,vj)�ϵĶ������: 2 4
����(vi,vj)�ϵĶ������: 2 5
����(vi,vj)�ϵĶ������: 4 6
����(vi,vj)�ϵĶ������: 5 6
===========================
�ڽӱ����:
A-->2-->1
C-->3-->0
E-->5-->4-->0
B-->1
D-->6-->2
F-->6-->2
G-->5-->4

ͼ��������ȱ���(��ջʵ��)Ϊ:   A E F G D C B
ͼ��������ȱ���(�ݹ�ʵ��)Ϊ:   A E F G D C B
ͼ�Ĺ�����ȱ���Ϊ:             A E C F D B G

*/