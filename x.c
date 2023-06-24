#include <stdio.h>

void main(){
	int j,i,a=0,l=7;
	double f[7] = {1,2.4,3,4,4,5,6};

	for(i=0;i<l;i++){

		  for(j=i+1;j<l;j++){

		  	if(f[i]<f[j]){
		  		a = f[i];
		  		f[i] = f[j];
		  		f[j]=a;
		  	}

		  }
		}

		for(i=0;i<l;i++){
			printf("%f",f[i]);
		}
}
