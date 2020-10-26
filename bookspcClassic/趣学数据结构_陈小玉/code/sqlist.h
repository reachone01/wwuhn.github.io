#define  Maxsize 100  //���ռ�

typedef struct{
  int *elem;
  int length;       // ˳���ĳ���
}SqList;

bool InitList(SqList &L) //����һ���յ�˳���L
{   //L��&��ʾ�������Ͳ����������ڲ��ĸı�����������Ȼ��Ч
//����&�ڲ��ı䣬������������Ч
    L.elem=new int[Maxsize];    //Ϊ˳������Maxsize���ռ�
    if(!L.elem) return false;      //�洢����ʧ��
    L.length=0;				//�ձ���Ϊ0
    return true;
}

//bool CreateList(SqList &L) //����һ��˳���L
//{   //L��&��ʾ�������Ͳ����������ڲ��ĸı�����������Ȼ��Ч
////����&�ڲ��ı䣬������������Ч
//    int a,i=0;
//    cin>>a;
//    while(a!=-1)
//    {
//     if(L.length==Maxsize)
//     {
//       cout<<"˳���������";
//       return false;
//     }
//     L.elem[i++]=a;
//     L.length++;
//     cin>>a;
//   }
//   return true;
//}

bool GetElem(SqList L,int i,int &e)
{
  if (i<1||i>L.length) return false;
   //�ж�iֵ�Ƿ����������������false
  e=L.elem[i-1];   //��i-1�ĵ�Ԫ�洢�ŵ�i������
  return true;
}

int LocateELem(SqList L,int x)
{
  for (int i=0;i<L.length;i++)
      if (L.elem[i]==x) return i+1; //�ڼ���Ԫ�أ������5��Ԫ�أ��±���ʵΪ4
  return -1;
}

bool ListInsert_Sq(SqList &L,int i ,int e)
{
   if(i<1 || i>L.length+1) return false;	 //iֵ���Ϸ�
   if(L.length==Maxsize) return false; //�洢�ռ�����
   for(int j=L.length-1;j>=i-1;j--)
       L.elem[j+1]=L.elem[j];   //�����һ��Ԫ�ؿ�ʼ���ƣ�ֱ����i��Ԫ�غ���
   L.elem[i-1]=e;              //����Ԫ��e�����i��λ��
   L.length++;		     	//����1
   return true;
}

bool ListDelete_Sq(SqList &L,int i,int &e)
{
   if((i<1)||(i>L.length)) return false;	 //iֵ���Ϸ�
   e=L.elem[i-1];   //����ɾ����Ԫ�ر�����e��
   for (int j=i; j<=L.length-1; j++)
		L.elem[j-1] = L.elem[j]; //��ɾ��Ԫ��֮���Ԫ��ǰ��
   L.length--; //����1
   return true;
}

//void print(SqList L)
//{
//   cout << "���˳���" << endl;
//   for(int j=0;j<=L.length-1;j++)
//     cout<<L.elem[j]<<"   ";
//   cout<<endl;
//}

void DestroyList(SqList &L)
{
  if (L.elem) delete []L.elem;    //�ͷŴ洢�ռ�
}

