#if 0
#include <stdio.h> 
 
int main(void)
{
	/* �������ַ���ֵ�����α��������Ϊ�ַ���ASCIIֵ */
	int   a = 'a';
	printf("a = %d\n", a);  //97
 
	/* ?������ν��� */
	a = 'abc';
	printf("a = %d\n", a);  //6382179
		
	/* ���ַ�����ֵ�����α��������Ϊ�ַ����ĵ�ֵַ */
	//a = "a";
	//printf("a = %d\n", a); //4206636
 
//	a = "abc";
	//printf("a = %d\n", a);	// 4206638
	while(1);
    return 0;

}
#endif

#if 1
#include <stdio.h>
union un
{
	int i;
	char c[4];
};
int main(void)
{
	int   a = 'a';
    printf("a = %d\n", a);/* �������ַ���ֵ�����α��������Ϊ�ַ���ASCIIֵ */
    int ch = 'abc';
    printf("%%d int ch = 'abc' %d\n",ch);
    union un b;
	b.i = 'abc';
    printf("%%d b.i = 'abc' %d\n",b.i);
	
	printf("b.i = %d\n", b.i); //b.i = 6382179
	printf("b.c = %c %c %c %c\n", b.c[0], b.c[1],b.c[2],b.c[3]); //b.c = c b a a
    printf("b.c = %d %d %d %d\n", b.c[0], b.c[1],b.c[2],b.c[3]); //b.c = 99 98 97 0
 
	/* ���ַ�����ֵ�����α��������Ϊ�ַ����ĵ�ֵַ */
//	a = "a";
//	printf("a = %d\n", a);
 
//	a = "abc";
//	printf("a = %d\n", a);
    printf("%c %c %c",0,1,2);
    while(1);
	return 0;
}
#endif.


