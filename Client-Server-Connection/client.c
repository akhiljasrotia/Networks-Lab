#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include <unistd.h>
#include<netinet/in.h>

int main(){

 int network_socket;
 network_socket=socket(AF_INET,SOCK_STREAM,0);

 struct sockaddr_in server_address;
 server_address.sin_family = AF_INET;
 server_address.sin_port = htons(9002);
 server_address.sin_addr.s_addr = INADDR_ANY;
 
 int connection_status = connect(network_socket,(struct sockaddr *) &server_address,sizeof(server_address));

 if(connection_status == -1){
    printf("Error");
 }

 char mess[200];
 printf("Enter the message \n");
 scanf("%s",mess);
 send(network_socket,mess,sizeof(mess),0);

 char server_response[256];
 recv(network_socket, &server_response, sizeof(server_response),0);
 printf("The new message is %s",server_response);
 //printf("The server returned %s", server_response);

 close(network_socket);

 return 0;
}