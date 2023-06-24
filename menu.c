#include<stdio.h>
#include<stdlib.h>

int displayMenu(int number);
int getInput();
int isPos(int number);
int isEven(int number);
int numDigit(int number);

int main(){
	displayMenu(1);
	return 0;
}

int getInput(){
	int number;
	printf("Enter a number\n");
	scanf("%d",&number);
	displayMenu(number);
}

int displayMenu(int number){
	int choice;
	printf("\nSelect>>\n[1] Get input \n[2] Determine if number is even or odd\n[3] Determine if number is positive or negative\n[4] Determine how many digits are in number\n[5] exit\n");
    scanf("%d",&choice); 
    switch(choice){
    	case 1:
    	  getInput();
    	  break;
    	case 2:
    	  isEven(number);
    	  break;
    	case 3:
    	  isPos(number);
    	  break;
    	case 4:
    	  numDigit(number);
    	  break;
    	case 5:
    	  printf("Exit...\n");
    	  break;

    	default:
    	  printf("\nInvalid choice\n");

    }


     return 0;
}

int isEven(int number){
	if(number%2 == 0){
		printf("\n%d is even\n",number);
	}else{
		printf("\n%d is odd\n",number);
	}
	displayMenu(number);
	return 0;
}

int isPos(int number){
	if(number==0){
		printf("\n%d is zero\n",number);
	}else if(number<0){
		printf("\n%d is negative\n",number);
	}else{
		printf("\n%d is positive\n",number);
	}
    displayMenu(number);
	return 0;
}

int numDigit(int number){
	if(number != 0){
     int i,divisions=0,Number=number;

     number = abs(number);
	
	for(i = 0; i>=0;i++){

		number = number/10;
        divisions++;
		if(number<1){
			break;
		}
      
	}
	printf("\n%d has %d digits\n",Number,divisions);
	displayMenu(Number);
}else{
  printf("\n0 has 1 digit\n");
  displayMenu(number);
}
return 0;	
}
