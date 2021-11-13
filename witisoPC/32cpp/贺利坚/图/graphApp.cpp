#include <stdio.h>
#include <malloc.h>
#include "graph.h"

int main()
{
    MGraph g1,g2;
    ALGraph *G1,*G2;
    int A[6][6]=
    {
        {0,5,0,7,0,0},
        {0,0,4,0,0,0},
        {8,0,0,0,0,9},
        {0,0,5,0,0,6},
        {0,0,0,5,0,0},
        {3,0,0,0,1,0}
    };

    ArrayToMat(A[0], 6, g1);  //ȡ��ά�������ʼ��ַ��ʵ�Σ���A[0]������ʵ��Ϊһά�����ַ�����β�ƥ��
    printf(" ����ͼg1���ڽӾ���:\n");
    DispMat(g1);

    ArrayToList(A[0], 6, G1);
    printf(" ����ͼG1���ڽӱ�:\n");
    DispAdj(G1);

    MatToList(g1,G2);
    printf(" ͼg1���ڽӾ���ת�����ڽӱ�G2:\n");
    DispAdj(G2);

    ListToMat(G1,g2);
    printf(" ͼG1���ڽӱ�ת�����ڽ�����g2:\n");
    DispMat(g2);
    printf("\nend\n");
    while(1);
    return 0;
}