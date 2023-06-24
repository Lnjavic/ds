#include<stdio.h>

int main(){
    int i;
    char courses[][20] = {"CSC 111","CSC 112","CSC 113","CSC 115","CSC 126","\0"};
    char grade;
    int marks[5];
    for(i=0;i<5;i++){
        printf("Enter %s Marks\n>> ",courses[i]);
        scanf("%d",&marks[i]);
    }
    printf("\nCOURSE   MARKS    GRADE\n");
    for(i=0;i<5;i++){

if(marks[i] < 40){ grade = 'F';}
if(marks[i] >= 40 && marks[i] < 50){ grade = 'D';}
if(marks[i] >= 50 && marks[i] < 60){ grade = 'C';}
if(marks[i]>= 60 && marks[i] < 70){ grade = 'B';}
if(marks[i] >= 70){ grade = 'A';}

printf("%s    %d       %c\n",courses[i],marks[i],grade);

    }
}
