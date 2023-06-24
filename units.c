#include<stdio.h>

void main(){
	int units = 4;
	int marks[500];
	char unitnames[][20] = {"CSC 111","CSC 112","CSC 113","CSC 115","CSC 126"};

	while(units>=0){
		printf("Enter %s Marks  ",unitnames[units]);
		scanf("%d",&marks[units]);
		units = units-1;
	}
}