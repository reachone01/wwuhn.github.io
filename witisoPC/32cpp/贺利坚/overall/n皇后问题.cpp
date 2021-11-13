#include <stdio.h>
#include <math.h>
#include <malloc.h>

void nQueens(int *x, int n);        /*���n�ʺ�����*/
int place(int *x, int k);           /*�ж��Ƿ�����ڵ�k�е�x[k]�аڷŻʺ�*/
void printSolution(int *x, int n);  /*��������*/

int main()
{
    int queens;
    int *solution;                                  /*���������������׵�ַ*/
    printf("������ʺ�����queens��������8������8�ʺ����⣺");
    scanf("%d", &queens);
    solution=(int*)malloc(sizeof(int)*(queens+1));  /*��̬��������ռ䣬 x[0]����*/
    nQueens(solution, queens);
    while(1);
    return 0;
}

/*���һ���ʺ��ܷ��ڵ�row�е�arr[row]�У��򷵻���(1)�����򷵻ؼ�(0)*/
int place(int arr[], int row)
{
    for(int i=1; i<row; i++)  /*��ǰrow-1�У����п���*/
    {       /*���ǰrow-1������ĳ�еĻʺ����row�е���ͬһ�л�ͬһб�ߣ�����0*/
        if((arr[i]==arr[row])||(fabs(arr[i]-arr[row])==fabs(i-row)))
            return 0;
    }       /*��ִ����һ�䣬˵���ڵ�k�е�x[k]�аڷŻʺ󣬲��ụ�๥��*/
    return 1;
}

int solutions = 0;          /*�������*/
void nQueens(int *solution, int n) /*�����n��n�������ϣ�����n���ʺ�ʹ�䲻�ܻ��๥��*/
{
    int curRow = 1;         /*curRow�ǵ�ǰ��*/
    solution[curRow] = 0;   /*solution[curRow]�ǵ�ǰ�У�����ѭ���У����̾ͻ�ִ��solution[curRow]++����ѡ���˵�1��*/
    while(curRow>0)         /*�ɺ���Ļ��ݲ�curRow--���������п��ܵĽⳢ�����curRow����Ϊ0������������*/
    {
        solution[curRow]++;             /*�Ƶ���һ��*/
        while(solution[curRow]<=n && !place(solution,curRow))  /*���п��죬�ҳ��ܰڷŻʺ����x[k]*/
            solution[curRow]++;
        if(solution[curRow]<=n)         /*�ҵ�һ��λ�ÿ��԰ڷŻʺ�*/
        {
            if(curRow==n)               /*��һ�������Ľ⣬�����*/
            {
                solutions++;
                printf("��%d���⣺\n",solutions);
                printSolution(solution, n);
            }
            else                        /*û��������һ�е�ѡ���ǲ��ֽ⣬ת����һ��*/
            {
                curRow++;               /*���ſ�����һ��*/
                solution[curRow]=0;     /*��ѭ����ʼִ��solution[curRow]++����һ�н��ӵ�1�п�ʼ����*/
            }
        }
        else                /*��Ӧx[k]>n�����Σ���һ���Ѿ�û�����Եı�Ҫ�����ݵ���һ��*/
            curRow--;        /*��ѭ����ʼִ��x[k]++����һ����ԭ��x[k]�е���1�п�ʼ����*/
    }
}

/*��������*/
void printSolution(int *x, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)  /*�����i��*/
    {
        for (j=1; j<=n; j++)
        {  
            if (j == x[i])   /*��x[i]�����Q�����������*�� */
                printf(" Q");
            else
                printf(" *");
        }
        printf("\n");
    }
    printf("\n");
}