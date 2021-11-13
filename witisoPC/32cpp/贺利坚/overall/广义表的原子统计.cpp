#ifndef GLIST_H_INCLUDED
#define GLIST_H_INCLUDED

typedef char ElemType;
typedef struct lnode
{
    int tag;                    //�ڵ����ͱ�ʶ
    union
    {
        ElemType data;          //ԭ��ֵ
        struct lnode *sublist;  //ָ���ӱ��ָ��
    } val;
    struct lnode *link;         //ָ����һ��Ԫ��
} GLNode;                       //�����ڵ����Ͷ���

int GLLength(GLNode *g);        //������g�ĳ���
int GLDepth(GLNode *g);     //������g�����
GLNode *CreateGL(char *&s);     //���������ű�ʾ����ʾs�Ĺ������ʽ�洢�ṹ
void DispGL(GLNode *g);                 //��������g

#endif // GLIST_H_INCLUDED

#include <stdio.h>


int atomnum(GLNode *g)  //������g�е�ԭ�Ӹ���
{
    if (g!=NULL)
    {
        if (g->tag==0)
            return 1+atomnum(g->link);
        else
            return atomnum(g->val.sublist)+atomnum(g->link);
    }
    else
        return 0;
}

ElemType maxatom(GLNode *g)             //������g�����ԭ��
{
    ElemType max1,max2;
    if (g!=NULL)
    {
        if (g->tag==0)
        {
            max1=maxatom(g->link);
            return(g->val.data>max1?g->val.data:max1);
        }
        else
        {
            max1=maxatom(g->val.sublist);
            max2=maxatom(g->link);
            return(max1>max2?max1:max2);
        }
    }
    else
        return 0;
}

int main()
{
    GLNode *g;
    char *s="(b,(b,a,(#),d),((a,b),c((#))))";
    g = CreateGL(s);
    DispGL(g);
    printf("\n");
    printf("ԭ�Ӹ��� :%d\n", atomnum(g));
    printf("���ԭ�� :%c\n", maxatom(g));
    while(1);
    return 0;
}

#include <malloc.h>

int GLLength(GLNode *g)     //������g�ĳ���
{
    int n=0;
    GLNode *g1;
    g1=g->val.sublist;      //gָ������ĵ�һ��Ԫ��
    while (g1!=NULL)
    {
        n++;                //�ۼ�Ԫ�ظ���
        g1=g1->link;
    }
    return n;
}

int GLDepth(GLNode *g)      //������g�����
{
    GLNode *g1;
    int max=0,dep;
    if (g->tag==0)          //Ϊԭ��ʱ����0
        return 0;
    g1=g->val.sublist;      //g1ָ���һ��Ԫ��
    if (g1==NULL)           //Ϊ�ձ�ʱ����1
        return 1;
    while (g1!=NULL)        //�������е�ÿһ��Ԫ��
    {
        if (g1->tag==1)     //Ԫ��Ϊ�ӱ�����
        {
            dep=GLDepth(g1);    //�ݹ��������ӱ�����
            if (dep>max)    //maxΪͬһ����������ӱ�����ȵ����ֵ
                max=dep;
        }
        g1=g1->link;            //ʹg1ָ����һ��Ԫ��
    }
    return(max+1);          //���ر�����
}

GLNode *CreateGL(char *&s)      //���������ű�ʾ����ʾs�Ĺ������ʽ�洢�ṹ
{
    GLNode *g;
    char ch=*s++;                       //ȡһ���ַ�
    if (ch!='\0')                      //��δ�����ж�
    {
        g=(GLNode *)malloc(sizeof(GLNode));//����һ���½ڵ�
        if (ch=='(')                    //��ǰ�ַ�Ϊ������ʱ
        {
            g->tag=1;                   //�½ڵ���Ϊ��ͷ�ڵ�
            g->val.sublist=CreateGL(s); //�ݹ鹹���ӱ�������ͷ�ڵ�
        }
        else if (ch==')')
            g=NULL;                     //����')'�ַ�,g��Ϊ��
        else if (ch=='#')               //����'#'�ַ�����ʾΪ�ձ�
            g=NULL;
        else                            //Ϊԭ���ַ�
        {
            g->tag=0;                   //�½ڵ���Ϊԭ�ӽڵ�
            g->val.data=ch;
        }
    }
    else                                 //������,g��Ϊ��
        g=NULL;
    ch=*s++;                            //ȡ��һ���ַ�
    if (g!=NULL)                        //��δ���������������ֵܽڵ�
    {
        if (ch==',')                    //��ǰ�ַ�Ϊ','
            g->link=CreateGL(s);        //�ݹ鹹���ֵܽڵ�
        else                            //û���ֵ���,���ֵ�ָ����ΪNULL
            g->link=NULL;
    }

    return g;                           //���ع����g
}

void DispGL(GLNode *g)                  //��������g
{
    if (g!=NULL)                        //��Ϊ���ж�
    {
        //�ȴ���g��Ԫ��
        if (g->tag==0)                  //g��Ԫ��Ϊԭ��ʱ
            printf("%c", g->val.data);  //���ԭ��ֵ
        else                            //g��Ԫ��Ϊ�ӱ�ʱ
        {
            printf("(");                //���'('
            if (g->val.sublist==NULL)   //Ϊ�ձ�ʱ
                printf("#");
            else                        //Ϊ�ǿ��ӱ�ʱ
                DispGL(g->val.sublist); //�ݹ�����ӱ�
            printf(")");                //���')'
        }
        if (g->link!=NULL)
        {
            printf(",");
            DispGL(g->link);            //�ݹ���������������
        }
    }
}
