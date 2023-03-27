#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

void main(){
	int sock_id,bind_v,newSocket,length;
	char recline[100],sendline[200];
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
	bind_v=bind(sock_id,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
	if(bind_v<0)
		printf("\nCannot Bind Socket");
	else
		printf("\nSuccessful: Bind Socket");
	listen(sock_id,10);
	length=sizeof(cli_addr);
	newSocket=accept(sock_id,(struct sockaddr*)&cli_addr,&length);
	printf("\nAccepted\n");		
	int option=0;

	while(1){
		bzero(sendline,100);
				bzero(recline,100);
		printf(" \nmessaage from client: ");
		read(newSocket,recline,100);
		
		if(strcmp(recline,"quit")==0||strcmp(sendline,"quit")==0){
			printf("CLOSED\n");
			exit(0);
			close(sock_id);
			close(newSocket);
		}
		puts(recline);
		printf("\nSend messaage to client: ");
		gets(sendline);
		write(newSocket,sendline,sizeof(sendline));
	
		
	
}
}
