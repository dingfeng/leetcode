#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include <Windows.h>
#include <fstream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
const int BUFFERSIZE = 1024 * 1024;
char  buffer[BUFFERSIZE];

int main(int argc, char  *argv[])
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
		printf("start %s\n",argv[1]);
	SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(6000);
	addrServ.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	bind(servSock, (SOCKADDR*)&addrServ, sizeof(SOCKADDR));
	if (listen(servSock, 20) == SOCKET_ERROR)
	{
		printf("listen failed with error: %ld\n", WSAGetLastError());
		closesocket(servSock);
		WSACleanup();
		return -1;
	}
	while (true)
	{
		SOCKADDR_IN cliAddr;
		int length = sizeof(SOCKADDR);
		SOCKET cliSock = accept(servSock, (SOCKADDR*)&cliAddr, &length);
		cout << "ip : " << inet_ntoa(cliAddr.sin_addr) << ":" << cliAddr.sin_port << endl;
		if (INVALID_SOCKET == cliSock)
		{
			printf("listen failed with error: %ld\n", WSAGetLastError());
			closesocket(cliSock);
			WSACleanup();
			return -1;
		}
		//ifstream in("N:/1.txt", ios::binary);
		ifstream in(argv[1], ios::binary);
		while (!in.eof())
		{
			in.read(buffer, BUFFERSIZE);
			int len = in.gcount();
			send(cliSock,buffer,len,0);
		}
		in.close();
		closesocket(cliSock);
	}
	
}

