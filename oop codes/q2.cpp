#include <iostream>
using namespace std;

void countLetters (char*string, int*&array ,int & size)
{
    int y=0, s=0, x=0, k=0, i=0, j=0;
    int count=0;
    for(y=0; string[y]!='\0'; ++y)
    {}
    char str2[y];
    x=0;
    while(string[x]!='\0')
    {
        str2[x]=string[x];
        ++x;
    }
    str2[x]='\0';
    size=y;
    array=new int[size];
    for (i=0;string[i]!='\0'; i++)
    {
        
        for (j=0;str2[j]!='\0';)
        {
            if (!(string[i]==str2[j]))
            {}
            else{
                ++count;
                str2[j]='-';
            }
            j++;
        }
            if (!(count>0)){}
            else
            {
            array[s]=count;
            ++s;
            }
            count=0;
    }
}

void countWordsBasedOnLength(char*string,int *&array ,int&size)
{
int i=0, spc=0;
    for (i=0; string[i]!='\0'; i++)
    {
        if (!(string[i]==' ')){}
        else
        {
            ++spc;
        }
    }
    int max=0, count=0, j=0, x=0;
    while (string[j]!='\0')
    {
        count++;
        if (string[j]==' ')
        {
            count=0;
        }
        
        if (count>max)
        {
            max=count;
        }
        j++;
    }
    size=max+1;
    array=new int[size];
    int d=0;
    for (d=0; d<size; ++d)
    {
        array[d]=0;
    }
    array[0]=spc;
    int t=0;
    count=0;
    int sum=0;
    while (string[t]!='\0')
    {
        if (!(string[t]!=' ')){}
        else
        {
           ++count; 
        }
        sum=sum+count;
        if (!(count==0 || string[t+1]=='\0')){}
        else
        {
            array[sum]++;
            sum=0;
        }
        count=0;                
        ++t;
    }
}


void countingUniqueWords(char *string, char **&uwords, int *&array, int &size ){
	int n=0,i,j=0;
	
	for(i=0;i<100;i++)
	{
		if(string[i]!=' '){
			uwords[n][j++]=string[i];
		}
		else{
			uwords[n][j++]='\0';//insert NULL
			printf("%s\n",uwords[n]);
			n++;
			j=0;
		}
		if(string[i]=='\0')
		    break;
	}
	
	}
	
/*int main(){
	char s1[]="This is a test String ";
	char** uwords1;
	int* arr1;
	int size1;
	countingUniqueWords(s1,uwords1,arr1,size1);
	
	}	*/
