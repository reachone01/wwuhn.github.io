#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int num;
}QueueData;

typedef struct node {
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct queueType {
	NodePtr head, tail;
} QueueType, *Queue;

Queue initQueue() 
{
	Queue qp = (Queue) malloc(sizeof(QueueType));
	qp -> head = NULL;
	qp -> tail = NULL;
	return qp;
}

int empty(Queue Q) 
{
	return (Q -> head == NULL);
}

void enqueue(Queue Q, QueueData d) 
{
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> data = d;
	np -> next = NULL;
	if (empty(Q)) 
	{
		Q -> head = np;
		Q -> tail = np;
	}
	else 
	{
		Q -> tail -> next = np; // �����½��ڵ�
		Q -> tail = np;			// �ƶ�tailָ�뵽�½��ڵ�
	}
}

QueueData dequeue(Queue Q) 
{
	if (empty(Q)) 
	{
		printf("\nAttempt to remove from an empty queue\n");
		exit(1);
	}
	QueueData hold = Q -> head -> data;
	NodePtr temp = Q -> head;		// ��ȡ׼���Ƴ���ͷ�ڵ�ָ��
	Q -> head = Q -> head -> next;	// �ƶ�headָ�뵽�ڽ��ڵ�
	if (Q -> head == NULL) 
		Q -> tail = NULL;
	free(temp);
	return hold;
}


int main() {
	int n;
	QueueData temp;
	Queue Q = initQueue();
	printf("Enter a positive Multidigit integer: ");
	scanf("%d", &n);
	while (n > 0) {
		temp.num = n % 10;
		enqueue(Q, temp);
		n = n / 10;
	}
	printf("\nDigits in reverse order: ");
	while (!empty(Q))
		printf("%d", dequeue(Q).num);
	printf("\n");
	system("pause");
}
/*
Enter a positive Multidigit integer: 34589

Digits in reverse order: 98543
*/
