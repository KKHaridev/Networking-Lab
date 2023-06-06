#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int random_num(int a){
	rand();
	int num=(random()%10)%a;
	return num == 0 ? 1 : num;
}

void main(){
	int b_size,o_rate,p_rm_size=0,p_size[100],clk,op,p_time;
	printf("Enter the Ouput Rate: ");
	scanf("%d",&o_rate);
	printf("Enter the bucket size: ");
	scanf("%d",&b_size);
	for(int i=1;i<=3;i++){
		p_size[i]=random_num(6) * 10;
		printf("packet_size[%d]: %d\n",i,p_size[i]);
	}
	for(int i=1;i<=3;i++){
		if((p_rm_size+p_size[i])>b_size){
			if(p_size[i]>b_size)
				printf("\n\nPacket Rejected since the incoming packet size (%d bytes) is greater than bucket capacity (%d bytes)", p_size[i], b_size);
			else
				printf("Bucket size exceeded - Packet Rejected\n");
		}
		else{
			p_rm_size+=p_size[i];
			printf("Incoming packet of size %d\n",p_size[i]);
            printf("\nBytes remaining to Transmit: %d", p_rm_size);
            p_time = random_num(4) * 10;
            printf("\nTime left for transmission: %d units", p_time);
            for(clk = 10; clk <= p_time; clk += 10)
            {
                sleep(1);
                if(p_rm_size)
                {
                    if(p_rm_size <= o_rate){
                    	op = p_rm_size;
                    	p_rm_size = 0;
                    }
                        
                    else{
                    	op = o_rate;
         	            p_rm_size -= o_rate;
     	                printf("\nPacket of size %d Transmitted", op);
       	                printf("Bytes Remaining to Transmit: %d", p_rm_size);
                    }
                }
                else
                {
                    printf("\nTime left for transmission: %d units", p_time-clk);
                    printf("\nNo packets to transmit!!");
                }
            }
		}
	}
}