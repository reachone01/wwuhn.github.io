#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")
void main()
{
WSADATA wsaData;
SOCKET sockClient;//�ͻ���Socket
SOCKADDR_IN addrServer;//����˵�ַ
WSAStartup(MAKEWORD(2,2),&wsaData);
//�½��ͻ���socket
sockClient=socket(AF_INET,SOCK_STREAM,0);
//����Ҫ���ӵķ���˵�ַ
addrServer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//Ŀ��IP(127.0.0.1�ǻ��͵�ַ)
addrServer.sin_family=AF_INET;
addrServer.sin_port=htons(6000);//���Ӷ˿�6000
//���ӵ������
connect(sockClient,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));
//��������
char message[20]="HelloSocket!";
send(sockClient,message,strlen(message)+1,0);
//�ر�socket
closesocket(sockClient);
WSACleanup();
system("pause");
}