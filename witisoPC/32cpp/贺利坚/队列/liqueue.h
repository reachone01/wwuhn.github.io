#ifndef LIQUEUE_H_INCLUDED
#define LIQUEUE_H_INCLUDED

typedef char ElemType;
typedef struct qnode
{
    ElemType data;
    struct qnode *next;
} QNode;        //�������ݽ�����Ͷ���

typedef struct
{
    QNode *front;
    QNode *rear;
} LiQueue;          //�������Ͷ���

void InitQueue(LiQueue *&q);    //��ʼ������
void DestroyQueue(LiQueue *&q); //��������
bool QueueEmpty(LiQueue *q);    //�ж������Ƿ�Ϊ��
int QueueLength(LiQueue *q);    //���ض���������Ԫ�ظ���
void enQueue(LiQueue *&q,ElemType e);   //���
bool deQueue(LiQueue *&q,ElemType &e);  //����

#endif // LIQUEUE_H_INCLUDED
