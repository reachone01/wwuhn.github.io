#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int n;
    struct Node * next;
    //Node(int i):n(i){next=NULL;} // �����˹��죬�����࣬�಻�����帳ֵ���ṹ�����
};


void initList(Node*& head)  // ͷ�ڵ��ǿսڵ�
{ 
    for(int i=0;i<10;i++)
    {
        Node * newNode = new Node;
        newNode->n = i+1*10;
        newNode->next = NULL;
        
        if(i==0)
            head->next = newNode;
        else
            newNode->next = head->next;
        head->next = newNode;
    }
}

void insert(Node*& head, int i)  // ͷ�ڵ��ǿսڵ�
{ 

        Node * newNode = new Node;
        newNode->n = i;
        newNode->next = NULL;
        
        if(i==0)
            head->next = newNode;
        else
            newNode->next = head->next;
        head->next = newNode;

}

void initList2(Node*& head)  // ͷ�ڵ���ʵ�ڵ�
{
    Node * tailNode;  
    for(int i=0;i<10;i++)
    {
        Node * newNode = new Node;
        newNode->n = i+1*10;
        newNode->next = NULL;
        
        if(i==0)
            head = newNode;
        else
            tailNode->next = newNode;
        tailNode = newNode; // ͷ�ڵ��Ժ��״�Ҳָ����ͷָ��
    }
}

void showList(Node* head)   // ͷ�ڵ��ǿսڵ�
{
    Node* pMove = head->next;
    while(pMove != NULL)
    {
        cout<<pMove->n<<" ";
        pMove = pMove->next;
    }
    cout<<endl;
}

void showList2(Node* head)  // ͷ�ڵ���ʵ�սڵ�
{
    Node* pMove = head;
    while(pMove != NULL)
    {
        cout<<pMove->n<<" ";
        pMove = pMove->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = new Node;
    initList(head);
    insert(head,999);
    showList(head);
    Node *head2;
    initList2(head2);
    showList2(head2);
restart:   

	
    goto restart;
    return 0;
}
/*
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
    printf("");
    while(1); // pause
    cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    system("pause");
    getchar();
*/