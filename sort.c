#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void start(float numbers[],int numLength);
void operationOption(float numbers[],int numLength);
void calcAvg(float numbers[],int numLength);
void calcDev(float numbers[],int numLength);
void findMax(float numbers[],int numLength);
void findMin(float numbers[],int numLength);
void sortDescending(float numbers[],int numLength);
void main();


void start(float numbers[],int numLength){
	operationOption(numbers,numLength);
}

void operationOption(float numbers[],int numLength){
	int option;
	printf("\nSelect>> \n[1] Sort numbers in descending order\n[2] Find minimum number\n[3] Find the maximum number\n[4] Calculate average of numbers\n[5] Calculate the standard deviation of numbers\n[6] Change numbers\n[7] Exit\n\n>> ");
	scanf("%d",&option);
	switch(option){
		case 1:
		  sortDescending(numbers,numLength);
		  break;
		case 2:
		  findMin(numbers,numLength);
		  break;
		case 3:
		  findMax(numbers,numLength);
		  break;
		case 4:
		  calcAvg(numbers,numLength);
		  break;
		case 5:
		  calcDev(numbers,numLength);
		  break;
		case 7:
		  printf("\n>> Exit...\n");
		  break;
		case 6:
		  main();
		  break;
		default:
		  printf("Invalid Option Try again\n");
		  start(numbers,numLength);
    }
}

void calcDev(float numbers[],int numLength){
	int i,j;
	float ave,stdDeviation,sum=0.0,sumSquares=0.0;

	for(i=0;i<numLength;i++){
      sum = sum + numbers[i];
	}

    ave = sum/numLength;

    for(i=0;i<numLength;i++){
      sumSquares += pow(numbers[i]-ave,2);

    }
    stdDeviation = sqrt(sumSquares/numLength);
    printf("\n>> Standard deviation = %0.2f\n",stdDeviation);
    operationOption(numbers,numLength);
}

void findMax(float numbers[], int numLength){

	int j,i,a=0;

	for(i=0;i<numLength;i++){

		  for(j=i+1;j<5;j++){

		  	if(numbers[i]<numbers[j]){
		  		a = numbers[i];
		  		numbers[i] = numbers[j];
		  		numbers[j]=a;
		  	}

		  }
		}

			printf("\n>>max = %.0f \n",numbers[0]);
	operationOption(numbers,numLength);

}

void findMin(float numbers[],int numLength){
	int j,i,a=0;

	for(i=0;i<numLength;i++){

		  for(j=i+1;j<5;j++){

		  	if(numbers[i]<numbers[j]){
		  		a = numbers[i];
		  		numbers[i] = numbers[j];
		  		numbers[j]=a;
		  	}

		  }
		}

			printf("\n>> min  = %.0f \n",numbers[numLength-1]);
			operationOption(numbers,numLength);

}

void calcAvg(float numbers[],int numLength){
	int total=0,i;
	float average;

	for(i=0;i<numLength;i++){
      total = total+numbers[i];
	}

    average = (float)total/(float)numLength;
    printf("\n>> Average = %0.0f\n",average);
    operationOption(numbers,numLength);

}

void sortDescending(float numbers[], int numLength){
	int j,i,a=0;

	for(i=0;i<numLength;i++){

		  for(j=i+1;j<numLength;j++){

		  	if(numbers[i]<numbers[j]){
		  		a = numbers[i];
		  		numbers[i] = numbers[j];
		  		numbers[j]=a;
		  	}

		  }
		}
    printf("\n>> ");
		for(i=0;i<numLength;i++){
			printf("%0.0f ",numbers[i]);
		}
    printf("\n");
		operationOption(numbers,numLength);

}


void main(){
	int OriginalLength,a,b,numLength,i;
	printf("How many numbers do you have?\n>> ");
	scanf("%d",&numLength);
	float numbers[numLength];

	OriginalLength = numLength+1;
    a = numLength;

	for(i=0;i<a;i++){
		b = OriginalLength-numLength;
		printf("Enter number[%d]\n>> ",b);
		scanf("%f",&numbers[i]);
		numLength = numLength-1;

	}
	start(numbers,a);
}
