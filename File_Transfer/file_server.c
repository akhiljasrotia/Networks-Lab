/*
	Server for file transferring 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	//Create a socket
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;

	//Specify the server address and port
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8080);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//Bind the socket to the IP
	bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address));

	//Listen to client connections
	listen(server_socket, 5);
		
	//Accept client
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	char data[100000];
	FILE *file;
	read(client_socket, data, sizeof(data));
	file = fopen("copied.txt","w");
	fprintf(file, "%s", data);
	printf("File recieved as 'recieved.txt'.\n");
	return 0;
}