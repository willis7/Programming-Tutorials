/****************************************************
	Networking Tutorials #5
	Multiple Hosts - ClientSide
	by redKlyde

****************************************************/

// Things that will be covered in this tutorial:
// absolutely nothing

// This part of the tutorial is exactly like tutorial #4 with one small exception.  The
// client will accept input from the command line, and send it to the server.  It will
// continue this until the client types 'quit'.  There is no new material, so browse 
// through the code, and play around with it as you like.
// - redklyde

// -----------------------------------------------------------------------------------
// startupClient() - will return us a socket that is connected to the server
// specified by serverName, on the port specified by port.  It will return -1
// if an error occurred during the process.
int startupClient(unsigned short port, const char* serverName);

// -----------------------------------------------------------------------------------
// shutdownClient() - will close the socket specified and clean up winsock.
void shutdownClient(int clientSocket);

// winsock for our network communication
#include <winsock2.h>
// stdio for I/O
#include <stdio.h>

int main() {
	printf("Welcome to redKlyde's Networking Tutorials!\n");
	printf("Tutorial #5 : Multiple Hosts - ClientSide\n\n");

	// my socket
	int mySocket;

	// create our client
	mySocket = startupClient(7654, "localhost");

	if (mySocket == -1) {
		// hmm an error occurred
		// shutdown our client and bail
		shutdownClient(mySocket);
		return 1;
	}

	// number of bytes sent
	int nBytes;
	
	// I will define a message size so we will know how much data we will send and receive
	#define MAX_MESSAGE_SIZE 4096
	char buffer[MAX_MESSAGE_SIZE];

	printf("Input text to send and press Enter\nType 'quit' to exit\n");

	// the main loop
	for (;;) {
		// get some input from the command line
		gets(buffer);

		// check if quit was typed, then exit
		if (strcmp(buffer, "quit") == 0) {
			break;
		}

		// get our message size
		unsigned long messageSize = strlen(buffer);

		// fix our byte ordering
		messageSize = htonl(messageSize);

		// send the message size
		if ((nBytes = send(mySocket, (char*)&messageSize, sizeof(messageSize), 0)) == SOCKET_ERROR) {
			printf("Send Failed!\n");
		}

		// re-fix our byte ordering
		messageSize = ntohl(messageSize);

		// send the actual message
		if ((nBytes = send(mySocket, buffer, messageSize, 0)) == SOCKET_ERROR) {
			printf("Send Failed!\n");
		}
	}

	// shutdown our client
	shutdownClient(mySocket);
	return 0;
}

int startupClient(unsigned short port, const char* serverName) {
	// an error code we will use to get more information about our errors
	int error;

	// the winsock data structure
	WSAData wsaData;

	// startup winsock
	if ((error = WSAStartup(MAKEWORD(2, 2), &wsaData)) == SOCKET_ERROR) {
		printf("Could Not Start Up Winsock!\n");
		return -1;
	}

	// create my socket
	int mySocket = socket(AF_INET, SOCK_STREAM, 0);

	// make sure nothing bad happened
	if (mySocket == SOCKET_ERROR) {
		printf("Error Opening Socket!\n");
		return -1;
	}

	struct hostent *host_entry;

	// setup the host entry
	if ((host_entry = gethostbyname(serverName)) == NULL) {
		printf("Could not find host!\n");
	}

	struct sockaddr_in server;

	// fill in the server socket info
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = *(unsigned long*) host_entry->h_addr;

	// connect to the server
	if (connect(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
		printf("Error connecting to server!\n");
	}

	printf("Client Started\n");

	return mySocket;
}

void shutdownClient(int clientSocket) {
	// close our socket
	closesocket(clientSocket);

	// shut down winsock
	WSACleanup();

	printf("Client Shutdown\n");
}

/*----------------------------*\
|  Done by:  redKylde		   |
|  © 2000-2005 GameTutorials   |
\*----------------------------*/
