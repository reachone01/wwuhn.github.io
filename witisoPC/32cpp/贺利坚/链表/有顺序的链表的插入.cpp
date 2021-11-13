#include "stdio.h"
#include "malloc.h"

typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

LinkList GreatLinkList(int n)                   /*����һ������Ϊn������*/
{
    LinkList pNew, rear, head = NULL;
    int elementData;
    for (int i=1;i<=n;i++){
        printf("�������%d�����ֵ����%d������",i,n);
        scanf("%d",&elementData);               /*��ȡ�������е�����Ԫ��*/
        pNew=(LinkList)malloc(sizeof(LNode));   /*����һ���µ�������*/
        pNew->data=elementData;
        pNew->next=NULL;
        if (head == NULL) {
            head = pNew;        /*headָ���һ����㣬head��ͷָ��*/
        } else {
            rear->next = pNew;  /*���½�����ӵ������β��*/
        }
        rear = pNew;            /*ָ��rʼ��ָ����������һ�����*/
    }
    return head;                /*���������ͷָ��*/
}

void insertListInOrder(LinkList *head,int elementData)
{                           /*��ֵ����(��������)������head�в������Ԫ��e�Ľ��*/
    LinkList pNew, pFront, pBack;
    pFront = *head;
    pNew=(LinkList)malloc(sizeof(LNode));  /*����һ���½�㣬��pNewָ����*/
    pNew->data=elementData;                /*��ý���������ֵe*/
    if (*head == NULL || elementData < (*head)->data) {
        pNew->next = *head;
        *head = pNew;
    } else {
        while(pFront != NULL && e >= pFront->data) {    /*ѭ���ҵ��������λ��*/
            pBack  = pFront;                            /*rָ��q��ǰ�����*/
            pFront = pFront->next;                      /*qָ������ƶ�*/
        }
        pNew->next  = pFront;                           /*�����µĽ��*/
        pBack->next = pNew;
    }
}

void delLink(LinkList *head, LinkList q) {
    LinkList r;
    if (q == *head) {
        *head = q->next;/*���qָ��Ľ�㼴Ϊ��1����㣬����Ҫ�޸�head��ֵ*/
        free(q);/*�ͷű�ɾ�����Ŀռ�*/
    } else {
        r = *head;
        while ((r->next != q)&&(r->next != NULL)) {
            r = r->next;/*ͨ��ѭ���ҵ�q��ָ����ǰ�����*/
        }
        if (r->next != NULL) {
            r->next = q->next;/*ɾ��q��ָ��Ľ��*/
            free(q);/*�ͷű�ɾ�����Ŀռ�*/
        }
    }
}
void deleteLinkList(LinkList *head) {
    LinkList p = *head;/*pָ���һ�����*/
    while (p != NULL) {
        *head = p ->next;/* headָ��p����һ����� */
        free(p);/*�ͷŵ�pָ������ڴ�ռ�*/
        p = *head;/*p��ָ���һ�����*/
    }
}
void printLink(LinkList head) {
    while (head != NULL) {
        printf("%3d",head->data);/*��ӡ��ÿ������е�����data*/
        head = head->next;
    }
    printf("\n");
}
void main() {
    int i;
    LinkList q,head = NULL;
    head = GreatLinkList(10); /*����һ������Ϊ10������*/
    printf("The elems of this linklist is\n");
    printLink(head); /*��ӡ�����������*/
    printf("����Ԫ��3\n");
    insertListInOrder(&head,3);/*����Ԫ��3*/
    printf("The elems of this linklist is\n");
    printLink(head); /*��ӡ�����������*/
    printf("����Ԫ��0\n");
    insertListInOrder(&head,0);/*����Ԫ��0*/
    printf("The elems of this linklist is\n");
    printLink(head); /*��ӡ�����������*/
    printf("����Ԫ��11\n");
    insertListInOrder(&head,11);/*����Ԫ��10*/
    printf("The elems of this linklist is\n");
    printLink(head); /*��ӡ�����������*/
    printf("ɾ�������еĵ�5��Ԫ�أ�\n");
    q=head;
    for (i=0; i<4; i++) {
        q = q->next;/*ָ��qָ�������е�5��Ԫ��*/
    }
    delLink(&head, q);/*ɾ��qָ��Ľ��*/
    printLink(head);/*��ӡ�������е�����*/
    deleteLinkList(&head);/*���ٸ�����*/
    if (head == NULL) {
        printf( " This Linklist have been deleted\n");
    }
    printf("\n-End-\n");
    while(1);
}
