#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>


int r,n;
struct frame{
	int data;
	char ack;
	char wait;
	
}frm[100];

void sender(int i){
	printf("Enter the data to be sent : ");
	scanf("%d",&frm[i].data);
		printf("\n");

	frm[i].ack='y';
	printf("Packet Sent\nwaiting for acknowledgement\n");
	printf("\n");
	sleep(1);
	
}

void recack(int i){
	frm[r].ack='n';
	if(frm[i].ack=='n'){
	printf("Packet Lost\n");
		sleep(2);
		exit(0);
	}
	else{
		printf("Packet received with data : %d\n",frm[i].data);
	}
}

void stop_wait(){
		for(int i=1;i<=n;i++){
		sender(i);
		recack(i);
	}
}


void get_values(){
	for(int i=1;i<=n;i++){
		printf("Enter the value of frame %d : ",i);
		scanf("%d",&frm[i].data);
		frm[i].ack='y';
		rand();	
		r=3;
	}
}

void selective(){
	get_values();
	int lc=1;
	int w_size;
	printf("Enter The Window Size: ");
	scanf("%d",&w_size);
	frm[r].ack='n';
	end:
	for(int i = lc; i <=(n - w_size) + 1;)  {   
        for(int j = i; j < i + w_size; j++){  
            if(frm[j].wait!='n'){
				printf("Sending value %d\n",frm[j].data);
			}
			frm[j].wait='y';
            
           
        }  
		sleep(1);
		int count=0;
		for(int j = i; j < i + w_size; j++){
			if(frm[j].ack=='y'){
				if(j==i)
				count++;
				printf("Packet received with data : %d\n",frm[j].data);
				
            }
			else{
				printf("Packet Lost %d\n",frm[j].data);
				goto skip;
			}
			
			if(count>0){
				lc++;
				printf("skipping\n");
				
				goto end;
			}
			}
		}
		skip:

		for(int i = lc; i <=n;i++){
			if(frm[i].ack!='n'){
				printf("Sending value %d\n",frm[i].data);
			}
			if(frm[i].ack=='y'){
				printf("Packet received with data : %d\n",frm[i].data);
				
            }
			else{
				frm[i].ack='y';
				printf("Packet Lost %d\n",frm[i].data);
			}
			if (i==lc+(w_size-1)){
				printf("Packet received with data : %d\n",frm[r].data);
			}
		}

		
    }  
	


void goBack(){
	
}

void main(){
	int option;
	printf("Enter the no of Frames : ");
	scanf("%d",&n);
	printf("\n");
	printf("1.Stop And Wait\n2.Selective Repeat\n3.Go Back N\n4.Exit\n Enter any option:");
	scanf("%d",&option);
	rand();	
	r=rand()%n;
	switch(option){
		case 1:stop_wait();
				break;
		case 2:selective();
				break;	
		case 3:goBack();
				break;
		case 4: exit(0);
	}
}
