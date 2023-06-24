#include<stdio.h>
#include<stdlib.h>

int main(){
int **rows;

rows = (int**)calloc(5,sizeof(int*));
for(int k = 0;k<10;k++){
	rows[k] = (int * )calloc(5,sizeof(int));
}


for(int i = 0; i<5;i++){
	for(int j = 0; j<5;j++){
		rows[i][j] = 0;
	}
}

for(int i = 0; i<5;i++){
	for(int j = 0; j<5;j++){
		printf("%d",rows[i][j]);
	}
	printf("\n");
}

}