#include <stdio.h>

int fibonacci(int number){
	if(number==0 || number==1){ //Cikis condition'i
		return 1;
	}
	else{
		return fibonacci(number-2) + fibonacci(number-1);
	}
}

int main(){
	int num,i;
	printf("Enter the number to show fibonacci numbers until it\n");
	scanf("%d",&num);
	for(i=0 ; i<num ; i++){
		printf("%d ",fibonacci(i));
	}
}
