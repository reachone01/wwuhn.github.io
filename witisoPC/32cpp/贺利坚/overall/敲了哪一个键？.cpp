#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
enum keys {HOME=151, UP, PGUP, LEFT=155, RIGHT=157, END=159, DOWN, PGDN};  //����ö������

int main()
{
    int ch;
    printf("�û�һ����,��ʾ��ĸ��ASCII�룺\n");
    do
    {
        ch=getch();
        if ( ch == 0xe0 )
        {
            ch=getch();
            ch+=80; 
        }
        switch(ch)
        {
        case UP:   // �����˿ɶ��ԣ�����Ƿ�
            printf("Up\n");
            break;
        case DOWN:
            printf("Down\n");
            break;
        case LEFT:
            printf("Left\n");
            break;
        case RIGHT:
            printf("Right\n");
            break;
        case HOME:
            printf("Home\n");
            break;
        case END:
            printf("End\n");
            break;
        case PGUP:
            printf("PageUp\n");
            break;
        case PGDN:
            printf("PageDown\n");
            break;
        case 8:             // ��ɾ��������
        case 163:
            system("cls");
            break;
        default:
            printf(" %c   %d\n",ch,ch);
        }
    }
    while (ch != 27 );   //ESC �˳�
    return 0;
}