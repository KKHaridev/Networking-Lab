#include<stdio.h>
#include<stdlib.h>

#include<math.h>

#include<unistd.h>


int r,n;
struct frame{
	int data;
	char ack;
	
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
		r=rand()%n;
	}
}

void selective(){
	get_values();
	int w_size;
	printf("Enter The Window Size: ");
	scanf("%d",&w_size);
	frm[r].ack='n';
	for(int i = 1; i <=(n - w_size) + 1; i++)  {   
        for(int j = i; j < i + w_size; j++){  
            printf("Sending value %d\n",frm[j].data);
            sleep(1);
           if(frm[j].ack=='n'){
            	printf("Packet Lost\n");
            	sleep(1);
            	printf("Resending...\n");
            	printf("Sending value %d\n",frm[j].data);
            	frm[j].ack='y';	
            }
            else{
            	printf("Packet received with data : %d\n",frm[j].data);
            }
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
