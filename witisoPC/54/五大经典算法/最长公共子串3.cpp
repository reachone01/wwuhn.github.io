#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void lcs(char* charA , char* charB)
{
    int i,j;
    int lenA    = strlen(charA);
    int lengthB = strlen(charB);
    
    // ��̬��ά����cell[][]
    int** cell=(int **)malloc(sizeof(int *) * lenA+1);
    if(cell==NULL)
    {
        printf("cell is null");
        exit(1);
    }
    for(i=0;i<lenA+1;i++)
    {
        cell[i]=(int*)malloc(sizeof(int)*lengthB+1);
        if(cell[i]==NULL)
            exit(1);
    }
    for(i=0;i<lenA+1;i++) // ��̬��ά����Խ������ݳ�ʼ��Ϊ0
        for(j=0;j<lengthB+1;j++)
            cell[i][j]=0;

    int maxLength = 0;
    int end = 0;
    for(i = 1; i<lenA;i++){
        for ( j= 1; j <lengthB; j++) {
            if (charA[i]==charB[j]){   // ���������ĸ��ͬ
                cell[i][j]=cell[i-1][j-1]+1;

            }
            if(maxLength<cell[i][j]){  // �ó����Ĺ����Ӵ�
                maxLength=cell[i][j];
                end=i;
            }
        }
    }
    printf("��ִ�:");

    for(i=end-maxLength+1;i<maxLength+1;i++)//����ѭ���Ǵ�1��ʼ��������Ҫ��1
        printf("%c",charA[i]);
    
    printf(" ����%d:\n",maxLength);
    
}

void main() {
    //��������
    char* a = "fishers";
    char* b = "ohisher";
    char* c = "vista";
    lcs(a,b);
    lcs(c,a);
    
    getchar();
}
/*output:
��ִ�:isher ����5:
��ִ�:is ����2:
*/