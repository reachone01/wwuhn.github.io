#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")
void main()
{
WSADATA wsaData;
SOCKET sockServer;
SOCKADDR_IN addrServer;
SOCKET sockClient;
SOCKADDR_IN addrClient;
WSAStartup(MAKEWORD(2,2),&wsaData);
sockServer=socket(AF_INET,SOCK_STREAM,0);
addrServer.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//INADDR_ANY��ʾ�κ�IP
addrServer.sin_family=AF_INET;
addrServer.sin_port=htons(6000);//�󶨶˿�6000
bind(sockServer,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));
 
//Listen������
listen(sockServer,5);//5Ϊ�ȴ�������Ŀ
printf("������������:\n������...\n");
int len=sizeof(SOCKADDR);
char sendBuf[100];//�������ͻ��˵��ַ���
char recvBuf[100];//���ܿͻ��˷��ص��ַ���
 
//���������̣�ֱ���пͻ�����������Ϊֹ
sockClient=accept(sockServer,(SOCKADDR*)&addrClient,&len);
//���ղ���ӡ�ͻ�������
recv(sockClient,recvBuf,100,0);
printf("%s\n",recvBuf);
 
//�ر�socket
closesocket(sockClient);
WSACleanup();}