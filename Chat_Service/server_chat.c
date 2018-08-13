/*
	Server Side Chat server
*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(){
	
	//Socket Creation
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,0);

	//Specify the server address and port
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//Binding
	bind(server_socket,(struct sockaddr*) &server_address ,sizeof(server_address)); 

	//Listening
	listen(server_socket,5); 

	int client_socket;
	client_socket=accept(server_socket,NULL,NULL);
	char server_message[256];
	char mess1[200];

	while(1)//Server Chat
	{
		recv(client_socket, &server_message, sizeof(server_message),0);
		printf("Client message: %s\n", server_message);
		printf("Enter the message from server side \n");
		scanf("%s",mess1);
		send(client_socket,mess1,sizeof(mess1),0);
	}

	close(server_socket);

	return 0;
}