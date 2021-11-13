#include<stdio.h>   //printf()��
#include<malloc.h>  // malloc()��
#include<process.h> //exit()
#define OK 1
#define OVERFLOW -2
typedef int Status;         //Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int ElemType;       //ElemType�����Ա�������Ԫ�ص����ͣ��˴���int
#define LIST_INIT_SIZE 10   // ���Ա�洢�ռ�ĳ�ʼ��������Ϊ������ԣ���Ϊ10

typedef struct 
{
    ElemType *elem; //�洢�ռ��ַ
    int length;     // ��ǰ����
    int listsize;   // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

Status InitList(SqList &L)  // �㷨2.3
{                           // �������������һ���յ�˳�����Ա�
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);         // �洢����ʧ��
    L.length=0;                 // �ձ���Ϊ0
    L.listsize=LIST_INIT_SIZE;  // ��ʼ�洢����
    return OK;
}

Status ListTraverse(SqList L)
{   // ��ʼ������˳�����Ա�L�Ѵ���
    // ����������������L�е�ÿ������Ԫ�أ�������û����display���������˸�רҵ�����������Traverse
    ElemType *p;
    int i;
    p=L.elem;
    printf("���Ա�ǰ����Ϊ: %d��",	L.listsize);
    if (L.length>0)
    {
        printf("���Ա����� %d ��Ԫ�أ��ֱ��ǣ�",L.length);
        for(i=1;i<=L.length;i++)
            printf("%d ",*p++);
    }
    else
        printf("Ŀǰ���ǿ����Ա�");
    printf("\n");
    return OK;
}

int main()
{
    SqList La;
    Status i;
    i=InitList(La);
    ListTraverse(La);
    while(1);
    return 0;
}  