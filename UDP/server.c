#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#define MAXLINE 1000

void main(){
	int sock_id,bind_v,len;
	char recline[100],sendline[200];
	struct sockaddr_in ser_addr,cli_addr;
	bzero(&ser_addr,sizeof(ser_addr));
	sock_id=socket(AF_INET,SOCK_DGRAM,0);
	if(sock_id<0)
		printf("Socket Cannot Be Created\n");
	else
		printf("Socket created\n");
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(3001);
	//ser_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	ser_addr.sin_addr.s_addr=inet_addr("10.0.4.23");
	
	

	
	if(	bind(sock_id,(struct sockaddr*)&ser_addr,sizeof(ser_addr))<0){
		printf("\nCannot Bind Socket");
		}
		
	printf("\nSuccessful: Bind Socket\n");

 	len = sizeof(cli_addr);
    while(strcmp(sendline,"quit")!=0){
    	int n = recvfrom(sock_id, recline, sizeof(recline),0, (struct sockaddr*)&cli_addr,&len);
    	    recline[n] = '\0';
    	    printf("Message from client: ");
    	    puts(recline);
    	    printf("Message to client: ");
    		gets(sendline);
    		
    		sendto(sock_id, sendline, MAXLINE, 0,(struct sockaddr*)&cli_addr, sizeof(cli_addr));
    		if(strcmp(sendline,"quit")==0)
    		    		{
    		    			exit(0);
    		    		}
    		
    }
	
	
	
}
