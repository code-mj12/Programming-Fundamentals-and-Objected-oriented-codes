//Majid Ahmad, 19I-1796, Assignment#2
#include <stdio.h>
#include <stdlib.h>
// This function takes 2 parameters which is the input from user and then starts printing the building and grass
void func1(char a, char b){
	printf("  | || %c %c %c %c || %c || %c %c %c  || %c || %c %c %c %c || | \n",a ,a ,a ,a ,a ,a ,a ,a ,a ,a ,a ,a ,a);
	printf("  ==================== ______ ====================\n");
	printf("  | || %c %c %c %c || %c || |    | || %c || %c %c %c %c || |   \n",a ,a ,a ,a ,a ,a ,a ,a ,a ,a);
	printf("  | || %c %c %c %c || %c || |    | || %c || %c %c %c %c || |   \n",a ,a ,a ,a ,a ,a ,a ,a ,a ,a);
	printf("  | || %c %c %c %c || %c ||_|____|_|| %c || %c %c %c %c || |   \n",a ,a ,a ,a ,a ,a ,a ,a ,a ,a);
	printf(" /                   /   __   \\                   \\ \n");
	printf("/    %c %c %c %c        /   /__\\   \\        %c %c %c %c    \\ \n",b ,b ,b ,b ,b ,b ,b ,b);
}
//This fuction builds the dome which is constant is all types of buildings
void const_1(){
	printf("                         !\n");
	printf("                       (***)\n");
	printf("                      |0|0|0|\n");	
}
int main(){
	char a, b;
	printf("FAST Main Building in ASCII Art \n");
	printf("Enter window and grass style: ");
	scanf("%c %c",&a,&b);
	const_1();
	func1(a,b);
}
