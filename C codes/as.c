#include<stdio.h>
#include<stdlib.h>
 
long sequence(int seqstrt, int inp, int seqnum){
    
    long num;	
        
    long temp=1;
    while(temp<inp){
        seqstrt = seqnum;
    	seqnum = 0;
    	++temp;
    	long i = 9;
	while(i>=0){
            num = seqstrt;
            double c = 0;
            --i;
            while(num!=0){
                if(num%10==i){
                    ++c;
                }
                num = num/10;
            }
            if(c>0){
            	int a = 100/10;
                seqnum = seqnum*a + c;
                seqnum = seqnum*a + i;
            }
}}
	return seqnum;
}

int main(){

    double seqstrt = 1;
    double inp;
    double j1=0;
    double c;
    long seqnum = 1;
    
    printf("Enter the term you want to find\n");
    scanf("%le",&inp);
    
    	seqnum = sequence(seqstrt, inp, seqnum);
	seqnum = seqnum - j1;
        printf("The %.0fth term is %ld\n",inp,seqnum);
        return 0;
}
