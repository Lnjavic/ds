
#include<iostream>
using namespace std;

int shift(int x[]){
	   
	}

int main(){
	
	int array[] = {1,2,3,4,5};
	int temp = array[4];
	
	int i = 0;
	int j = 1;
	
	while(j<=4 && i<=4){
		   array[i] = array[j];
		   j++;
		   i++;
		} 
	array[4] = NULL;	
	
	for(int c = 0;c<5;c++){
		  cout << array[c];
		}
	}
