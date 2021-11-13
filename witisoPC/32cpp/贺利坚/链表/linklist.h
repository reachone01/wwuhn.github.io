#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef int ElemType;
typedef struct LNode        //���嵥����������
{
    ElemType data;
    struct LNode *next;     //ָ���̽��
}LinkList;
void CreateListF(LinkList *&L,ElemType a[],int n);//ͷ�巨����������
void CreateListR(LinkList *&L,ElemType a[],int n);//β�巨����������
void InitList(LinkList *&L);        //��ʼ�����Ա�
void DestroyList(LinkList *&L);     //�������Ա�
bool ListEmpty(LinkList *L);        //�ж����Ա��Ƿ�Ϊ��
int ListLength(LinkList *L);        //�����Ա���
void DispList(LinkList *L);         //������Ա�
bool GetElem(LinkList *L,int i,ElemType &e);        //�����Ա�ĳ������Ԫ��ֵ
int LocateElem(LinkList *L,ElemType e);             //��Ԫ��ֵ����
bool ListInsert(LinkList *&L,int i,ElemType e);     //��������Ԫ��
bool ListDelete(LinkList *&L,int i,ElemType &e);    //ɾ������Ԫ��

#endif // LINKLIST_H_INCLUDED