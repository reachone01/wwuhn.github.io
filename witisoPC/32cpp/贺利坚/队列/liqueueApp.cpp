#include <stdio.h>
#include "liqueue.h"

int main()
{
    ElemType e;
    LiQueue *q;
    printf("(1)��ʼ������q\n");
    InitQueue(q);
    printf("(2)���ν�����Ԫ��a,b,c\n");
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    printf("(3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
    if (deQueue(q,e)==0)
        printf("�ӿ�,���ܳ���\n");
    else
        printf("(4)����һ��Ԫ��%c\n",e);
    printf("(5)����q��Ԫ�ظ���:%d\n",QueueLength(q));
    printf("(6)���ν�����Ԫ��d,e,f\n");
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    printf("(7)����q��Ԫ�ظ���:%d\n",QueueLength(q));
    printf("(8)����������:");
    while (!QueueEmpty(q))
    {
        deQueue(q,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(9)�ͷ�����\n");
    DestroyQueue(q);
    while(1);
    return 0;
}
