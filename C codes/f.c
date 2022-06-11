//Majid ahmed 19I-1796 assignment 6
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int main(){
	int z=1;
	while(1){
	float sent=0,ch=0,wor=1;
	char a[1000],e;
	int i=0,check=0;
	printf("Enter a sentence %d: ",z++);
	
	while((e=getchar()) != '\n'){
		a[i]=e;
		if(ispunct(e) && e != ',' && e != '-'){
			sent++;
		}
		else if(isalnum(e)){
			ch++;
		}
		else if((isalnum(a[i-1]) || isalnum(a[i-2])) && (isspace(e) || ispunct(e)) && (e != ',')){
			wor++;
			}
		if(e == 39){
			wor++;
		}
		if(i < 5 && (a[0] == 'q' || a[1] == 'u' || a[2] == 'i' || e == 't')){
			check++;}
		i++;
		
		}
		
	if(check == 4){break;}
		
	if(sent == 0 ){sent = 0.5;}
		
	double ari;
	double div1 =ch/wor;
	double div2 = wor/sent;
	ari = 4.71 * div1 + .5 * div2 - 21.43; 
	
	if(ari<0){ari = 0;}
	if(ch ==0 && wor==1){wor--;}
//	if(ch>0 && wor==0){wor=1;sent=1.0;}	
	
	printf("\nNumber of sentences: %.0f",sent);
	printf("\nNumber of words: %.0f",wor);
	printf("\nNumber of characters: %.0f\n",ch);
	printf("Readability index: %.0lf\n\n",ceil(ari));
	}
	return 0;
	}
