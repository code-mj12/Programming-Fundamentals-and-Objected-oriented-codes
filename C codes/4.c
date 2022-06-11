//Majid Ahmad Khan 19I-1796 AI-J Assignment # 4
#include <stdio.h>

double fact(double n){			//This function produces factorials
	if(n == 0){
		return 1;
	}
	else{
		return n * fact(n-1);
	}
}

double combin(double n,double r){		//This function produces combinations 
	return fact(n)/(fact(r)*fact(n-r));
}
	
double firsttriangle(double cold, double row){ 		// this function produces triangle
	if(cold <=0){
		return 1;
	}
	else{
			--row;
			--cold;
			printf("%.0lf",combin(row,cold));
		if(combin(row,cold) < 10 && cold > 0){
			printf("     ");
			
		}
		else if(combin(row,cold) <100 && cold > 0){
			printf("    ");
		}
		else if(combin(row,cold) <1000 && cold > 0){
			printf("   ");
		}
		else if(combin(row,cold) <10000 && cold > 0){
			printf("  ");
		}
		else{
			printf(" ");
		}
			++row;
			++cold;
	return firsttriangle(cold-1,row);
	}
}

double space(double c){		//This function produces left spaces
	if(c == 1){
		printf("  ");
		return 1;}
	else{		
		printf("   ");
		return space(c-1);	
	}
}

double func2(double a, double c){ 	//This function calls all function and and changes their values
	if(c == 0){
		return 1;
	}
	else{
		space(c);
		firsttriangle(a,a);
		printf("\n");
		return func2(a+1,c-1);		
	}
}

int main(){
	double b;
	printf("Enter the number of rows in Pascal's Triangle: ");
	scanf("%lf",&b);
	func2(1,b);
	return 0;
	}
