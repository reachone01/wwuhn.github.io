#include <stdio.h>
#include "btree.h"

int main()
{
    BTNode *b,*p,*lp,*rp;;
    printf("  (1)����������:");
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("\n");
    printf("  (2)���������:");
    DispBTNode(b);
    printf("\n");
    printf("  (3)����H�ڵ�:");
    p=FindNode(b,'H');
    if (p!=NULL)
    {
        lp=LchildNode(p);
        if (lp!=NULL)
            printf("����Ϊ%c ",lp->data);
        else
            printf("������ ");
        rp=RchildNode(p);
        if (rp!=NULL)
            printf("�Һ���Ϊ%c",rp->data);
        else
            printf("���Һ��� ");
    }
    else
        printf(" δ�ҵ���");
    printf("\n");
    printf("  (4)������b�����:%d\n",BTNodeDepth(b));
    printf("  (5)�ͷŶ�����b\n");
    DestroyBTNode(b);
    printf("end!");
    while(1);
    return 0;
}