/*
	Client for file transferring 
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
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);

	//Specify the server address and port
	struct sockaddr_in client_address;
	bzero(&client_address, sizeof(client_address));
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(8080);
	client_address.sin_addr.s_addr = INADDR_ANY;

	//Connection
	int connect_status = connect(client_socket, (struct sockaddr *) &client_address, sizeof(client_address));

	//Error check
	if(connect_status < 0){
		int errno;
		perror("Error");
	}
	char data[100000];

	FILE *file;
	file = fopen("tosend.txt", "r");
	fgets(data, sizeof(data), file);

	//Write to server
	write(client_socket, data, sizeof(data));
	printf("File sent\n");
	return 0;
}