#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>
#include <fstream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
const int BUFFERSIZE = 1024 * 1024;
char buffer[BUFFERSIZE];
int main(int argc, char * argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");

	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSock == -1)
	{
		perror("socket创建出错！");
		exit(1);
	}
	SOCKADDR_IN addrClient;
	addrClient.sin_addr.S_un.S_addr = inet_addr(argv[1]);
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(6000);

	int ret = connect(clientSock, (sockaddr*)&addrClient, sizeof(SOCKADDR));
	if (ret)
	{
		printf("连接失败\n");
		return -1;
	}
	ofstream out(argv[2],ios::binary);
	int len = 0;
	while (len = recv(clientSock, buffer, BUFFERSIZE,0))
	{
		out.write(buffer,len);
	}
	out.close();
	closesocket(clientSock);
}