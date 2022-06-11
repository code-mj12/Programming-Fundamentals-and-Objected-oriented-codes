#include <stdio.h>
#include <stdlib.h>

int downfloor(int a){
	if(a == 3){
		printf("  | || |   | || |\n");
	}
	else if(a == 5){
		printf("  | || O || |   | || O || |\n");
	}
	else{
	int b = a;
		b = b + 1 - 6;
		b = b/2; 
	printf("  | ||");
	while(b > 0){
	  	printf(" %c",'O');
	  	b--;
	  	     }
	printf(" || O || |   | || O ||");  

	int e = a;
		e = e + 1 - 6;
		e = e/2;	     
	while(e > 0){
	  	printf(" %c",'O');
	  	e--;
	  	     }	
	printf(" || |\n");	
	}}

int downfloor1(int a){
	if(a == 3){
		printf("  | || |___| || |\n");
	}
	else if(a == 5){
		printf("  | || O || |___| || O || |\n");
	}
	else{
	int b = a;
		b = b + 1 - 6;
		b = b/2; 
	printf("  | ||");
	while(b > 0){
	  	printf(" %c",'O');
	  	b--;
	  	     }
	printf(" || O || |___| || O ||");  
	int e = a;
		e = e + 1 - 6;
		e = e/2;	     
	while(e > 0){
	  	printf(" %c",'O');
	  	e--;
	  	     }	
	printf(" || |\n");	
	}}

void defbuild(){

	printf("       _____     \n");
	printf("       |   |     \n");
	printf("       |   |     \n");
	printf("  ____ |___| ____\n");
	printf(" /   /  ___  \\   \\ \n");
	printf("/ * /  /___\\  \\ * \\ \n");	

	}
	
int spacedome(int a){
	int b = a;
	if(b == 3){
		printf("     ");
	}
	else if(b == 5){
		printf("          ");
	}
	else{
		while(b >= -7){
			printf(" ");
			b--;
			}
	    }
	}

int dome(int a){
		spacedome(a);
	printf("    !\n");
		spacedome(a);
	printf("  (***)\n");
		spacedome(a);
	printf(" |O|O|O|\n");
	
	printf("   /\\");
	
	int c = a;
		c = c + 3;
	if(a == 5){
		printf("_____");	
	}
	else if (a > 6){
		while(c > 0){
			printf("_");
			c--;
			    }
		}	
	printf("---------");
	int f = a;
		f = f + 3;
	if(a == 5){
		printf("_____");	
	}
	else if (a > 6){
		while(f > 0){
			printf("_");
			f--;
			    }
		}
	printf("/\\\n");
	
	}

int ground_spaces(int a){
	if(a == 3){
		printf("  ");
		}
	else if(a == 5){
		printf("       ");
		}
	else{
		int b = a;
			b = b+5;
			b = b/2;
		while(b >0){
			printf("  ");
			b--;
			}
		}}

int star(int a){
	if(a == 3){
		printf("* ");
		}
	else if(a == 5){
		printf("* * * *");
		}
	else{
		int b = a;
			b = b+5;
			b = b/2;
		while(b >0){
			printf("* ");
			b--;
			}
		}}

int ground(int a){
	printf(" / ");
	ground_spaces(a);
	printf("/  ___  \\");
	ground_spaces(a);
	printf(" \\\n");
	
	//next line
	printf("/ ");
	star(a);
	if(a==5){
		printf("/  /___\\  \\");}
	else{
		printf("/  /___\\  \\ ");}
	star(a);
	if(a==5){
		printf(" \\\n");}
	else{
		printf("\\\n");}
	}

int equalsign(int a){
	
	printf("  ");
	if(a==3){
		printf("==== _____ ====");
	}
	else if(a==5){
		printf("========= _____ =========");
	}
	else{
		int b = a;
		b = b + 7;
		while(b > 0){
			printf("=");
			b--;}
		printf(" _____ ");
		int c = a;
		c = c + 7;
		while(c > 0){
			printf("=");
			c--;
			    }	
	}
	printf( "\n");
 
	}
void tankspaces(int a){
	if(a == 3){
		printf("   ");
		}
	else if(a==5){
		printf("             ");
		}
	else{
		int b = a;
		b = b-7;
		b = 23 + 2*b;
		while(b > 0){
			printf(" ");
			b--;
		}}
	}

void tankspaces1(int a){
	if(a == 3){
		printf("___");
		}
	else if(a==5){
		printf("_____________");
		}
	else{
		int b = a;
		b = b-7;
		b = 23 + 2*b;
		while(b > 0){
			printf("_");
			b--;
		}}
	}

void tank(int a){
	printf("  ______");
	tankspaces(a);
	printf("______\n");
	
	printf("  |    |");
	tankspaces(a);
	printf("|    |\n");
	
	printf("  |    |");
	tankspaces1(a);
	printf("|    |\n");
	}
	
int topfloor(int a){
	if(a == 3){
		printf("  | || O O O || |\n");
		}
	else if(a == 5){
	printf("  | || O || O O O || O || |\n");
		}
	else{
		printf("  | || ");
		
		int b = a;
			b = b-5;
			b = b/2;
		while(b>0){
			printf("O ");
			b--;
		}
		
		printf("|| O || O O O || O || ");
		int c = a;
			c = c-5;
			c = c/2;
		while(c>0){
			printf("O ");
			c--;
		}
		printf("|| |\n");
		
		}
	}

int repfl(int e, int a){
	int b = e;
		b = b -3;
	while(b > 0){
		topfloor(a);
		b--;
		}
	}
	
void downdash(int a){
	printf("  ");
	if(a == 3){
		printf("____");
	}
	else if(a == 5){
		printf("_________");
	}
	else{
		int b = a;
		while(b > -7){
			printf("_");
			b--;
		}
	}
	printf(" |   | ");
		if(a == 3){
		printf("____");
	}
	else if(a == 5){
		printf("_________");
	}
	else{
		int c = a;
		while(c > -7){
			printf("_");
			c--;
		}
	}
	printf("\n");	
	}
void downdash1(int a){
	printf("  ");
	if(a == 3){
		printf("    ");
	}
	else if(a == 5){
		printf("         ");
	}
	else{
		int b = a;
		while(b > -7){
			printf(" ");
			b--;
			}
		}
	printf(" _____ ");
		if(a == 3){
		printf("    ");
		}
	else if(a == 5){
		printf("           ");
		}
	else{
		int c = a;
		while(c > -7){
			printf(" ");
			c--;
			}
		}
	printf("\n");
	}
	
void downdash2(int a){
	printf("  ");
	if(a == 3){
		printf("    ");
	}
	else if(a == 5){
		printf("         ");
	}
	else{
		int b = a;
		while(b > -7){
			printf(" ");
			b--;
			}
		}
	printf(" |   | ");
		if(a == 3){
		printf("    ");
		}
	else if(a == 5){
		printf("           ");
		}
	else{
		int c = a;
		while(c > -7){
			printf(" ");
			c--;
			}
		}
	printf("\n");
	}
			
int main(){
	
	int a, b, c, d, e;
	printf("FAST Main Building in ASCII Art\n");
	printf("Enter number of floors: ");
	scanf("%d",&a);
	printf("Enter width of building: ");
	scanf("%d",&b);
	
	if( b%2 == 0 && b >2){
		b--;}
	
	if(a < 0 || b < 3){
		defbuild();}
	
	else if(a>=3 && a<8){
		dome(b);
		repfl(a,b);
		equalsign(b);
		downfloor(b);
		downfloor(b);
		downfloor1(b);
		ground(b);
		}
	    
	else if(a == 2){
		downdash1(b);
		downdash(b);
		downfloor(b);
		downfloor1(b);
		ground(b);
		}
	else if(a == 1){
		downdash1(b);
		downdash2(b);
		downdash(b);
		downfloor1(b);
		ground(b);
	
		}
	else if(a == 0){
		downdash1(b);
		downdash2(b);
		downdash2(b);
		downdash(b);
		ground(b);
	}
	else if(a >= 8){
		tank(b);
		repfl(a,b);
		equalsign(b);
		downfloor(b);
		downfloor(b);
		downfloor1(b);
		ground(b);
		}
	    
	return 0;
	
	}
