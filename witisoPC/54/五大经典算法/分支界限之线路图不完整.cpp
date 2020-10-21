#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

#define ROWS 9
#define COLS 9

int grid[ROWS][COLS];
int indexcount=0;

struct Position
{
    int row;
    int col;
};

void showPath()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
            cout<<setw(2)<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}

bool FindPath(Position start,Position finish,int &PathLen,Position *&path)
{
    // ��������λ��start��Ŀ��λ��finish����̲���·����
	// �ҵ���̲���·���򷵻�true�����򷵻�false
	
    if((start.row==finish.row) && (start.col==finish.col))
    {
        PathLen=0;
        cout<<"start=finish"<<endl;
        return true;
    }
	
    for(int i=1; i<ROWS-1; i++) // ��ʼ��ͼ��-1Ϊδ����
    {
        for(int j=1; j<COLS-1; j++)
            grid[i][j]=-1;
		
    }

	grid[2][3]=-2; // ����赲��
	grid[4][4]=-2;
	grid[5][5]=-2;
	grid[6][2]=-2;
	grid[6][3]=-2;
    for(i=0; i< COLS; i++)	        // ���÷������С�Χǽ��
        grid[0][i]=grid[ROWS-1][i]=-2; // �����͵ײ�
    for(i=0; i< ROWS; i++)
        grid[i][0]=grid[i][COLS-1]=-2; // ����������
	
    cout<<"����ͼ"<<endl;
    showPath();
    Position offset[4];//��ʼ�����λ��
    offset[0].row=0;  // ��
    offset[0].col=1;
    offset[1].row=1;  // ��
    offset[1].col=0;
    offset[2].row=0;  // ��
    offset[2].col=-1;
    offset[3].row=-1; // ��
    offset[3].col=0;
    int NumOfNbrs=4;  // ���ڷ�����
    Position here,nbr;
    here.row = start.row;
    here.col = start.col;
    grid[start.row][start.col]=0;
	// ��ǿɴ﷽��λ��
	cout<<"����ǰͼ"<<endl;
    showPath();
	
    queue<Position> Q;
    do  // ������ڿɴ﷽��
    {
        for(int I=0; I<NumOfNbrs; I++)
        {
            nbr.row=here.row + offset[I].row;
            nbr.col=here.col + offset[I].col;
            if(grid[nbr.row][nbr.col]==-1)
            {
				//�÷���δ�����
                //cout<<grid[nbr.row][nbr.col]<<endl;//��ʾ·��ֵ
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
				//cout<<nbr.col<<"   "<<nbr.row<<endl;//��ʾ����
            }
            if((nbr.row==finish.row) &&(nbr.col==finish.col)) break; //��ɲ���
            Q.push(nbr);
			
			
        }
		//�Ƿ񵽴�Ŀ��λ��finish��
        if((nbr.row==finish.row)&&(nbr.col==finish.col)) break;//��ɲ���
		//��������Ƿ�ǿգ�
        if(Q.empty()) return false;//�޽�
        here = Q.front();
        //cout<<here.col<<" "<<here.row<<endl;
        Q.pop();//ȡ��һ����չ���
		
        indexcount++;
		// cout<<"��һ�ڵ�"<<indexcount<<endl;
    }while(true);
	// ������̲���·��
    PathLen=grid[finish.row][finish.col];
    path=new Position[PathLen];
	// ��Ŀ��λ��finish��ʼ����ʼλ�û���
    here=finish;
    for(int j=PathLen-1; j>=0; j--)
    {
        path[j]=here;
		// ��ǰ��λ��
        for(int i=0; i<NumOfNbrs; i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==j)
            {
				// cout<<j<<endl;
                break;
            }
        }
        here = nbr;// ��ǰ�ƶ�
    }
    return PathLen;
}
int main()
{
    Position start;
    start.row=3;
	start.col=2;
	
	cout<<"�������"<<endl;
	cout<<start.col<<" "<<start.row<<endl;

    Position finish;
    finish.row=4;
    finish.col=6;

	cout<<"���߽�����"<<endl;
	cout<<finish.row<<" "<<finish.col<<endl;

    int PathLen=0;
    Position *path;
	
    FindPath(start,finish,PathLen,path);
    cout<<"���ߺ�·��ͼ"<<endl;
    showPath();
    cout<<"·��"<<endl;
    for(int i=0; i<PathLen; i++)
    {
        cout<<path[i].col<<" "<<path[i].row<<endl;
    }
    cout << "�����������!" << endl;
	
	system("pause");
    return 0;
}