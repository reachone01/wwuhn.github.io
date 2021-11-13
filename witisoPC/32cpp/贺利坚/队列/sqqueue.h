#ifndef SQQUEUE_H_INCLUDED
#define SQQUEUE_H_INCLUDED

#define MaxSize 5
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;     /*���׺Ͷ�βָ��*/
} SqQueue;


void InitQueue(SqQueue *&q);  //��ʼ��˳���ζ���
void DestroyQueue(SqQueue *&q); //����˳���ζ���
bool QueueEmpty(SqQueue *q);  //�ж�˳���ζ����Ƿ�Ϊ��
int QueueLength(SqQueue *q);   //���ض�����Ԫ�ظ�����Ҳ�ƶ��г���
bool enQueue(SqQueue *&q,ElemType e);   //����
bool deQueue(SqQueue *&q,ElemType &e);  //����

#endif // SQQUEUE_H_INCLUDED
