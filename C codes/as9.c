//Majid Ahmed 19I-1796 AI-J
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 10000
#define ASCII_LEN 255

int main(int argc, char *argv[]){

	char ascis[96],a[MAX_SIZE],b[1000];
	int x,y=32,z,len;
   	float bignum=6488665;
	
	ascis[0] = '\n';
	for(x=1;x<96;x++){					//ascii[0] and 1 stores new line and space and so on
		ascis[x]=(char)y;				//stores the ascii characters in array
		y++;
	}
	y=32;
	char ascis2[96];
	ascis2[0] = '\n';
	for(x=1;x<96;x++){					//ascii[0] and 1 stores new line and space and so on
		ascis2[x]=(char)y;				//stores the ascii characters in array
		y++;
	}	

	FILE *fp;
	fp = fopen(argv[1],"r");
	int i=0;
	do
   	{ 
        	char c = fgetc(fp); 				//stores the the characters of encrypted file	
        	if (feof(fp)){break;} 
  		a[i]=c;
  		i++;
  		z=i;	
  		
    	}while(1);
    	a[i]='\0';
	fclose(fp);

    	float freq[ASCII_LEN] = {0};
    	len = strlen(a);
    	for (i = 0; i < len; i++)
    		{					//Stores frequency of encrypted.txt
    		    freq[a[i]]++;
    		}

	long double encfreq[96],enctmp;
	encfreq[0] = (freq[10]/z)*100; 
	for(int i = 1,y=32; i < 96 ;i++,y++){		//stores freq of encrypted in newline and 32-126
		enctmp=(freq[y]/z)*100;
		encfreq[i]=enctmp;
		//printf("'%c'   %.5Lf\n",y,encfreq[i]);
	}
	

   	i=0;
   	char str[6488665], ch;	
   	FILE *fp1;
    	fp1 = fopen("big.txt","r");
    	ch = fgetc(fp1);
    	
    	while(ch != EOF){
    		str[i]=ch;			//stores big.txt
    		i++;
    		ch = fgetc(fp1);
    	}	
    	str[i-1]='\0';
    	fclose(fp1);
    	
    	
    	float freq1[ASCII_LEN] = {0};
    	len = strlen(str);
    	for (i = 0; i < len; i++)
    		{					//Stores frequency of big.txt
    		    freq1[str[i]]++;
    		}
		    	
	long double bfs[96],bfs1;
	bfs[0]=(freq1[10]/bignum)*100;	
	//printf("'%c'  %.5Lf\n",10,bfs[0]);
	for(int i = 1,x=32;i<96;i++,x++)
	{
		bfs1= (freq1[x]/bignum)*100;
		bfs[i]=bfs1;					//stores according big.txt file
	}
        
        float a1 = 0.0;
        char t1;
        for(int i = 0; i < 96; ++i) 
        {
            for(int j = i + 1; j < 96; ++j) 
            {
                if(bfs[i] < bfs[j]) 
                {
                    t1 = ascis[i];
                    ascis[i] = ascis[j];
                    ascis[j] = t1;
                    a1 = bfs[i];
                    bfs[i] = bfs[j];
                    bfs[j] = a1;
                }
            }
        }
        
	float a2 = 0.0;
        char t2;
        for(int i = 0; i < 96; ++i) 
        {
            for(int j = i + 1; j < 96; ++j) 
            {
                if(encfreq[i] < encfreq[j]) 
                {
                    t2 = ascis2[i];
                    ascis2[i] = ascis2[j];
                    ascis2[j] = t2;
                    a2 = encfreq[i];
                    encfreq[i] = encfreq[j];
                    encfreq[j] = a2;
                }
            }
        }

	char cipher[126],mcipher[96];
	int temp,h;
	for(int i = 0,x=1; i<96; i++){
		temp=(int)ascis[i];
		cipher[temp]=ascis2[i];
		mcipher[temp-30]=cipher[temp];
		h=i;
	}
	cipher[h]='\0';
	mcipher[0]=cipher[10];
	for(int j=0,x=32; j<96; j++,x++){
		printf("%c",mcipher[j]);
	}
		printf("\n");

	return 0;
	}
