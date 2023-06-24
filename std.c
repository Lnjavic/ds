#include <stdio.h>
#include <math.h>

int get_marks();
int grade_marks();
int total_marks();
int calculate_std();
int displayMenu();


char name[50],regNo[50];
int marks[5] = {1,2,3,4,5};
char courses[][20] = {"CSC 111","CSC 112","CSC 113","CSC 115","CSC 126"};


void main(){


    printf("Enter your name\n>> ");
    scanf("%[^\n]s",&name);
    printf("Enter your registration number\n>> ");
    scanf("%s",&regNo);

    displayMenu();
}

int displayMenu(){
	int option;
	printf("\nSelect>>\n[1] Enter marks\n[2] Grade marks\n[3] Calculate total \n[4] Find standard deviation of marks\n[5] Exit\n\n>> ");
	scanf("%d",&option);

    switch(option){
    	case 1:
    	  get_marks();
    	  break;
    	case 2:
    	  grade_marks();
    	  break;
    	case 3:
    	  total_marks();
    	  break;
    	case 4:
    	  calculate_std();
    	  break;
    	case 5:
    	  printf("Exit...\n");
    	  break;
    	default:
    	  printf("\nInvalid choice\n");
    	  displayMenu();
    }

    return 0;
}

int get_marks(){
	for(int i = 0; i < 5; i++){
		printf("Enter %s marks\n>> ",courses[i]);
		scanf("%d",&marks[i]);
	}
	displayMenu();
	return 0;
}

int grade_marks(){
	char grade;
	printf("\nCOURSE   MARKS    GRADE\n");
	for(int i = 0; i < 5; i++){
		if(marks[i] < 40){ grade = 'F';}
        if(marks[i] >= 40 && marks[i] < 50){ grade = 'D';}
        if(marks[i] >= 50 && marks[i] < 60){ grade = 'C';}
        if(marks[i]>= 60 && marks[i] < 70){ grade = 'B';}
        if(marks[i] >= 70){ grade = 'A';}

        printf("\n%s    %d       %c\n",courses[i],marks[i],grade);
	}
	displayMenu();
	return 0;
}

int total_marks(){
	int total = 0;
	for(int i = 0; i < 5;i++){
       total += marks[i];
	} 

	printf("\nYour total = %d\n ",total);
	displayMenu();
	return 0;
}

int calculate_std(){
	float ave,stdDeviation,sum=0.0,sumSquares=0.0;

	for(int i=0;i<5;i++){
      sum += marks[i];
	}

    ave = sum/5;

    for(int i=0;i<5;i++){
      sumSquares += pow(marks[i]-ave,2);

    }
    stdDeviation = sqrt(sumSquares/5);

    printf("\n>> Standard deviation = %0.2f\n",stdDeviation);
    displayMenu();

    return 0;
}
