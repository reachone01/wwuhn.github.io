#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
/*
      A
     /\
   B    C
  /\    /\
 D  E  F  G
    /      \
   H        I
  /\
 J  K
   /\
   L  M
       \
        N
*/
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;              //����Ԫ��
    struct node *lchild;        //ָ������
    struct node *rchild;        //ָ���Һ���
} BTNode;

void CreateBTNode(BTNode *&b,char *str);//��str������������
BTNode *FindNode(BTNode *b,ElemType x); //����data��Ϊx�Ľڵ�ָ��
BTNode *LchildNode(BTNode *p);          //����*p�ڵ�����ӽڵ�ָ��
BTNode *RchildNode(BTNode *p);          //����*p�ڵ���Һ��ӽڵ�ָ��
int BTNodeDepth(BTNode *b);             //�������b�����
void DispBTNode(BTNode *b);             //�����ű�ʾ�����������
void DestroyBTNode(BTNode *&b);         //���ٶ�����

#endif // BTREE_H_INCLUDED
