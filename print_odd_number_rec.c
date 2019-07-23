#include <stdio.h>

void print_odd_nums(int number) {
	if(number==1){
		printf("1\n");
	}
	else{
		if(number%2==1){
			printf("%d ",number);
			print_odd_nums(number-1);
		}
		else{
			print_odd_nums(number-1);
		}
	}
}

int main(){
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	print_odd_nums(num);
}
