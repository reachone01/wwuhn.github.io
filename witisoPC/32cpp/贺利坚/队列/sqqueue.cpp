#include <stdio.h>
#include <malloc.h>
#include "sqqueue.h"

void InitQueue(SqQueue *&q)  //��ʼ��˳���ζ���
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q) //����˳���ζ���
{
    free(q);
}
bool QueueEmpty(SqQueue *q)  //�ж�˳���ζ����Ƿ�Ϊ��
{
    return(q->front==q->rear);
}


int QueueLength(SqQueue *q)   //���ض�����Ԫ�ظ�����Ҳ�ƶ��г���
{
    return (q->rear-q->front+MaxSize)%MaxSize;
}

bool enQueue(SqQueue *&q,ElemType e)   //����
{
    if ((q->rear+1)%MaxSize==q->front)  //���������
        return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(SqQueue *&q,ElemType &e)  //����
{
    if (q->front==q->rear)      //�ӿ������
        return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}
