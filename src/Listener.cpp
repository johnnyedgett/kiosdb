// Learning with https://docs.microsoft.com/en-us/windows/win32/winsock

#define _WIN32_WINNT
#define _WIN32_WINNT 0x50
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512

#include "Listener.h"
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

Listener::Listener(const int PORT) : PORT(PORT) {
	// Create the WSADATA structure -> contains info about the Winsock implementation
	WSADATA wsaData;

	// Call WSAStartup and check for errors
	int iResult;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}

	// After wsadata initialization, a socket object needs to be instantiated
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	ZeroMemory(&hints, sizeof(hints)); // -> memset()
	hints.ai_family = 2; // IPv4
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	SOCKET ListenSocket = INVALID_SOCKET; // The server will listen for client connections on this socket

	// Call the 'socket' function and return value to listensocket -> this is the first P returned by getadddrinfo 
	//	which matched the above parameters (TCP Streaming socket using IPv4)
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	
	// Check the socket was created
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
	}

	// Bind the ListenSocket to a network address within the system
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
	}

	// Now that the socket is bound to an IP Address/Port using bind(), can start listening for new requests
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
	}

	// Accept client connection(s) -> in this case, only one, no multithreading yet (TODO)
	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
	}

	// Receive data on the socket
	char recvbuf[DEFAULT_BUFLEN];
	int iSendResult;
	int recvbuflen = DEFAULT_BUFLEN;

	// Receive until the connection closes
	do {

		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);

			// Echo the buffer back to the sender
			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
			}
			printf("Bytes sent: %d\n", iSendResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
		}

	} while (iResult > 0);
}