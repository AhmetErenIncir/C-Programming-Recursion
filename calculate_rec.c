#include <stdio.h>

int calculate_rec(int number){
	int sum=0;
	if(number==0){
		return 0;
	}
	else{
		sum = sum + number + calculate_rec(number-1);
	}
	return sum;
}

int main(){
	int num;
	printf("Enter number\n");
	scanf("%d",&num);
	printf("Sum : %d\n",calculate_rec(num));
}
