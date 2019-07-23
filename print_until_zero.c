#include <stdio.h>

void PrintRecursively(int number){
	if(number==0){
		printf("%d",number);
	}
	else{
		printf("%d",number);
		PrintRecursively(number-1);
	}
}

int main(){

	int n,i;

	printf("Enter the n\n");
	scanf("%d",&n );

	PrintRecursively(n);
}
