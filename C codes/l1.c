//Majid Ahmed AI-J 19I-1796
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	
	char temp[100],neg[5000][100],pos[4000][50],stpw[300][50],e,a[3000][100];
	int l=0,i=0,j=0,len2d;
	int lneg,lpos,lstp;
	int negsent=0,possent=0;
	
	FILE *fp;
	fp = fopen("negative-words.txt","r");
       	while(fgets(temp,100,fp)!= NULL){
        	for(i=0;temp[i]!='\n';i++){
        		neg[l][i]=temp[i];		//st
        	}
        	neg[l][i-1]='\0';
 		l++;	
        }
        lneg=l;	
        fclose(fp);
        
        fp = fopen("positive-words.txt","r");
        l=0;
	while(fgets(temp,100,fp)!= NULL){
        	for(i=0;temp[i]!='\n';i++){
        		pos[l][i]=temp[i];
        	}
        	pos[l][i-1]='\0';
 		l++;
	}
	lpos=l;
	fclose(fp);
        
	fp = fopen("stopwords.txt","r");
        l=0;
	while(fgets(temp,100,fp)!= NULL){
        	for(i=0;temp[i]!='\n';i++){
        		stpw[l][i]=temp[i];
        	}
        	stpw[l][i-1]='\0';
 		l++;
	}
	lstp=l;
	fclose(fp);
	
	while(1){
	negsent=0,possent=0;
	printf("enter a review -- Press return to exit: \n");
	i=0,j=0;
	while((e=getchar()) != '\n' ){
		if(e == 27){break;}
		if(e == ' '){
			a[i][j]='\0';
			i++;			//splits the string to words
			j=0;
			continue;			
			}								//stores the paragraph
		if(ispunct(e)){
			continue;		//replaces the punctuations
			}
		a[i][j]=e;
		j++;}
	if(e == 27){break;}								
	if(e == '\n'){a[i][j]='\0';}
	
	len2d=i;
	char tempwor[100];
	for(i=0;i<=len2d;i++){
		for(j=0;a[i][j]!='\0';j++){
			a[i][j] = tolower(a[i][j]);		// to lowercase
			}
		}
	for(i=0;i<=len2d;i++){
		for(j=0;j<lstp;j++){
			if(strcmp(&stpw[j][0],&a[i][0])==0){
				stpw[j][0]=' ';			//removes stopwords
				}}}	
	for(i=0;i<=len2d;i++){
		for(j=0;j<lneg;j++){
			if(strcmp(&neg[j][0],&a[i][0])==0){
				negsent++;
				}			//increase neg words
			}				
	}
	for(i=0;i<=len2d;i++){
		for(j=0;j<lpos;j++){
			if(strcmp(&pos[j][0],&a[i][0])==0){
				possent++;			//increase pos
				}
			}				
	}		
	if(negsent>possent){
		printf("Negative Sentiment\n\n");}
	else if(possent>negsent){
		printf("Positive Sentiment\n\n");}
	else{printf("Neutral\n\n");}}
	return 0;}
