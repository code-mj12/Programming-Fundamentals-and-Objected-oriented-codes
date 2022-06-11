#include<stdio.h>

int main(){
	
	char a[1000],e,newarr[1000];
	int i=0,check=0,j=0,u=0,wor=1;
	printf("Enter a sentence: ");
	
while((e=getchar()) != '\n'){
		a[i]=e;
		i++;}
		
	if(e == '\n'){
		a[i]='\0';}
	
	printf("Orignal sentence:\n%s\n",a);
	
	int z =0,z1=0;	
	while(a[z]!='\0'){
		if(a[z]=='a' && a[z+1]=='m' && a[z+2]==' '){			//am
			z = z + 3;continue;}
		if(a[z]=='a' && a[z-1]==' ' && a[z+1]==' ' ){			//a
			z = z +2;continue;}	
		if(a[z]==',' || a[z]==';' || a[z]=='!'|| a[z]=='.'){ //Spaces to be removed put in
			z = z + 1;continue;}
		if(a[z]=='t' && a[z+1]=='h' && a[z+2]=='e' && a[z+3]==' '){	//the
			z = z + 4;continue;}
		if(a[z]=='a' && a[z+1]=='r' && a[z+2]=='e' && a[z+3]==' '){	//are
			z = z + 4;continue;}
		if(a[z]=='o' && a[z+1]=='f' && a[z+2]==' '){			//of
			z = z + 3;continue;}
		if(a[z]=='a' && a[z+1]=='n' && a[z+2]=='d' && a[z+3]==' '){	//and
			z = z + 4;continue;}
		if(a[z]=='i' && a[z+1]=='s' && a[z+2]==' '){			//is
			z = z + 3;continue;}
		
		newarr[z1]=a[z];
		z++;
		z1++;}
	
	newarr[z1]='\0';
					printf("\nAfter removal of stop words: \n%s\n\n",newarr);
						
	int w = 0;				//word count
	while(newarr[w]!='\0'){
		if(newarr[w]== ' '){wor++;}
		w++;}
							//printf("%s %d\n",newarr,wor);

	int l = 0;int k1,k2;
	
	char dim2[30][30];  				//1d to 2d
	
	for(int f=0;f<wor;f++){
		for(int q = 0;q<30;q++){
			if(newarr[l]==' '){
				dim2[f][q]='\0';
				l++;
				//printf("\n");
				k2=q;
				break;}
			else{
				dim2[f][q]=newarr[l];
					if(newarr[l]=='\0'){break;}
				l++;
				}}
			k1=f;
		}
		
	dim2[k1][k2] = '\0'; // the last element is made /0	//printf("%d %d\n",k1,k2);	
			
	char temp[20],temp2[20];
	int wor1=wor;
	int wor2=wor;
	int counttemp=1;
	int t=0, p=0;
	int check1=15, check2=15, check3=15, check4=15;
	int o=1;
	
	while(t<wor2){
	for(p = 0;dim2[t][p]!='\0';p++){
		if(check1==t || check2==t || check3==t || check4==t){
		t++;continue;
		}
		else{
		temp[p]=dim2[t][p];}
		
	}
	temp[p]='\0';
	t++;
	counttemp = 0,o=0;
	while(o<wor1){
	for(p = 0;dim2[o][p]!='\0';p++){
		temp2[p]=dim2[o][p];
	}
	
	o++;temp2[p]='\0';
	for(int s = 0;temp2[s]!='\0';s++){
		if(temp[s]==temp2[s]){	
			if(temp[s+1]!='\0'){
				counttemp++;//printf("uuuu");
				/*if(check1==0){check1=o;/*printf("check4");}
				else if(check2==0){check2=o;}
				else if(check3==0){check3=o;}
				else if(check4==0){check4=o;}*/
				/*printf("check5")*/;break;				
				}
				continue;//printf("check5");
				}
				else{/*printf("check2")*/;break;}
				}
				
				}
				

	
	printf("%s is repeated %d times\n",temp,counttemp);
	}
	/*int y=1,y1=0;	
	while(y1<wor1){
		while(dim2[y1][p]!='\0'){
			temp[p]=dim2[y1][p];		//storing first array in temp1d array	
			p++;
			}
		temp[p]='\0';
					//printf("%s occurences is \n",temp);	
		y++;p = 0;
		while(dim2[y][p]!='\0'){
			temp2[p]=dim2[y][p];	
			if(temp[p]==temp2[p]){
				if(temp[p+1]=='\0'){//working for first word and showing count to but prob with temp2
					counttemp++;y++;p=0;
				}
			p++;	
			}
			else{y++;p=0;continue;}
			}
			y1++;
			printf("%s occurences is %d\n",temp,counttemp);		
		}*/	
		
	printf("\n PS:it shows the word count correctly if word matches totally including capital letters  program has a slight issue of showing how many word are being reapeated\n");

	return 0;
	}
