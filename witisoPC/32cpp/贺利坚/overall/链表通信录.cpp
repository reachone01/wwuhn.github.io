#include<stdio.h>       // ����ͨ��¼
#include<string.h>
#include<stdlib.h>
typedef struct          //ͨѶ¼�������
{
    char num[5];        //���
    char name[9];       //����
    char sex[3];        //�Ա�
    char phone[13];     //�绰
    char addr[31];      //��ַ
} DataType;

typedef struct node     //������Ͷ���
{
    DataType data;      //���������
    struct node * next; //���ָ����
} ListNode;

typedef ListNode * LinkList;
LinkList head;
ListNode *p;

//����˵��
int menu_select();
LinkList CreateList();
void InsertNode(LinkList head,ListNode *p);
ListNode *ListFind(LinkList head);
void DelNode(LinkList head);
void PrintList(LinkList head);

//������
int main()
{
    for(;;)
    {
        switch(menu_select())
        {
        case 1:
            printf("****************************************\n");
            printf("*          ͨѶ¼����Ľ���            *\n");
            printf("****************************************\n");
            head=CreateList();
            break;
        case 2:
            printf("****************************************\n");
            printf("*            ͨѶ����Ϣ�����          *\n");
            printf("****************************************\n");
            printf("*���(4) ����(8) �Ա� �绰(11) ��ַ(31)*\n");
            printf("****************************************\n");
            p=(ListNode *)malloc(sizeof(ListNode));    //�����½��
            scanf("%s%s%s%s%s",p->data.num,p->data.name,
                p->data.sex,p->data.phone,p->data.addr);
            InsertNode(head,p);
            break;
        case 3:
            printf("****************************************\n");
            printf("*          ͨѶ¼��Ϣ�Ĳ�ѯ            *\n");
            printf("****************************************\n");
            p=ListFind(head);
            if(p!=NULL)
            {
                printf("*�� ��  �� ��  �� ��  ��ϵ�绰  �� ַ  *\n");
                printf("----------------------------------------\n");
                printf("%s\t%s\t%s\t%s\t%s\n",p->data.num,p->data.name,
                    p->data.sex,p->data.phone,p->data.addr);
                printf("----------------------------------------\n");
            }
            else
                printf("û�в鵽Ҫ��ѯ��ͨ���ߣ�\n");
            break;
        case 4:
            printf("****************************************\n");
            printf("*          ͨѶ¼��Ϣ��ɾ��            *\n");
            printf("****************************************\n");
            DelNode(head);    //ɾ�����
            break;
        case 5:
            printf("****************************************\n");
            printf("*          ͨѶ¼��������            *\n");
            printf("****************************************\n");
            PrintList(head);
            break;
        case 0:
            printf("\t ��  ���� \n");
            return 0;
        }
    }
}

/**********************************/
/*       �˵�ѡ��������         */
/**********************************/
int menu_select()
{
    int sn;
    printf("==============================\n");
    printf("   ͨѶ¼����ϵͳ\n");
    printf("==============================\n");
    printf("   1.ͨѶ¼����Ľ���\n");
    printf("   2.ͨѶ�߽��Ĳ���\n");
    printf("   3.ͨѶ�߽��Ĳ�ѯ\n");
    printf("   4.ͨѶ�߽���ɾ��\n");
    printf("   5.ͨѶ¼��������\n");
    printf("   0.�˳�����ϵͳ\n");
    printf("==============================\n");
    for(;;)
    {
        scanf(" %d",&sn);
        if(sn<0||sn>5)
            printf("\n\t���������ѡ0-5");
        else
            break;
    }
    return sn;
}

/***********************************/
/*  ��β�巨����ͨѶ¼������     */
/***********************************/
LinkList CreateList()
{
    //β�巨������ͷ����ͨѶ¼�����㷨
    LinkList head=(ListNode*)malloc(sizeof(ListNode)); //�����ͷ���
    ListNode *p,*rear;
    int flag=0;        //������־��0
    rear=head;         //βָ���ʼָ��ͷ���
    while(flag==0)
    {
        p=(ListNode*)malloc(sizeof(ListNode));    //�����½��
        printf("���(4) ����(8) �Ա�  �绰(11)  ��ַ(31) \n");
        printf("-----------------------------------------\n");
        scanf(" %s%s%s%s%s",p->data.num,p->data.name,p->data.sex,
            p->data.phone,p->data.addr);
        rear->next=p;               //�½�����ӵ�β���֮��
        rear=p;                     //βָ��ָ���½��
        printf("���������� (1����/0����):");
        scanf(" %d",&flag);         //����һ����־����
    }
    rear->next=NULL;                //�ն˽��ָ�����ÿ�
    return head;
}

/*****************************************/
/*   ��ͨѶ¼(˳��)����head�в�����    */
/*****************************************/
void InsertNode(LinkList head,ListNode *p)
{
    ListNode *pAfter,*pCurr;
    pAfter=head;
    pCurr=pAfter->next;
    while(pCurr!=NULL && strcmp(pCurr->data.num,p->data.num)<0)
    {
        pAfter=pCurr;         //p1ָ��շ��ʹ��Ľ��
        pCurr=pCurr->next;    //p2ָ������һ�����
    }
    pAfter->next=p;           //����p��ָ��Ľ��
    p->next=pCurr;            //���ӱ���ʣ�ಿ��
}

/*****************************************/
/*        ����ͨѶ¼�����ϵĲ���         */
/*****************************************/
ListNode * ListFind(LinkList head)
{
    //����ͨѶ¼�����ϵĲ���
    ListNode *p;
    char num[5];
    char name[9];
    int xz;
    printf("=================\n");
    printf("  1.����Ų�ѯ   \n");
    printf("  2.��������ѯ   \n");
    printf("=================\n");
    printf("��ѡ��:");
    p=head->next;    //�ٶ�ͨѶ¼����ؽ��
    scanf("%d",&xz);
    fflush(stdin);
    if(xz==1)
    {
        printf("������Ҫ�����ߵı�ţ�");
        scanf("%s",num);
        fflush(stdin);
        while(p&&strcmp(p->data.num,num)<0)
        {
            p=p->next;
        }
        if(p==NULL||strcmpi(p->data.num,num)>0)
        {
            p=NULL;        //û�в鵽Ҫ���ҵ�ͨѶ��
        }
    }
    else
    {
        if(xz==2)
            printf("������Ҫ�����ߵ�������");
        scanf("%s",name);
        fflush(stdin);
        while(p&&strcmp(p->data.name,name)!=0)
            p=p->next;
    }
    return p;
}

/*****************************************/
/*        ͨѶ¼�����Ͻ���ɾ��         */
/*****************************************/
void DelNode(LinkList head)
{
    char jx;
    ListNode *p,*q;
    p=ListFind(head);    //���ò��Һ���
    if(p==NULL)
    {
        printf("û�в鵽Ҫɾ����ͨѶ��");
        return;
    }
    printf("���Ҫɾ���ý����?(y/n):");
    scanf("%c",&jx);    //ע����%cǰ����һ�ո���Դ�������뻺����
    fflush(stdin);        //���������Ҳ����������뻺����
    if(jx=='y'||jx=='Y')
    {
        q=head;
        while(q!=NULL && q->next!=p)
            q=q->next;
        q->next=p->next;    //ɾ�����
        free(p);            //�ͷű�ɾ���Ľ��ռ�
        printf("ͨѶ���ѱ�ɾ��\n");
    }
}

/*****************************************/
/*        ͨѶ¼�������������         */
/*****************************************/
void PrintList(LinkList head)
{
    ListNode *p;
    p=head->next;            //��Ϊ�����ͷ��㣬ʹpָ������ʼ���
    printf("���  ����  �Ա�  ��ϵ�绰  ��ַ\n");
    printf("------------------------------------------\n");
    while(p!=NULL)
    {
        printf("%s%s%s%s%s\n",p->data.num,p->data.name,
            p->data.sex,p->data.phone,p->data.addr);
        printf("------------------------------------------\n");
        p=p->next;            //����һ�����
    }
}