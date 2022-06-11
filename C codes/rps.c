//Majid Ahmad 19I-1796 Assignment #3
#include <stdio.h>
#include "rps.h"
int playRound(char name[100], int roundNo, int user_choice, int x) 
{ 

//1 for rock 2 for paper 3 for sccisors; and returns 1 if draw return 2 if use user win and return 3 for computer
	if(x == 1 && user_choice == 1){
	printf("Computer picked ROCK, %s picked ROCK\n",name);
	printf("\nWe picked the same thing! This round is a draw.\n\n");
	return 1;}
	
	else if(x == 2 && user_choice == 2){
	printf("Computer picked PAPER, %s picked PAPER\n",name);
	printf("\nWe picked the same thing! This round is a draw.\n\n");
	return 1;}
	
	else if(x == 3 && user_choice == 3){
	printf("Computer picked SCISSORS, %s picked SCISSORS\n",name);
	printf("\nWe picked the same thing! This round is a draw.\n\n");
	return 1;}
	
	else if(x == 1 && user_choice == 2 ){
	printf("Computer picked ROCK, %s picked Paper\n",name);
	printf("\nPAPER covers ROCK. You win..\n\n");
	return 2;}
	
	else if(x == 1 && user_choice == 3 ){
	printf("Computer picked ROCK, %s picked SCISSORS\n",name);
	printf("\nROCK breaks SCISSORS. I win.\n\n");
	return 3;}
	
	else if(x == 2 && user_choice == 1 ){
	printf("Computer picked PAPER, %s picked ROCK\n",name);
	printf("\nPAPER covers ROCK. I win.\n\n");
	return 3;}
	
	else if(x == 2 && user_choice == 3 ){
	printf("Computer picked PAPER, %s picked SCISSORS\n",name);
	printf("\nSCISSORS cut PAPER. You win.\n\n");
	return 2;}
	
	else if(x == 3 && user_choice == 1 ){
	printf("Computer picked SCISSORS, %s picked ROCK\n",name);
	printf("\nROCK breaks SCISSORS. You win.\n\n");
	return 2;}
	
	else if(x == 3 && user_choice == 2 ){
	printf("Computer picked SCISSORS, %s picked Paper\n",name);
	printf("\nSCISSORS cut PAPER. I win.\n\n");
	return 3;}
	
	else{
	printf("Computer picked ROCK, %s picked INVALID.\n",name);
	printf("\nInvalid choice. You lose.\n\n");
	return 3;}
	 
}
void same_lines(char name[100], int roundNo){
	printf("Round %d \n",roundNo);
	printf("%s, Please enter your choice for this round.\n",name);
	printf("1 for ROCK, 2 for PAPER, and 3 for SCISSORS: ");	
}
int main(void)
{
	char name[100];
	int user = 0, comp = 0, draw = 0; //stores user's computer's and draws win
	int user_choice; 
	int r; //stores return value and changes every time when playround function is called
	int x = getComputerChoice(); // stores computer choice
	initializeRandom();

	printf("Welcome to ROCK PAPER SCISSORS.\n");
	printf("I, Computer, will be your opponent.\n");
	printf("Please type in your name and press return: ");
	scanf("%s", name);
	printf("Welcome %s.\n\n", name);
	printf("All right %s. We will be playing 3 rounds.\n\n", name);
	
	same_lines(name,1);
	scanf("%d",&user_choice);
	r = playRound(name,1,user_choice,x);
	if(r == 1){
	draw++;}
	else if(r == 2){
	user++;}
	else{comp++;}
	
	same_lines(name,2);
	scanf("%d",&user_choice);
	r = playRound(name,2,user_choice,x);
	if(r == 1){
	draw++;}
	else if(r == 2){
	user++;}
	else{comp++;}
	
	same_lines(name,3);
	scanf("%d",&user_choice);
	r = playRound(name,3,user_choice,x);
	if(r == 1){
	draw++;}
	else if(r == 2){
	user++;}
	else{comp++;}
		
	printf("Number of times Computer won: %d \n",comp);
	printf("Number of times %s won: %d \n",name,user);
	printf("Number of draws: %d \n",draw);
	
	if(comp == user)
	{printf("We are evenly matched.\n");}
	else if(user > comp)
	{printf("You, %s, are a master at ROCK, PAPER, SCISSORS.\n",name);}
	else
	{printf("I, Computer, am a master at ROCK, PAPER, SCISSORS.\n");}
	
	return 0;
}
