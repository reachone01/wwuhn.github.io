#include <iostream>
using namespace std; // ��������
class Bulk
{
public:
    void get_value();
    void display();
private:
    void get_volume();  //�����ڲ�����ģ���Ϊ˽�к�����������Ϣ����
    void get_area();
    float lengh;
    float width;
    float height;
    float volume;
    float area;
};

void Bulk::get_value()
{ 
    cout<<"please input lengh, width, height:";
    cin>>lengh;
    cin>>width;
    cin>>height;
    get_volume();  //����߻��ֵ�Ժ󼴿��Լ��㣬Ҳ������display�����ǰ���㣬���ۺ϶��ԣ��˴�����
    get_area();
}

void Bulk::get_volume()
{
    volume=lengh*width*height;
}

void Bulk::get_area()
{
    area=2*(lengh*width+lengh*height+width*height);
}

void Bulk::display()
{ 
    //get_volume()��get_area()Ҳ�����ڴ˴����ã������м��㹤���ڳ����ȷ�������̽���	
    cout<<"The volume is: "<<volume<<endl;
    cout<<"The surface area is: "<<area<<endl;
}

int main()
{
    Bulk b1,b2,b3;
    
    b1.get_value();
    cout<<"For bulk1: "<<endl;
    b1.display();
    
    b2.get_value();
    cout<<"For bulk2: "<<endl;
    b2.display();
    
    b3.get_value();
    cout<<"For bulk3: "<<endl;
    b3.display();
    return 0;
}