#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>

void main(){
	int sock_id,bind_v,newSocket,length;
	char sendline[100],recline[100];
	struct sockaddr_in ser_addr,cli_addr;
	bzero(&ser_addr,sizeof(ser_addr));
	sock_id=socket(AF_INET,SOCK_STREAM,0);
	if(sock_id<0)
		printf("Socket Cannot Be Created\n");
	else
		printf("Socket created\n");
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(3000);
	ser_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	connect(sock_id,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
	printf("\nClient Connected\n");
	bzero(sendline,100);
					bzero(recline,100);
	while(1){
	
		
		printf("\nSend messaage to server: ");
		gets(sendline);
		
		write(sock_id,sendline,sizeof(sendline));
		if(strcmp(recline,"quit")==0||strcmp(sendline,"quit")==0){
									printf("CLOSED\n");
									exit(0);
									close(sock_id);
								}
		printf(" \nmessaage from server: ");
		read(sock_id,recline,100);
		puts(recline);
		
		

				
		
		
		
	}
}
