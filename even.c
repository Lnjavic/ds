#include <stdio.h>

int main(){
	int i,numbers=0,total=0;
	float avrge;
	for(i = 20; i<=50;i++){
		if(i%2 != 0){
			continue;
		}
	total += i;
	numbers++;
	}
    avrge = total/numbers;
	printf("Total = %d\n",total);
	printf("Average = %0.2f\n",avrge);
}