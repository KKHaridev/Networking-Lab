#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000
void main(){
	int sock_id,bind_v,length;
	char sendline[100],recline[100];
	struct sockaddr_in ser_addr,cli_addr;
	bzero(&ser_addr,sizeof(ser_addr));
	sock_id=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_id<0)
		printf("Socket Cannot Be Created\n");
	else
		printf("Socket created\n");
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(3001);
	ser_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(connect(sock_id,(struct sockaddr*)&ser_addr,sizeof(ser_addr))<0){
		printf("Connection failed\n");
	}
	bzero(sendline,100);
	bzero(recline,100);
	sendline[10]="test";
	do
	{
		printf("Message to server: ");
			gets(sendline);
			if(strcmp(sendline,"quit")==0){
				exit(0);
			}
			sendto(sock_id, sendline, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(ser_addr));
		    printf("\tMessage from server: ");
		    recvfrom(sock_id, recline, sizeof(recline), 0, (struct sockaddr*)NULL, NULL);
		    puts(recline);
			if(strcmp(recline,"quit")==0){
				exit(0);
			}
		    
		    
	}while(strcmp(recline,"quit")||strcmp(sendline,"quit")!=0);
  
    close(sock_id);
	
}
