#include <iostream>

using namespace std;

int Strlen(char * s1){
	int i = 0;
	while(*(s1+i) != '\0'){
		i++;
	}
	return i;
}

char *Strcpy (char *s1, const char *s2 ){
	int i = 0, j = 0, k =0;
	while(*(s2+j) != '\0'){
		j++;
	}
	while(*(s1+k) != '\0'){
		k++;
	}
	while(*(s2+i) != '\0'){
		*(s1+i) = *(s2+i);
		i++;}
	*(s1+i) =  '\0';
	if(k<j){
		*s1='\0';
	/*	while(*(s2+i) != '\0'){
			*(s1+i) = '/0';
			i++;}*/
		return s1;
		}
	else{
		return s1;
	}
}

char *Strncpy (char *s1, const char *s2, int n ){
	int i = 0;
	int j = 0;
	while(*(s2+j) != '\0'){
		j++;
	}
	while(i < n && i < j){
		*(s1+i) = *(s2+i);
		i++;
	}
	//*(s1+i) =  '\0';
	return s1;
}

char *StrCat(char *s1, const char *s2 ){
	int i = 0,j=0;
	while(*(s1+i) != '\0'){
		//*(s1+i) = *(s2+i);
		i++;
	}
	while(*(s2+j) != '\0'){
		*(s1+i) = *(s2+j);
		j++;i++;
	}
	*(s1+i) ='\0';
	return s1;
}

char *StrnCat(char *s1, const char *s2, int n ){
	int i = 0,j=0;
	while(*(s1+i) != '\0'){
		//*(s1+i) = *(s2+i);
		i++;
	}
	while(j<n){
		*(s1+i) = *(s2+j);
		j++;i++;
	}
	*(s1+i) ='\0';
	return s1;
}
int StrCmp( const char *s1, const char *s2){
	int sum1=0,sum2=0;
	int i = 0;
	while(*(s1+i) != '\0'){
	sum1 = sum1 + *(s1+i);
	i++;
	}
	i=0;
	while(*(s2+i) != '\0'){
	sum2 = sum2 + *(s2+i);
	i++;
	}
	if(sum1<sum2){
		return -1;}
	else if(sum1>sum2){
		return 1;}
	else if(sum1==sum2){
			return 0;}
}

int StrnCmp( const char *s1, const char *s2, int n){
	int sum1=0,sum2=0;
	int i = 0;
	while(i<n){
	sum1 = sum1 + *(s1+i);
	i++;
	}
	i=0;
	while(i<n){
	sum2 = sum2 + *(s2+i);
	i++;
	}

	if(sum1<sum2){
	return -1;}
	else if(sum1>sum2){
		return 1;}
	else if(sum1==sum2){
			return 0;}
}
char **StrTok(char *s1,const char s2)
{
    int len=0, j=0, i=0, row=0, col=0;
    for (j=0; s1[j]!='\0'; ++j)
    {
        if(!(s1[j]==s2)){}
		else{
            len++;
        }
    }
    char **ptr=new char*[len+1];
    for (i=0; i<=len; i++)
    {
        ptr[i]=new char[15];
    }
    for (j=0; s1[j]!='\0';++j)
    {
        if(!(s1[j]==s2)){
			ptr[row][col]=s1[j];
        	++col;
        }else{
			++row;
			col=0;
        }       
    }
    return ptr;
}
/*int StrFind (char *s1, char *s2){
	int i = 0,k=0,j=0,sum=0;
	while(*(s2+i) != '\0'){
		i++;
		//cout<<i;
	}
	while(*(s1+k) != '\0'){
		k++;
		//cout<<i;
	}
	//cout<<k;
	while(k>0){
		if(*(s2+j)==*(s1+j)){
			sum++;
			cout<<sum<<endl;
			if(sum == i){
				//cout<<j-i+1;
				return j-i+1;
			}
		}
		else{
			sum=0;
		}
		//cout<<sum;
		j++;
		k--;
	}
	return -1;
}*/
int StrFind(char *s1, char* s2)
{
    int sum1=0, sum2=0, true1=0, i=0, j=0, k=0;
    for (i=0;s2[i]!='\0'; ++i)
    {
        sum2++;
    }
    for (j=0 ;s1[j]!='\0';++j)
    {
        sum1++;
    }
    while (k<sum1)
    {
        if(!(s1[k]==s2[true1])){}
		else{
            true1++;
        }
        if (!(true1 == sum2)){}
		else{
            true1=0;
            return (k-sum2+1);
        }
        ++k;
    }
    return -1;
}
char *SubStr ( char *s1, int pos, int len){
	char *s2 = new char[len];
	int i = 0;
	while(i<len){
		*(s2+i)=*(s1+pos+i);
		++i;
	}
	*(s2+i)='\0';
	return s2;
}
/*int main() {


	//int i;
	char s1[25]="World",s2[25]="World";
	cout<<StrCmp(s1,s2);
	
	
	return 0;
}*/
