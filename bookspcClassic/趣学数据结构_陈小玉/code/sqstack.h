
#define Maxsize 100  //Ԥ�ȷ���ռ䣬�����ֵ����ʵ����ҪԤ��ȷ����

typedef struct SqStack {
	Elemtype *base; //ջ��ָ��
	Elemtype *top; //ջ��ָ��
}SqStack;

bool InitStack(SqStack &S) //����һ����ջS
{
	S.base = new Elemtype[Maxsize];//Ϊ˳��ջ����һ���������ΪMaxsize�Ŀռ�
	if (!S.base)    //�ռ����ʧ��
	   return false;
	S.top=S.base;  //top��ʼΪbase����ջ
	return true;
}

bool Empty(SqStack S) //�ж�ջ��
{
	if(S.top==S.base)
        return 1;
    return 0;
}

bool Push(SqStack &S, Elemtype e) // ����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top-S.base == Maxsize) //ջ��
		return false;
	*(S.top++)=e; //Ԫ��eѹ��ջ����Ȼ��ջ��ָ���1���ȼ���*S.top=e; S.top++;
	return true;
}

bool Pop(SqStack &S, Elemtype &e) //ɾ��S��ջ��Ԫ�أ��ݴ��ڱ���e��
{
	if (S.base == S.top) //ջ��
		return false;
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return true;
}

int GetTop(SqStack S) //����S��ջ��Ԫ�أ�ջ��ָ�벻��
{
	if (S.top != S.base)  //ջ�ǿ�
		return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
    else
        return -1;
}


