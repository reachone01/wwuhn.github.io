#include <iostream>
#include <vector>
using namespace std;
template< typename T>
class Animal{
 private:
	 T t;
 public:
	 void talk(){t.talkImplement();}
};
class SayMiao {
public:
	void talkImplement(){cout<<"Miao \n";}
};
class SayHW{
public:
	void talkImplement(){cout<<"Hello world \n";}
};
template<typename T>
void LetAnimalTalk(Animal<T>& pa){
	pa.talk(); 
}
int main(){
	Animal<SayMiao> am;
	Animal<SayHW> ah;
	LetAnimalTalk(am);
	LetAnimalTalk(ah);
	vector<Animal<SayMiao> > va;
	va.push_back(am); // OK
	//va.push_back(ah); // compile error here
    system("pause");
	return 0;
}
/*
Miao
Hello world
*/