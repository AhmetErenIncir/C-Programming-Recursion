#include "stdio.h"

int fact(int number){
	if(number == 1){
		return 1;
	}
	else{
		return number * fact(number-1);
	}
}

int main(){
	int num;
	printf("Enter the number to find factorial\n");
	scanf("%d",&num);
	printf("factorial of %d = %d\n",num,fact(num));
}
